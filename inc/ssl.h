/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:07:26 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/10 11:45:22 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H__
#define SSL_H__

#include "../libft/libft.h"

typedef struct			s_elem
{
	char				*str;
	struct	s_elem		*next;
}						t_elem;

void		ft_do_cmd(int argc, char **argv);
void		ft_error_cmd(char *str);
void		md5(int argc, char **argv);
t_elem		*ft_create_elem(char *str, t_elem *begin);
t_elem		*ft_readFile(char* file, t_elem *begin);
char		*ft_hash_md5(char *str);

#endif
