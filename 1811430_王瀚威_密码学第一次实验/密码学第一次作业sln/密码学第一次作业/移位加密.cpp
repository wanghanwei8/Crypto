#include <iostream>
#include <string.h>
using namespace std;
void enc(char* before, char* after, int num)
{
	for (int i = 0; i < strlen(before); i++)
	{
		if (int(before[i]) <= int('z') && int(before[i]) >= int('a'))
		{
			after[i] = int('a') + (int(before[i]) + num - int('a')) % 26;
		}
		else if (int(before[i]) <= int('Z') && int(before[i]) >= int('A'))
		{
			after[i] = int('A') + ((int(before[i]) + num - int('A')) % 26);
		}
		else
		{
			after[i] = before[i];
		}
	}
}
void dec(char* before, char* after, int num)
{
	for (int i = 0; i < strlen(before); i++)
	{
		if (int(before[i]) <= int('z') && int(before[i]) >= int('a'))
		{
			after[i] = int('a') + (int(before[i]) + 26 - num - int('a')) % 26;
		}
		else if (int(before[i]) <= int('Z') && int(before[i]) >= int('A'))
		{
			after[i] = int('A') + ((int(before[i]) + 26 - num - int('A')) % 26);
		}
		else
		{
			after[i] = before[i];
		}
	}
}
int main() {
	int num;//ƫ����

	//cout << (-1) % 26;
	char to_enc[256];
	char after_enc[256];
	char after_dec[256];
	cout << "����������" << endl;
	cin.getline(to_enc, 255);
	int n = strlen(to_enc);
	cout << "������ƫ���� " << "    " << endl;
	cin >> num;
	after_enc[n] = 0;
	enc(to_enc, after_enc, num);
	cout << "���ܺ�" << endl;
	for (int i = 0; i < n; i++)
		cout << after_enc[i];

	dec(after_enc, after_dec, num);
	cout << endl << "���ܺ�" << endl;
	for (int i = 0; i < n; i++)
		cout << after_dec[i];

	cout << endl << "����λ������й�������" << endl;
	for (int i = 1; i <= 25; i++)
	{
		dec(after_enc, after_dec, i);
		cout << "key is " << i << "��  ";
		for (int i = 0; i < n; i++)
			cout << after_dec[i];
		cout << endl;
	}
	/*
	��ĸ��ӽ�����
		cout << endl << "����ĸ��" << endl;
		char a[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (int i = 0; i < strlen(to_enc); i++)
		{
			if (int(to_enc[i]) <= int('Z') && int(to_enc[i]) >= int('A'))
			{
				after_enc[i] = a[(int(to_enc[i]) - int('A') + num) % 26];
			}
			else
			{
				after_enc[i] = to_enc[i];
			}
		}
		for (int i = 0; i < strlen(to_enc); i++)
			cout << after_enc[i];

			*/

			//�û�
	char a[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ZHB[27] = "WANGHEIBCDFJKLMOPQRSTUVXYZ";
	//NVEXCYZIBLOGHJMQURPSATDKFW
	cout << endl << "�����û�����" << endl;
	for (int i = 0; i < n; i++)
	{
		if (to_enc[i] == ' ')
		{
			after_enc[i] = ' ';
			continue;
		}
		else
			for (int j = 0; j <= 25; j++)
				if (to_enc[i] == a[j])
				{
					after_enc[i] = ZHB[j];
					break;
				}
	}
	for (int i = 0; i <n; i++)
		cout << after_enc[i];

	cout << endl << "�����û�����" << endl;
	for (int i = 0; i < n; i++)
	{
		if (after_enc[i] == ' ')
		{
			after_dec[i] = ' ';
			continue;
		}
		else
			for (int j = 0; j <= 25; j++)
				if (after_enc[i] == ZHB[j])
				{
					after_dec[i] = a[j];
					break;
				}
	}
	for (int i = 0; i < n; i++)
		cout << after_dec[i];
 
	system("pause");
}
