#include<stdio.h>

int main()
{
    int n,num;
    printf("Enter the total element of Array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Array:");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter any number:");
    scanf("%d",&num);
    for(int i = 0; i < n; i++){
        if(num == arr[i]){
            printf("The entered number is at %d element.",i);
        }
    }
    return 0;
}