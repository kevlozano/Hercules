/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:17:29 by mchi              #+#    #+#             */
/*   Updated: 2019/02/23 13:32:39 by klozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		flood(char **piece, int check_board[4][4], int x, int y)
{
	if (x == -1 || x == 4 || y == -1 || y == 4
		|| piece[x][y] != '#' || check_board[x][y] == 1)
		return (0);
	check_board[x][y] = 1;
	return (1 + flood(piece, check_board, x - 1, y)
		+ flood(piece, check_board, x + 1, y)
		+ flood(piece, check_board, x, y - 1)
		+ flood(piece, check_board, x, y + 1));
}

void	clear_board(int check_board[4][4])
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			check_board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	square_output(t_square output)
{
	int i;
	int j;

	i = 0;
	while (i < output.size)
	{
		j = 0;
		while (j < output.size)
		{
			write(1, &output.form[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		isvalid(char **piece)
{
	int		count;
	int		i;
	int		j;
	int		check_board[4][4];

	clear_board(check_board);
	count = 0;
	if (piece[0][0] == '#')
		count = flood(piece, check_board, 0, 0);
	else if (piece[0][1] == '#')
		count = flood(piece, check_board, 0, 1);
	else if (piece[0][2] == '#')
		count = flood(piece, check_board, 0, 2);
	if (count != 4)
		return (0);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if ((piece[i][j] == '#' && check_board[i][j] == 0) ||
				(piece[i][j] != '.' && piece[i][j] != '#'))
				return (0);
	}
	return (1);
}
