#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Linkedlist
{
private:
    Node *head;
    Node *last;

public:
    Linkedlist()
    {
        head = nullptr;
        last = nullptr;
    }
    void insert(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            head->prev = nullptr;
            last = head;
        }
        else
        {
            last->next = new Node(value);
            last->next->prev = last;
            last = last->next;
        }
    }

    void insertAfter(int key, int value)
    {
        Node *ptr = head;
        while (ptr != nullptr && ptr->data != key)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
        {
            cout << "The node with value " << key << " not found!" << endl;
            return;
        }
        if(ptr == last){
            insert(value);
            return;
        }
        Node *newNode = new Node(value);
        newNode->prev = ptr;
        ptr->next->prev = newNode;
        newNode->next = ptr->next;
        ptr->next = newNode;
        cout << value << " added after " << key << " ." << endl;
        return;
    }

    void deleteNode(int key)
    {
    
        Node *ptr = head;
        if (head == nullptr)
        {
            cout << "The linked list is empty!" << endl;
            return;
        }


        while (ptr != nullptr && ptr->data != key)
        {
            ptr = ptr->next;
        }

        if (ptr == nullptr)
        {
            cout << "The node with value " << key << " not found!" << endl;
            return;
        }

        if (ptr == head)
        {
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
        }

        if(ptr == last){
            last = last->prev;
            last ->next=nullptr;
        }
        else
        {
            // Adjust the pointers of the surrounding nodes
            ptr->prev->next = ptr->next;
            if (ptr->next != nullptr)
                ptr->next->prev = ptr->prev;
        }

        delete (ptr);
        // cout << "The node with value " << key << " deleted." << endl;
        return;
    };

    void display()
    {
        Node *ptr = head;
        if (head == nullptr)
        {
            cout << "Linked list is empty!" << endl;
            return;
        }
        while (ptr != nullptr)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    Linkedlist list;
    list.insert(50);
    list.insert(34);
    list.insert(22);
    list.insertAfter(22, 44444);
    list.deleteNode(34);
    list.display();
    list.deleteNode(22);
    list.insert(344444);
    list.insert(3222);
    list.insert(989);
    list.display();
    list.deleteNode(989);
    list.display();
    return 0;
}
