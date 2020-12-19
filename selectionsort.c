#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void selectionSort(int *A, int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    // int A[] = {1,2,3,4,5,6};
    printf("The array before sorting: \n");
    printArray(A, 6); //Printing the array before sorting

    selectionSort(A, 6); //Function to sort array

    printf("\nThe array after sorting: \n");
    printArray(A, 6); //Printing the array after sorting

    return 0;
}