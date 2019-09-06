/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:01:25 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/06 16:48:10 by jyakdi           ###   ########.fr       */
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
	pFlag = 0;
	qFlag = 0;
	rFlag = 0;
	i = 2;
	while (i < argc)
	{
		//ft_putendl(argv[i]);
		if (ft_strcmp(argv[i], "-p") == 0)
			pFlag++;
		else if(ft_strcmp(argv[i], "-q") == 0)
			qFlag = 1;
		else if(ft_strcmp(argv[i], "-r") == 0)
			rFlag = 1;
		else if(ft_strcmp(argv[i], "-s") == 0)
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
			ft_readFile(argv[i], begin);
		}
		i++;
	}
	while (begin)
	{
		ft_putstr("testing -s strings : ");
		ft_putendl(begin->str);
		begin = begin->next;
	}
	ft_putstr("pFlag = ");
	ft_putnbr(pFlag);
	ft_putstr("\nqFlag = ");
	ft_putnbr(qFlag);
	ft_putstr("\nrFlag = ");
	ft_putnbr(rFlag);
	ft_putendl("");
}
