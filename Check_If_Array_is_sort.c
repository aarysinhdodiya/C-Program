#include<stdio.h>

int main()
{
    int n,a = 0;

    printf("Enter the total element of Array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Array:");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i =0; i < n; i++){
        if(arr[i] > arr[i + 1]){
            a++;
        }
    }
    if(a == 0){
        printf("The Array is Sort in Ascending Order.");
    }
    else{
        printf("The Array is not Sort in Ascending Order.");
    }
    return 0;
}