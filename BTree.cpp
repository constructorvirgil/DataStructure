#include <iostream>
#include <fstream>
#define TREESIZE 10000

using namespace std;
struct Node
{
	Node* leftChild;
	Node* rightChild;
	int val;
};

struct BTree
{
	Node* root;

};

BTree bTree;
int vals[TREESIZE] = { 0 };

void CreateRecur(Node* node,int j)
{
	if (vals[j * 2 + 1] != 0)
	{
		node->leftChild = new Node();
		node->leftChild->val = vals[j * 2 + 1];
		CreateRecur(node->leftChild, j * 2 + 1);
	}
	if (vals[j * 2 + 2] != 0)
	{
		node->rightChild = new Node();
		node->rightChild->val = vals[j * 2 + 2];
		CreateRecur(node->rightChild, j * 2 + 2);
	}
	return ;
}

int CreateTreeFromFile()
{
	if (bTree.root != nullptr)
	{
		cout << "Tree Existed" << endl;
		return -1;
	}
	ifstream filein("data.txt");
	if (filein.is_open() != true)
	{
		cout << "Open File Failed" << endl;
		return -2;
	}

	int d;

	int i = 0;
	while (1)
	{
		filein >> d;
		if (d == 0)
		{
			break;
		}
		vals[i] = d;
		i++;
	}

	bTree.root = new Node();
	Node* node = bTree.root;
	node->val = vals[0];

	CreateRecur(node,0);

	filein.close();
	return 0;
}

void PrePrintTree(Node * node)
{
	if (node == nullptr)
	{
		return;
	}
	cout << node->val << endl;
	if (node->leftChild != nullptr)
	{
		PrePrintTree(node->leftChild);
	}
	if (node->rightChild != nullptr)
	{
		PrePrintTree(node->rightChild);
	}
	return;
}

void MidPrintTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->leftChild != nullptr)
	{
		MidPrintTree(node->leftChild);
	}
	cout << node->val << endl;
	if (node->rightChild != nullptr)
	{
		MidPrintTree(node->rightChild);
	}

	return;
}

void LastPrintTree(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->leftChild != nullptr)
	{
		LastPrintTree(node->leftChild);
	}
	if (node->rightChild != nullptr)
	{
		LastPrintTree(node->rightChild);
	}
	cout << node->val << endl;

	return;
}


int main()
{
	if (CreateTreeFromFile() < 0)
	{
		cout << "Create Tree Failed" << endl;
		return -1;
	}
	cout << "先序遍历二叉树" << endl;
	PrePrintTree(bTree.root);
	cout << "中序遍历二叉树" << endl;
	MidPrintTree(bTree.root);
	cout << "后序遍历二叉树" << endl;
	LastPrintTree(bTree.root);

	return 0;
}
