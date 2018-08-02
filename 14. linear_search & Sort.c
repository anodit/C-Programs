#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}*head=NULL;

void create();
void display();
void search();
void sort();
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\t|********    MAIN MENU    ********|");
        printf("\n\n\t| 1. Create Single Linked List    |");
        printf("\n\n\t| 2. Display                      |");
        printf("\n\n\t| 3. Linear Search                |");
        printf("\n\n\t| 4. Selection Sort               |");
        printf("\n\n\t| 5. Exit                         |");
        printf("\n\t-----------------------------------");
        printf("\n\n\tEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: search();
                    break;
            case 4: sort();
                    break;
            case 5: exit(0);
                    break;
            default : printf("\n\t!! Wrong choice");
                     break;
        }
    }
        return 0;
}

void create()
{
    int n,m,i;
    struct node *temp,*q;
    if(head==NULL)
    {
        printf("\n\tEnter the no. of nodes that you want to create : ");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            printf("\n\tEnter the data of %d node : ",i);
            scanf("%d",&m);
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=m;
            temp->next=NULL;
            if(head==NULL)
                head=temp;
            else
            {
                q=head;
                while(q->next!=NULL)
                {
                    q=q->next;
                }
                q->next=temp;
            }
        }
        printf("\n\tSingle Linked List Created Successfully.");
    }
    else
        printf("\n\tList is already created..");
}

void display()
{
    struct node *q;
    if(head==NULL)
    printf("\n\tList is Empty ");
    else
    {
        q=head;
        printf("\n\tElements are\t");
        while(q!=NULL)
        {
            printf("-> %d ",q->data);
            q=q->next;
        }
    }
}

void search()
{
    int key,true=0;
    struct node *temp;
    if(head==NULL)
    {
        printf("\n\tList is Empty ");
    }
    else
    {
        printf("\n\tEnter the value that you want to search : ");
        scanf("%d",&key);
            temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==key)
                true++;
            temp=temp->next;
        }
        if (true>0)
        {
            printf("\n\t%d is found in the list i.e (Search Successful)", key);
        }
        else
        {
            printf("\n\t%d is not found in the list i.e (Search Unsuccessful)", key);
        }
    }
}

void sort()
{
    struct node *q,*p;
    int data;
    if(head==NULL)
        printf("\n\tList is Empty ");
    else
    {
        q=head;
        while(q!=NULL)
        {
            p=q->next;
            while(p!=NULL)
            {
                if(q->data>p->data)
                {
                    data=q->data;
                    q->data=p->data;
                    p->data=data;
                }
                p=p->next;
            }
            q=q->next;
        }
        printf("\n\tList Sorted Successfully");
    }
}
