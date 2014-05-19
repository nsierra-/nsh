/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 08:01:50 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 09:26:07 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <tokens.h>

int		end_of_command(const char *token)
{
	ft_putendl("End of command");
	if (!token || !ft_strncmp(token, TOK_PIPE, 2)
			|| !ft_strncmp(token, TOK_SEMICOL, 1))
	{
		printf("Success %s\n", token);
		return (1);
	}
	else
		return (0);
}

int		is_input_token(const char *token)
{
	ft_putendl("Input fct");
	if (!ft_strncmp(token, TOK_REDIR_IN, 1)
			|| !ft_strncmp(token, TOK_HEREDOC, 2))
	{
		printf("Success %s\n", token);
		return (1);
	}
	else
		return (0);
}

int		is_output_token(const char *token)
{
	ft_putendl("outpu fct");
	if (!ft_strncmp(token, TOK_REDIR_OUT, 1)
			|| !ft_strncmp(token, TOK_APPEND, 2))
	{
		printf("Success %s\n", token);
		return (1);
	}
	else
		return (0);
}
