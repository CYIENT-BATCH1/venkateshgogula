Find empty strings in an array of strings (Array of strings will be given as input to program) and print the position of array where
 empty string is present. And replace the empty string array element as “CYIENT”.


Algorithm:
1.Take a one array of string and define size of the array string
2.Declare the variables
3.Depending upon size you have to give iterations and you have to find out which position you want
4.When the position of array where
 empty string is present and replace the empty string array element as “CYIENT”.
5.Print the o/p as CYIENT.
#include <stdio.h>
int main()
{
    char *arr[]={"vicky","anil","krishna","pinky","   ","siva"};
    int n=sizeof arr/sizeof(arr[0]);
    int pos=1;
    printf("%d",n);
    int i,j,k,count=0;
    for(i=0;i<5;i++){
        printf("\n");
        if(arr[i]=="   "){
            pos=pos+4;
            arr[i]="cyient";
        }
    printf("%s ",*(arr+i));
    }
    printf("\n");
     printf("pos=%d\n",pos);
    return 0;
}


