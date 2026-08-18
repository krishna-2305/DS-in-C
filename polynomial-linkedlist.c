#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff;
    int power;
    struct Node *next;
};
struct Node* createNode(int coeff, int power){
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
};
void insertTerm(struct Node **poly, int coeff, int power){
    if (coeff == 0)
        return;
    struct Node *temp = *poly;
    if (*poly == NULL){
        *poly = createNode(coeff, power);
        return; }
    if ((*poly)->power == power){
        (*poly)->coeff += coeff;
        return; }
    while (temp->next != NULL) {
        if (temp->next->power == power)
        {
            temp->next->coeff += coeff;
            return; }
        temp = temp->next; }
    temp->next = createNode(coeff, power);
};
void display(struct Node *poly) {
    while (poly != NULL){
        printf("%dx^%d", poly->coeff, poly->power);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next; }
    printf("\n");
}
struct Node* addPolynomial(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    while(p1!=NULL&&p2==NULL){
        if(p1->power==p2->power){
            insertTerm(&result,p1->coeff+p2->coeff,p1->power);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->power > p2->power){
            insertTerm(&result,p1->coeff,p1->power);
            p1=p1->next;
        }
        else{
            insertTerm(&result,p2->coeff,p2->power);
            p2=p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&result, p1->coeff, p1->power);
        p1 = p1->next; 
    }
    while (p2 != NULL) {
        insertTerm(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}
struct Node* subtractPolynomial(struct Node *p1, struct Node *p2){
    struct Node *result = NULL;
    while(p1!=NULL&&p2!=NULL){
        if(p1->power==p2->power){
            insertTerm(&result,p1->coeff-p2->coeff,p1->power);
            p1=p1->next;
            p2=p2->next;
        }
        else if (p1->power>p2->power){
            insertTerm(&result,p1->coeff,p1->power)
                p1=p1->next;
        }
        else{
            insertTerm(&result,-p2->coeff,p2->power);
            p2=p2->next;
        }
    }
    while (p1 != NULL){
        insertTerm(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2 != NULL){
        insertTerm(&result, -p2->coeff, p2->power);
        p2 = p2->next;
    }
    return result;
}
struct Node* multiplyPolynomial(struct Node *p1, struct Node *p2){
    struct Node *result = NULL;
    struct Node *temp1 = p1;
    struct Node *temp2;
    while (temp1 != NULL){
        temp2 = p2;
        while (temp2 != NULL){
            int coeff = temp1->coeff * temp2->coeff;
            int power = temp1->power + temp2->power;
            insertTerm(&result, coeff, power);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}
int evaluate(struct Node *poly, int x){
    int result = 0;
    while (poly != NULL){
        int power = 1;
        for (int i = 0; i < poly->power; i++){
            power *= x;
        }
        result += poly->coeff * power;
        poly = poly->next;
    }
    return result;
}
struct Node* differentiate(struct Node *poly){
    struct Node *result = NULL;
    while (poly != NULL){
        if (poly->power != 0){
            insertTerm(&result,
                       poly->coeff * poly->power,
                       poly->power - 1);
        }
        poly = poly->next;
    }
    return result;
};
int main()
{
    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    insertTerm(&p1, 5, 3);
    insertTerm(&p1, 4, 2);
    insertTerm(&p1, 2, 0);
    insertTerm(&p2, 3, 3);
    insertTerm(&p2, 2, 2);
    insertTerm(&p2, 7, 1);
    insertTerm(&p2, 1, 0);
    printf("P1 = ");
    display(p1);
    printf("P2 = ");
    display(p2);
    struct Node *sum = addPolynomial(p1, p2);
    printf("\nAddition = ");
    display(sum);
    struct Node *difference = subtractPolynomial(p1, p2);
    printf("Subtraction = ");
    display(difference);
    struct Node *product = multiplyPolynomial(p1, p2);
    printf("Multiplication = ");
    display(product);
    int x = 2;
    printf("\nP1(%d) = %d\n", x, evaluate(p1, x));
    struct Node *derivative = differentiate(p1);
    printf("Derivative of P1 = ");
    display(derivative);
    return 0;
}
