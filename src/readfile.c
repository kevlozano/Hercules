/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:15:05 by klozano-          #+#    #+#             */
/*   Updated: 2019/02/23 13:56:44 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		ft_tetrimino_size(t_tetrimino *begin_list)
{
	t_tetrimino	*current;
	int			count;

	if (begin_list == NULL)
		return (0);
	count = 1;
	current = begin_list;
	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int		readfile(t_tetrimino **list, char *file)
{
	int		fd;
	char	buf[21];
	char	c;
	int		ret;

	c = 'A';
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while (((ret = read(fd, buf, 20)) == 20))
	{
		if (!lstpush(list, buf, c)
			|| (((ret = read(fd, buf, 1)) == 1) && buf[0] != '\n'))
			return (0);
		if (buf[0] == '\n')
			c += 1;
	}
	if ((ret != 20 && ret != 0) || (c - 'A' + 1 != ft_tetrimino_size(*list)))
		return (0);
	return (1);
}
