#include<stdio.h>

int main()
{
    int n,m;
    printf("Enter the Length of Square:");
    scanf("%d", &n);

    printf("Enter the widgth of Square:");
    scanf("%d", &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}