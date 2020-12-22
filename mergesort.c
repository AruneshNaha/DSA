#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;  //calculating size of the lower half array
    int n2 = high - mid + 1; // calculating size of the upper half array
    int L[n1], H[n2];        // declaring the lower half and the upper half array with it's calculated size

    //Putting the elements in the lower half and the upper half array
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        H[i] = arr[mid + i + 1];

    i = 0;
    j = 0;
    k = low; // initial index of the array initialized to k
    while (i < n1 && j < n2)
    {
        if (L[i] < H[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = H[j++];
        }
    }
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = H[j++];
    }
}

void mergeSort(int *A, int low, int high)
{
    int mid = low + (high - low) / 2;

    if (low < high)
    {
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {12, 11, 13, 5, 6, 7 };
    // int A[] = {1,2,3,4,5,6};
    printf("The array before sorting: \n");
    printArray(A, 6); //Printing the array before sorting

    mergeSort(A, 0, 5); //Function to sort array

    printf("\nThe array after sorting: \n");
    printArray(A, 6); //Printing the array after sorting

    return 0;
}