#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *prev;
        struct node *next;

}*head=NULL,*last=NULL;

void create(int);
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();

int main()
{
        int choice,n;
        while(1){
                printf("\n\n\t***DOUBLE LINKED LIST OPERATIONS:****\n");
                printf("\n\t                MENU                             \n");
                printf(" \t|------------------------------------|\n");
                printf("\n\t| 1.Create                           |\n");
                printf("\n\t| 2.Display                          |\n");
                printf("\n\t| 3.Insert at the beginning          |\n");
                printf("\n\t| 4.Insert at the end                |\n");
                printf("\n\t| 5.Insert at specified position     |\n");
                printf("\n\t| 6.Delete from beginning            |\n");
                printf("\n\t| 7.Delete from the end              |\n");
                printf("\n\t| 8.Delete from specified position   |\n");
                printf("\n\t| 9.Exit                             |\n");
                printf("\n\t|------------------------------------|\n");
                printf("\n\tEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:

                                if(head == NULL)
                                        {
                                            printf("\n\tEnter the number of nodes that you want to create: ");
                                            scanf("%d", &n);
                                            create(n);
                                        }
                                else
                                        printf("\n\tList is already created..");
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3:
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        case 9:
                                        exit(0);
                                        break;
                        default:
                                        printf("\n\tWrong Choice:\n");
                                        break;
                }
        }
        return 0;
}

void create(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf("\n\tEnter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;
            last = head;
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                    printf("\n\tEnter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;

                    last->next = newNode;
                    last = newNode;
                }
                else
                {
                    printf("\n\tUnable to allocate memory.");
                    break;
                }
            }

            printf("\n\tDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("\n\tUnable to allocate memory");
        }
    }
}

void display()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
        printf("\n\tList is Empty!");
    }
    else
    {
        temp = head;
        printf("\n\tDATA IN THE LIST :----->");

        while(temp != NULL)
        {
            printf("  %d",temp->data);
            n++;
            temp = temp->next;
        }
    }
}

void insert_begin()
{
    struct node * newNode;
    int data;
    if(head == NULL)
    {
        printf("\n\tList is Empty!");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("\n\tEnter data of first node : ");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        printf("\n\tNODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST");
    }
}

void insert_end()
{
    struct node * newNode;
    int data;
    if(last == NULL)
    {
        printf("\n\tList is Empty!");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("\n\tEnter data of last node : ");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        printf("\n\tNODE INSERTED SUCCESSFULLY AT THE END OF LIST");
    }
}

void insert_pos()
{
    int i,position,data;
    struct node * newNode, *temp;

    if(head == NULL)
    {
        printf("\n\tList is Empty!\n");
    }
    else
    {
        temp = head;
        i=1;
        printf("\n\tEnter the position where you want to insert new node: ");
        scanf("%d",&position);
        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }
        if(position == 1)
        {
            insert_begin();
        }
        else if(temp == last)
        {
            insert_end();
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("\n\tEnter data of %d node : ", position);
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;
            if(temp->next != NULL)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;

            printf("\n\tNODE INSERTED SUCCESSFULLY AT %d POSITION\n", position);
        }
        else
        {
            printf("\n\tInvalid position");
        }
    }
}

void  delete_begin()
{
    struct node *del=head,*temp=head;
    if(head==NULL)
        printf("\n\tList is Empty!");
    else
    {
        if(temp->next==NULL)
        {
            free(temp);
            head=NULL;
        }
        else
        {
            head=head->next;
            head->prev=NULL;
            free(del);
        }
         printf("\n\tSUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.");
    }
}

void delete_end()
{
    struct node *del;
    if(last==NULL || head==NULL)
        printf("\n\tUnable to delete i.e List is Empty!");
    else
    {
        if(last->prev==NULL)
        {
            free(last);
            last=NULL;
        }
        else
        {
            del=last;
            last=last->prev;
            last->next=NULL;
            free(del);
        }
        printf("\n\tSUCCESSFULLY DELETED NODE FROM END OF THE LIST.");
    }
}

void delete_pos()
{
    struct node *current;
    int i,position;
    if(head==NULL)
        printf("\n\tList is Empty!");
    else
    {
         printf("\n\tEnter the node position which you want to delete: ");
    scanf("%d",&position);
    current = head;
    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        delete_begin();
    }
    else if(current == last)
    {
        delete_end();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current);

        printf("\n\tSUCCESSFULLY DELETED NODE FROM %d POSITION.", position);
    }
    else
    {
        printf("\n\tInvalid position.");
    }
    }

}



