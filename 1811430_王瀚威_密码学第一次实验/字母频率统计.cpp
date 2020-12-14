#include<iostream>
#include<cstring>
 
using namespace std;
 
 
int main()
{
    char s[]="SIC GCBSPNA XPMHACQ JB GPYXSMEPNXIY JR SINS MF SPNBRQJSSJBE JBFMPQNSJMB FPMQ N XMJBS N SM N XMJBS H HY QCNBR MF N XMRRJHAY JBRCGZPC GINBBCA JB RZGI N VNY SINS SIC MPJEJBNA QCRRNEC GNB MBAY HC PCGMTCPCD HY SIC PJEISFZA PCGJXJCBSR SIC XNPSJGJXNBSR JB SIC SPNBRNGSJMB NPC NAJGC SIC MPJEJBNSMP MF SIC QCRRNEC HMH SIC PCGCJTCP NBD MRGNP N XMRRJHAC MXXMBCBS VIM VJRICR SM ENJB ZBNZSIMPJOCD GMBSPMA MF SIC QCRRNEC";
    cout << s << endl;
 
    int up_arr[26] = {0};
    int low_arr[26] = {0};
 
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] - 'a' >= 0 && s[i] - 'a' < 26)
            ++low_arr[s[i] - 'a'];
        if (s[i] - 'A' >= 0 && s[i] - 'A' < 26)
            ++up_arr[s[i] - 'A'];
    }
 int total=0; 
 double fre[26];
 for (int j = 0; j < 26; ++j)
 total+=up_arr[j];
 for (int j = 0; j < 26; ++j)
 fre[j]=double(up_arr[j])/double(total);

    for (int j = 0; j < 26; ++j)
    {      //  cout << char(j + 'a') << ':' << low_arr[j] << endl;
            cout << char(j + 'A') << ':' << up_arr[j] <<"´Î  ÆµÂÊÎª"<<double(fre[j])<<endl;
    }
 
    return 0;
}
