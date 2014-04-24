/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 22:58:07 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 20:29:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "qd_sh.h"
#include "env.h"
#include "errors.h"
#include "libft.h"

static int		valid_input_or_die(const char **args)
{
	size_t		args_size;

	args_size = env_get_size(args);
	if (!args)
		return (ft_print(ERROR(SH, E_GENERIC), 2, 0));
	if (args_size > 2)
		return (ft_print(ERROR(EXIT, E_TOO_MANY_ARGS), 2, 0));
	return (1);
}

int				builtin_exit(t_env *e, char **args)
{
	int			ret;

	(void)e;
	if (!valid_input_or_die((const char **)args))
		return (0);
	if (!args[1])
		exit(0);
	ret = ft_atoi(args[1]);
	exit(ret);
}
