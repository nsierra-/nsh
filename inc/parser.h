/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 03:30:56 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/16 05:11:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <tokens.h>

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

#endif
