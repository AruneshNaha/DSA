#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void bubbleSort(int *A, int n)//adaptive bubble sort
{
    int arrayIsSorted = 1;
    for (int i = 0; i < n - 1; i++)
    {
        printf("\nSorting array in pass number %d \n", i);
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                arrayIsSorted = 0;
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
        if (arrayIsSorted)
        {
            break;
        }
    }
}

int main()
{
    int A[] = {12, 54, 65, 7, 23, 9};
    // int A[] = {1,2,3,4,5,6};
    printf("The array before sorting: \n");
    printArray(A, 6); //Printing the array before sorting

    bubbleSort(A, 6); //Function to sort array

    printf("\nThe array after sorting: \n");
    printArray(A, 6); //Printing the array after sorting

    return 0;
}
