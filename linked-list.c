#include <stdio.h>
#include <stdlib.h>
struct Node {

    int data;
    struct Node* next;
};
struct Node* Traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    return NULL;
};
struct Node* Insert_at_End(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
};   
struct Node* Insert_at_Beginning(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
};
struct Node* Insert_at_Index(struct Node* head,int data,int index){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;
    ptr->data=data;
    return head;
};
struct Node Insert_After_node(struct Node* head,struct Node* current,int data){
struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
newNode->next=second->next;
second->next=newNode;
return head;
};
int main() {
    struct Node* head;
    struct Node* first;
    struct Node* second;
    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next=first;
    first->data = 2;
    first->next=second;
    second->data =3;
    second->next=NULL;
    Traversal(head);
    head = Insert_at_Beginning(head, 8);
    printf("After Insertion at Beginning\n");
    Traversal(head);
    head = Insert_at_End(head, 5);
    printf("After Insertion at End  \n");
    Traversal(head);
    head = Insert_at_Index(head, 10, 2);
    printf("After Insertion at Index 2\n");
    Traversal(head);
}

