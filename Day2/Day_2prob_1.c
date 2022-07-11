//Consider the phone number of a person as user input and find the sum of its digits. 
#include<stdio.h>
int main(){
    long int n,sum=0,x;
    printf("enter value");
    scanf("%ld",&n);
    while(n>0){
        x=n%10
        n=n/10;
        sum=sum+x;
    }
    printf("%ld",sum);
}
