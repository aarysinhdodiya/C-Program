#include<stdio.h>

void fun(int a[]){
    int temp;
    temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}

int main()
{
    int arr[2] = { 2, 4};

    printf("%d %d\n", arr[0], arr[1]);
    fun(arr);
    printf("%d %d\n", arr[0], arr[1]);
    return 0;
}