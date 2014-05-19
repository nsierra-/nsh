/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:00:03 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 05:21:58 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "errors.h"
#include "libft.h"
#include "gnl.h"
#include "env.h"
#include "qd_sh.h"

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
