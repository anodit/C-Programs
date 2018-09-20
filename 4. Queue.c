#include <stdio.h>

#define MAX 5
int queue_array[MAX];
int rear = - 1;
int front = - 1;

int main()
{
    int choice;
    while (1)
    {
		printf("\n\n**********   Queue Operations   **********\n\n");
        printf("  1.Insert element to queue \n");
        printf("  2.Delete element from queue \n");
        printf("  3.Display all elements of queue \n");
        printf("  4.Quit \n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
			insert();
			break;
            case 2:
			delete();
			break;
            case 3:
			display();
			break;
            case 4:
			exit(1);
	    default:
			printf("Wrong choice \n");
        }
    }
}

insert()
{
    int add_item;
    if (rear == MAX - 1)
    printf("\n Queue Overflow \n");
    else
    {
        if (front == - 1)
        front = 0;
        printf("\nInset the element in queue : ");
        scanf("%d", &add_item);
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

delete()
{
    if (front == - 1 || front > rear)
    {
        printf("\n Queue Underflow \n");
        return ;
    }
    else
    {
        printf("\n Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
}

display()
{
    int i;
    if (front == - 1)
        printf("\nQueue is empty \n");
    else
    {
        printf("\nQueue is : \n");
        for (i = front; i <= rear; i++)
            printf("\n\t\t%d ", queue_array[i]);
        printf("\n");
    }
}
