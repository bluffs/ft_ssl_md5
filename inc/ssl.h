/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:07:26 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/08 18:19:03 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H__
#define SSL_H__

#include "../libft/libft.h"

typedef struct					s_var
{
	int							r[64];
	unsigned int				k[64];
	unsigned int				h0;
	unsigned int				h1;
	unsigned int				h2;
	unsigned int				h3;
	unsigned int				a;
	unsigned int				b;
	unsigned int				c;
	unsigned int				d;
	unsigned int				tmp;
}								t_var;

typedef struct					s_elem
{
	char						*str;
	char						*hash;
	struct	s_elem				*next;
}								t_elem;

void			ft_do_cmd(int argc, char **argv);
void			ft_error_cmd(char *str);
void			md5(int argc, char **argv);
t_elem			*ft_create_elem(char *str, t_elem *begin);
char			*ft_read_file(char *file);
char			*ft_hash_md5(char *str, int i, int j);
void			init_tab(t_var *tab);
void			ft_usage(void);
char			ft_itoh(unsigned int nb);
unsigned char	*ft_padding(char *str, int *size);
unsigned int	*ft_chunk(unsigned char *str, t_var *tab);

#endif
