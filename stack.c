#include<stdio.h>
#include<stdlib.h>
struct stack {
    struct node *Top;
    int capacity;
    int size;
};
struct node{
    int data;
    struct node*next;
};
struct stack* createStack(int capacity){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->capacity=capacity;
    s->size=0;
    s->Top=NULL;
    return s;
};
struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
};
struct stack* push(struct stack* s,int data){
    if(s->size==s->capacity){
        printf("Stack Overflow\n");
        return s;
    }
    struct node* newNode=createNode(data);
    newNode->next=s->Top;
    s->Top=newNode;
    s->size++;
    return s;
};
struct stack* pop(struct stack* s){
    if(s->size==0){
        printf("Stack Underflow\n");
        return s;
    }
    struct node* temp=s->Top;
    s->Top=s->Top->next;
    free(temp);
    s->size--;
    return s;
};
int peek(struct stack* s){
    if(s->size==0){
        printf("Stack is empty\n");
        return -1;                  
    }
    return s->Top->data;
};
struct stack* display(struct stack* s){
    struct node* temp=s->Top;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    return s;
}; 
int main(){
    int a,b,cs;
    printf("Enter the capacity of stack\n");
    scanf("%d",&a);
    struct stack* s=createStack(a);
    for(int i=0;i<a;i++){
        printf("Enter the element to be pushed\n");
        scanf("%d",&b);
        s=push(s,b);
    }
    printf("Enter your choice\n");
    printf("1.Display\n2.Peek\n3.Pop\n");
    scanf("%d",&cs);
    printf("\n");
    switch (cs){
        case 1:
            s=display(s);
            break;
        case 2:
            printf("Top element is %d\n",peek(s));
            break;
        case 3:
            s=pop(s);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
} 