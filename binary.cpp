#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data, Node* prnt=nullptr){
        this->value=data;
        left=nullptr;
        right=nullptr;
        parent = prnt;
    };
};


class BinaryTree {
    private:
        Node* root;
    
    public:
        BinaryTree(){
            root = nullptr;
        }

        void insert(int data){
            if(root==nullptr)
                root = new Node(data);
            
            Node* current = root;
            while(true){
                if(current->value==data)
                    return;
                if(current->value>data){
                    if(current->left == nullptr){
                        current->left = new Node(data,current);
                        return;
                    }
                    current=current->left;
                }
                if(current->value<data){
                    if(current->right ==nullptr){
                        current->right=new Node(data,current);  
                        return;
                    }
                    current= current->right;
                }
            }
        };

        Node* search(int data){
            Node* current=root;
            while(true){
                if(current->value == data)
                    return current;
                else if (current->value<data){
                    if(current->right ==nullptr)
                        return nullptr;
                    current=current->right;
                }
                else{
                    if(current->left==nullptr)
                        return nullptr;
                    current=current->left;
                }
            }
        };

        void traverse(Node* node){
            if(node == nullptr){
                return;
            }
            traverse(node->left);
            cout<<node->value<<" ";
            traverse(node->right);
        };

        void printInOrder(){
            traverse(root);
        };

        Node* findImmediateSuccessor(int data){
            Node* node = search(data);
            if(node->right != nullptr){
                node = node->right;
                while(true){
                    if(node->left==nullptr)
                        return node;
                    node=node->left;
                }
                return node;
            };
            while(true){
                if(node->parent!= nullptr){
                    if(node->parent->value<data){
                        node= node->parent;
                    }
                    else if(node->parent->value>data){
                        return node->parent;
                    }
                }
            }
        };
};

int  main(int argc, const char** argv) {
    BinaryTree tree;
    tree.insert(34);
    tree.insert(12);
    tree.insert(1);
    tree.insert(54);
    tree.insert(6432);
    tree.insert(23);
    tree.insert(23434);
    tree.insert(364);
    tree.insert(3);
    tree.insert(64);
    tree.printInOrder();
    Node* successor = tree.findImmediateSuccessor(54);
    cout<<"\nThe immediate successor is : "<< successor->value<<endl;
    return 0;
}