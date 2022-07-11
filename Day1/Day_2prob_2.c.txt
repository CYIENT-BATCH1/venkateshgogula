2.Consider a character input from a user and print if it is a vowel or consonant.



#include<stdio.h>
int main(){
char a;
printf("enter the value");
scanf("%c",&a);
(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') ? printf("vowels"):printf("consonant");
}
