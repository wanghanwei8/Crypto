#pragma once
#include <iostream>
#include "BigInteger.h"
using namespace std;
bool RabinMiller(const BigInt& n)//RabinMiller���
{
	BigInt r, a, y;
	unsigned int s, j;
	r = n - 1;
	s = 0;
	while (!r.IsOdd())
	{
		s++;
		r >> 1;
	}
	a.Randomsmall();//��������ļ����a
	y = PowerMode(a, r, n);	//y = (a^r)modn
	if ((!(y == 1)) && (!(y == (n - 1))))
	{
		j = 1;
		while ((j <= s - 1) && (!(y == (n - 1))))
		{
			y = (y * y) % n;
			if (y == 1)
				return false;
			j++;
		}
		if (!(y == (n - 1)))
			return false;
	}
	return true;
}
BigInt GeneratePrime(int& time)//���ɴ���������
{
	BigInt n;
	int i = 0;
	//���޴�ѭ�������ϲ���������ֱ��i==5ʱ��ͨ������RabinMiller���ԣ��Ż�����whileѭ��
	while (i < 5)
	{
		//��¼�����˶��ٴδ�����
		time++;

		//����һ����������
		cout << "--------------------------------------------------------" << endl;
		cout << "��"<<time<<"�����ɴ�������" << endl;
		SortPrime(n);
		n.display();

		i = 0;
		//��������RABINMILLER����,����ȫ��ͨ���������ϸ�
		for (; i < 5; i++)
		{
			cout << "��" << i + 1 << "��RabinMiller���ԣ�";
			if (!RabinMiller(n))
			{
				cout << "--------------->����ʧ��" << endl << endl;
				break;
			}
			cout << "--------------->����ͨ��" << endl << endl;
		}
	}
	return n;
}
BigInt gcd(const BigInt& m, const BigInt& n)//շת����������Լ��

{
	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}
BigInt Extendedgcd(const BigInt& a, const BigInt& b, BigInt& x, BigInt& y)//��չŷ�������˷���Ԫ
{
	BigInt t, d;
	//���һ��������Ϊ�����޷����г�������
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	d = Extendedgcd(b, a % b, x, y);
	t = x;
	x = y;
	y = t - ((a / b) * y);
	return d;
}