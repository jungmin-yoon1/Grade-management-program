//성적표_ver_2_2.cpp
#include "students.h"
#include "list.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student  //한 명의 학생에 대한 정보를 보관할 구조체
{
	int student_No;//학번
	string name; //이름
	int kor, eng, math; //국어, 영어, 수학 점수
	float average; // 평균
};

List* students = NULL;

float TotalAve = 0.0f; //전체 평균
int NumberOfStudent = 0; //현재까지 입력된 학생 수

//학생 한명 추가
//반환 값: 더 이상 입력할 수 없는 경우 false 반환

bool AddStudent()
{
	Student* std = new Student; //링크드 리스트에 보관하기 위해 Student 변수를 동적으로 할당

	std->student_No = NumberOfStudent + 1; //해당 학생의 학생번호를 자동으로 입력

	//입력하는 학생의 이름, 성적을 순서대로 입력받음
	cout << "이름(공백없이) 국어, 영어, 수학 점수를 입력하세요: \n"; 
	cin >> std->name >> std->kor >> std->eng >> std->math;

	std->average = float(std->kor + std->eng + std->math) / 3.0f; //개인 평균 계산

	const int prev_num = NumberOfStudent; //이전까지 입력받은 학생 수 
	const int current_num = NumberOfStudent + 1; //현재까지 입력받은 학생 수 1 증가

	TotalAve = (TotalAve * prev_num + std->average) / current_num; //전체 평균 계산

	NumberOfStudent++; //입력 받은 학생 수 증가

	//students 리스트에 새 노드 추가
	InsertNodeAfter(GetTail(students), std);
	return true;
}

//전체 성적 보여줌
void ShowAll()
{
	cout.precision(2);
	cout << fixed;

	cout << "\n        <전체 성적표 보기>";
	cout << "\n   학번 국어 영어 수학   평균\n";

	//리스트에 있는 모든 학생들의 정보 출력
	Node* current = students->head->next; //헤드 노드의 다음 노드부터 탐색 시작
	while (current != students->head)
	{
		const Student* std = (Student*)GetData(current); //현재 노드의 데이터를 가져옴
		cout << setw(7) << std->student_No << setw(7); 
		cout << std->name << setw(5) << std->kor << setw(5);
		cout<< std->eng << setw(5) << std->math << setw(7) << std->average << endl;
		current = GetNext(current);
	}

	cout << "\n전체 평균 = " << TotalAve << endl; //전체 평균 출력
}

void Setup() //링크드 리스트를 초기화, AddStudent(), ShowAll() 함수 호출전에 반드시 호출해야함
{
	students = CreateList(); //리스트 생성
}

void Teardown() //사용한 리소스를 정리, 프로그램 종료전 반드시 호출해야 메모리가 올바르게 해제됨
{
	RemoveList(students, true); //리스트 정리
}