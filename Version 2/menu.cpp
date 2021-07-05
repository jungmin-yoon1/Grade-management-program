//성적표_ver_2_2.cpp

#include "menu.h"
#include <iostream>
using namespace std;

MENU ShowMenu() //메뉴 보여주고 선택 값을 반환
{
	while (1)
	{
		//메뉴 보여주기
		cout << "\n--------메뉴--------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기\n";
		cout << "Q. 프로그램 종료\n";
		cout << "\n------------------- \n";
		cout << "원하는 작업의 번호를 입력하세요 : ";

		char select; //작업 번호 입력 받기
		cin >> select;

		switch (select)
		{
		case '1':
			return MENU_ADD_STUDENT;
		case '2':
			return MENU_SHOW_ALL;
		case 'q':
		case 'Q':
			return MENU_QUIT;
		defalut:
			cout << "올바른 값을 입력해주세요\n";
			break;
		}
	}
	return MENU_QUIT; //이 문장은 절대 실행 안됨, 단, 오류 메시지 출력 방지를 위해 추가

}