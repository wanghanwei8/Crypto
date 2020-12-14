#include<iostream>
#include<string>
#include"md5.h"

using namespace std;
static const struct{
	char* msg;
	unsigned char hash[16];
} tests[] = {
    { " ",
      { 0xd4, 0x1d, 0x8c, 0xd9, 0x8f, 0x00, 0xb2, 0x04,
        0xe9, 0x80, 0x09, 0x98, 0xec, 0xf8, 0x42, 0x7e } },
    { "a",
      {0x0c, 0xc1, 0x75, 0xb9, 0xc0, 0xf1, 0xb6, 0xa8,
       0x31, 0xc3, 0x99, 0xe2, 0x69, 0x77, 0x26, 0x61 } },
    { "abc",
      { 0x90, 0x01, 0x50, 0x98, 0x3c, 0xd2, 0x4f, 0xb0,
        0xd6, 0x96, 0x3f, 0x7d, 0x28, 0xe1, 0x7f, 0x72 } },
    { "message digest",
      { 0xf9, 0x6b, 0x69, 0x7d, 0x7c, 0xb7, 0x93, 0x8d,
        0x52, 0x5a, 0x2f, 0x31, 0xaa, 0xf1, 0x61, 0xd0 } },
    { "abcdefghijklmnopqrstuvwxyz",
      { 0xc3, 0xfc, 0xd3, 0xd7, 0x61, 0x92, 0xe4, 0x00,
        0x7d, 0xfb, 0x49, 0x6c, 0xca, 0x67, 0xe1, 0x3b } },
    { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",
      { 0xd1, 0x74, 0xab, 0x98, 0xd2, 0x77, 0xd9, 0xf5,
        0xa5, 0x61, 0x1c, 0x2c, 0x9f, 0x41, 0x9d, 0x9f } },
    { "12345678901234567890123456789012345678901234567890123456789012345678901234567890",
      { 0x57, 0xed, 0xf4, 0xa2, 0x2b, 0xe3, 0xc9, 0x55,
        0xac, 0x49, 0xda, 0x2e, 0x21, 0x07, 0xb6, 0x7a } },

};

int diff(string str1, string str2) {
    int result = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            result++;
    }
    return result;
}
int main() {
    cout << "md5测试结果：" << endl;
    for (int i = 1; i <= 6; i++)
    {
        cout << "第" << i << "组测试" << endl;
        cout << "message: " << endl;
        cout << tests[i].msg << endl;
        cout << "md5哈希值为:" << endl;
        cout << md5(tests[i].msg) << endl << endl;;
    }
//我裂开了  ddl咋这么多
    cout << endl << endl << "雪崩实验:" << endl;
    cout << "原消息为：" << endl << tests[5].msg << endl << "原MD5哈希值为：" <<endl<< md5(tests[5].msg) << endl;
    char* msg1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.";//增加一个.
    cout << "第一次雪崩实验 消息为：" << endl << msg1 << endl << "MD5哈希值为：" << endl << md5(msg1) << endl<<"有 "<<diff(md5(msg1),md5(tests[5].msg))<<"处变化"<<endl;
    char* msg2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 ";//增加空格
    cout << "第二次雪崩实验 消息为：" << endl << msg2 << endl << "MD5哈希值为：" << endl << md5(msg2) << endl << "有 " << diff(md5(msg2), md5(tests[5].msg)) << "处变化" << endl;
    char* msg3 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!";//增加感叹号
    cout << "第三次雪崩实验 消息为：" << endl << msg3 << endl << "MD5哈希值为：" << endl << md5(msg3) << endl << "有 " << diff(md5(msg3), md5(tests[5].msg)) << "处变化" << endl;
    char* msg4 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789?";//增加问号
    cout << "第四次雪崩实验 消息为：" << endl << msg4 << endl << "MD5哈希值为：" << endl << md5(msg4) << endl << "有 " << diff(md5(msg4), md5(tests[5].msg)) << "处变化" << endl;
    char* msg5 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789*";//增加星号
    cout << "第五次雪崩实验 消息为：" << endl << msg5 << endl << "MD5哈希值为：" << endl << md5(msg5) << endl << "有 " << diff(md5(msg5), md5(tests[5].msg)) << "处变化" << endl;
    char* msg6 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+";//增加加号
    cout << "第六次雪崩实验 消息为：" << endl << msg6 << endl << "MD5哈希值为：" << endl << md5(msg6) << endl << "有 " << diff(md5(msg6), md5(tests[5].msg)) << "处变化" << endl;
    char* msg7 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-";//增加减号
    cout << "第七次雪崩实验 消息为：" << endl << msg7 << endl << "MD5哈希值为：" << endl << md5(msg7) << endl << "有 " << diff(md5(msg7), md5(tests[5].msg)) << "处变化" << endl;
    char* msg8 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789~";//增加波浪线
    cout << "第八次雪崩实验 消息为：" << endl << msg8 << endl << "MD5哈希值为：" << endl << md5(msg8) << endl << "有 " << diff(md5(msg8), md5(tests[5].msg)) << "处变化" << endl;

   
	system("pause");
	return 0;
  
}