#include<stdio.h>

int main()
{
	int length , width , area;
	
	printf("Enter length of triangle \n",length);
	scanf("%d",&length);
	
	printf("Enter width of triangle \n",width);
	scanf("%d",&width);
	
	area = length * width;
	
	printf("The area of triangle is %d",area);
	return 0;
}
