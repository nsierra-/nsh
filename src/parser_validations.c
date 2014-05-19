/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 08:01:50 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 10:59:12 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <tokens.h>

int		end_of_command(const char *token)
{
	if (!token || !ft_strncmp(token, TOK_PIPE, 2)
			|| !ft_strncmp(token, TOK_SEMICOL, 1))
		return (1);
	else
		return (0);
}

int		is_input_token(const char *token)
{
	if (!ft_strncmp(token, TOK_REDIR_IN, 1)
			|| !ft_strncmp(token, TOK_HEREDOC, 2))
		return (1);
	else
		return (0);
}

int		is_output_token(const char *token)
{
	if (!ft_strncmp(token, TOK_REDIR_OUT, 1)
			|| !ft_strncmp(token, TOK_APPEND, 2))
		return (1);
	else
		return (0);
}
