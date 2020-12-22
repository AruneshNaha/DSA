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

            printf("\t%d\t", tmp->data);
            tmp = tmp->next;
        }
        printf("\t%d", tmp->data);
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
    if (tmp->data == num)
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

// void insertionInNode(){
//     Node *tmp;
//     tmp=(Node *)malloc(sizeof(Node));
//     int num, nodedata;
//     printf("Enter the node data to insert:");
//     scanf("%d",&num);

//     printf("\nEnter the node data after which you want to insert:");
//     scanf("%d",&nodedata);

//     //Logic if the node data is found in head
//     if (head->data == nodedata)
//     {
//         tmp->data=num;

//     }
    
// }

void main()
{

    create();
    read();
    update();
    delete();
}