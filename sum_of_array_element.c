#include<stdio.h>

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5}, sum = 0;

    for(int i = 0; i < 5; i++){
        sum += arr[i];
    }
    printf("The sum of given array's element is %d", sum);
    return 0;
}