#include<stdio.h>
#include<stdlib.h>

int top=-1,size;

void display(int *A){
    if (top==-1)
    {
        printf("\nStack underflow. No data present!");
    }else
    {
        int i=0;
        while (i <= top)
        {
            printf("%d ", A[i++]);
        }
    }  
    
}

void Push(int *array, int n){
    if (top==size-1)
    {
        printf("\nStack overflow! Operation denied\n");
    }else
    {
        array[++top]=n;
    }  
}

int Pop(int *array){
    if (top==-1)
    {
        printf("\nStack underflow!Operation denied!");
        return -999;
    }else
    {
        return array[top--];
    }      
}

int peek(int *array){
    if (top==-1)
    {
        printf("\nStack underflow.No data present!");
        return -999;
    }else
    {
        return array[top];
    }
    
    
}

void main(){
    int choice, num;
    printf("\nEnter the size of the stack:");
    scanf("%d",&size);
    int stack[size];
    printf("\n*****Stack using Array*****\n");
    
    while (choice)
    {
        printf("\nPress \n 1> push\n 2> pop\n 3> peep\n 4> display\n 0> Terminate program \nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data to push:");
            scanf("%d",&num);
            Push(stack, num);
            break;

        case 2:
            num = Pop(stack);
            if(num != -999)
                printf("\nData returned: %d",num);
            break;

        case 3:
            num = peek(stack);
            if (num!=-999)
            {
                printf("\nData peeked: %d", num);
            }
            break;
            
        case 4:printf("\nThe datas present in the stack:\n");
            display(stack);
            break;
        
        default:
            printf("Invalid choice! Enter again!");
            break;
        }
    }
    

}