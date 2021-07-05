//����ǥ_ver_2_2.cpp

#include "list.h"

List* CreateList() //���ο� ��ũ�� ����Ʈ ����, ��ȯ ��: ���ο� ��ũ�� ����Ʈ�� ������
{
	Node* head = new Node; //head ��带 ����� �ʱ�ȭ
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List; //List ����ü�� �������� �����ϰ� �ʱ�ȭ
	list->head = head; // ��� ���Ͽ��� ���� head ����� ������ ���� head ���� �ʱ�ȭ
	return list; // List ����ü ��ȯ
}

// ����Ʈ�� ��� ���� ������ ����
void RemoveList(List* list, bool deleteData)
{
	Node* current = list->head; //��� ������ ������ ����

	do
	{
		Node* next = current->next;// �̸� ���� ����� �ּҸ� ����

		if (deleteData)
		{
			delete current->data;
		}
		delete current;
		current->next;
	} while (current != list->head);

	delete list; //����Ʈ ����
}

Node* GetTail(List* list) //������ ��� ��ȯ
{
	return list->head->prev; //��� ��� ���� ��ȯ(�ڱ� �ڽ��� ���� ����)
}


void InsertNodeAfter(Node* node, void* data) //���ο� ��带 �߰� , node �ڿ� ���ο� ��尡 �߰��� ����, data= �� ��忡 �� ������
{
	//���ԵǴ� ���� �յ� ��� �ּҸ� before, after ������ �־��
	Node* before = node;
	Node* after = node->next;

	//�� ��带 ����� �ʱ�ȭ
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	//�� ��� ��ġ ����
	after->prev = newNode;
	before->next = newNode;
}

void RemoveNode(Node* node, bool deleteData) // node: ������ ���, deleteData: true�� ��尡 ����Ű�� �����͵� ����
{
	Node* before = node->prev;
	Node* after = node->next;

	//node�� ���� ���� ���� ��带 ����
	before->next = after;
	after->prev = before;

	//node�� �����Ϳ� node �ڽ��� ����
	if (deleteData)
	{
		delete node->data;
	}
	delete node;
}

//����� ���� ��� ��ȯ
Node* GetNext(Node* node)
{
	return node->next;
}

//����� ���� ��� ��ȯ
Node* GetPrev(Node* node)
{
	return node->prev;
}

//��忡 ������ ������ ��ȯ
void* GetData(Node* node)
{
	return node->data;
}

