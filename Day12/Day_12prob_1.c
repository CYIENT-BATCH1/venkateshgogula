Find common elements in three sorted arrays, 3 array values are given as input to program.

Algorithm:
1.To declare the three sorted arrays and find each size of an array
2.To instilize the variables
3.Compare the three arrays 
  -->by using while loop
  -->By using conditional statements(if elseif .. else)
4.Find the common numbers in given 3 arrays.

int main()
{
    int arr1[] = { 1,2,3,5,7,11,13,17,19};
    int arr2[] = { 1,2,4,8,16,32,64,128 };
    int arr3[] = { 1,2,17,19,45,46,93,53 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("The common elements are:");
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            printf("%d ", arr1[i]);
            i++;
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr3[k])
            j++;
        else
            k++;
    }


    printf(" ");
    //findCommon(arr1, arr2, arr3, n1, n2, n3);
    return 0;
