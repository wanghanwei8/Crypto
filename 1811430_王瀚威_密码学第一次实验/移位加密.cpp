#include <iostream>
#include <string.h>
using namespace std;
void enc(char *before,char *after,int num)
{
	for(int i=0;i<strlen(before);i++)
	{
		if(int(before[i])<=int('z')&&int(before[i])>=int('a'))
		{
		after[i]=int('a')+(int(before[i])+num)%int('a');
	    }
	    else if(int(before[i])<=int('Z')&&int(before[i])>=int('A'))
	    		{
		after[i]=int('A')+((int(before[i])+num-int('A'))%26);
	    }
	    else 
		{
		after[i]=before[i];
     	}
	}
}
int main(){
cout<<"a"<<endl;
cout<<int('a');
int num;//偏移量
cout<<"请输入偏移量 "<<endl; 
cin>>num; 
char a[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
cout<<strlen(a)<<"  "<<a[0]<<a[25];
/*char to_enc[256];
char after_enc[256];
cout<<"请输入明文"<<endl;
cin.getline(to_enc,255);
for(int i=0;i<strlen(to_enc);i++)
{
	if(int(to_enc[i])<=int('Z')&&int(to_enc[i])>=int('A'))
	{
		after_enc[i]=a[(int(to_enc[i])-int('A')+num)%26];
	}
	else
	{
		after_enc[i]=to_enc[i];
	}
}
//enc(a,after_enc,1);
//for(int i=0)
for(int i=0;i<strlen(after_enc);i++)
cout<<after_enc[i];*/
}

