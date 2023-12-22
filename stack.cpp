#include <iostream>
#define size 5
using namespace std;

struct Stack
{
    int data[size];
    int top;

    Stack()
    {
        top = -1;
    }

    void push()
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!" << endl;
            return;
        }
        top++;
        cout << "Enter the value to push: ";
        cin >> data[top];
        cout << data[top] << " pushed to the stack" << endl;
        cin.ignore();
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            cin.ignore();
            return;
        }
        else
        {
            cout << data[top] << " popped from the stack!" << endl;
            top -= 1;
        }
        cin.ignore();
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty!" << endl;
            getchar();
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << endl;
        }
        cin.ignore();
    }
};

int main()
{
    Stack s;
    int choice;
    while (true)
    {
        system("clear");
        cout << "Choose the operation that you want to do" << endl;
        cout << "\t1. Push\n\t2. Pop\n\t3. Display\n\t0. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.push();
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice!!" << endl;
            getchar();
        }
        cin.ignore();
    }
    return 0;
}
