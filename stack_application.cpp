#include <iostream>
#include <string>
#include <stack>
using namespace std;

//--------------------------------------------------------------------------------------------------------------

class Paranthesis_match
{
public:
    bool isValid(string s)
    {
        int size = s.length();
        // cout<<"Size of the string is: "<<size;
        stack<char> a;
        for (int i = 0; i < size; i++)
        {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{')
            {
                a.push(s[i]);
            }
            else
            {
                if (a.empty())
                {
                    return 0;
                }
                else if (a.top() == '(' and s[i] == ')')
                {

                    a.pop();
                }
                else if (a.top() == '[' and s[i] == ']')
                {

                    a.pop();
                }
                else if (a.top() == '{' and s[i] == '}')
                {

                    a.pop();
                }
                else
                {
                    return 0;
                }
            }
        }

        if (a.empty())
        {
            return 1;
        }
        return 0;
    }
};

//---------------------------------------------------------------------------------------------------------------------

class InfixToPostfix
{
public:
    int precedence(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '*' or c == '/')
        {
            return 2;
        }
        else if (c == '+' or c == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    string infixtopostfix(string s)
    {
        string g;
        stack<char> a;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= 'a' and s[i] <= 'z' or s[i] >= 'A' and s[i] <= 'Z')
            {
                g += s[i];
            }
            else if (s[i] == '(')
            {
                a.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!a.empty() and a.top() != '(')
                {
                    g += a.top();
                    a.pop();
                }

                if (!a.empty())
                {
                    a.pop();
                }
            }
            else
            {
                while (!a.empty() and precedence(a.top()) > precedence(s[i]))
                {
                    g += a.top();
                    a.pop();
                }
                a.push(s[i]);
            }
        }
        while (!a.empty())
        {
            g += a.top();
            a.pop();
        }
        return g;
    }
};

int main()
{

    // string s = "{[()]}";
    // Paranthesis_match A;
    // cout<<A.isValid(s);

    InfixToPostfix A;
    string s = "a*(b+c)*d";
    string k = A.infixtopostfix(s);
    cout << k;
    return 0;
}