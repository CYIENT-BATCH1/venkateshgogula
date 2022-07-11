Write a program to Implement ”Selection Sort” using Recursion for given elements (Number elements will vary, so make it as configurable item)
How Selection sort works is explained below.

Algorithm:
1.We can use recursion depending our requirement and Declare the variables
2.Take i/p from user
3.Now you go for selection sort 
  -->By using iterations(for) you have to compare present and past values until desired ascending order
   -->swap the array(arr[i] and arr[j])
4.Go to main function and find after sort Array elements.
5.To see o/p as ascending order.
#include<stdio.h>
void sortarrayelement(int arr[], int num)
{
    int i,j;
    if(num>0)
    {
    int i,j,temp;
     for(j=0;arr[j];j++)
    {
    for(i=j+1;arr[i];i++)
    {
        if(arr[i]<arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    }
}
}
int main()
{
    int num=5,i;
    int arr[num];
    printf("Enter the Array Element:");
    for(i=0;i<num;i++)
    {
        scanf("%d",&arr[i]);
    }
    sortarrayelement(arr,num);
    printf("After sort Array Elements are:");
    int j;
    for (j=0; j< num; j++)
     printf("%d ", arr[j]);
    return 0;
}

