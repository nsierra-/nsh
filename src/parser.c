/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 05:31:50 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 05:42:29 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <parser.h>
#include <qd_sh.h>


int				parser(char **lex_input)
{
	t_tmptab	*tmp;

	(void)g_tok;
	(void)lex_input;
	tmp = singleton(set, cmd, (char *)"test");
	puts(tmp->tab[0]);
	return (1);
}
