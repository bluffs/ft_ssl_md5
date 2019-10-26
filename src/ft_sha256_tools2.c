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
	tmp[i++] = (len >> 24) & 0xFF;
	tmp[i++] = (len >> 16) & 0xFF;
	tmp[i++] = (len >> 8) & 0xFF;
	tmp[i++] = (len >> 0) & 0xFF;
	return (tmp);
}
