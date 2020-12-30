#include <stdio.h>

int size, front = -1, rear = -1;

//enqueueF(), enqueueR(), deQueueF(), deQueueR()

void enqueue(int *arr)
{
  int num;
  printf("\nEnter the element you want to push: ");
  scanf("%d", &num);
  printf("\n rear: %d front: %d\n", rear, front);

  //Condition if queue is full
  if ((front == 0 && rear == size - 1) || (rear + 1 == front))
  {
    printf("Queue is full!");
    return;
  }
  else
  {
    if (rear == size - 1 && front != 0)
    {
      rear = -1;
    }
    arr[++rear] = num;
    printf("\n %d is inserted succesfully!", arr[rear]);
    if (front == -1)
    {
      front = 0;
    }
  }
}

int dequeue(int *arr)
{
  int n;

  if (front == -1 && rear == -1)
    printf("\nCircular Queue is Empty! Deletion is not possible!!!\n");
  else
  {
    printf("\nDeleted element : %d\n", arr[front++]);
    if (front == size)
      front = 0;
    if (front - 1 == rear)
      front = rear = -1;
  }
}

void display(int *arr)
{
  int i = front;
  if (front == -1)
  {
    printf("\nQueue is empty");
    return;
  }
  else
  {
    if (front < rear)
    {
      while (i <= rear)
      {
        printf(" %d ", arr[i]);
      }
    }
    else
    {
      while (i <= size - 1)
        printf(" %d ", arr[i++]);
      i = 0;
      while (i <= rear)
        printf(" %d ", arr[i++]);
    }
  }
}

void main()
{
  int choice, num;

  printf("\n*****Queue using array*****\n");
  printf("\nEnter the size of the queue:\n");
  scanf("%d", &size);

  int queue[size];

  while (choice)
  {
    printf("\nPress \n1> push \n2> pop \n3> Display the queue \n0> End program \nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      enqueue(queue);
      break;

    case 2:
      num = dequeue(queue);
      if (num != -999)
      {
        printf("\nData removed: %d", num);
      }
      break;

    case 3:
      display(queue);
      break;

    case 0:
      break;

    default:
      printf("\nInvalid choice! Enter again.");
    }
  }
}