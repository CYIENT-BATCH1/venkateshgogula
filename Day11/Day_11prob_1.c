13.Write a program to do binary search in a sorted array. Program should take input of sorted values and search value. 
(Make number of elements as configurable value)

How binary search works is explained below.
Algorithm:
>>Accept the stored data 
>>Accept the serch value
>>size of array/2
>>Get the value of x=array[size of array/2]
>>serch value > x
>>size of array-x
>>push array data to (size of array /2)+1
>>Repeat the steps 3 to 6 untill you found the value.



#include<stdio.h>
int binarySearch(int array[], int x, int low, int high) {
 // Repeat the loop until low and medium meet each other
 while(low<=high) {
 int mid=low+(high-low)/2;
 if(array[mid]==x)
 return mid;
 if(array[mid]<x)
 low=mid+1;
 else
 high=mid-1;
 }
 return 0;
}
int main(void) {
 int array[11]={1,5,7,11,13,17,19,23,27,29,31};
int n=sizeof(array)/sizeof(array[0]);
printf("Enter the elements:");
/*for(int i=0;i<n;i++){
scanf("%d",&array[i]);*/
 //int n=sizeof(array)/sizeof(array[0]);
 int x=9;//serching 9 (in given array present or not)
 int result=binarySearch(array,x,0,n-1);//go to 2nd line as binary serch
 if(result==0)
 printf("Not found");
else
 printf("Element is found at index %d", result);
 return 0;
}
