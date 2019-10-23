#include "../inc/ssl.h"

void	init_tab_sha256(t_256 *tab)
{
	tab->h0 = 0x6a09e667;
	tab->h1 = 0xbb67ae85;
	tab->h2 = 0x3c6ef372;
	tab->h3 = 0xa54ff53a;
	tab->h4 = 0x510e527f;
	tab->h5 = 0x9b05688c;
	tab->h6 = 0x1f83d9ab;
	tab->h7 = 0x5be0cd19;
}
