#include<stdio.h>
#include<stdlib.h>

void selection();
void insertion();
void shell();
void bubble();
void quick();
void merge();
void heap();

void merge_sub_array(int a[],int i1,int j1,int i2,int j2);
void merge_sort(int a[],int i,int j);
void heapify(int a[],int n);
void adjust(int a[],int n);

int main()
{
    int choice;
    while(1)
    {
            printf("\n\t\t\t\t************************");
            printf("\n\t\t\t\t| ALL SORTING PROGRAMS  |");
            printf("\n\t\t\t\t************************");
            printf("\n\t--------------------------------------------------------------------------");
            printf("\n\t| 1.Selection Sort");
            printf("\t\t\t\t\t2.Insertion Sort |");
            printf("\n\t| 3.Shell Sort");
            printf("\t\t\t\t\t\t4.Bubble Sort    |");
            printf("\n\t| 5.Quick Sort");
            printf("\t\t\t\t\t\t6.Merge Sort     |");
            printf("\n\t| 7.Heap Sort");
            printf("\t\t\t\t\t\t8.Exit           |");
            printf("\n\t--------------------------------------------------------------------------");
            printf("\n\n\tEnter your choice : ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: selection();
                        break;
                case 2: insertion();
                        break;
                case 3: shell();
                        break;
                case 4: bubble();
                        break;
                case 5: quick();
                        break;
                case 6: merge();
                        break;
                case 7: heap();
                        break;
                case 8: exit(0);
                        break;
                default: printf("\n\tWrong choice\n");
                        break;
            }
    }

    return 0;
}

void selection()
{
    int n,i,j,k,temp=0;
    printf("\n\tEnter no. of elements that you want to sort : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    for(j=0;j<n;j++)
    {
        for(k=j;k<n;k++)
        {
            if(a[j]<a[k])
            {
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
            }
        }
    }
    printf("\n\tSelection_Sorted Elements in ascending order :-> ");
    for(i=0;i<n;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void insertion()
{
    int i,j,n,temp=0;
    printf("\n\tEnter the no. of elements that you want to sort : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("\n\tInsertion_Sorted Elements in ascending order :-> ");
    for(i=0;i<n;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void shell()
{
    int i,j,k,num,tmp;
    printf("\n\tEnter the no. of elements that you want to sort : ");
    scanf("%d",&num);
    int a[num];
    for(i=0;i<num;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j=i;j<num;j++)
        {
            for(k=j-i;k>=0;k=k-i)
            {
                if (a[k+i] >= a[k])
                    break;
                else
                {
                    tmp = a[k];
                    a[k] = a[k+i];
                    a[k+i] = tmp;
                }
            }
        }
    }
    printf("\n\tShell_Sorted Elements in ascending order :-> ");
    for(i=0;i<num;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void bubble()
{
    int i,j,n,temp=0;
    printf("\n\tEnter the no. of elements that you want to sort : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\n\tBubble_Sorted Elements in ascending order :-> ");
    for(i=0;i<n;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void quicksort(int a[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
         pivot=first;
         i=first;
         j=last;

         while(i<j)
        {
             while(a[i]<=a[pivot]&&i<last)
                 i++;
             while(a[j]>a[pivot])
                 j--;
             if(i<j)
            {
                 temp=a[i];
                  a[i]=a[j];
                  a[j]=temp;
             }
         }

         temp=a[pivot];
         a[pivot]=a[j];
         a[j]=temp;
         quicksort(a,first,j-1);
         quicksort(a,j+1,last);

    }
}
void quick()
{
    int n,i;
    printf("\n\tEnter the no. of elements that you want to sort : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("\n\tQuick_Sorted Elements in ascending order :-> ");
    for(i=0;i<n;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void merge_sort(int a[],int i,int j)
{
    int mid;

    if(i<j)
    {
        mid=(i+j)/2;
        merge_sort(a,i,mid);
        merge_sort(a,mid+1,j);
        merge_sub_array(a,i,mid,mid+1,j);
    }
}

void merge_sub_array(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;

    while(i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)
        temp[k++]=a[i++];

    while(j<=j2)
        temp[k++]=a[j++];

    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

void merge()
{
    int n,i;
    printf("\n\tEnter the no. of elements that you want to sort : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    merge_sort(a,0,n-1);
    printf("\n\tMerge_Sorted Elements in ascending order :-> ");
    for(i=0;i<n;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void heap()
{
    int n,i,t;
    printf("\n\tEnter the no. of elements that you want to sort : ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("\n\tEnter the %d Element : ",i+1);
        scanf("%d",&a[i]);
    }
    heapify(a,n);

     for(i=n-1;i>0;i--)
     {
          t = a[0];
          a[0] = a[i];
          a[i] = t;
          adjust(a,i);
     }
    printf("\n\tHeap_Sorted Elements in ascending order :-> ");
    for(i=0;i<n;i++)
    {
        printf(" %d  ",a[i]);
    }
    printf("\n");
}

void heapify(int a[],int n)
{
     int k,i,j,item;
     for(k=1;k<n;k++)
     {
        item = a[k];
        i = k;
        j = (i-1)/2;
      while((i>0)&&(item>a[j]))
      {
        a[i] = a[j];
        i = j;
        j = (i-1)/2;
      }
      a[i] = item;
     }
}

void adjust(int a[],int n)
{
     int i,j=0,item;
     item = a[j];
     i = 2*j+1;

     while(i<=n-1)
     {
       if(i+1 <= n-1)
         if(a[i] <a[i+1])
           i++;
       if(item<a[i])
       {
         a[j] = a[i];
         j = i;
         i = 2*j+1;
       }
       else
          break;
     }
     a[j] = item;
}

