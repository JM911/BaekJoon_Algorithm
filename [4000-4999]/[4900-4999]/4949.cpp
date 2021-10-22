// 4949. 균형잡힌 세상
// S4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string s;

    while (true)
    {
        getline(cin, s);
        stack<char> st;
        if (s == ".")
            break;

        bool isBalanced = true;
        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '[':
                st.push(s[i]);
                break;
            case ')':
                if (!st.empty())
                {
                    if (st.top() == '(')
                        st.pop();
                    else
                        isBalanced = false;
                }
                else
                {
                    isBalanced = false;
                }
                break;
            case ']':
                if (!st.empty())
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        isBalanced = false;
                }
                else
                {
                    isBalanced = false;
                }
                break;
            default:
                break;
            }

            if (isBalanced == false)
                break;
        }

        while (!st.empty())
        {
            isBalanced = false;
            st.pop();
        }

        if (isBalanced)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';

        
    }


    return 0;
}
