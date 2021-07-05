#include <iostream>
#include <iomanip> //setw() 사용하기 위함, setw(5) : 뒤이어 출력하는 값은 무조건 5칸 사용
using namespace std;

int main()
{
	int S1_No, S2_No, S3_No; //학번
	int S1_Kor, S2_Kor, S3_Kor; //국어 점수
	int S1_Math, S2_Math, S3_Math; // 수학 점수
	int S1_Eng, S2_Eng, S3_Eng;//영어 점수
	float S1_Ave, S2_Ave, S3_Ave; //개인 평균
	float TotalAve = 0.0f; // 전체 평균
	int NumberOfStudent = 0; // 현재까지 입력된 학생 수

	while (1)
	{
		cout << "\n--------메뉴--------\n";
		cout << "1. 학생 성적 추가\n";
		cout << "2. 전체 성적 보기\n";
		cout << "Q. 프로그램 종료\n";
		cout << "\n------------------- \n";
		cout << "원하는 작업의 번호를 입력하세요 : ";

		char select;
		cin >> select;

		switch (select)
		{
		case '1':  //학생 성적 추가
		{
			if (NumberOfStudent==3)
			{
				cout << "\n더이상 입력 불가합니다.\n";
				break;
			}
			int Kor, Eng, Math;
			cout << "국어, 영어, 수학 점수를 입력하세요 : ";
			cin >> Kor >> Eng >> Math;

			float Ave = float(Kor + Eng + Math) / 3.0f;
			if (NumberOfStudent==0)
			{
				S1_No = NumberOfStudent + 1;
				S1_Kor = Kor;
				S1_Eng = Eng;
				S1_Math = Math;
				S1_Ave = Ave;
				TotalAve = S1_Ave;
			}
			else if (NumberOfStudent == 1)
			{
				S2_No = NumberOfStudent + 1;
				S2_Kor = Kor;
				S2_Eng = Eng;
				S2_Math = Math;
				S2_Ave = Ave;
				TotalAve = (S1_Ave+S2_Ave)/2;
			}
			else
			{
				S3_No = NumberOfStudent + 1;
				S3_Kor = Kor;
				S3_Eng = Eng;
				S3_Math = Math;
				S3_Ave = Ave;
				TotalAve = (S1_Ave + S2_Ave + S3_Ave) / 3;
			}

			NumberOfStudent++; //입력 받은 학생 수 증가

			cout << "\n학생 성적이 올바르게 입력되었습니다.\n"; //작업 성공 알림
			break;
		}
		case '2': //전체 성적 보기
		{
			//실수 출력시 소수점 이하 두 자리만 표시되도록
			cout.precision(2); 
			cout << fixed;

			cout << "\n        <전체 성적표 보기>";
			cout << "\n   학번 국어 영어 수학   평균\n";
			int i;
			for (i = 0; i<NumberOfStudent; ++i) // 입력 받은 학생 수 만큼 반복
			{
				if (i == 0)
				{
					cout <<setw(7) << S1_No << setw(5) << S1_Kor << setw(5) << S1_Eng << setw(5) << S1_Math << setw(7) << S1_Ave << endl;
				}
				else if (i == 1)
				{
					cout << setw(7) << S2_No << setw(5) << S2_Kor << setw(5) << S2_Eng << setw(5) << S2_Math << setw(7) << S2_Ave << endl;
				}
				else
				{
					cout << setw(7) << S3_No << setw(5) << S3_Kor << setw(5) << S3_Eng << setw(5) << S3_Math << setw(7) << S3_Ave << endl;
				}
			}

			cout << "\n전체 평균 = " << TotalAve << endl;
			break;
		}
		case 'Q':
		case 'q':
			cout << "\n프로그램을 종료합니다.\n";
			return 0;
		defalut:
			cout << "올바른 값을 입력해주세요\n";
			break;
		}

	}

	return 0;
}