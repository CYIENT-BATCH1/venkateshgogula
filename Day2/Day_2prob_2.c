#include<stdio.h>
int main(){
    int i, x,a;
    printf("enter value");
    scanf("%d",&a);
    for(i=7;i>=0;i--){
        x=(a>>i)&1;
        printf("%d",x);
    }
}
