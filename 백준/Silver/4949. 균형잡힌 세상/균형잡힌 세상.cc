#include <iostream>
#include <stack>
#include <istream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1)
    {
        string s;
        getline(cin, s);

        if(s==".") break;

        stack<char> str;
        bool flag = true;

        for(auto c : s)
        {
            if(c=='(' || c=='[')
                str.push(c);
            else if(c==')')
            {
                // 쌍이 맞을 경우
                if(str.empty() || str.top()!='(')
                {
                    flag = false;
                    break;
                }
                str.pop();
            }
            else if(c==']')
            {
                // 쌍이 맞을 경우
                if(str.empty() || str.top()!='[')
                {
                    flag = false;
                    break;
                }
                str.pop();
            }
        }

        // 다 돌았는데 stack이 비어있지 않는 경우 => 조건을 만족하지 않음
        if(!str.empty())
            flag = false;
        
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}