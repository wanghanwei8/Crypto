#include "RSA_head.h"
#include <iostream>

using namespace std;

int main(void)
{
	Rsa rsa;
	Key key = rsa.produce_keys();
	cout << "�������ܵó��ĸ�Կ�����£�" << endl;
	cout << "��Կ��" << key.pkey << endl;
	cout << "������Կ��" << key.ekey << endl;
	cout << "������Կ��" << key.dkey << endl;
	long msg;
	cout << "������Ҫ���ܵ���Ϣ�����֣����ܹ��󣩣�" << endl;
	cin >> msg;
	long msg_des = rsa.endecrypt(msg, key.ekey, key.pkey);
	cout << "���ܺ���ϢΪ��" << msg_des << endl;
	msg_des = rsa.endecrypt(msg_des, key.dkey, key.pkey);
	cout << "���ܺ���ϢΪ��" << msg_des << endl;
	return 0;
}
