#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertAfter(int after, int value)
    {
        Node *newNode = new Node(value);
        Node *temp = head;
        while ( temp != nullptr && temp->data != after) 
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "The node with the provided value not found!" << endl;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void deleteNode(int key)
    {
        if (head == nullptr)
        {
            cout << "Linked list is empty." << endl;
            return;
        }
        Node *temp = head;
        while(temp!=nullptr && temp->next->data!=key){
            temp=temp->next;
        }
        if(temp==nullptr){
            cout<<"The node with the provided value not found!"<<endl;
        }else{
            Node *toDelete=temp->next;
            temp->next=temp->next->next;
            delete toDelete;
            cout<<"Node with value "<<key<<" deleted successfully!"<<endl;
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.display();
    list.insertAfter(20, 25);
    list.display();
    list.deleteNode(20);
    list.display();
    return 0;
}
