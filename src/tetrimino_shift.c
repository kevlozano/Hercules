/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:38:48 by klozano-          #+#    #+#             */
/*   Updated: 2019/02/22 19:27:08 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		emptylines(char **form)
{
	int		i;
	int		j;
	int		emptylines;

	i = 0;
	emptylines = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			if (form[i][j] == '#')
				break ;
		if (j != 4)
			break ;
		(emptylines)++;
		i++;
	}
	return (emptylines);
}

int		emptycol(char **form)
{
	int		i;
	int		j;
	int		emptycol;

	j = 0;
	emptycol = 0;
	while (j < 4)
	{
		i = -1;
		while (++i < 4)
			if (form[i][j] == '#')
				break ;
		if (i != 4)
			break ;
		(emptycol)++;
		j++;
	}
	return (emptycol);
}

char	**tetrimino_shift(char *form)
{
	int		i;
	int		j;
	int		eline;
	int		ecol;
	char	**ret;

	i = 0;
	j = 0;
	if (!check_line(form))
		return (NULL);
	ret = ft_strsplit(form, '\n');
	eline = emptylines(ret);
	ecol = emptycol(ret);
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			if (ret[i][j] == '#')
			{
				ret[i][j] = '.';
				ret[i - eline][j - ecol] = '#';
			}
		i++;
	}
	return (ret);
}
