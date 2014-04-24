/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 03:38:42 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/23 03:11:21 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1

typedef struct		s_read
{
	ssize_t			size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

int					get_next_line(int const fd, char **line);
int					get_next_linew(int const fd, char **line);

#endif
