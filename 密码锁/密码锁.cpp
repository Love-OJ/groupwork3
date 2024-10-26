#include<iostream>
#include<vector>
#include<string>

using namespace std;

//����ǰ׺���ȵ�����

vector<int>LPS(const string& s)
{
    int len=s.length();
    vector<int>LPS(len,0);
    int m=0;//��¼����
    int i=1;
    while(i<len)
    {
       if(s[i]==s[m]){
           m++;
          LPS[i]=m;
           i++;
        }
        else{
            if(m!=0)
            {
                m=LPS[m-1];
            }
            else{
                LPS[i]=0;
                i++;
            }
        }
      }
      return LPS;
}
bool open(string &parten,string & text){
 int len1=parten.length();
 int len2=text.length();
 vector<int>lps=LPS(parten);
 int i=0,j=0;
 while(i<len2){
    if(parten[j]==text[i]){
        i++;
        j++;
    }
    if(j==len1){
        return true;
    }
    else if(i<len2&&parten[j]!=text[i]){
        if(j==0)
        {
            i++;
        }
        else{
            j=lps[j-1];
        }
    }
 }
return false;
}
int main(){
 string password,text;
 cout<<"������ԭ����õ����룺"<<endl;
 cin>>password;
 cout<<"���뿪�����룺"<<endl;
 cin>>text;
 if(open(password,text)){
    cout<<"�����ɹ���"<<endl;
 }
else{
    cout<<"����ʧ��!"<<endl;

 }
 return 0;
}

