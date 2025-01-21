#include<stdio.h>

int swap(int a[], int n){
    for(int i = 0; i <= n/2; i++){
        int temp = 0;
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

int main()
{
    int n; 
    
    printf("Enter the total element of an array:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the element of Array:");

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    swap(arr, n);
    
    return 0;
}