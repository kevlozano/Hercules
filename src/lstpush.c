/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 18:39:33 by klozano-          #+#    #+#             */
/*   Updated: 2019/02/25 11:31:49 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		lstpush(t_tetrimino **head, char *form, char c)
{
	t_tetrimino *last;
	t_tetrimino *new;

	if (*head != NULL)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		new = last->next;
	}
	else
	{
		*head = (t_tetrimino *)malloc(sizeof(t_tetrimino));
		new = *head;
	}
	if (new == NULL)
		return (0);
	new->form = tetrimino_shift(form);
	new->next = NULL;
	if (new->form == NULL || !isvalid(new->form))
		return (0);
	new->c = c;
	return (1);
}
