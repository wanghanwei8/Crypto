#include<iostream>
#include<string>
#include<cmath>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//密钥置换选择1（64变56）
static int PC_1[56] = { 57,49,41,33,25,17,9,
1,58,50,42,34,26,18,
10,2,59,51,43,35,27,
19,11,3,60,52,44,36,
63,55,47,39,31,23,15,
7,62,54,46,38,30,22,
14,6,61,53,45,37,29,
21,13,5,28,20,12,4, };
//密钥置换选择2（56变48）
static int PC_2[48] = { 14,17,11,24,1,5,
3,28,15,6,21,10,
23,19,12,4,26,8,
16,7,27,20,13,2,
41,52,31,37,47,55,
30,40,51,45,33,48,
44,49,39,56,34,53,
46,42,50,36,29,32 };
//密钥移位表
static int keyoffbit[16] = { 1,1,2,2,2,2,2,2,
 1,2,2,2,2,2,2,1 };
//初始置换
static int IP[64] = { 58,50,42,34,26,18,10,2,
 60,52,44,36,28,20,12,4,
 62,54,46,38,30,22,14,6,
 64,56,48,40,32,24,16,8,
 57,49,41,33,25,17,9,1,
 59,51,43,35,27,19,11,3,
 61,53,45,37,29,21,13,5,
 63,55,47,39,31,23,15,7 };
//扩展E置换
static int E[48] = { 32,1,2,3,4,5,
 4,5,6,7,8,9,
 8,9,10,11,12,13,
 12,13,14,15,16,17,
 16,17,18,19,20,21,
 20,21,22,23,24,25,
 24,25,26,27,28,29,
 28,29,30,31,32,1 };
//8个S盒
static int s1[4][16] = { 14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
 0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
 4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
 15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
};
static int s2[4][16] = { 15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
 3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
 0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
 13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
};
static int s3[4][16] = { 10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
 13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
 13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
 1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
};
static int s4[4][16] = { 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
};
static int s5[4][16] = { 2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
 14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
 4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
 11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
};
static int s6[4][16] = { 12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
 10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
 9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
 4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
};
static int s7[4][16] = { 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
};
static int s8[4][16] = { 13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
 1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
 7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
 2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};
//P置换
static int P[32] = { 16,7,20,21,
 29,12,28,17,
 1,15,23,26,
 5,18,31,10,
 2,8,24,14,
 32,27,3,9,
 19,13,30,6,
 22,11,4,25
};
//逆初始置换表
static int _IP[64] = { 40,8,48,16,56,24,64,32,
39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,
37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,
33,1,41,9,49,17,57,25
};
string trans_bin(char* c) //字符串转换为二进制
{
	int i = 0;
	char ch;
	string bin;
	for (; i < 8; i++)
	{
		ch = c[i];
		int mask = 128;
		for (int k = 0; k < 8; k++)
		{
			if (ch & mask)
				bin += '1';
			else
				bin += '0';
			mask >>= 1;
		}
	}
	return bin;
}
string keyoff(string& c, int off) //密钥的循环左移位
{
	int i;
	char temp;
	for (i = 0; i < off; i++)
	{
		temp = c[0];
		for (int j = 0; j < 27; j++)
		{
			c[j] = c[j + 1];
		}
		c[27] = temp;
	}
	return c;
}
void ProduceSubkey(char* key, string* subkey) //生成子密钥
{
	string binkey;
	int i = 0;
	//trans_bin
	binkey = trans_bin(key);
	string key56;
	int j = 0;
	for (i = 0; i < 56; i++)
	{
		key56 += binkey[PC_1[i] - 1];
	}
	string ctemp, dtemp;
	for (i = 0; i < 28; i++)
	{
		ctemp += key56[i];
		dtemp += key56[i + 28];
	}
	char keytemp[56];
	//string subkey[16];
	for (i = 0; i < 16; i++)
	{
		keyoff(ctemp, keyoffbit[i]);
		keyoff(dtemp, keyoffbit[i]);
		for (j = 0; j < 28; j++)
		{
			keytemp[j] = ctemp[j];
			keytemp[j + 28] = dtemp[j];
		}
		for (j = 0; j < 48; j++)
		{
			subkey[i] += keytemp[PC_2[j] - 1];
		}
	}
}
void initswap(char* txt, string& ltemp, string& rtemp) //初始置换，得到L0, R0
{
string bintxt;
bintxt = trans_bin(txt);
int i;
//string rtemp,ltemp;
for (i = 0; i < 32; i++)
{
ltemp += bintxt[IP[i] - 1];
rtemp += bintxt[IP[i + 32] - 1];
}
};
string XOR(string a, string b) //异或
{
	int i;
	string result;
	if (a.size() != b.size())
	{
		cout << "XOR Wrong!" << endl;
	}
	else
	{
		for (i = 0; i < a.size(); i++)
		{
			if (a[i] == b[i])
				result += '0';
			else
				result += '1';
		}
	}
	return result;
};
string f(string r, string key) //如书上轮结构中定义的F函数
{
	int i, j;
	string temp; //扩展后的Ri
	for (i = 0; i < 48; i++)
		temp += r[E[i] - 1];
	string Er; //与子密钥异或后的48位
	Er = XOR(temp, key);
	string str[8];
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 6; j++)
			str[i] += Er[j + i * 6];
	}
	//s盒
	int num[8];
	for (i = 0; i < 8; i++)
	{
		int row = (str[i][0] - '0') * 2 + (str[i][5] - '0');
		int col = (str[i][1] - '0') * 8 + (str[i][2] - '0') * 4 + (str[i][3] -
			'0') * 2 + (str[i][4] - '0');
		if (i == 0)
		{
			num[i] = s1[row][col];
			continue;
		}
		if (i == 1)
		{
			num[i] = s2[row][col];
			continue;
		}
		if (i == 2)
		{
			num[i] = s3[row][col];
			continue;
		}
		if (i == 3)
		{
			num[i] = s4[row][col];
			continue;
		}
		if (i == 4)
		{
			num[i] = s5[row][col];
			continue;
		}
		if (i == 5)
		{
			num[i] = s6[row][col];
			continue;
		}
		if (i == 6)
		{
			num[i] = s7[row][col];
			continue;
		}
		if (i == 7)
		{
			num[i] = s8[row][col];
			continue;
		}
}
	char buffer[5];
	string tempresult;
	for (i = 0; i < 8; i++)
	{
		_itoa_s(num[i], buffer, 2);
		if (strlen(buffer) < 4)
		{
			int bit = 4 - strlen(buffer);
			for (int q = 0; q < bit; q++)
			{
				tempresult += '0';
			}
		}
		tempresult += buffer;
	}
	//P置换
	string result;
	for (i = 0; i < 32; i++)
	{
		result += tempresult[P[i] - 1];
	}
	return result;
};
void main()
{
	char key[8] = { 0x10, 0x31, 0x6E, 0x02, 0x8C, 0x8F, 0x3B, 0x4A }; //密钥
		char txt[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; //明文
	
		cout << "TEST DES"<<endl<<"使用第一组数据进行加密解密测试"<<endl;
		string subkey[16];
	ProduceSubkey(key, subkey);
	string ltemp, rtemp;
	initswap(txt, ltemp, rtemp);
	int i;
	string temp;
	for (i = 0; i < 16; i++)
	{
		temp = ltemp;
		ltemp = rtemp;
		rtemp = XOR(temp, f(rtemp, subkey[i]));
	}
	string result;
	result += rtemp;
	result += ltemp;
	string out;
	for (i = 0; i < 64; i++)
	{
		out += result[_IP[i] - 1];
	}
	cout << endl;
	cout << "------------------------------加密--------------------------------："<<endl<<endl;
		cout << "转二进制密文：" << endl << out << endl;
	cout << endl;
	cout << "十六进制表示：" << endl;
	for (i = 0; i <= out.size() - 4; i += 4)
	{
		int ming = (out[i] - '0') * 8 + (out[i + 1] - '0') * 4 + (out[i + 2] -
			'0') * 2 + (out[i + 3] - '0');
		if (ming >= 10)
			cout << char(ming - 10 + 'a');
		else
			cout << ming;
	}
	cout << endl;
	cout << endl;
	cout << "------------------------------解密-------------------------------- ："<<endl<<endl;//解密
		string _rtemp, _ltemp, _temp;
	for (i = 0; i < 32; i++)
	{
		_ltemp += out[IP[i] - 1];
		_rtemp += out[IP[i + 32] - 1];
	}
	for (i = 15; i >= 0; i--) //字密钥顺序相反
	{
		_temp = _ltemp;
		_ltemp = _rtemp;
		_rtemp = XOR(_temp, f(_rtemp, subkey[i]));
	}
	string _result;
	_result += _rtemp;
	_result += _ltemp;
	string _out;
	for (i = 0; i < 64; i++)
	{
		_out += _result[_IP[i] - 1];
	}
	cout << "转为二进制明文：" << endl << _out << endl;
	cout << endl;
	cout << "十六进制表示：" << endl;
	for (i = 0; i <= _out.size() - 4; i += 4)
	{
		int mi = (_out[i] - '0') * 8 + (_out[i + 1] - '0') * 4 + (_out[i + 2] -
			'0') * 2 + (_out[i + 3] - '0');
		if (mi >= 10)
			cout << char(mi - 10 + 'a');
		else
			cout << mi;
	}
	

	system("pause");
}
