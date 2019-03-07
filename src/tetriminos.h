/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchi <mchi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:53:38 by mchi              #+#    #+#             */
/*   Updated: 2019/02/23 15:49:58 by mchi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <fcntl.h>
# include <libft.h>

typedef struct	s_tetrimino
{
	char				**form;
	char				c;
	struct s_tetrimino	*next;
}				t_tetrimino;

typedef struct	s_square
{
	char	**form;
	int		size;
}				t_square;

int				fillit(t_tetrimino *root, int num_element);
int				fillout(t_square output, t_tetrimino *piece);
void			square_output(t_square output);
char			**tetrimino_shift(char *form);
int				isvalid(char **piece);
int				lstpush(t_tetrimino **head, char *form, char c);
int				clean(t_tetrimino *list);
int				check_line(char *form);
int				readfile(t_tetrimino **list, char *file);
int				ft_tetrimino_size(t_tetrimino *begin_list);
#endif
