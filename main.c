#include <stdio.h>
#include "libftprintf.h"
#include <limits.h> 


int main()
{
	// printf("printf :%d\n",ft_printf("Test sans rien %% %c\n", '%'));
	// printf("printf :%d\n",printf("Test sans rien %% %c\n", '%'));

	// printf("printf :%d\n",ft_printf("Test avec un char : %-3c\n", 'A'));
	// printf("printf :%d\n",printf("Test avec un char : %-3c\n", 'A'));

	// char *svoid = (char *) NULL;
	// printf("printf :%d\n",ft_printf("Test avec un string : %-30.5s, %-.2s, %s, %-10.5s, %.6s\n", "Je suis un boss", "u", "", svoid, "MDR PHRASE DE FOU"));
	// printf("printf :%d\n",printf("Test avec un string : %-30.5s, %-.2s, %s, %-10.5s, %.6s\n", "Je suis un boss", "u", "", svoid, "MDR PHRASE DE FOU"));
	
	// printf("printf :%d\n",ft_printf("Test avec un string : %15.5s\n", "Je suis un boss"));
	// printf("printf :%d\n",printf("Test avec un string : %15.5s\n", "Je suis un boss"));

	// printf("printf :%d\n",ft_printf("Test avec string et char : %c%c%c%c%c%s !\n",'L','o','u','i','s'," est un boss"));
	// printf("printf :%d\n",printf("Test avec string et char : %c%c%c%c%c%s !\n",'L','o','u','i','s'," est un boss"));
	
	// printf("ft_printf :%d\n",ft_printf("Test de nombre %+.5d, %+-5.10d, %+01d, %+5.20d, %+20.5d, %-+20.5d \n",-15000, 0 ,214748, 15029, -06101, -06101));
	// printf("printf :%d\n",printf("Test de nombre %+.5d, %+-5.10d, %+01d, %+5.20d, %+20.5d, %-+20.5d \n", -15000, 0, 214748, 15029, -06101, -06101));
	// printf("ft_printf :%d\n",ft_printf("%.6d\n",  -15000));
	// printf("printf :%d\n",printf("%.6d\n", -15000));

	// printf("printf :%d\n",ft_printf("Test de nombre %% %% %#x, %#.5x,  %#-19X %% \n", 1658, 0 ,-214748));
	// printf("printf :%d\n",printf("Test de nombre %% %% %#X, %#.5x,  %#-19X %% \n", 1658, 0, -214748));

	// printf("printf :%d\n",ft_printf("Test de nombre %-15.10u, %05u, %20.13u\n",15000, 0 ,-214748));
	// printf("printf :%d\n",printf("Test de nombre %-15.10u, %05u, %20.13u\n", 15000, 0, -214748));

	// int	a;
	// int	b;
	// char	*str = "LOUIS";
	// printf("printf :%d\n",ft_printf("Test de pointeurs %% %% %p, %-25p, %17p = %s, %2p, %30p, %% \n", NULL, &a, &b, str, str, (void *) ULLONG_MAX));
	// printf("printf :%d\n",printf("Test de pointeurs %% %% %s, %-25p, %17p = %s, %2p, %30p, %% \n", "0x0", &a, &b, str, str, (void *) ULLONG_MAX));

	// printf("printf :%d\n",ft_printf(">%4d<\n", -12)); // > -12<
	// printf("printf :%d\n",printf(">%4d<\n", -12));

	// printf("printf :%d\n",ft_printf("%42.7X\n",30));
	// printf("printf :%d\n",printf("%42.7X\n",30));
	
	// printf("printf :%d\n",ft_printf("%42.5X\n",30));
	// printf("printf :%d\n",printf("%42.5X\n",30));

	// printf("printf :%d\n",ft_printf("%-42.7X\n",30));
	// printf("printf :%d\n",printf("%-42.7X\n",30));

	// printf("printf :%d\n",ft_printf("%2.5X\n",30));
	// printf("printf :%d\n",printf("%2.5X\n",30));

	// printf("printf :%d\n",ft_printf("%#012x \n", 42));
	// printf("printf :%d\n",printf("%#012x \n", 42));

	// printf("printf :%d\n",ft_printf(" NULL %10.6s NULL \n", (char *) NULL));
	// printf("printf :%d\n",printf(" NULL %10.6s NULL \n", (char *) NULL));

	// printf("printf :%d\n",ft_printf("%5p %5p\n", (void *) 0, (void *) 0));
	// printf("printf :%d\n",printf("%p %p\n", (void *) 0, (void *) 0));

	// printf("printf :%d\n",ft_printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 42, 42, 42, 42 ,42, "test"));
	// printf("printf :%d\n",printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 42, 42, 42, 42 ,42, "test"));

	// printf("printf :%d\n",ft_printf("%.u %.i %.d %.x %.X %.s\n", 42, 42, 42, 42 ,42, "test"));
	// printf("printf :%d\n",printf("%.u %.i %.d %.x %.X %.s\n", 42, 42, 42, 42 ,42, "test"));

	// printf("printf :%d\n",ft_printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 0, 0, 0, 0 ,0, "test"));
	// printf("printf :%d\n",printf("%.0u %.0i %.0d %.0x %.0X %.0s\n", 0, 0, 0, 0 ,0, "test"));

	return 0;
}