/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:53:57 by mchi              #+#    #+#             */
/*   Updated: 2019/02/25 11:36:57 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void		cleanup_square(t_square sqr)
{
	int i;
	int j;

	i = 0;
	while (i < sqr.size)
	{
		j = 0;
		while (j < sqr.size)
		{
			sqr.form[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		free_square(t_square array, int size)
{
	while (size > 0)
	{
		size--;
		free(array.form[size]);
	}
	free(array.form);
	array.form = NULL;
}

t_square	allocate_square(int size)
{
	int			i;
	t_square	output;

	i = 0;
	output.size = size;
	output.form = (char **)malloc(sizeof(char *) * size);
	if (output.form == NULL)
		return (output);
	while (i < size)
	{
		output.form[i] = (char *)malloc(sizeof(char) * size);
		if (output.form[i] == NULL)
			break ;
		i++;
	}
	if (i == size)
		return (output);
	while (i >= 0)
	{
		free(output.form[i]);
		i--;
	}
	free(output.form);
	return (output);
}

int			fillit(t_tetrimino *root, int num_element)
{
	const int	max_size[12] = {0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 26};
	t_square	output;
	int			size;

	size = 0;
	while (max_size[size] < num_element)
		size++;
	output = allocate_square(size);
	if (output.form == NULL)
		return (0);
	cleanup_square(output);
	while (!fillout(output, root))
	{
		free_square(output, size);
		size++;
		output = allocate_square(size);
		if (output.form == NULL)
			return (0);
		cleanup_square(output);
	}
	square_output(output);
	return (1);
}

void		calc_answer(t_tetrimino *root, int num_element)
{
	if (!fillit(root, num_element))
		write(1, "error\n", 6);
}
