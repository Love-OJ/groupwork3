#include<iostream>
#include<vector>
#include<string>

using namespace std;

//计算前缀长度的数组
int cot=0;
vector<int>LPS(const string& s)
{
    int len=s.length();
    vector<int>LPS(len,0);
    int m=0;//记录长度
    int i=1;
    while(i<len)
    {
        if(s[i]==s[m])
        {
            m++;
            LPS[i]=m;
            i++;
        }
        else
        {
            if(m!=0)
            {
                m=LPS[m-1];
            }
            else
            {
                LPS[i]=0;
                i++;
            }
        }
    }
    return LPS;
}
bool open(string &parten,string & text)
{
    int len1=parten.length();
    int len2=text.length();
    vector<int>lps=LPS(parten);
    int i=0,j=0;
    while(i<len2)
    {
        if(parten[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==len1)
        {
            return true;
        }
        else if(i<len2&&parten[j]!=text[i])
        {
            if(j==0)
            {
                i++;
            }
            else
            {
                j=lps[j-1];
            }
        }
    }
    return false;
}
string init()
{
    string password;
    cout<<"输入你原本设好的密码："<<endl;
    cin>>password;
    return password;
}
void fal(string p)
{

    string text;
    cin>>text;
    if(open(p,text))
    {
        cout<<"开锁终于成功了！"<<endl;

    }
    else
    {
          cot++;
        if(cot==4)
        {
            cout<<"多次输入5不成功！已无法再次输入！"<<endl;

        }

        else
        {
            cout<<"开锁还是失败了，请重输入："<<endl;
            fal(p);
        }


    }
}
int main()
{
    string text;
    string p=init();
    cout<<"输入开锁密码："<<endl;
    cin>>text;
    if(open(p,text))
    {
        cout<<"开锁成功！"<<endl;
    }
    else
    {
        cout<<"开锁失败！重新输入："<<endl;
        fal(p);

    }
    return 0;
}

