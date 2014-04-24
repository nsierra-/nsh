/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 10:00:22 by nsierra-          #+#    #+#             */
/*   Updated: 2014/04/23 18:21:22 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

int				ft_cisvalid(int c, const char *to_avoid)
{
	while (*to_avoid != '\0')
	{
		if (*to_avoid == c)
			return (0);
		++to_avoid;
	}
	return (1);
}

static size_t	clean_string_get_word_count(char *str, const char *to_avoid)
{
	int			i;
	int			j;
	size_t		word_count;

	i = 0;
	j = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if (!ft_cisvalid(str[i], to_avoid))
			str[i] = '\0';
		++i;
	}
	while (j < i)
	{
		if (j < i && str[j] != '\0' && ++word_count)
		{
			while (j < i && str[j] != '\0')
				++j;
		}
		else
			++j;
	}
	return (word_count);
}

char			**ft_split(const char *str, const char *to_avoid)
{
	size_t		i;
	size_t		j;
	size_t		word_count;
	char		*tmp;
	char		**ret;

	i = 0;
	j = 0;
	tmp = ft_strdup(str);
	word_count = clean_string_get_word_count(tmp, to_avoid);
	if (!(ret = NULL)
			&& !(ret = malloc(sizeof(char *) * word_count + 1)))
		return (NULL);
	ret[word_count] = NULL;
	while (i < word_count)
	{
		while (tmp[j] == '\0')
			++j;
		ret[i] = ft_strdup(tmp + j);
		++i;
		j += ft_strlen(tmp + j);
	}
	free(tmp);
	return (ret);
}

char			**ft_mdsplit(char *str, const char *to_avoid)
{
	size_t		i;
	size_t		j;
	size_t		word_count;
	char		**ret;

	i = 0;
	j = 0;
	word_count = clean_string_get_word_count(str, to_avoid);
	if (!(ret = NULL)
			&& !(ret = malloc(sizeof(char *) * word_count + 1)))
		return (NULL);
	ret[word_count] = NULL;
	while (i < word_count)
	{
		while (str[j] == '\0')
			++j;
		ret[i] = str + j;
		++i;
		j += ft_strlen(str + j);
	}
	return (ret);
}
