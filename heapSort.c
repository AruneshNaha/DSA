#include<stdio.h>

void main()
{
    int arr[]={30, 10, 60, 20, 50, 40, 90, 40};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorting: \n");

    printArray(arr, n);
    printf("\nThe array after sorting:\n");
    heapSort(arr, n);
    printArray(arr, n);

}

void heapSort(int *arr, int n){
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n-1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(int *arr, int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l<n && arr[l]>arr[largest])
    {
        largest = l;
    }

    if (r<n && arr[r]>arr[largest])
    {
        largest = r;
    }
    
    if (i!=largest)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void swap(int *A, int *B){
    int temp =*A;
    *A=*B;
    *B=temp;
}

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    
}
