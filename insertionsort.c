#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void insertionSort(int *A, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (A[j] > key && j >= 0)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    // int A[] = {1,2,3,4,5,6};
    printf("The array before sorting: \n");
    printArray(A, 6); //Printing the array before sorting

    insertionSort(A, 6); //Function to sort array

    printf("\nThe array after sorting: \n");
    printArray(A, 6); //Printing the array after sorting

    return 0;
}