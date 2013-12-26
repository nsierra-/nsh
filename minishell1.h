/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/26 08:51:20 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/26 10:20:56 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL1_H
# define MINISHELL1_H
# include <unistd.h>
# include <stdlib.h>

extern char		**environ;

typedef struct	s_env
{
	char		**path;
	char		*pwd;
}				t_env;

void			ft_putstr(char const *s);
int				get_next_line(int fd, char **line);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_strsplit(char const *s, char c, int start);

#endif /* !MINISHELL1_H */
