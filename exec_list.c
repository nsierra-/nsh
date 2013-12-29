/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 10:02:04 by nsierra-          #+#    #+#             */
/*   Updated: 2013/12/29 10:54:26 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell1.h"

t_lexec				*add(t_env *e, char *name, char *path, int x_ok)
{
	t_lexec			*new_elem;

	new_elem = NULL;
	if (!(new_elem = malloc(sizeof(t_lexec))))
		return (NULL);
	if (e->lexec == NULL)
		new_elem->next = NULL;
	else
		new_elem->next = e->lexec;
	new_elem->name = name;
	new_elem->path = path;
	new_elem->x_ok = x_ok;
	return (new_elem);
}
