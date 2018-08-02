#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
    int data;
    struct node *next;
}*top=NULL,*front=NULL,*rear=NULL;

void push(int);
void pop();
void display_s();
void insert(int);
void del();
void display_q();
int main()
{
    char ch;
    int c1,c2,value1,value2;
    abc:
    printf("\n\t\t##########   MAIN MENU   ##########\n");
    printf("\n\t[A] -> Implementation of stack using Linked list ");
    printf("\n\t[B] -> Implementation of Queue using Linked list ");
    printf("\n\n\tEnter your choice i.e ( either a or b ) : ");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='a' || ch=='A')
    {
        while(1)
        {
		    printf("\n\n\t**********   MENU   **********");
            printf("\n\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Go to Main Menu\n\t5.Exit\n");
		    printf("\n\tEnter your choice : ");
			scanf("%d",&c1);
            switch(c1)
            {
                case 1: printf("\n\tEnter the value that you want to insert in stack : ");
                        scanf("%d",&value1);
                        push(value1);
                        break;
                case 2: pop();
                        break;
                case 3: display_s();
                        break;
                case 4: goto abc;
                        break;
                case 5: exit(0);
                        break;
                default: printf("\n\t!!wrong choice\n");
                         break;
            }
        }
    }
     else if(ch=='b' || ch=='B')
    {
        while(1)
        {
		    printf("\n\n\t**********   MENU   **********");
			printf("\n\n\t1.Insert\n\t2.Delete\n\t3.Display\n\t4.Go to Main Menu\n\t5.Exit\n");
			printf("\n\tEnter your choice : ");
			scanf("%d",&c2);
            switch(c2)
            {
                case 1: printf("\n\tEnter the value that you want to insert in Queue : ");
                        scanf("%d",&value2);
                        insert(value2);
                        break;
                case 2: del();
                        break;
                case 3: display_q();
                        break;
                case 4: goto abc;
                        break;
                case 5: exit(0);
                        break;
                default: printf("\n\t!!wrong choice\n");
                         break;
            }
        }
    }
    else
        printf("\n\tYou Enter wrong choice ");

    return 0;
}

void push(int x)
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    if(top==NULL)
        newNode->next=NULL;
    else
        newNode->next=top;
    top = newNode;
}

void pop()
{
    if(top==NULL)
        printf("\n\tStack is empty i.e (underflow condition)");
    else
    {
        struct node *temp=top;
        printf("\n\tDeleted element is %d",temp->data);
        top = temp->next;
        free(temp);
    }
}

void display_s()
{
    if(top==NULL)
        printf("\n\tStack is empty !!");
    else
    {
        printf("\n\tElements stored in stack : \t");
        struct node *temp=top;
        while(temp->next!=NULL)
        {
            printf("%d ---> ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void insert(int y)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data = y;
    newnode->next=NULL;
    if(front==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }

}

void del()
{
    if(front==NULL)
        printf("\n\tQueue is empty !!");
    else
    {
        struct node *temp=front;
        front = front->next;
        printf("\n\tDeleted element is %d ",temp->data);
        free(temp);
    }

}

void display_q()
{
     if(front == NULL)
      printf("\n\tQueue is Empty !!\n");
   else
    {
        printf("\n\tELements stored in Queue :\t");
        struct node *temp = front;
        while(temp->next != NULL)
        {
                printf("%d ---> ",temp->data);
                temp = temp -> next;
        }
        printf("%d\n",temp->data);
   }
}
