#include <stdio.h>

void mergeArrays(int a[], int n1, int b[], int n2, int merged[]) {
    int i;

    for (i = 0; i < n1; i++) {
        merged[i] = a[i];
    }

    for (i = 0; i < n2; i++) {
        merged[n1 + i] = b[i];
    }
}

int main() {
    int a[100], b[100], merged[200];
    int n1, n2, i;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter elements of first array:\n");
    for (i = 0; i < n1; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of second array:\n");
    for (i = 0; i < n2; i++) {
        scanf("%d", &b[i]);
    }

    mergeArrays(a, n1, b, n2, merged);

    printf("Merged array:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}