/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:01:25 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/17 14:05:10 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ssl.h"

void	md5(int argc, char **argv)
{
	//if -p do it instantly
	//read options (q r) for printing mode
	//chained list with all strings and file contents
	//if chained list is empty and no -p read on stdin
	int	i;
	int pFlag;
	int qFlag;
	int rFlag;
	int	files;
	
	t_elem	*begin;
	begin = NULL;
	files = 0;
	pFlag = 0;
	qFlag = 0;
	rFlag = 0;
	i = 2;
	while (i < argc)
	{
		//ft_putendl(argv[i]);
		if (files == 0 && ft_strcmp(argv[i], "-p") == 0)
			pFlag++;
		else if (files == 0 && ft_strcmp(argv[i], "-q") == 0)
			qFlag = 1;
		else if (files == 0 && ft_strcmp(argv[i], "-r") == 0)
			rFlag = 1;
		else if (files == 0 && ft_strcmp(argv[i], "-s") == 0)
		{
			if (i + 1 < argc)
			{
				//if there is an error on malloc return
				if (!(begin = ft_create_elem(argv[++i], begin)))
					return ;
			}
		}
		else
		{
			files = 1;
			if (!(begin = ft_readFile(argv[i], begin)))
				return ;
				//ft_putendl_fd("error", 2);
		}
		i++;
	}
	while (begin)
	{
		ft_putstr("hashing string : ");
		ft_putendl(begin->str);
		ft_hash_md5(begin->str);
		begin = begin->next;
	}
	/*ft_putstr("pFlag = ");
	ft_putnbr(pFlag);
	ft_putstr("\nqFlag = ");
	ft_putnbr(qFlag);
	ft_putstr("\nrFlag = ");
	ft_putnbr(rFlag);
	ft_putendl("");*/
}
