/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 05:31:50 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 11:01:24 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <parser.h>
#include <qd_sh.h>

static void		get_output_will(char **lex_input, int *i)
{
	singleton(set, out, lex_input[*i]);
	*i = *i + 1;
	if (end_of_command(lex_input[*i]) && (g_parse_error = 1)
			&& ft_rprint(PARS_ERR, 1))
		return ;
	singleton(set, out, lex_input[*i]);
	*i = *i + 1;
}

static void		get_input_will(char **lex_input, int *i)
{
	singleton(set, in, lex_input[*i]);
	*i = *i + 1;
	if (end_of_command(lex_input[*i]) && (g_parse_error = 1)
			&& ft_rprint(PARS_ERR, 1))
		return ;
	singleton(set, in, lex_input[*i]);
	*i = *i + 1;
}

static void		get_cmd(char **lex_input, int *i)
{
	while (!g_parse_error && !end_of_command(lex_input[*i]))
	{
		if (is_input_token(lex_input[*i]))
			get_input_will(lex_input, i);
		else if (is_output_token(lex_input[*i]))
			get_output_will(lex_input, i);
		else
		{
			singleton(set, cmd, lex_input[*i]);
			*i = *i + 1;
		}
	}
}

int				parser(char **lex_input)
{
	int			i;

	(void)g_tok;
	g_parse_error = 0;
	i = 0;
	singleton(all, init, NULL);
	while (lex_input[i] != NULL)
	{
		get_cmd(lex_input, &i);
	}
	singleton(all, reset, NULL);
	return (1);
}
