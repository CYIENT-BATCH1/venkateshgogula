7.Find whether a given 10-digit number is palindrome or not. (HINT: Any number is said to be a palindrome if the original number and the reverse of the original number are the same.)





#include<stdio.h>
int main(){
int n,num,rev=0;
printf("enter the value");
scanf("%d",&n);
while(n>0){
int temp=n;
num=n%10;
rev=rev*10+num;
n=n/10;
}
if(rev==temp)
printf("the given no is palindrome);
else
printf("the given no is not palindrome);
}
