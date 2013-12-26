/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 08:45:41 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/26 10:31:18 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

static void		get_env_info(t_env *e, char **environ)
{
	int			info_loaded;

	info_loaded = 0;
	while (info_loaded < 2)
	{
		if (ft_strcmp("PATH=", *environ) == 0
				&& (e->path = ft_strsplit(*environ, ':', 5)))
			++info_loaded;
		else if (ft_strcmp("PWD=", *environ) == 0)

	}
}

int 			main(void)
{
	t_env		e;

	e.path = NULL;
	e.pwd = NULL;
	get_env_info(&e, environ);
	return (0);
}
