#include<bits/stdc++.h>
using namespace std;

int main()
{
    string infix;
    cin>>infix;

    string postfix;
    string temp;
    stack<char> check;
    stack<char> stemp;
    int k = 0;
    for(int i = 0; i<infix.size(); i++)
    {
        char ch = infix[i];///(a+b)*(c+d)
        if(ch>='1' && ch<='9' && k==0) ///k=1
        {
            postfix += ch;
        }
        else if((ch=='+' || ch=='-' || ch=='*' || ch=='/') && k==0)
        {
            if(check.size()==0)
            {
                check.push(ch);
            }
            else if(ch=='*' || ch=='/')
            {
                check.push(ch);
            }
            else
            {
                while(check.size())
                {
                    postfix += check.top();
                    check.pop();
                }
                check.push(ch);
            }
        }
        else
        {
            if(ch=='(')
            {
                k=1;
            }
            else if(ch>='1' && ch<='9')
            {
                temp += ch;
            }
            else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
            {
                if(stemp.size()==0)
                {
                    stemp.push(ch);
                }
            }
            else
            {
                while(stemp.size())
                {
                    temp += stemp.top();
                    stemp.pop();
                }
                k = 0;
                postfix += temp;
                temp = "";
            }
        }
    }
    while(check.size())
    {
        postfix += check.top();
        check.pop();
    }
    cout<<"Postfix = "<<postfix;

    stack<int> cal;
    int total = 0;
    for(int i=0; i<postfix.size(); i++) ///456+8*+1-
    {
        char c = postfix[i];
        if(c>='1' && c<='9')
        {
            cal.push(c-48);
        }
        else
        {
            if(c=='+')
            {
                int p = cal.top();
                cal.pop();
                int q = cal.top();
                cal.pop();
                cal.push(q+p);
            }
            else if(c=='*')
            {
                int p = cal.top();
                cal.pop();
                int q = cal.top();
                cal.pop();
                cal.push(q*p);
            }
            else if(c=='-')
            {
                int p = cal.top();
                cal.pop();
                int q = cal.top();
                cal.pop();
                cal.push(q-p);
            }
            else if(c=='/')
            {
                int p = cal.top()-48;
                cal.pop();
                int q = cal.top()-48;
                cal.pop();
                cal.push(q/p);
            }
        }
    }
    int ans = cal.top();
    cout<<"\n";
    cout<<"ANS = "<<ans;
    cal.pop();
    return 0;
}
