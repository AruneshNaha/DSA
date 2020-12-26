#include<stdio.h>

int size,front=-1,rear=0;

//enqueueF(), enqueueR(), deQueueF(), deQueueR()

void enQueueR(int *arr){
    int num;
    printf("\nEnter the element you want to push: ");
    scanf("%d",&num);

    if (rear!=size )
    {
        printf("\nFront value: %d rear value: %d", front, rear);
        arr[rear] = num;
        rear++;
    }else
    {
        printf("\nThe queue is full from rear!");
    } 
}

void enQueueF(int *arr){
    int num;
    printf("\nEnter the element you want to push: ");
    scanf("%d",&num);

    if (front == -1)
    {
        printf("\nThe queue is full from front!");
    }else
    {
        
         printf("\nFront value: %d rear value: %d", front, rear);
        arr[front] = num;
        front--;
    } 
}

int deQueueR(int *arr){
    int n;
    if (rear-1<=front || rear==0)
    {
        printf("Queue is empty from rear!");
        return -999;
    }
    else
    {
        n=arr[--rear];
        printf("\nFront value: %d rear value: %d", front, rear);        
        return n;
    }
    
    
}

int deQueueF(int *arr){
    int n;
    //rear==front+1 ||
    // || rear==0 
    if (front >= rear-1 )
    {
        printf("\nQueue is empty from front");
        return -999;
    }
    else
    {
        n= arr[++front];
        printf("\nFront value: %d rear value: %d", front, rear);        
        return n;
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
        printf("\nPress \n1> push from front \n2> push from rear \n3> pop from front \n4> pop from rear \n5> Display the queue \n0> End program \nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueueF(queue); 
            break;

        case 2:
            enQueueR(queue);
            break;

        case 3:
            num = deQueueF(queue);
            if (num!=-999)
            {
                printf("\nData removed: %d", num);
            }            
            break;

        case 4:
            num = deQueueR(queue);
            if (num!=-999)
            {
                printf("\nData removed: %d", num);
            }            
            break;
        
        case 5:
            display(queue);
            break;

        case 0:
            break;
        
        default:printf("\nInvalid choice! Enter again.");
            break;
        }
    }
    
}