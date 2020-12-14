#pragma once
#include <iostream>
#include "BigInteger.h"
using namespace std;
bool RabinMiller(const BigInt& n)//RabinMiller检测
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
	a.Randomsmall();//随机产生的检测数a
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
BigInt GeneratePrime(int& time)//生成大素数素数
{
	BigInt n;
	int i = 0;
	//无限次循环，不断产生素数，直到i==5时（通过五轮RabinMiller测试）才会跳出while循环
	while (i < 5)
	{
		//记录生成了多少次大奇数
		time++;

		//产生一个待测素数
		cout << "--------------------------------------------------------" << endl;
		cout << "第"<<time<<"次生成大奇数：" << endl;
		SortPrime(n);
		n.display();

		i = 0;
		//进行五轮RABINMILLER测试,五轮全部通过则素数合格
		for (; i < 5; i++)
		{
			cout << "第" << i + 1 << "次RabinMiller测试：";
			if (!RabinMiller(n))
			{
				cout << "--------------->测试失败" << endl << endl;
				break;
			}
			cout << "--------------->测试通过" << endl << endl;
		}
	}
	return n;
}
BigInt gcd(const BigInt& m, const BigInt& n)//辗转相除法求最大公约数

{
	if (n == 0)
		return m;
	else
		return gcd(n, m % n);
}
BigInt Extendedgcd(const BigInt& a, const BigInt& b, BigInt& x, BigInt& y)//扩展欧几里得求乘法逆元
{
	BigInt t, d;
	//如果一个操作数为零则无法进行除法运算
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