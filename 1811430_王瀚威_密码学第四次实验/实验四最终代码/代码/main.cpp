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
	cout << "开始尝试生成素数p" << endl;
	int time = 0;//生成大奇数次数
	clock_t start = clock();//开始时间
	BigInt p = GeneratePrime(time);	//产生大素数
	clock_t finish = clock();	//结束时间
	cout << "成功生成512bit大素数   耗时" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	cout << "共尝试： " << time << "次" << endl;
	cout << "生成的大素数为： " << endl;
	ofstream outfile("output.txt");
	//16进制形式显示
	p.display();
	outfile << "大素数:" << endl;
	outfile << p;
	cout << endl;
	cout << "开始尝试生成素数q" << endl;
	time = 0;//重新记次数
	start = clock();
	BigInt q = GeneratePrime(time);
	finish = clock();
	cout << "成功生成512bit大素数   耗时" << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	cout << "共尝试： " << time << "次" << endl;
	cout << "生成的大素数为： " << endl;
	//16进制形式显示
	q.display();
	outfile << "大素数:" << endl;
	outfile << q;
	cout << endl;
	cout << "公钥n = p * q" << endl;
	cout << "/********************************************************/" << endl;
	BigInt n = p * q;
	cout << "公钥n为： " << endl;
	//16进制形式显示
	n.display();
	outfile << "公钥n为：" << endl;
	outfile << n;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "计算公钥e 和秘钥d " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt t = (p - 1) * (q - 1);
	BigInt e;//公钥e
	BigInt d;	//d为秘密钥，即e模t的乘法逆元
	BigInt y;//y用于参与扩展欧几里得运算，存储t模e的乘法逆元
	BigInt temp;//临时变量temp
	while (1)
	{
		//产生与t互质的e
		e.Random();
		while (!(gcd(e, t) == 1))
		{
			e.Random();
		}
		//用扩展欧几里德算法试图求出e模t的乘法逆元
		temp = Extendedgcd(e, t, d, y);
		//e*d模t结果为1，说明d确实是e模t的乘法逆元
		temp = (e * d) % t;
		if (temp == 1)
			break;
		//否则重新生成e
	}
	cout << "公钥e： " << endl;
	//16进制形式显示
	e.display();
	outfile << "公钥e:" << endl;
	outfile << e;
	cout << endl;
	cout << "秘钥d： " << endl;
	//16进制形式显示
	d.display();
	outfile << "秘钥d:" << endl;
	outfile << d;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "随机生成明文m " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt m;
	m.Random();
	cout << "明文m为：" << endl;
	//16进制形式显示
	m.display();
	outfile << "明文m为：" << endl;
	outfile << m;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "用秘钥e加密m,得到密文c " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt c = PowerMode(m, e, n);
	cout << "密文c为：" << endl;
	//16进制形式显示
	c.display();
	outfile << "密文c为：" << endl;
	outfile << c;
	cout << endl;
	cout << "/****************************************************************************/" << endl;
	cout << "用公钥d对c解密，得到明文m2 " << endl;
	cout << "/****************************************************************************/" << endl;
	BigInt m2 = PowerMode(c, d, n);
	cout << "明文m2为：" << endl;
	//16进制形式显示
	m2.display();
	outfile << "明文m2为：" << endl;
	outfile << m2;
	cout << endl;
	system("pause");
	return 0;
}
