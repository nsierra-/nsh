/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 03:30:56 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 08:56:33 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# define PARS_ERR "Parse error.\n"
# include <qd_sh.h>
# include <tokens.h>
# include <singleton.h>

typedef struct				s_token
{
	char					*id;
	size_t					size;
}							t_token;

static t_token g_tok[] =
{
	{ TOK_HEREDOC, 2 },
	{ TOK_APPEND, 2 },
	{ TOK_REDIR_IN, 1 },
	{ TOK_REDIR_OUT, 1 },
	{ TOK_PIPE, 1 },
	{ TOK_SEMICOL, 1 },
	{ NULL }
};

static int					g_parse_error;

int							parser(char **lex_input);
int							is_input_token(const char *token);
int							end_of_command(const char *token);
int							is_output_token(const char *token);

#endif
