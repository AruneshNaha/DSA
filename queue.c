#include<stdio.h>

int size,front=-1,rear=0;

void push(int *arr){
    int num;
    printf("\nEnter the element you want to push: ");
    scanf("%d",&num);

    if (rear!=size)
    {
        printf("\nFront value: %d rear value: %d", front, rear);
        arr[rear] = num;
        rear++;
    }else
    {
        printf("\nThe queue is full from rear!");
    } 
}

int pop(int *arr){
    int n;
    if (front==rear-1)
    {
        front=-1;
        rear=0;
        printf("\nQueue is empty");
        return -999;
    }
    else
    {
        n= arr[++front];
        printf("\nFront value: %d rear value: %d", front, rear);        
        return n;
    }
}

int peekAtFront(int *arr){
    if ( front ==-1)
    {
        printf("\nQueue is empty");
        return -999;
    }
    else
    {
        return arr[front];
    }
}

int peekAtRear(int *arr){
    if ( front ==-1)
    {
        printf("\nQueue is empty");
        return -999;
    }else
    {
        return arr[rear];
    }
}

void display(int *arr){
    if (front == rear-1)
    {
        printf("\nQueue is empty");
        return;
    }else
    {
        printf("\nThe datas present in the queue are:\n");
        int i=front+1;
        while (i<rear)
        {
            printf("%d ",arr[i++]);
        }
        
    }
    
}

void main(){
    int choice, num;

    printf("\n*****Queue using array*****\n");
    printf("\nEnter the size of the queue:\n");
    scanf("%d",&size);
    

    int queue[size];

    while (choice)
    {
        printf("\nPress \n1> push \n2> pop \n3> display the entire queue \n0> End program \nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(queue); 
            break;

        case 2:
            num = pop(queue);
            if (num!=-999)
            {
                printf("\nData removed: %d", num);
            }            
            break;
        
        case 3:
            display(queue);
            break;

        case 0:
            break;
        
        default:printf("\nInvalid choice! Enter again.");
            break;
        }
    }
    
}