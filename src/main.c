/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:38:20 by klozano-          #+#    #+#             */
/*   Updated: 2019/02/25 11:30:36 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	main(int argc, char **argv)
{
	t_tetrimino	*list;

	if (argc != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	list = NULL;
	if (!readfile(&list, argv[1]))
	{
		clean(list);
		write(1, "error\n", 6);
		return (0);
	}
	else if (!fillit(list, ft_tetrimino_size(list)))
		write(1, "error\n", 6);
	clean(list);
	return (0);
}
