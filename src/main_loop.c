/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:00:03 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 05:26:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "errors.h"
#include "libft.h"
#include "gnl.h"
#include "env.h"
#include "qd_sh.h"

char			**prompt(t_env *e, unsigned int *stop)
{
	char		*line;
	char		**line_splitted;

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
	line_splitted = split_usr_input(line);
	free(line);
	return (line_splitted);
}

int					execution(t_env *e)
{
	unsigned int	stop;
	char			**lex_input;

	stop = false;
	while (!stop)
	{
		if (!(lex_input = prompt(e, &stop)))
			return (0);
		else if (lex_input[0])
			find_and_exec(e, lex_input);
		env_destroy(lex_input);
	}
	return (1);
}
