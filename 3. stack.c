#include<stdio.h>
#include<process.h>
#include<stdlib.h>

#define MAX 5

int top=-1,stack[MAX];
void push();
void pop();
void display();

int main()
{
    int ch;

    while(1)
    {
        printf("\n**********  Stack Menu  **********");
        printf("\n\n  1.Push\n  2.Pop\n  3.Display\n  4.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);

            default: printf("\n Wrong Choice!!");
        }
    }
	return 0;
}

void push()
{
    int val;

    if(top==MAX-1)
    {
        printf("\nStack is overflow!!\n");
    }
    else
    {
        printf("\nEnter element to push : ");
        scanf("%d",&val);
        top=top+1;
        stack[top]=val;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack is underflow!!\n");
    }
    else
    {
        printf("\nDeleted element is %d\n",stack[top]);
        top=top-1;
    }
}

void display()
{
    int i;
    if(top==-1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nStack is...\n");
        for(i=top;i>=0;--i)
            printf("\t\t%d\n",stack[i]);
    }
}
