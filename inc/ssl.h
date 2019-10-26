/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:07:26 by jyakdi            #+#    #+#             */
/*   Updated: 2019/10/26 16:41:20 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SSL_H
# define __SSL_H

# include "../libft/libft.h"

typedef struct	s_var
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
}				t_var;

typedef struct	s_256
{
	unsigned int				h0;
	unsigned int				h1;
	unsigned int				h2;
	unsigned int				h3;
	unsigned int				h4;
	unsigned int				h5;
	unsigned int				h6;
	unsigned int				h7;
	unsigned int				a;
	unsigned int				b;
	unsigned int				c;
	unsigned int				d;
	unsigned int				e;
	unsigned int				f;
	unsigned int				g;
	unsigned int				h;
	unsigned int				t1;
	unsigned int				t2;	
	unsigned int				k[64];
}				t_256;

typedef struct	s_elem
{
	char						*str;
	char						*hash;
	struct s_elem				*next;
}				t_elem;

void			ft_do_cmd(int argc, char **argv);
void			ft_error_cmd(char *str);
void			md5(int argc, char **argv, int i, int files);
void			sha256(int argc, char **argv, int i, int files);
t_elem			*ft_create_elem(char *str, t_elem *begin);
int				ft_read_file(char *file, char **finalstr, char *str, int fd);
char			*ft_hash_md5(char *str, int i, int j);
char			*ft_hash_sha256(char *str, int i, int j);
void			init_tab(t_var *tab);
void			init_tab_sha256(t_256 *tab);
void			ft_usage(char c);
void			ft_usage_sha256(char c);
char			ft_itoh(unsigned int nb);
unsigned char	*ft_padding(char *str, int *size);
unsigned char	*ft_padding_sha256(char *str, int *size);
unsigned int	*ft_chunk(unsigned char *str, t_var *tab);
void			ft_no_file(char *file);
void			ft_print_file_md5(char *str, char *hash, int flag);
void			ft_print_md5(char *str, char *hash, int flag);
void			ft_print_file_sha256(char *str, char *hash, int flag);
void			ft_print_sha256(char *str, char *hash, int flag);
int				ft_flag_check(char **argv, int i, int *p_flag, int *qr_flag);
char			*ft_final_print(t_var *tab);
void			ft_reverse(unsigned int num, char *hash, int start);
void			ft_print_binary(unsigned char *str);
unsigned int	ft_get_unsigned(unsigned char *str);
void			ft_set_unsigned(unsigned char *str, unsigned int nb);
unsigned int	ft_big_sigma_zero(unsigned int x);
unsigned int	ft_big_sigma_one(unsigned int x);
unsigned int	ft_small_sigma_zero(unsigned int x);
unsigned int	ft_small_sigma_one(unsigned int x);
unsigned int 	ft_ch(unsigned int x, unsigned int y, unsigned int z);
unsigned int	ft_maj(unsigned int x, unsigned int y, unsigned int z);
void			ft_sha_to_hex(unsigned int num, char *hash, int start);

#endif
