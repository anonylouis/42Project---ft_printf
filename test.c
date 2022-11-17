#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

# define reset "\033[0;00m"
# define red "\033[1;31m"
# define italic "\033[3m"

int main()
{
	printf("%sTEST %%%s\n\n", red, reset);
	
	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec un %%|\n"), reset);
	printf("%sprintf:    %d%s\n", italic,     printf("Test avec un %%|\n"), reset);

	printf("\n");

	printf("%sTEST %%%c%s\n\n", red, 'c', reset);
	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec des char : %c, %-3c, %5c|\n", 'A', 'B', 1091), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("Test avec des char : %c, %-3c, %5c|\n", 'A', 'B', 1091), reset);

	printf("\n");

	printf("%sTEST %%%c%s\n\n", red, 's', reset);
	
	char *svoid = NULL;
	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec des string : %s, %-10.5s, %-.2s, %s, %-10.5s, %.6s, %15.20s|\n", "basic", "phraseunpeulongue", "courte", "", svoid, "PHRASEDEFOU", "JeSuisUnBoss"), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("Test avec des string : %s, %-10.5s, %-.2s, %s, %-10.5s, %.6s, %15.20s|\n", "basic", "phraseunpeulongue", "courte", "", svoid, "PHRASEDEFOU", "JeSuisUnBoss"), reset);
	
	printf("\n");

	printf("%sTEST %%%s%s\n\n", red, "d/i", reset);

	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec des ints : %+.5d, %+-5.10i, %+01d, %+5.20i, %+20.7d, %-+20.5i, %.6d, % 05i, %+05d|\n",-15000, 1 ,214748, 15029, -06101, -06101, -15000, 4, 2), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("Test avec des ints : %+.5d, %+-5.10i, %+01d, %+5.20i, %+20.7d, %-+20.5i, %.6d, % 05i, %+05d|\n",-15000, 1 ,214748, 15029, -06101, -06101, -15000, 4, 2), reset);

	printf("\n");

	printf("%sTEST %%%s%s\n\n", red, "x/X", reset);

	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avc des hexas : %x, %#x, %#.5x, %#-19X, %10.5x, %5.10X, %#12x|\n", 424242, 1658, 2 ,-214748, 2121, 1919, 33), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("Test avc des hexas : %x, %#x, %#.5x, %#-19X, %10.5x, %5.10X, %#12x|\n", 424242, 1658, 2 ,-214748, 2121, 1919, 33), reset);

	printf("\n");

	printf("%sTEST %%%c%s\n\n", red, 'u', reset);

	printf("%sft_printf: %d%s\n", italic, ft_printf("Test d'unsigned int : %-15.10u, %05u, %20.17u|\n", 15000, 0 ,-214748), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("Test d'unsigned int : %-15.10u, %05u, %20.17u|\n", 15000, 0, -214748), reset);

	printf("\n");

	printf("%sTEST %%%c%s\n\n", red, 'p', reset);

	int	a;
	int	b;
	char	*str = "LOUIS";
	printf("%sft_printf: %d%s\n", italic, ft_printf("Test de pointeurs : %-p, %-25p, %17p = %s, %2p, %30p|\n", NULL, &a, &b, str, str, (void *) ULLONG_MAX), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("Test de pointeurs : %-p, %-25p, %17p = %s, %2p, %30p|\n", NULL, &a, &b, str, str, (void *) ULLONG_MAX), reset);

	printf("%sOTHER TESTS %s\n", red, reset);

	printf("\ntest 1: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf(">%4d<\n", -12), reset);
	printf("%sprintf:    %d%s\n", italic,    printf(">%4d<\n", -12), reset);

	printf("\ntest 2: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%42.7X\n",30), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%42.7X\n",30), reset);
	
	printf("\ntest 3: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%42.5X\n",30), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%42.5X\n",30), reset);

	printf("\ntest 4: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%-42.7X\n",30), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%-42.7X\n",30), reset);

	printf("\ntest 5: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%2.5X\n",30), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%2.5X\n",30), reset);

	printf("\ntest 6: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%#012x \n", 42), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%#012x \n", 42), reset);

	printf("\ntest 7: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf(" NULL %10.6s NULL \n", svoid), reset);
	printf("%sprintf:    %d%s\n", italic,    printf(" NULL %10.6s NULL \n", svoid), reset);

	printf("\ntest 8: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%5p %5p\n", (void *) 0, (void *) 0), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%p %p\n", (void *) 0, (void *) 0), reset);

	printf("\ntest 9: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 42, 42, 42, 42 ,42, "test"), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 42, 42, 42, 42 ,42, "test"), reset);

	printf("\ntest 10: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%.u %.i %.d %.x %.X %.s\n", 42, 42, 42, 42 ,42, "test"), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%.u %.i %.d %.x %.X %.s\n", 42, 42, 42, 42 ,42, "test"), reset);

	printf("\ntest 11: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%10.u/%10.0i %10.0d %10.0x %10.0X %10.0s|\n", 0, 1, 2, 3, 4, "test"), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%10.u/%10.0i %10.0d %10.0x %10.0X %10.0s|\n", 0, 1, 2, 3, 4, "test"), reset);

	printf("\ntest 12: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf(" NULL %10.4s NULL \n", svoid), reset);
	printf("%sprintf:    %d%s\n", italic,    printf(" NULL %10.4s NULL \n", svoid), reset);

	printf("\ntest 13: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf(" NULL %10.6s NULL \n", svoid), reset);
	printf("%sprintf:    %d%s\n", italic,    printf(" NULL %10.6s NULL \n", svoid), reset);

	printf("\ntest 14: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%.s\n", "test"), reset);
	printf("%sprintf:    %d%s\n", italic,    printf("%.s\n", "test"), reset);

	printf("\ntest 15: \n");
	ft_printf("%.4i, %.2i, %.20i, %.0i, %.0i, %.i, %.i, %.i\n", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);
	   printf("%.4i, %.2i, %.20i, %.0i, %.0i, %.i, %.i, %.i\n", 127, 0, 1023, 0, (int)-2147483648, 0, 1, (int)-2147483648);
	
	printf("\ntest 16: \n");
	printf("%sft_printf: %d%s\n", italic, ft_printf("%c%c%c*|\n", '\0', '1', 1), reset);
	printf("%sft_printf: %d%s\n", italic,    printf("%c%c%c*|\n", '\0', '1', 1), reset);
	
	printf("\n%sLIMITS TESTS %s\n\n", red, reset);

	ft_printf("int : %d, %i, %i, %d\n", INT_MAX, INT_MIN, INT_MAX + 1, INT_MIN - 1);
	   printf("int : %d, %i, %i, %d\n", INT_MAX, INT_MIN, INT_MAX + 1, INT_MIN - 1);
	
	ft_printf("unsigned int : %u, %u, %u, %u\n", UINT_MAX, 0 , UINT_MAX + 1, -1);
	   printf("unsigned int : %u, %u, %u, %u\n", UINT_MAX, 0 , UINT_MAX + 1, -1);

	ft_printf("hexa : %x, %X, %x, %X\n", UINT_MAX, 0 , UINT_MAX + 1, -1);
	   printf("hexa : %x, %X, %x, %X\n", UINT_MAX, 0 , UINT_MAX + 1, -1);

	ft_printf("pointer: %p, %p, %p, %p\n", (void *) ULLONG_MAX, (void *) 0 , (void *) ULLONG_MAX + 1, (void *) -1);
	   printf("pointer: %p, %p, %p, %p\n", (void *) ULLONG_MAX, (void *) 0 , (void *) ULLONG_MAX + 1, (void *) -1);

	ft_printf("null = %s\n", svoid);
	   printf("null = %s|\n", svoid);

	ft_printf("%----c, i%---c, p%4c, s%--11c, x\n", 'a', 'b', 'c', 'd');
	   printf("%----c, i%---c, p%4c, s%--11c, x\n", 'a', 'b', 'c', 'd');
	
	ft_printf("|%03.d|\n", 0);
	   printf("|%03.d|\n", 0);

	ft_printf("%042.2d|\n", 42000);
	   printf("%042.2d|\n", 42000);

	ft_printf("%#x\n", 0);
	   printf("%#x\n", 0);

	printf("\n%sCRASH TESTS %s\n\n", red, reset);

	ft_printf(NULL);
	ft_printf("");
	ft_printf("With nothing\n\n");
	
	ft_printf("|non existant conversion : %k%@: end|\n");
	   printf("|non existant conversion : %k%@: end|\n");


	return 0;
}