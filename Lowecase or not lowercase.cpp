#include<stdio.h>

int main()
{
	char ch;
	printf("Enter character: ");
	scanf("%c",&ch);
	
	if((ch>=97) && (ch<=122)){
		printf("This character is lowercase\n");
	}
	else
	printf("This character is not lowercase\n");
	return 0;
}
