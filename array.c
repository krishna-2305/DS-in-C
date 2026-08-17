//#include <stdio.h>

//int main() {
  //  int arr[100] = {10, 20, 30, 40, 50};
   // int n = 5;
    //int pos, value;

    //printf("Enter position: ");
    //scanf("%d", &pos);

    //printf("Enter value: ");
    //scanf("%d", &value);

    // Shift elements to the right
    //for (int i = n; i >= pos; i--) {
    //    arr[i] = arr[i - 1];
    //}

    //arr[pos - 1] = value;
    //n++;

    //printf("Array after insertion:\n");

    //for (int i = 0; i < n; i++) {
    //    printf("%d ", arr[i]);
    //}

    //return 0;
//}

#include <stdio.h>

void insertAtEnd(int arr[], int *n, int value)
{
    arr[*n] = value;
    (*n)++;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    insertAtEnd(arr, &n, 60);

    display(arr, n);

    return 0;
}