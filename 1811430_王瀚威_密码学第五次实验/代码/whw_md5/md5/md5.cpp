#include "md5.h"

string Int2HexString(int origin)
{
	const char str16[] = "0123456789abcdef";
	unsigned hexNum;
	string temp;
	string hexString = "";

	for (int i = 0; i < 4; i++) {
		//�����е�4���ֽ���һ������
		temp = "";
		//ȡ��Ӧ�ֽڵ�8bit���õ����ֽ�����ʾ��ֵ
		hexNum = (origin >> (i * 8)) & 0xff;
		for (int j = 0; j < 2; j++) {
			temp.insert(0, 1, str16[hexNum % 16]);
			hexNum /= 16;
		}
		hexString += temp;
	}
	return hexString;
}

string md5(string message)
{
	unsigned int A = 0x67452301;
	unsigned int B = 0xefcdab89;
	unsigned int C = 0x98badcfe;
	unsigned int D = 0x10325476;

	int lengthInByte = message.length();
	int groupNum = ((lengthInByte + 8) / 64) + 1;
	//ÿ������ĳ���Ϊ 16 * 32bit = 512bit
	unsigned int* messageByte = new unsigned int[groupNum * 16];
	memset(messageByte, 0, sizeof(unsigned int) * groupNum * 16);//����
	for (int i = 0; i < lengthInByte; i++) {
		//ÿ�����ж�Ӧ�洢4���ֽڵ�����
		messageByte[i >> 2] |= message[i] << ((i % 4) * 8);
	}
	//�������
	messageByte[lengthInByte >> 2] |= 0x80 << ((lengthInByte % 4) * 8);
	//������Ϣ�ĳ���
	messageByte[groupNum * 16 - 2] = lengthInByte * 8;

	unsigned int a, b, c, d;
	for (int i = 0; i < groupNum; i++) {
		a = A; b = B; c = C; d = D;
		unsigned int g;
		int k;
		for (int j = 0; j < 64; j++) {
			if (j < 16) {
				g = F(b, c, d);
				k = j;
			}
			else if (j < 32) {
				g = G(b, c, d);
				k = (1 + 5 * j) % 16;
			}
			else if (j < 48) {
				g = H(b, c, d);
				k = (5 + 3 * j) % 16;
			}
			else {
				g = I(b, c, d);
				k = (7 * j) % 16;
			}

			unsigned tempd = d;
			d = c;
			c = b;
			b = b + shift(a + g + messageByte[i * 16 + k] + T[j], s[j]);
			a = tempd;
		}
		A = a + A;
		B = b + B;
		C = c + C;
		D = d + D;
	}
	return Int2HexString(A) + Int2HexString(B) + Int2HexString(C) + Int2HexString(D);
}
