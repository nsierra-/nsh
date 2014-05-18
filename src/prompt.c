/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 03:11:43 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/18 23:41:16 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <parser.h>
#include <libft.h>
#include <gnl.h>
#include <qd_sh.h>

char			**prompt(t_env *e, unsigned int *stop)
{
	char			*line;
	char			**line_splitted;

	line = NULL;
	line_splitted = NULL;
	ft_putstr(e->prompt_str);
	if (get_next_line(0, &line) == -1)
	{
		*stop = true;
		if (line)
			free(line);
		return (NULL);
	}
	line_splitted = ft_split(line, WHITE_SPACES);
	free(line);
	return (line_splitted);
}
