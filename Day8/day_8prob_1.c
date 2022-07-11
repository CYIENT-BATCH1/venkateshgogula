Write a program in C to sort an array using Pointer. The sample output must be as below.
algorithm
1.initialize a array
2.find the size of array.
3.Declare a varibles
4.using two for loops and compare the values using conditional statement


#include<stdio.h>
int main(){
int a[]={25,45,89,15,82};
int n=sizeof(a)/sizeof(a[0]);
int i=0,j=0,temp;
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(*(a+i)>*(a+j)){
            temp=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=temp;
        }
    }
}
for(i=0;i<n;i++){
    printf("%d ",*(a+i));
}
}
