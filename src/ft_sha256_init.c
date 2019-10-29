/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 13:42:49 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/29 13:57:58 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

void	init_tab3(t_256 *tab)
{
	tab->k[40] = 0xa2bfe8a1;
	tab->k[41] = 0xa81a664b;
	tab->k[42] = 0xc24b8b70;
	tab->k[43] = 0xc76c51a3;
	tab->k[44] = 0xd192e819;
	tab->k[45] = 0xd6990624;
	tab->k[46] = 0xf40e3585;
	tab->k[47] = 0x106aa070;
	tab->k[48] = 0x19a4c116;
	tab->k[49] = 0x1e376c08;
	tab->k[50] = 0x2748774c;
	tab->k[51] = 0x34b0bcb5;
	tab->k[52] = 0x391c0cb3;
	tab->k[53] = 0x4ed8aa4a;
	tab->k[54] = 0x5b9cca4f;
	tab->k[55] = 0x682e6ff3;
	tab->k[56] = 0x748f82ee;
	tab->k[57] = 0x78a5636f;
	tab->k[58] = 0x84c87814;
	tab->k[59] = 0x8cc70208;
	tab->k[60] = 0x90befffa;
	tab->k[61] = 0xa4506ceb;
	tab->k[62] = 0xbef9a3f7;
	tab->k[63] = 0xc67178f2;
}

void	init_tab2(t_256 *tab)
{
	tab->k[16] = 0xe49b69c1;
	tab->k[17] = 0xefbe4786;
	tab->k[18] = 0x0fc19dc6;
	tab->k[19] = 0x240ca1cc;
	tab->k[20] = 0x2de92c6f;
	tab->k[21] = 0x4a7484aa;
	tab->k[22] = 0x5cb0a9dc;
	tab->k[23] = 0x76f988da;
	tab->k[24] = 0x983e5152;
	tab->k[25] = 0xa831c66d;
	tab->k[26] = 0xb00327c8;
	tab->k[27] = 0xbf597fc7;
	tab->k[28] = 0xc6e00bf3;
	tab->k[29] = 0xd5a79147;
	tab->k[30] = 0x06ca6351;
	tab->k[31] = 0x14292967;
	tab->k[32] = 0x27b70a85;
	tab->k[33] = 0x2e1b2138;
	tab->k[34] = 0x4d2c6dfc;
	tab->k[35] = 0x53380d13;
	tab->k[36] = 0x650a7354;
	tab->k[37] = 0x766a0abb;
	tab->k[38] = 0x81c2c92e;
	tab->k[39] = 0x92722c85;
	init_tab3(tab);
}

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
	tab->k[0] = 0x428a2f98;
	tab->k[1] = 0x71374491;
	tab->k[2] = 0xb5c0fbcf;
	tab->k[3] = 0xe9b5dba5;
	tab->k[4] = 0x3956c25b;
	tab->k[5] = 0x59f111f1;
	tab->k[6] = 0x923f82a4;
	tab->k[7] = 0xab1c5ed5;
	tab->k[8] = 0xd807aa98;
	tab->k[9] = 0x12835b01;
	tab->k[10] = 0x243185be;
	tab->k[11] = 0x550c7dc3;
	tab->k[12] = 0x72be5d74;
	tab->k[13] = 0x80deb1fe;
	tab->k[14] = 0x9bdc06a7;
	tab->k[15] = 0xc19bf174;
	init_tab2(tab);
}
