/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 03:11:43 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/16 06:06:39 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <parser.h>
#include <libft.h>
#include <gnl.h>
#include <qd_sh.h>

static int		find_token(const char *usr_input)
{
	int			i;

	i = 0;
	while (g_tok[i].id != NULL)
	{
		if (!ft_strncmp(usr_input, g_tok[i].id, g_tok[i].size))
			return (i);
		++i;
	}
	return (-1);
}

static void		prepare_input(const char *usr_input, char *buf)
{
	size_t		i;
	size_t		j;
	size_t		k;
	int			tmp;

	i = 0;
	j = 0;
	while (i < MAX_INPUT_SIZE && j < MAX_INPUT_SIZE && usr_input[i] != '\0')
	{
		k = 0;
		if ((tmp = find_token(usr_input + i)) != -1)
		{
			if (i > 0 && usr_input[i - 1] != ' ')
				buf[j++] = ' ';
			while (j < MAX_INPUT_SIZE && k < g_tok[tmp].size)
				buf[j++] = g_tok[tmp].id[k++];
			i += g_tok[tmp].size;
			if (j < MAX_INPUT_SIZE && usr_input[i] != ' ')
				buf[j++] = ' ';
		}
		else
			buf[j++] = usr_input[i++];
	}
}

static char		**split_usr_input(const char *usr_input)
{
	static char	buf[MAX_INPUT_SIZE];

	ft_strclean(buf, MAX_INPUT_SIZE);
	prepare_input(usr_input, buf);
	return (ft_split(buf, WHITE_SPACES));
}

char			**prompt(t_env *e, unsigned int *stop)
{
	char			*line;
	char			**line_splitted;

	line = NULL;
	line_splitted = NULL;
	ft_putstr(e->prompt_str);
	if (get_next_line(0, &line) == -1)
	{
		*stop = true;
		if (line)
			free(line);
		return (NULL);
	}
	line_splitted = split_usr_input(line);
	free(line);
	return (line_splitted);
}

