/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 11:26:16 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/26 16:44:05 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "env.h"

static char		*gen_var(const char *var, const char *value, char del)
{
	size_t		new_var_size;
	char		*new_var;
	char		*keep;

	new_var_size = 1;
	if (var)
		new_var_size += ft_strlen(var);
	if (value)
		new_var_size += ft_strlen(value);
	if (!(new_var = malloc(sizeof(char) * new_var_size + 1)))
		return (NULL);
	keep = new_var;
	while (var && *var != '\0')
	{
		*new_var = *var++;
		++new_var;
	}
	*new_var++ = del;
	while (value && *value != '\0')
	{
		*new_var = *value++;
		++new_var;
	}
	*new_var = '\0';
	return (keep);
}

void			env_print(const char **env)
{
	if (env)
	{
		while (*env)
			ft_putendl(*env++);
	}
}

char			**env_add_var(char **env, const char *var, const char *value)
{
	char		**new_env;
	char		*new_var;
	size_t		old_env_size;

	new_var = NULL;
	old_env_size = env_get_size((const char **)env);
	if (!(new_env = env_create_new(old_env_size + 1))
		|| !(new_env = env_copy((const char **)env, new_env))
		|| !(new_var = gen_var(var, value, '=')))
		return (NULL);
	new_env[old_env_size] = new_var;
	new_env[old_env_size + 1] = NULL;
	env_destroy(env);
	return (new_env);
}

int				env_update_var(char **env, const char *var, const char *value)
{
	char		*new_var;
	int			var_index;

	if (!var || !env || (var_index = env_is_set((const char **)env, var)) < 0
		|| !(new_var = gen_var(var, value, '=')))
		return (-1);
	free(env[var_index]);
	env[var_index] = new_var;
	return (var_index);
}

int				is_var(const char *to_match, const char *var)
{
	size_t		size_to_match;

	size_to_match = ft_strlen(to_match);
	if (!ft_strncmp(to_match, var, size_to_match)
			&& var[size_to_match] == '=')
		return (1);
	else
		return (0);
}
