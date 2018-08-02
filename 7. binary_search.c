#include <stdio.h>

int RecursiveBinarySearching(int arr[], int low, int high, int element)
{
      int middle;
      if(low > high)
        {
            return -1;
        }

      middle = (low + high) / 2;

      if(element > arr[middle])
        {
            RecursiveBinarySearching(arr, middle + 1, high, element);
        }
      else if(element < arr[middle])
        {
            RecursiveBinarySearching(arr, low, middle - 1, element);
        }
      else
        {
            return middle;
        }
}

int main()
{
      int count, element,size, arr[50], position;
      printf("\n Enter the size of Array : ");
      scanf("%d", &size);
      printf("\n Enter %d Elements in Array: \n", size);
      for(count = 0; count < size; count++)
        {
            scanf("%d", &arr[count]);
        }
      printf("\n Elements stored in an array : ");
      for(count = 0; count < size; count++)
        {
            printf("\n\t\t\t\ta[%d] = %d\n",count,arr[count]);
        }
      printf("\n Enter Element To Search :  \t");
      scanf("%d", &element);
      position = RecursiveBinarySearching(arr, 0, size-1, element);
      if(position == -1)
        {
            printf("\n Element %d Not Found i.e (Search unsuccessful)\n", element);
        }
      else
        {
            printf("\n Element %d Found at Position a[%d] i.e (Search successful)\n", element, position);
        }
      return 0;
}
