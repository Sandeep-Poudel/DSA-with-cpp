#include <stdio.h>
#include <stdlib.h>
#define size 5
struct Stack{
    int data[size];
    int top;
}s;

void push(struct Stack* s){
    if(s->top == size-1){
        printf("Stack overflow!");
        return ;
    }
    s->top++;
    printf("Enter the value to push: ");
    scanf("%d",&s->data[s->top]);
    printf("%d pushed to the stack \n",s->data[s->top]);
    getchar();
}

void pop(struct Stack * s){
    if(s->top==-1){
        printf("Stack is empty!\n");
        getchar();
        return;
    }
    else{
        printf("%d popped from the stack!",s->data[s->top]);
        s->top-=1;
    }
    getchar();
}

void display(struct Stack * s)
{
    if(s->top==-1){
        printf("Stack is empty!\n");
        return;
    }
    for(int i=s->top;i>=0;i--){
        printf("%d\n",s->data[i]);
    }
    getchar();
};



int main(){
    struct Stack s;
    s.top=-1;
    int choice;
    while(1){
        system("clear");
        printf("Choose the operation that you want to do \n");
        printf("\t1. Push\n\t2. Pop \n\t3. Display \n\t0. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice!!");
        }
        getchar();

    };
    return 0;

}