#include <iostream>
#include <fstream>
using namespace std;

//结点
struct Node
{
	int val;
	Node* pre;
	Node* next;
};

struct  List
{
	Node * head;//链表的头结点
	int length;//表中结点的个数
};

List list;

//通过读取文件来创建一个新的链表
int CreateListFromFile()
{
	if (list.head != nullptr)
	{
		cout << "List Existed" << endl;
		return -1;
	}
	ifstream filein("ListData.txt");
	if (filein.is_open() != true)
	{
		cout << "Open File Failed" << endl;
		return -2;
	}
	list.head = new Node();
	list.length = 1;
	filein >> list.head->val;
	Node * preNode = list.head;
	Node * nextNode = list.head;
	int d;
	while (1)
	{
		filein >> d;
		if(d == 0)
		{
			break;
		}
		preNode = new Node();
		list.length++;
		preNode->val = d;
		preNode->pre = nextNode;
		nextNode->next = preNode;
		nextNode = preNode;

	}

	filein.close();
	return 0;
}

//通过循环的方式打印链表
int PrintList()
{
	if (list.head == nullptr)
	{
		cout << "Bad List" << endl;
		return -1;
	}
	Node* node = list.head;
	while (node != nullptr)
	{
		cout << node->val << " ";
		node = node->next;
	}
	cout << endl;

	return 0;
}

//通过递归的方式打印链表
int PrintListRecur(Node * node)
{
	if (node  == nullptr)
	{
		cout << endl;
		return 0;
	}
	cout << node->val << " ";
	PrintListRecur(node->next);
}

//清空链表的所有内容
int ClearList()
{
	Node * preNode = list.head->next;
	Node * nextNode = list.head->next;
	delete(list.head);
	list.head = nullptr;
	while (nextNode != nullptr)
	{
		preNode = nextNode->next;
		delete(nextNode);
		nextNode = preNode;
	}
	return 0;
}

int main()
{
	if (CreateListFromFile() < 0)
	{
		cout << "Create Linked List Failed" << endl;
		return -1;
	}
	PrintList();
	PrintListRecur(list.head);
	ClearList();

	return 0;
}
