#include<stdio.h>

int main()
{
    int n,num, j = 0;;
    printf("Enter the total element of Array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Array:");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the number:");
    scanf("%d",&num);

    for(int i = 0; i < n; i++){
        if(arr[i] == num){
            j++;
        }
    }
    printf("%d is appear %d times in the array.",num,j);
    return 0;
}