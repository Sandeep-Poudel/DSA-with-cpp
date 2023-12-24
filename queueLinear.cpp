#include <iostream>
#include <cstdlib>
using namespace std;
#define size 5

struct Queue
{
    int data[size];
    int front, rear;
    Queue()
    {
        rear = -1;
        front = 0;
    }

    void enqueue()
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            getchar();
            return;
        }
        cout << "Enter value to enqueue:" << endl;
        cin >> data[++rear];
        cout << data[rear] << " enqueued " << endl;
        getchar();
    }

    void dequeue()
    {
        if (rear < front)
        {
            cout << "Queue is empty!" << endl;
            getchar();

            return;
        }
        cout << data[front] << "dequeued" << endl;
        front += 1;
        getchar();
    }

    void dequeueShifting()
    {
        if (rear < front)
        {
            cout << "Queue is empty!" << endl;
            getchar();
            return;
        }
        for (int i = front; i < rear; i++)
        {
            data[i] = data[i + 1];
        }
        rear -= 1;
        getchar();
    }

    void display()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << data[i]<<"   ";
            if(i ==rear){
                cout<<endl;
            }
        }

        getchar();
    }
};

void clear()
{
    system("clear");
}

int menu(Queue &q)
{
    clear();
    int choice;
    cout << "Enter your choice:" << endl;
    cout << "\t1 ----- Enqueue\n\t2 ----- Dequeue\n\t3 ----- Dequeue With shifting\n\t4 ----- Display\n\t0 ----- Exit\n Choice:";
    cin >> choice;
    switch (choice)
    {
    case 1:
        q.enqueue();
        getchar();
        break;
    case 2:
        q.dequeue();
        getchar();
        break;
    case 3:
        q.dequeueShifting();
        getchar();
        break;
    case 4:
        q.display();
        getchar();
        break;
    case 0:
        exit(0);
    }
    return 0;
}

int main()
{
    Queue q;
    while (true)
    {
        menu(q);
    }
}