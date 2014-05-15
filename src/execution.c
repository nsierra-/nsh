/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:00:03 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/15 02:45:27 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "errors.h"
#include "libft.h"
#include "gnl.h"
#include "env.h"
#include "qd_sh.h"

static char			**prompt(t_env *e, unsigned int *stop)
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
	line_splitted = ft_split(line, " \r\t\f\n\v");
	free(line);
	return (line_splitted);
}

int					execution(t_env *e)
{
	unsigned int	stop;
	char			**usr_input;

	stop = false;
	while (!stop)
	{
		if (!(usr_input = prompt(e, &stop)))
			return (ft_print(ERROR(SH, E_GENERIC), 2, 0));
		else if (usr_input[0])
			find_and_exec(e, usr_input);
		env_destroy(usr_input);
	}
	return (1);
}
