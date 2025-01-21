#include<stdio.h>

int ascending(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int temp = 0;
        for(int j = 0; j < n - i - 1;j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
}

int main()
{
    int n;
    printf("Enter the total element of array");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the element of array:");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("The Array is:");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    ascending(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n%d is second largest number in array",arr[n -2]);
    
}