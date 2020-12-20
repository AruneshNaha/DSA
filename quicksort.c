#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}

int partition(int *A, int low, int high)
{
    int i = low - 1;
    int j;
    int pivot = A[high];

    for (j = low; j < high; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i + 1], &A[high]);
    return i + 1;
}

void quickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int pi = partition(A, low, high);
        quickSort(A, low, pi - 1);
        quickSort(A, pi + 1, high);
    }
}

int main()
{
    int A[] = {9, 3, 7, 5, 6, 4, 8, 2};
    // int A[] = {1,2,3,4,5,6};
    printf("The array before sorting: \n");
    printArray(A, 8); //Printing the array before sorting

    quickSort(A, 0, 7); //Function to sort array

    printf("\nThe array after sorting: \n");
    printArray(A, 8); //Printing the array after sorting

    return 0;
}