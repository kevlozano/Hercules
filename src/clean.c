/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:44:27 by klozano-          #+#    #+#             */
/*   Updated: 2019/02/23 13:56:11 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void	clean_node(t_tetrimino *list)
{
	int i;

	if (list == NULL)
		return ;
	clean_node(list->next);
	if (list->form != NULL)
	{
		i = 0;
		while (i < 4)
		{
			free(list->form[i]);
			i++;
		}
	}
	free(list);
}

int		clean(t_tetrimino *list)
{
	clean_node(list);
	return (0);
}
