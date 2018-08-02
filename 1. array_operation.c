#include<stdio.h>
#include<process.h>
void traverse();
void insert();
void del();
void search();
void sort();
void exit();
int n,i=0,a[10];
int main()
{
	int choice;
	do{
		printf("\n\n\t!!!!!!!!!!!    Array Operations    !!!!!!!!!!!!!\n");
		printf("\n\n 1.Traverse\n 2.Insert\n 3.Delete\n 4.Search\n 5.Sort\n 6.Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		      case 1:	traverse();
                        break;
		      case 2:   insert();
                        break;
		      case 3:   del();
                        break;
		      case 4:   search();
                        break;
		      case 5:   sort();
                        break;
		      case 6:   exit(0);
                        break;
		      default:  printf("\n\n\tYou have enter wrong choice");
                        break;
	     }
     }while(choice!=6);
   return 0;
}
void traverse()
{
    int j;
    printf("\nElement stores in an array :\n ");
    if(i==0)
        printf("\nArray is empty ");
    for(j=0;j<i;j++)
    {
        printf("\t\t\t\ta[%d] = %d \n",j,a[j]);
    }
}

void insert()
{
    printf("\nInsert an element : ");
    scanf("%d",&n);
    a[i]=n;
    i++;
}

void del()
{
    int j;
    printf("\nElements stores in array after deletion : \n");
    if(i==0)
    {
        printf("\nArray is empty");
    }
    for(j=0;j<(i-1);j++)
    {
        printf("\t\t\t\t\ta[%d] = %d \n",j,a[j]);
    }
}

void search()
{
    int item,j;
    printf("\nEnter the elements that you want to search : ");
    scanf("%d",&item);
    for(j=0;j<i;j++)
    {
        if(item==a[j])
        {
            printf("\nSearch successful i.e Element found at a[%d]",j);
            break;
        }
    }

        if(item!=a[j])
            printf("\nSearch unsuccessful i.e element not found ");
}

void sort()
{
    if(i==0)
        printf("\nArray is empty");
    printf("\nElement after sorting : \n");
    int j,k,temp;
    for(j=0;j<i;j++)
    {
        for(k=j+1;k<i;k++)
        {

            if(a[j] > a[k])
            {
                temp   = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
        }
        printf("\t\t\ta[%d] = %d \n",j,a[j]);
     }

}





