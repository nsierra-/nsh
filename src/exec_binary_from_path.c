/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary_from_path.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 20:39:14 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/27 19:46:47 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "errors.h"
#include "libft.h"
#include "env.h"
#include "qd_sh.h"

static char			*validate_file(char *path, int errors)
{
	struct stat		stat_info;

	if (stat(path, &stat_info) == 0)
	{
		if (!(stat_info.st_mode & S_IFREG || stat_info.st_mode & S_IFLNK))
		{
			if (errors)
				ft_print(ERROR(SH, E_WRGFILETYPE), 2, 0);
			free(path);
			return (NULL);
		}
		else if (!(stat_info.st_mode & S_IXUSR))
		{
			if (errors)
				ft_print(ERROR(SH, E_NOTX), 2, 0);
			free (path);
			return (NULL);
		}
		else
			return (path);
	}
	else if (errors)
		ft_print(ERROR(SH, E_CMDNOTFOUND), 2, 0);
	free(path);
	return (NULL);
}

static char			*find_bin(char *path, char *bin)
{
	DIR				*dirp;
	S_DIRENT		*dirent;

	if (!(dirp = opendir(path)))
		return (NULL);
	while ((dirent = readdir(dirp)) != NULL)
	{
		if (ft_strcmp((const char *)dirent->d_name, (const char *)bin) == 0)
		{
			closedir(dirp);
			return (validate_file(ft_pathbuilder(path, bin), 0));
		}
	}
	closedir(dirp);
	return (NULL);
}

static int			execute(char *bin_path, char **argv, char **env)
{
	pid_t			child;
	int				child_status;

	if ((child = fork()) == 0)
	{
		if (execve(bin_path, argv, env) == -1)
			return (EXIT_FAILURE);
	}
	else if (child > 0)
	{
		wait(&child_status);
		return (WEXITSTATUS(child_status));
	}
	return (EXIT_FAILURE);
}

static int			test_direct_path(char *path, char **env, char **argv,
										int *not_found)
{
	char			*tmp;

	(void)not_found;
	(void)path;
	if (!(tmp = validate_file(ft_strdup(argv[0]), 1)))
	{
		free(tmp);
		return (EXIT_FAILURE);
	}
	return (execute(argv[0], argv, env));
}

int					exec_binary_from_path(char *path, char **env, char **argv,
											int *not_found)
{
	char			**pathlst;
	char			*bin_path;
	int				ret;
	size_t			i;

	i = 0;
	if (!path)
		pathlst = ft_mdsplit(env_dup_var(env, "PATH"), ":");
	else
		pathlst = ft_split(path, ":");
	while (pathlst && pathlst[i] != NULL)
	{
		if ((bin_path = find_bin(pathlst[i++], argv[0])) != NULL)
		{
			ret = execute(bin_path, argv, env);
			free(bin_path);
			env_destroy(pathlst);
			return (ret);
		}
	}
	env_destroy(pathlst);
	return (test_direct_path(path, env, argv, not_found));
}
