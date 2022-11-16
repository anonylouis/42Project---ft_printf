#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int a;

	//printf("%d\n%d\n", SPACE, PLUS);
	//printf("%s\n", ((char *[3]){"abcdef", "lol", "ppp"})[2]);

	//printf("%10.7d\n",12453);
	printf("%-35c\n",'A');

	char s[2];
	s[1] = 0;
	s[0] = 99;
	printf("%s\n", s);

	//printf("$%.5s\n","test");
	//printf("% u",452);
}