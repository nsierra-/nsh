/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 02:40:36 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/26 17:07:31 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "qd_sh.h"
#include "env.h"
#include "libft.h"
#include "errors.h"
#include <stdio.h>

static int			valid_input_or_die(const char **args)
{
	if (env_get_size(args) < 1)
		return (ft_print(ERROR(ECHO, E_INPUT), 2, 0));
	if (!ft_strcmp("-n", args[1]) && args[2] == NULL)
		return (0);
	return (1);
}

int					builtin_echo(t_env *e, char **args)
{
	t_bool			no_newline;

	e = e;
	no_newline = false;
	if (!valid_input_or_die((const char **)args))
		return (0);
	++args;
	if (!ft_strcmp("-n", *args) && args++)
		no_newline = true;
	while (*args != NULL)
	{
		if (*args)
			ft_print(*args, 1, 0);
		++args;
		if (args)
			ft_putchar(' ');
	}
	if (no_newline == false)
		ft_putchar('\n');
	return (1);
}
