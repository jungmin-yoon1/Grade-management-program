//성적표_ver_2_2.cpp

#include "list.h"

List* CreateList() //새로운 링크드 리스트 생성, 반환 값: 새로운 링크드 리스트의 포인터
{
	Node* head = new Node; //head 노드를 만들고 초기화
	head->prev = head;
	head->next = head;
	head->data = 0;

	List* list = new List; //List 구조체를 동적으로 생성하고 초기화
	list->head = head; // 헤더 파일에서 만든 head 멤버를 위에서 만든 head 노드로 초기화
	return list; // List 구조체 반환
}

// 리스트의 모든 노드와 데이터 제거
void RemoveList(List* list, bool deleteData)
{
	Node* current = list->head; //헤드 노드부터 제거할 것임

	do
	{
		Node* next = current->next;// 미리 다음 노드의 주소를 저장

		if (deleteData)
		{
			delete current->data;
		}
		delete current;
		current->next;
	} while (current != list->head);

	delete list; //리스트 제거
}

Node* GetTail(List* list) //마지막 노드 반환
{
	return list->head->prev; //헤드 노드 이전 반환(자기 자신일 수도 있음)
}


void InsertNodeAfter(Node* node, void* data) //새로운 노드를 추가 , node 뒤에 새로운 노드가 추가될 것임, data= 새 노드에 들어갈 데이터
{
	//삽입되는 곳의 앞뒤 노드 주소를 before, after 변수에 넣어둠
	Node* before = node;
	Node* after = node->next;

	//새 노드를 만들고 초기화
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = after;
	newNode->prev = before;

	//새 노드 위치 조정
	after->prev = newNode;
	before->next = newNode;
}

void RemoveNode(Node* node, bool deleteData) // node: 제거할 노드, deleteData: true면 노드가 가리키는 데이터도 제거
{
	Node* before = node->prev;
	Node* after = node->next;

	//node의 이전 노드와 다음 노드를 연결
	before->next = after;
	after->prev = before;

	//node의 데이터와 node 자신을 제거
	if (deleteData)
	{
		delete node->data;
	}
	delete node;
}

//노드의 다음 노드 반환
Node* GetNext(Node* node)
{
	return node->next;
}

//노드의 이전 노드 반환
Node* GetPrev(Node* node)
{
	return node->prev;
}

//노드에 보관된 데이터 반환
void* GetData(Node* node)
{
	return node->data;
}

