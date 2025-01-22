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
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == num){
                printf("(%d, %d)\n",arr[i], arr[j]);
            }
        }
    }
    return 0;
}