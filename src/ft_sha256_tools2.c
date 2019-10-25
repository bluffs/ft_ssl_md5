#include "../inc/ssl.h"
#include <stdlib.h>
#include <stdio.h>

unsigned char		*ft_padding_sha256(char *str, int *size)
{
	unsigned char	*tmp;
	int				i;
	int				nb;
	int				len;

	len = ft_strlen(str);
	nb = 1;
	while (((len + nb) % 64) != 60)
		nb++;
	if (!(tmp = ft_memalloc((len + nb + 4) * 4)))
		exit(0);
	*size = len + nb + 4;
	i = -1;
	while (++i < len)
		tmp[i] = (unsigned char)(str[i]);
	tmp[i++] = 0b10000000;
	while (i < len + nb)
		tmp[i++] = 0;
	len *= 8;
	//printf("len = %d\n", len);
	//printf("i = %d\n", i);
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = (len >> 0) & 0xFF;
	{
		/*int n = 0;
		while (n <= 60)
		{
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 0]);
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 1]);
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 2]);
			printf("n = %d : %x\n", n / 4 + 1, (tmp)[n + 3]);
			n += 4;
		}*/
		int n = 0;
		while (n < 64)
		{
			ft_putnbr(n);
			ft_putstr(". ");
			ft_print_binary(&tmp[n * 4]);
			ft_putchar('\n');
			n++;
		}
		ft_putchar('\n');
	}
	return (tmp);
}
