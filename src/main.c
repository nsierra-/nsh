/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:28:59 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 18:21:48 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "qd_sh.h"
#include "errors.h"
#include "env.h"

static void				set_all_pointers_to_null(t_env *e)
{
	unsigned int		i;

	i = 0;
	e->env = NULL;
	e->path = NULL;
	e->cwd = NULL;
	e->owd = NULL;
	e->home = NULL;
	e->term = NULL;
	while (i < PROMPT_MAX_SIZE)
		e->prompt_str[i++] = '\0';
}

int						main(int ac, const char **av, const char **envp)
{
	t_env				e;

	(void)ac;
	(void)av;
	set_all_pointers_to_null(&e);
	e.original_env = envp;
	if (!load_shell_vars(&e) || !execution(&e))
		return (ft_print("Abording.\n", 2, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
