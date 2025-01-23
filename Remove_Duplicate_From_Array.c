#include<stdio.h>

int main()
{
    int n;
    printf("Enter the total element of Array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Array:");
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                for(int k = j; k < n; k++){
                    arr[j] = arr[j + 1];
                }
                n--;
                i--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}