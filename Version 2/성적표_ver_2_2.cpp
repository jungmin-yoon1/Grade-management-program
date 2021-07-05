#include "students.h"
#include "menu.h"
#include <iostream>
using namespace std;

int main()
{
	//프로그램이 종료될 때까지 메뉴 보여주고 작업 처리
	while (1)
	{ 
		MENU select; //메뉴를 보여줌
		select = ShowMenu();

		switch (select)
		{
		case MENU_ADD_STUDENT: //ShowMenu()에서 MENU_ADD_STUDENT 반환한 경우에 실행
		{
			bool succeeded;
			succeeded = AddStudent();

			if (succeeded)
				cout << "\n학생 성적이 올바르게 입력되었습니다.\n";
			else
				cout << "\n더 이상 입력할 수 없습니다.\n";
			break;
		}
		case MENU_SHOW_ALL: //전체 성적 보기
		{
			ShowAll();
			break;
		}
		case MENU_QUIT:
			cout << "\n프로그램을 종료합니다.\n";
			return 0;
		}
	}
	return 0;
}