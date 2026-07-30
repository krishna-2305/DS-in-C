#include <stdio.h>
#include <stdlib.h>
struct Node {

    int data;
    struct Node* next;
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
    printf("%d\n",head->data);
    return 0;
}