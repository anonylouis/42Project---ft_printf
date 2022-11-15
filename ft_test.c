#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

# define reset "\033[0;00m"
# define red "\033[1;31m"
# define italic "\033[3m"

int main()
{
	printf("%sTEST %%%s\n\n", red, reset);
	
	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec un %%\n"), reset);
	printf("%sprintf:    %d%s\n",italic,     printf("Test avec un %%\n"), reset);

	printf("\n");

	printf("%sTEST %%%c%s\n\n", red, 'c', reset);
	printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec des char : %c, %-3c, %c\n", 'A', 'B', 'C'), reset);
	printf("%sprintf:    %d%s\n",italic,     printf("Test avec des char : %c, %-3c, %c\n", 'A', 'B', 'C'), reset);

	// char *svoid = (char *) NULL;
	// printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec un string : %-30.5s, %-.2s, %s, %-10.5s, %.6s\n", "Je suis un boss", "u", "", svoid, "MDR PHRASE DE FOU"), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test avec un string : %-30.5s, %-.2s, %s, %-10.5s, %.6s\n", "Je suis un boss", "u", "", svoid, "MDR PHRASE DE FOU"), reset);
	
	// printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec un string : %15.5s\n", "Je suis un boss"), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test avec un string : %15.5s\n", "Je suis un boss"), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("Test avec string et char : %c%c%c%c%c%s !\n",'L','o','u','i','s'," est un boss"), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test avec string et char : %c%c%c%c%c%s !\n",'L','o','u','i','s'," est un boss"), reset);
	
	// printf("ft_printf :%d\n",ft_printf("Test de nombre %+.5d, %+-5.10d, %+01d, %+5.20d, %+20.5d, %-+20.5d \n",-15000, 0 ,214748, 15029, -06101, -06101), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test de nombre %+.5d, %+-5.10d, %+01d, %+5.20d, %+20.5d, %-+20.5d \n", -15000, 0, 214748, 15029, -06101, -06101), reset);
	// printf("ft_printf :%d\n",ft_printf("%.6d\n",  -15000), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%.6d\n", -15000), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("Test de nombre %% %% %#x, %#.5x,  %#-19X %% \n", 1658, 0 ,-214748), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test de nombre %% %% %#X, %#.5x,  %#-19X %% \n", 1658, 0, -214748), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("Test de nombre %-15.10u, %05u, %20.13u\n",15000, 0 ,-214748), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test de nombre %-15.10u, %05u, %20.13u\n", 15000, 0, -214748), reset);

	// int	a;
	// int	b;
	// char	*str = "LOUIS";
	// printf("%sft_printf: %d%s\n", italic, ft_printf("Test de pointeurs %% %% %p, %-25p, %17p = %s, %2p, %30p, %% \n", NULL, &a, &b, str, str, (void *) ULLONG_MAX), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("Test de pointeurs %% %% %s, %-25p, %17p = %s, %2p, %30p, %% \n", "0x0", &a, &b, str, str, (void *) ULLONG_MAX), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf(">%4d<\n", -12), reset); // > -12<
	// printf("%sprintf:    %d%s\n",italic,     printf(">%4d<\n", -12), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%42.7X\n",30), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%42.7X\n",30), reset);
	
	// printf("%sft_printf: %d%s\n", italic, ft_printf("%42.5X\n",30), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%42.5X\n",30), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%-42.7X\n",30), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%-42.7X\n",30), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%2.5X\n",30), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%2.5X\n",30), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%#012x \n", 42), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%#012x \n", 42), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf(" NULL %10.6s NULL \n", (char *) NULL), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf(" NULL %10.6s NULL \n", (char *) NULL), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%5p %5p\n", (void *) 0, (void *) 0), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%p %p\n", (void *) 0, (void *) 0), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 42, 42, 42, 42 ,42, "test"), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 42, 42, 42, 42 ,42, "test"), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%.u %.i %.d %.x %.X %.s\n", 42, 42, 42, 42 ,42, "test"), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%.u %.i %.d %.x %.X %.s\n", 42, 42, 42, 42 ,42, "test"), reset);

	// printf("%sft_printf: %d%s\n", italic, ft_printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 0, 0, 0, 0 ,0, "test"), reset);
	// printf("%sprintf:    %d%s\n",italic,     printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 0, 0, 0, 0 ,0, "test"), reset);

	return 0;
}