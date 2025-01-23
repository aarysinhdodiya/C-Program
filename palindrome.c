#include<stdio.h>

int main()
{
    int n,count = 0;

    printf("Enter the Total element of array:");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Enter the %d element of array:", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Your array is: \n");

    for(int i = 0; i < n; i++){
       printf("%d ", arr[i]);
    }

    for(int i = 0; i < (n/2); i++){
        if(arr[i] == arr[n-i-1]){
            count++;
        }
    }
    if(count == (n/2)){
        printf("\nThis array is palindrome.");
    }
    else{
        printf("\nThis array is not palindrome.");
    }
    return 0;
}