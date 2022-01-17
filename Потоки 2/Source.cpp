#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <windows.h>

////������������ ����� ���� � �����
//#define MAX_PATH 260
////���������� �������� �� ������
//#define NUM_COLS 18
////���������� ����� �� ������
//#define NUM_ROWS 24



using namespace std;

void main()
{
	srand(time(NULL));
	char Answer;
	const int MessageCount = 9;
	int i, j;
	//���������
	enum { CHOICE = 3, INPUT_FILENAME, INPUT_DIMENSIONS, INPUT_ELEMENT, FILE_ERROR };
	//��������� 
	char Msg[MessageCount][50] =
	{
		"1. ������� ������ �� ���������� �����\n",
		"2. �������� ������ � ��������� ����\n",
		"3. ����� �� ���������\n",
		"\n ��� �����: ",
		"������� ��� ��������������� �����: ",
		"������� ����������� �������: ",
		"������� �������� �������: ",
		"��������� ��������(��-1/���-2)",
		"���������� ������� ����"
	};
	//������������ ��������� � ����� ���� �� �����
	for (i = 0; i < MessageCount; i++)
	{
		CharToOemA(Msg[i], Msg[i]);
	}
	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << Msg[i];
		}
		cin >> Answer;

	} while (Answer < '1' || Answer>'3');
	if (Answer == '3')
	{
		return;
	}
	//���������� ��� ����� �����
	char FileName[80];
	//����������� �������
	int M, N;
	int num;
	cout << "\n" << Msg[INPUT_FILENAME];
	cin >> FileName;
	//���� ������ ������ ����� ����, �� ������� ������ �� ���������� ����� �����
	if (Answer == '1')
	{
		//���� ���� � ��������� ������ ��� ���������� ������� ��������� �� ������
		ifstream inF(FileName, ios::in | ios::_Nocreate);
		if (!inF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//��������� ����������� �������
		inF >> M;
		inF >> N;
		
		//��������� �������� ������� �� ����� � ������� �� ����� �� �����
		for (i = 0; i < M; i++)
		{
			for (j = 0; j < N; j++)
			{
				inF >> num;
				cout << setw(6) << num;
			}
			cout << "\n";
		}
		inF.close();
	}

	//���� ������ ������ ����� ����, �� ������� ������ �� ���������� ����� �����
	if (Answer == '2')
	{
		//��������� ���� ��� ������.
		// ���� ����� �� ���������� �� ��������� ������� ���
		ofstream outF(FileName, ios::out);
		if (!outF)
		{
			cout << "\n" << Msg[FILE_ERROR];
			return;
		}
		//����������� ����������� ������� � ���������� ������ � ����
		cout << Msg[INPUT_DIMENSIONS];
		cout << "\nM: ";
		cin >> M;
		cout << "\nN: ";
		cin >> N;

		outF << M << " " << N << "\n";
		int** matrix = new int* [M];
		for (int i = 0; i < M; i++)
		{
			matrix[i] = new int[N];
		}
		int answ;
		cout << Msg[7];
		cin >> answ;
		if (answ == 1)
		{
			//����������� �������� ������� � ���������� �� � ����
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{			
					matrix[i][j] = rand() % 60 - 30;
					

				}
			}

			for (int c = 0; c <= (M * N); c++)
			{
				for (int k = 0; k < M; k++)
				{
					for (int l = 0; l < N - 1; l++)
					{
						if (matrix[k][l] > matrix[k][l + 1])
						{
							int temp = matrix[k][l];
							matrix[k][l] = matrix[k][l + 1];
							matrix[k][l + 1] = temp;
						}
					}
				}

				for (int x = 0; x < N; x++)
				{
					for (int z = 0; z < M - 1; z++)
					{
						if (matrix[x][z] > matrix[x][z + 1])
						{
							int temp = matrix[x][z];
							matrix[x][z] = matrix[x][z + 1];
							matrix[x][z + 1] = temp;
						}
					}
				}
			}

		
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					outF << matrix[i][j] << " ";

				}
				outF << "\n";
			}

		}
		if (answ == 2)
		{
			cout << Msg[INPUT_ELEMENT];
			//����������� �������� ������� � ���������� �� � ����
			for (i = 0; i < M; i++)
			{
				for (j = 0; j < N; j++)
				{
					cout << "Array[" << i << "]" << "[" << j << "] = ";
					cin >> num;
					outF << num << " ";
				}
				outF << "\n";
			}
			outF.close();
		}
	}










}