4) GIVEN NUMBER IS POWER OF 2 OR NOT
#include <stdio.h>



int main() {
int n;
printf("enter the value");
scanf("%d",&n);
((n&n-1)==0)?printf("power"):printf("not");

return 0;
}
