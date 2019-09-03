/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:01:25 by jyakdi            #+#    #+#             */
/*   Updated: 2019/09/03 18:05:31 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	md5(int argc, char **argv)
{
	//if -p do it instantly
	//read options (q r) for printing mode
	//chained list with all strings and file contents
	//if chained list is empty and no -p read on stdin
	int	i;
	int pFlag;
	
	pFlag = 0;
	i = 2;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		if (ft_strcmp(argv[i], "-p") == 0)
		{
			pFlag++;
		}
		
		i++;
	}
}
