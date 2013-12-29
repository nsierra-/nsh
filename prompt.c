/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 03:47:37 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 16:00:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static void		clean_env(t_env *e)
{
	free(e->usr_input);
}

static t_lexec	*find_exec(t_env *e, char *usr_input)
{
	t_lexec		*cursor;

	cursor = e->lexec;
	while (cursor && ft_strcmp(cursor->name, usr_input))
		cursor = cursor->next;
	return (cursor);
}

static void		deal_with_input(t_env *e, char **usr_input)
{
	t_lexec		*exec_info;
	char		*tmp;

	exec_info = NULL;
	if ((!ft_strcmp(usr_input[0], "exit") || !ft_strcmp(usr_input[0], "logout"))
		&& (e->exitflag = TRUE))
		return ;
	else if ((exec_info = find_exec(e, usr_input[0])))
	{
		ft_putstr(usr_input[0]);
		ft_putstr(" found. Path : <");
		ft_putstr(exec_info->path);
		ft_putendl(">");
	}
	else
	{
		ft_putstr("ft_minishell1: command not found: ");
		ft_putendl(usr_input[0]);
	}
	while (*usr_input)
	{
		tmp = *usr_input;
		free(tmp);
		++usr_input;
	}
}

int				prompt(t_env *e)
{
	e = e;
	while (e->exitflag == FALSE)
	{
		ft_putstr("$> ");
		if (get_next_line(1, &e->usr_input) > 0)
		{
			if (e->usr_input[0] != '\0')
				deal_with_input(e, ft_strsplit(e->usr_input, ' ', 0));
			clean_env(e);
		}
	}
	return (0);
}
