#include <iostream>
#include <iomanip> //setw() ����ϱ� ����, setw(5) : ���̾� ����ϴ� ���� ������ 5ĭ ���
using namespace std;

int main()
{
	int S1_No, S2_No, S3_No; //�й�
	int S1_Kor, S2_Kor, S3_Kor; //���� ����
	int S1_Math, S2_Math, S3_Math; // ���� ����
	int S1_Eng, S2_Eng, S3_Eng;//���� ����
	float S1_Ave, S2_Ave, S3_Ave; //���� ���
	float TotalAve = 0.0f; // ��ü ���
	int NumberOfStudent = 0; // ������� �Էµ� �л� ��

	while (1)
	{
		cout << "\n--------�޴�--------\n";
		cout << "1. �л� ���� �߰�\n";
		cout << "2. ��ü ���� ����\n";
		cout << "Q. ���α׷� ����\n";
		cout << "\n------------------- \n";
		cout << "���ϴ� �۾��� ��ȣ�� �Է��ϼ��� : ";

		char select;
		cin >> select;

		switch (select)
		{
		case '1':  //�л� ���� �߰�
		{
			if (NumberOfStudent==3)
			{
				cout << "\n���̻� �Է� �Ұ��մϴ�.\n";
				break;
			}
			int Kor, Eng, Math;
			cout << "����, ����, ���� ������ �Է��ϼ��� : ";
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

			NumberOfStudent++; //�Է� ���� �л� �� ����

			cout << "\n�л� ������ �ùٸ��� �ԷµǾ����ϴ�.\n"; //�۾� ���� �˸�
			break;
		}
		case '2': //��ü ���� ����
		{
			//�Ǽ� ��½� �Ҽ��� ���� �� �ڸ��� ǥ�õǵ���
			cout.precision(2); 
			cout << fixed;

			cout << "\n        <��ü ����ǥ ����>";
			cout << "\n   �й� ���� ���� ����   ���\n";
			int i;
			for (i = 0; i<NumberOfStudent; ++i) // �Է� ���� �л� �� ��ŭ �ݺ�
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

			cout << "\n��ü ��� = " << TotalAve << endl;
			break;
		}
		case 'Q':
		case 'q':
			cout << "\n���α׷��� �����մϴ�.\n";
			return 0;
		defalut:
			cout << "�ùٸ� ���� �Է����ּ���\n";
			break;
		}

	}

	return 0;
}