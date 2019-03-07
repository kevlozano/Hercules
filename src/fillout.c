/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:48:19 by mchi              #+#    #+#             */
/*   Updated: 2019/02/23 15:51:29 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	remove_piece(t_square output, t_tetrimino *piece, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (piece->form[i][j] == '#')
				output.form[i + x][j + y] = '.';
	}
}

int		try_piece(t_square output, t_tetrimino *piece, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (piece->form[i][j] == '#')
				if (i + x >= output.size || j + y >= output.size ||
					output.form[i + x][j + y] != '.')
					return (0);
	}
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (piece->form[i][j] == '#')
				output.form[i + x][j + y] = piece->c;
	}
	if (fillout(output, piece->next))
		return (1);
	remove_piece(output, piece, x, y);
	return (0);
}

int		fillout(t_square output, t_tetrimino *piece)
{
	int i;
	int j;

	if (piece == NULL)
		return (1);
	i = 0;
	while (i < output.size)
	{
		j = 0;
		while (j < output.size)
		{
			if (try_piece(output, piece, i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
