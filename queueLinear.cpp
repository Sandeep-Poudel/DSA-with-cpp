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
};

void enqueue(Queue *q)
{
    if (q->rear == size - 1)
    {
        cout << "Queue is full" << endl;
        getchar();
        return;
    }
    cout << "Enter value to enqueue:" << endl;
    cin >> q->data[++q->rear];
    cout << q->data[q->rear] << " enqueued " << endl;
    getchar();
}

void dequeue(Queue *q)
{
    if (q->rear < q->front)
    {
        cout << "Queue is empty!" << endl;
        getchar();

        return;
    }
    cout << q->data[q->front] << "dequeued" << endl;
    q->front += 1;
    getchar();
}

void dequeueShifting(Queue *q)
{
    if (q->rear < q->front)
    {
        cout << "Queue is empty!" << endl;
        getchar();
        return;
    }
    for (int i = q->front; i < q->rear; i++)
    {
        q->data[i] = q->data[i + 1];
    }
    q->rear -= 1;
    getchar();
}

void display(Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        cout << q->data[i] << "   ";
        if (i == q->rear)
        {
            cout << endl;
        }
    }

    getchar();
}

;

void clear()
{
    system("clear");
}

int menu(Queue *q)
{
    clear();
    int choice;
    cout << "Enter your choice:" << endl;
    cout << "\t1 ----- Enqueue\n\t2 ----- Dequeue\n\t3 ----- Dequeue With shifting\n\t4 ----- Display\n\t0 ----- Exit\n Choice:";
    cin >> choice;
    switch (choice)
    {
    case 1:
        enqueue(q);
        getchar();
        break;
    case 2:
        dequeue(q);
        getchar();
        break;
    case 3:
        dequeueShifting(q);
        getchar();
        break;
    case 4:
        display(q);
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
        menu(&q);
    }
}