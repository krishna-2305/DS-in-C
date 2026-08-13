#include<stdio.h>
#include<stdlib.h>
#define max 100
struct stack {
    int arr[max];
    int top;
};
void push(struct stack*s,int data){
    if(s->top==max-1){
        printf("Stack overflow\n"); 
        return ;
    } 
        s->top++;
        s->arr[s->top]=data;
};
struct stack* pop(struct stack*s){
    if(s->top==-1){
        printf("Stack underflow\n");
        return s;
    }
    s->top--;
    return s;
}; 
int peek(struct stack*s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
};
int isEmpty(struct stack*s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return 1;
    }
    return 0;
};
int isFull(struct stack*s){
    if(s->top==max-1){
        printf("Stack is full\n");
        return 1;
    }
    return 0;
};
void display(struct stack*s){
    if(s->top==-1){
        printf("Stack is empty\n");
    }
    for(int i=s->top;i>=0;i--)
    {
        printf("%d\n",s->arr[i]);
    }
};
int main(){
    struct stack* s= (struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    int a,b;
    printf("Enter the number of elements to push: ");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&b);
        push(s,b);
    }
    printf("Elements in the stack are:\n");
    display(s);
    printf("Top element is: %d\n", peek(s));
    pop(s);
    printf("Elements in the stack after pop operation are:\n");
    display(s);
    return 0;
}