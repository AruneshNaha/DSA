#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} * head;

typedef struct Node Node;

void create()
{
    Node *tmp1, *tmp2;
    int moreNodes = 1;
    int num;
    while (moreNodes)
    {
        printf("Enter the node data:");
        scanf("%d", &num);

        if (head == NULL)
        {
            head = (Node *)malloc(sizeof(Node));
            head->data = num;
            head->next = NULL;
        }
        else
        {
            tmp1 = head;
            while (tmp1->next != NULL)
            {
                tmp1 = tmp1->next;
            }
            tmp2 = (Node *)malloc(sizeof(Node));
            tmp2->data = num;
            tmp2->next = NULL;
            tmp1->next = tmp2;
        }

        printf("\n More nodes? 1/0:  ");
        scanf("%d", &moreNodes);
    }
}

void read()
{
    Node *tmp;
    if (head == NULL)
    {
        printf("\nNo nodes present!\n");
    }
    else
    {
        tmp = head;
        while (tmp->next != NULL)
        {

            printf("%d  ", tmp->data);
            tmp = tmp->next;
        }
        printf("%d ", tmp->data);
    }
}

void update()
{
    int num, replacenum, found = 0;
    printf("\nEnter the number in the node to search and replace: ");
    scanf("%d", &num);
    printf("\nEnter the number to replace with: ");
    scanf("%d", &replacenum);

    Node *tmp;
    tmp = (Node *)malloc(sizeof(Node));

    if (head == NULL)
    {
        printf("\nThe Node is null");
    }
    else
    {
        tmp = head;
        do
        {
            if (tmp->data == num)
            {
                found = 1;
                tmp->data = replacenum;
                break;
            }
            tmp = tmp->next;

        } while (found || (!found && tmp->next != NULL));

        //Logic for updating the last node
        if (tmp->data == num)
        {
            found = 1;
            tmp->data = replacenum;
        }

        if (found)
            printf("\n The node was found!\n");
        else
            printf("\nThe node was not found!\n");

        printf("The updated node list is:\n");

        read();
    }
}

void delete ()
{

    int num, found = 0;

    printf("\nEnter the node data you want to delete:");
    scanf("%d", &num);

    Node *tmp, *prevtmp;

    tmp = head;
    prevtmp = head;

    if (head == NULL)
    {
        printf("\nThe node is empty!\n");
    }

    //Logic for removing the head element
    else if (head->data == num)
    {
        head = head->next;
    }

    //Logic for removing a middle element from the node
    else
    {
        do
        {

            if (tmp->data == num)
            {
                found = 1;
                if (tmp->next != NULL)
                    prevtmp->next = tmp->next;

                break;
            }
            prevtmp = tmp;
            tmp = tmp->next;
        } while (found || (tmp->next != NULL && !found));
    }

    //Logic for removing the last element from the node
    if (!found && tmp->data == num)
    {
        found = 1;
        prevtmp->next = NULL;
    }

    if (found)
        printf("\n The node was found!\n");
    else
        printf("\nThe node was not found!\n");

    printf("\nThe updated node is:\n");
    read();
}

void insertionInNode()
{
    Node *tmp, *tmp2 = head;
    tmp = (Node *)malloc(sizeof(Node));
    int num, nodedata, found = 0, nodeAtEnd = 0, nodeAtFront = 0;
    printf("\nEnter the node data to insert:");
    scanf("%d", &num);

    printf("Do you want to insert the node at the very beginning? 1/0 : ");
    scanf("%d", &nodeAtFront);

    if (!nodeAtFront)
    {
        printf("Do you want to insert the node at the very end? 1/0 : ");
        scanf("%d", &nodeAtEnd);
    }

    if (nodeAtFront || nodeAtEnd)
    {
        //Insertion of node at front
        if (nodeAtFront)
        {
            tmp->data = num;
            tmp->next = head;
            head = tmp;
            printf("\nThe updated node list is: \n");
            read();
            return;
        }
        //Insertion of node at the end
        if (nodeAtEnd)
        {
            while (tmp2->next != NULL)
            {
                tmp2 = tmp2->next;
            }
            tmp->data = num;
            tmp->next = NULL;
            tmp2->next = tmp;
            printf("\nThe updated node list is: \n");
            read();
            return;
        }
    }

    //Insertion of the node at the midle
    printf("\nEnter the node data after which you want to insert:");
    scanf("%d", &nodedata);

    //Logic if the node data is found in head
    while (found || (tmp2->next != NULL && !found))
    {
        if (tmp2->data == nodedata)
        {
            found = 1;
            tmp->data = num;
            tmp->next = tmp2->next;
            tmp2->next = tmp;
            break;
        }
        tmp2 = tmp2->next;
    }
    if (found)
    {
        printf("\n Your element was found\n");
    }
    else
    {
        printf("\n Your element was not found\n");
    }

    printf("\nThe updated node list is: \n");
    read();
}

void main()
{
    int choice;

    // create();
    // read();
    // insertionInNode();
    // delete();
    while (choice)
    {
        printf("\n********Linked List Operations**********\n Press:\n 1> Add data to the list \n 2> Print Linked Lst data \n 3> Insert in node \n 4> Update existing data in the node \n 5> Delete data from the node \n 0> Terminate the program \n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        
        case 2: 
            read();
            break;

        case 3:
            insertionInNode();
            break;

        case 4: 
            update();
            break;
        case 5:
            delete();
            break;
        case 0:
            continue;

        default:
            break;
        }
    }   
    
}