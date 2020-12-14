#include <iostream>
#include "Get_BigPrime.h"
#include "BigInteger.h"
#include <ctime>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	cout << "��ʼ������������p" << endl;
	int time = 0;//���ɴ���������
	clock_t start = clock();//��ʼʱ��
	BigInt p = GeneratePrime(time);	//����������
	clock_t finish = clock();	//����ʱ��
	cout << "�ɹ�����512bit������   ��ʱ" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	cout << "�����ԣ� " << time << "��" << endl;
	cout << "���ɵĴ�����Ϊ�� " << endl;
	ofstream outfile("output.txt");
	//16������ʽ��ʾ
	p.display();
	outfile << "������:" << endl;
	outfile << p;
	cout << endl;
	cout << "��ʼ������������q" << endl;
	time = 0;//���¼Ǵ���
	start = clock();
	BigInt q = GeneratePrime(time);
	finish = clock();
	cout << "�ɹ�����512bit������   ��ʱ" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	cout << "�����ԣ� " << time << "��" << endl;
	cout << "���ɵĴ�����Ϊ�� " << endl;
	//16������ʽ��ʾ
	q.display();
	outfile << "������:" << endl;
	outfile << q;
	cout << endl;
	cout << "��Կn = p * q" << endl;
	cout << "/********************************************************/" << endl;
	BigInt n = p * q;
	cout << "��ԿnΪ�� " << endl;
	//16������ʽ��ʾ
	n.display();
	outfile << "��ԿnΪ��" << endl;
	outfile << n;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "���㹫Կe ����Կd " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt t = (p - 1) * (q - 1);
	BigInt e;//��Կe
	BigInt d;	//dΪ����Կ����eģt�ĳ˷���Ԫ
	BigInt y;//y���ڲ�����չŷ��������㣬�洢tģe�ĳ˷���Ԫ
	BigInt temp;//��ʱ����temp
	while (1)
	{
		//������t���ʵ�e
		e.Random();
		while (!(gcd(e, t) == 1))
		{
			e.Random();
		}
		//����չŷ������㷨��ͼ���eģt�ĳ˷���Ԫ
		temp = Extendedgcd(e, t, d, y);
		//e*dģt���Ϊ1��˵��dȷʵ��eģt�ĳ˷���Ԫ
		temp = (e * d) % t;
		if (temp == 1)
			break;
		//������������e
	}
	cout << "��Կe�� " << endl;
	//16������ʽ��ʾ
	e.display();
	outfile << "��Կe:" << endl;
	outfile << e;
	cout << endl;
	cout << "��Կd�� " << endl;
	//16������ʽ��ʾ
	d.display();
	outfile << "��Կd:" << endl;
	outfile << d;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "�����������m " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt m;
	m.Random();
	cout << "����mΪ��" << endl;
	//16������ʽ��ʾ
	m.display();
	outfile << "����mΪ��" << endl;
	outfile << m;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "����Կe����m,�õ�����c " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt c = PowerMode(m, e, n);
	cout << "����cΪ��" << endl;
	//16������ʽ��ʾ
	c.display();
	outfile << "����cΪ��" << endl;
	outfile << c;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "�ù�Կd��c���ܣ��õ�����m2 " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt m2 = PowerMode(c, d, n);
	cout << "����m2Ϊ��" << endl;
	//16������ʽ��ʾ
	m2.display();
	outfile << "����m2Ϊ��" << endl;
	outfile << m2;
	cout << endl;
	system("pause");
	return 0;
}
