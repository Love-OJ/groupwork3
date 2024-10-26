#include<iostream>
#include<vector>
#include<string>

using namespace std;

//计算前缀长度的数组

vector<int>LPS(const string& s)
{
    int len=s.length();
    vector<int>LPS(len,0);
    int m=0;//记录长度
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
 cout<<"输入你原本设好的密码："<<endl;
 cin>>password;
 cout<<"输入开锁密码："<<endl;
 cin>>text;
 if(open(password,text)){
    cout<<"开锁成功！"<<endl;
 }
else{
    cout<<"开锁失败!"<<endl;

 }
 return 0;
}

