/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 19:14:34 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 19:16:19 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "qd_sh.h"

int					builtin_env(t_env *e, char **args)
{
	(void)args;
	env_print((const char **)e->env);
	return (0);
}
