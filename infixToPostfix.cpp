#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;

const unordered_set<char> operators = {'^', '+', '-', '/', '*'};
stack<char> stck;
string postfix;

int findPrecedence(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '/':
        return 2;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return -1;
    }
}

int comparePrecedence(char op1, char op2)
{
    int precedence1 = findPrecedence(op1);
    int precedence2 = findPrecedence(op2);
    if (precedence1 < precedence2)
    {
        return -1;
    }
    else if (precedence1 > precedence2)
    {
        return 1;
    }
    else
        return 0;
}

bool equals(char op, char op2 = '(')
{
    return op == op2;
}

bool isOperator(char c)
{
    return operators.find(c) != operators.end();
}

int main()
{

    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);
    for (int i = 0; i <= infix.size() - 1; i++)
    {
        char ch = infix[i];
        if (!isOperator(ch) && ch != '(' && ch != ')')
        {
            postfix += ch;
            continue;
        }
        if (ch == '(')
        {
            stck.push(ch);
            continue;
        }
        if (ch == ')')
        {
            while (!stck.empty() && stck.top() != '(')
            {
                postfix += stck.top();
                stck.pop();
            }
            stck.pop();
            continue;
        }
        if (isOperator(ch))
        {
            if (stck.empty() || stck.top() == '(' || comparePrecedence(ch, stck.top()) == 1)
            {
                stck.push(ch);
            }
            else
            {
                while (!stck.empty() && isOperator(stck.top()) && comparePrecedence(stck.top(), ch) >= 0)
                {
                    postfix += stck.top();
                    stck.pop();
                }
                stck.push(ch);
            }
        }
    }
    while (!stck.empty())
    {
        postfix += stck.top();
        stck.pop();
    };
    cout << "The postfix is:   " << postfix << endl;
    return 0;
}