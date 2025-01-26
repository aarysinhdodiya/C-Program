#include<stdio.h>

int main()
{
    int n, a = 0, b = 0, c;
    printf("Enter the total element of Array:");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Array:");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }   
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                a++;
            }
            if(b < a){
                b = a;
                c = arr[i];
            }
        }
    } 
    printf("%d is the majority element in the Array.", c);
    return 0;
}