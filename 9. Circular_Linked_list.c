#include <stdio.h>
#include<conio.h>
#include <malloc.h>
#include <stdlib.h>
struct Circular_Linked_List
{
   int data;
   struct Circular_Linked_List *next;
};

typedef struct Circular_Linked_List node;
node *start = NULL;

node* createnode()
{
   node * newnode;
   newnode = (node *) malloc(sizeof(node));
   printf("\n\tEnter the  data : ");
   scanf("%d", &newnode -> data);
   newnode -> next = NULL;
   return newnode;
}

void create_Circular_Linked_List(int n)
{
   int i;
   node *newnode , *ptr;

   for(i = 0; i < n; i++)
    {
       newnode = createnode();
        if(start == NULL)
         {
           start = newnode;
         }
        else
        {
          ptr = start;
          while(ptr -> next != NULL)
          {
            ptr = ptr -> next;
    }
    ptr -> next = newnode;
     }
    }
    newnode ->next = start;
}

void insert_beg()
{
  node *newnode ,*ptr;
  newnode = createnode();
  if(start == NULL)
   {
       start = newnode;
       newnode -> next = start;
   }
  else
   {
     ptr = start;
     while(ptr -> next != start)
     {
        ptr = ptr -> next;
     }
     ptr -> next = newnode;
     newnode -> next =start;
     start = newnode;
   }

}

void insert_end()
{
   node *newnode, *ptr;
   newnode = createnode();
   if(start == NULL)
   {
       start = newnode;
       newnode -> next = start;
   }
   else
   {
      ptr = start;
      while(ptr -> next != start)
      {
      ptr = ptr -> next;
      }
      ptr -> next = newnode;
      newnode -> next = start;
   }
}

int countnode(node *ptr)
{
  int num_of_node=0;
  if (start != NULL)
  {
    do
  {
       num_of_node++;
       ptr = ptr -> next;
     }while(ptr != start);
 }
  return (num_of_node);
}

void insert_pos()
{
  node *newnode, *ptr, *preptr;
  int pos, totalnode, move = 1;
  printf("\n\tEnter the position where u want to insert the node : ");
  scanf("%d", &pos);
  totalnode = countnode(start);
  if(pos > 1 && pos < totalnode)
  {
     newnode = createnode();
  ptr = start;
     while(move < pos-1)
     {
       ptr = ptr -> next;
       move++;
     }
     newnode -> next = ptr -> next ;
     ptr -> next = newnode;
     ;
  }
  else
    printf("\n\tposition %d is not available", pos);
}

void delete_beg()
{
   node *ptr;
   if(start == NULL)
   {
      printf("\n\tList is Empty.");
      return ;
   }
   else
   {
      ptr = start;
      while(ptr -> next != start)
      {
      ptr = ptr -> next;
      }
      ptr -> next = start -> next;
      free(start);
      start = ptr -> next ;
      printf("\n\tNode deleted successfuly... ");
   }
}

void delete_last()
{
  node *ptr, *temp;
  if(start == NULL)
  {
    printf("\n\tList is Empty.");
    return ;
  }

  else if(start ==start->next)
  {
   free(start);
   start=NULL;
  }
  else
  {
    ptr = start;
    while(ptr -> next  -> next != start)
    {
       ptr = ptr -> next;
    }
    temp = ptr -> next;
    ptr->next =start;
    free(temp);
    printf("\n\tNode deleted successfuly... ");
  }
}

void delete_pos()
{
  node *ptr, *preptr;
  int pos, totalnode, move = 1;
  if(start == NULL)
   {
      printf("\n\tList is Empty.");
      return ;
   }
  else
   {
      printf("\n\tEnter the position of node from where u want to delete: ");
      scanf("%d", &pos);
      totalnode = countnode(start);
      if(pos > totalnode)
      {
        printf("\n\tThere is no such node  found in the list!");
      }
      if(pos > 1 && pos < totalnode)
      {
        ptr = preptr = start;
        while(move < pos)
        {
            preptr = ptr;
            ptr = ptr -> next;
            move ++;
        }
        preptr -> next = ptr -> next;
        free(ptr);
        printf("\n\tNode deleted successfuly...");
      }
     else
      {
        printf("\n\tPosition is invalid...  ");
      }
   }
}

void display_List()
{
  node *ptr;
  ptr = start;
  if(start == NULL)
  {
    printf("\n\tList is Empty");
    return;
  }
  else
  {
      printf("\n\tThe contents of Circular_Linked_List :\t--->");
      do
       {
          printf(" %d -->", ptr -> data);
          ptr = ptr -> next;
       } while(ptr != start);
  }
}
int main()
{
  int choice, n;

  while(1)
  {
           printf("\n\n\t***CIRCULAR LINKED LIST OPERATIONS:****\n");
                printf("\n\t                MENU                             \n");
                printf(" \t|------------------------------------|\n");
                printf("\n \t| 1.Create                           |\n");
                printf("\n \t| 2.Display                          |\n");
                printf("\n \t| 3.Insert at the beginning          |\n");
                printf("\n \t| 4.Insert at the end                |\n");
                printf("\n \t| 5.Insert at specified position     |\n");
                printf("\n \t| 6.Delete from beginning            |\n");
                printf("\n \t| 7.Delete from the end              |\n");
                printf("\n \t| 8.Delete from specified position   |\n");
                printf("\n \t| 9.count total no. of nodes         |\n");
                printf("\n \t| 10.Exit                            |\n");
                printf("\n \t|------------------------------------|\n");
                printf("\n\tEnter your choice:\t");
                scanf("%d",&choice);
      switch(choice)
      {
            case 1:  if(start == NULL)
                    {
                        printf("\n\tEnter the number of nodes that you want to create: ");
                        scanf("%d", &n);
                        create_Circular_Linked_List(n);
                        printf("\n\tList created successfuly..");
                    }
                    else
                        printf("\n\tList is already created..");
                        break;

            case 2: display_List();    break;

            case 3: insert_beg();      break;

            case 4: insert_end();      break;

            case 5: insert_pos();      break;

            case 6: delete_beg();      break;

            case 7:  delete_last();    break;

            case 8: delete_pos();      break;

            case 9: printf("\n\tTotal number of nodes : %d ", countnode(start));
                 break;

            case 10 : exit(0);

            default : printf("\n\t!!Wrong choice.");
                      break;
      }
   }
}
