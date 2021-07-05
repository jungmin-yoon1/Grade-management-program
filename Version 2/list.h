//성적표_ver_2_2.cpp

#ifndef LIST_H
#define LIST_H

struct Node  //Node 구조체 설계
{
	Node* prev;
	Node* next;

	void* data;
};

struct List
{
	Node* head;
};

List* CreateList();
void RemoveList(List* list, bool deleteData);
Node* GetTail(List* list);

void InsertNodeAfter(Node* node, void* data);
void RemoveNode(Node* node, bool deleteData);
Node* GetNext(Node* node);
Node* GetPrev(Node* node);
void* GetData(Node* node);

#endif