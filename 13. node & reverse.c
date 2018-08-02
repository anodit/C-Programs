#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL,*temp=NULL;

void create(int);
void display();
void count();
void reverse();
int main()
{
    int choice,value;

    while(1)
    {
        printf("\n\n\t###################################");
         printf("\n\n\t|**********  MAIN MENU   *********|");
         printf("\n\n\t| 1. Create Linked List           |");
         printf("\n\n\t| 2. Display Linked List          |");
         printf("\n\n\t| 3. Count no. of nodes           |");
         printf("\n\n\t| 4. Reverse Linked List          |");
         printf("\n\n\t| 5. Exit                          |");
         printf("\n\t-----------------------------------");
         printf("\n\n\tEnter your choice : ");
         scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\n\tEnter the data to be inserted in node : ");
                    scanf("%d",&value);
                    create(value);
                    break;
            case 2: display();
                    break;
            case 3: count();
                    break;
            case 4: reverse();
                    break;
            case 5: exit(0);
                    break;
            default : printf("\n\t!! wrong Choice ");
                    break;
        }
    }
    return 0;
}

void create(int value)
{
    struct node *var;
    temp=head;
    var=(struct node *)malloc(sizeof(struct node));
    var->data=value;

    if(head==NULL)
    {
         head=var;
         head->next=NULL;
    }
    else
    {
         while(temp->next!=NULL)
         {
              temp=temp->next;
         }
         var->next=NULL;
         temp->next=var;
    }
}

void display()
{
     struct node *var;
     if(head==NULL)
        printf("\n\tList is Empty ");
     else
     {
        var=head;
        printf("\n\tElements are\t");
        while(var!=NULL)
        {
            printf("-> %d ",var->data);
            var=var->next;
        }
    }
}

void count()
{
     int i=0;
     temp=head;
     while(temp!=NULL)
     {
          i++;
          temp=temp->next;
     }
     printf("\n\tNumber of nodes are %d  ",i);
}

void reverse()
{
    struct node *prevNode, *curNode;
    if(head==NULL)
    {
        printf("\n\tList is Empty ");
    }
    else if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;
        prevNode->next = NULL;
        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;
        printf("\n\tSUCCESSFULLY REVERSED LIST\n");
    }
}
