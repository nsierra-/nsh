/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 03:30:56 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 05:15:44 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <tokens.h>
# define TMPTAB_SIZE 1024

typedef enum				e_action
{
	get,
	set,
	reset
}							t_action;

typedef enum				e_stype
{
	cmd,
	in,
	out
}							t_stype;

typedef struct				s_token
{
	char					*id;
	size_t					size;
}							t_token;

typedef struct				s_tmptab
{
	char					*tab[TMPTAB_SIZE];
	int						i;
}							t_tmptab;

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

t_tmptab					*singleton(t_action action, t_stype type,
											char *token);

#endif
