1.We'll say a number is special if it is a multiple of 11 or if it is one more than a multiple of 11. Print “SPECIAL” if the given non-negative number is special. Use the % "mod" operator. #include<stdio.h>
int main(){
int n;
printf("enter the value");
scanf("%d",&n);
(n%11==0||n%11==1) ? printf("spcial"):printf("nothing");
}
