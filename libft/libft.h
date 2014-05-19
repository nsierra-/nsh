/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:28:34 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 08:43:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define WHITE_SPACES " \r\t\f\n\v"

# include <stddef.h>

char			*ft_strdup(const char *str);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_sisnum(const char *str);
void			ft_putendl(const char *str);
void			ft_putchar(int c);
int				ft_atoi(const char *str);
int				ft_isvalid(char c, const char *to_avoid);
int				ft_freer(void *to_del, int ret);
char			**ft_split(const char *str, const char *to_avoid);
char			**ft_mdsplit(char *str, const char *to_avoid);
void			ft_putstr(const char *str);
char			*ft_strcat(char *dest, const char *src);
char			*ft_pathbuilder(char *path, char *file);
void			ft_strclean(char *str, size_t len);
int				ft_rprint(const char *str, int ret);

#endif
