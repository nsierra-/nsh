/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 08:45:41 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 14:56:38 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"
#include <dirent.h>

static int			bouild_list(t_env *e, DIR *cur_dir, char *path)
{
	struct dirent	*ent;
	char			*exec_path;

	ent = NULL;
	while ((ent = readdir(cur_dir)))
	{
		if (ft_strcmp(".", ent->d_name) != 0
			&& ft_strcmp("..", ent->d_name) != 0
			&& (exec_path = ft_makepath(path, ent->d_name)))
		{
			e->lexec = add(e, D_NAME, exec_path, access(exec_path, X_OK));
			if (!e->lexec)
				return (FAIL);
		}
	}
	return (SUCCESS);
}

static int			build_exec_list(t_env *e, char **path)
{
	t_build_tools	tl;

	tl.cur_dir = NULL;
	tl.i = 0;
	tl.no_inc = FALSE;
	while (path[tl.i])
	{
		if (!(tl.cur_dir = opendir(path[tl.i])))
			exit(error(TRUE, ERROR_MSG_PATH));
		if (!(bouild_list(e, tl.cur_dir, path[tl.i])))
			exit(error(TRUE, ERROR_MSG_PATH));
		if (closedir(tl.cur_dir) == -1)
			exit(error(TRUE, ERROR_MSG_CLDIR));
		while (path[tl.i] && tl.i > 0 && ++tl.j != tl.i)
		{
			if (ft_strcmp(path[tl.j], path[tl.i]) == 0 && ++tl.i && ++tl.no_inc)
				tl.j = -1;
		}
		tl.j = -1;
		if (tl.no_inc == FALSE)
			tl.i++;
		else
			tl.no_inc = FALSE;
	}
	return (SUCCESS);
}

static void			get_env_info(t_env *e)
{
	int				info_loaded;
	extern char		**environ;

	info_loaded = 0;
	while (info_loaded < 2 && *environ)
	{
		if (ft_strncmp("PATH=", *environ, 5) == 0
			&& (e->path = ft_strsplit(*environ, ':', 5))
			&& build_exec_list(e, e->path))
			++info_loaded;
		else if (ft_strncmp("PWD=", *environ, 4) == 0
			&& (e->pwd = ft_strsub(*environ, 4, ft_strlen(*environ) - 4)))
			++info_loaded;
		++environ;
	}
}

static void			init_env(t_env *e)
{
	e->path = NULL;
	e->pwd = NULL;
	e->usr_input = NULL;
	e->lexec = NULL;
	e->exitflag = FALSE;
	get_env_info(e);
}

int					main(void)
{
	t_env			e;

	init_env(&e);
	prompt(&e);
	return (0);
}
