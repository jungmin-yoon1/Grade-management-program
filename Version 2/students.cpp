//����ǥ_ver_2_2.cpp
#include "students.h"
#include "list.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student  //�� ���� �л��� ���� ������ ������ ����ü
{
	int student_No;//�й�
	string name; //�̸�
	int kor, eng, math; //����, ����, ���� ����
	float average; // ���
};

List* students = NULL;

float TotalAve = 0.0f; //��ü ���
int NumberOfStudent = 0; //������� �Էµ� �л� ��

//�л� �Ѹ� �߰�
//��ȯ ��: �� �̻� �Է��� �� ���� ��� false ��ȯ

bool AddStudent()
{
	Student* std = new Student; //��ũ�� ����Ʈ�� �����ϱ� ���� Student ������ �������� �Ҵ�

	std->student_No = NumberOfStudent + 1; //�ش� �л��� �л���ȣ�� �ڵ����� �Է�

	//�Է��ϴ� �л��� �̸�, ������ ������� �Է¹���
	cout << "�̸�(�������) ����, ����, ���� ������ �Է��ϼ���: \n"; 
	cin >> std->name >> std->kor >> std->eng >> std->math;

	std->average = float(std->kor + std->eng + std->math) / 3.0f; //���� ��� ���

	const int prev_num = NumberOfStudent; //�������� �Է¹��� �л� �� 
	const int current_num = NumberOfStudent + 1; //������� �Է¹��� �л� �� 1 ����

	TotalAve = (TotalAve * prev_num + std->average) / current_num; //��ü ��� ���

	NumberOfStudent++; //�Է� ���� �л� �� ����

	//students ����Ʈ�� �� ��� �߰�
	InsertNodeAfter(GetTail(students), std);
	return true;
}

//��ü ���� ������
void ShowAll()
{
	cout.precision(2);
	cout << fixed;

	cout << "\n        <��ü ����ǥ ����>";
	cout << "\n   �й� ���� ���� ����   ���\n";

	//����Ʈ�� �ִ� ��� �л����� ���� ���
	Node* current = students->head->next; //��� ����� ���� ������ Ž�� ����
	while (current != students->head)
	{
		const Student* std = (Student*)GetData(current); //���� ����� �����͸� ������
		cout << setw(7) << std->student_No << setw(7); 
		cout << std->name << setw(5) << std->kor << setw(5);
		cout<< std->eng << setw(5) << std->math << setw(7) << std->average << endl;
		current = GetNext(current);
	}

	cout << "\n��ü ��� = " << TotalAve << endl; //��ü ��� ���
}

void Setup() //��ũ�� ����Ʈ�� �ʱ�ȭ, AddStudent(), ShowAll() �Լ� ȣ������ �ݵ�� ȣ���ؾ���
{
	students = CreateList(); //����Ʈ ����
}

void Teardown() //����� ���ҽ��� ����, ���α׷� ������ �ݵ�� ȣ���ؾ� �޸𸮰� �ùٸ��� ������
{
	RemoveList(students, true); //����Ʈ ����
}