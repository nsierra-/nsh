/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_tmptab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 04:41:28 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 05:46:03 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <singleton.h>

static void			init_tmptab(t_tmptab *tmptab, int *init)
{
	int				i;

	i = 0;
	tmptab->i = 0;
	while (i < TMPTAB_SIZE)
		tmptab->tab[i++] = NULL;
	*init = 1;
}

static t_tmptab		*in_singleton(t_action action, char *token)
{
	static int		is_init = 0;
	static t_tmptab	tab;

	if (is_init == 0)
		init_tmptab(&tab, &is_init);
	if (action == get)
		return (&tab);
	else if (action == set)
		tab.tab[tab.i++] = token;
	else if (action == reset)
	{
		while (tab.i >= 0)
			tab.tab[tab.i--] = NULL;
	}
	return (NULL);
}

static t_tmptab		*out_singleton(t_action action, char *token)
{
	static int		is_init = 0;
	static t_tmptab	tab;

	if (is_init == 0)
		init_tmptab(&tab, &is_init);
	if (action == get)
		return (&tab);
	else if (action == set)
		tab.tab[tab.i++] = token;
	else if (action == reset)
	{
		while (tab.i >= 0)
			tab.tab[tab.i--] = NULL;
	}
	return (NULL);
}

static t_tmptab		*cmd_singleton(t_action action, char *token)
{
	static int		is_init = 0;
	static t_tmptab	tab;

	if (is_init == 0)
		init_tmptab(&tab, &is_init);
	if (action == get)
		return (&tab);
	else if (action == set)
		tab.tab[tab.i++] = token;
	else if (action == reset)
	{
		while (tab.i >= 0)
			tab.tab[tab.i--] = NULL;
	}
	return (NULL);
}

t_tmptab			*singleton(t_action action, t_stype type, char *token)
{
	if (type == cmd)
		return (cmd_singleton(action, token));
	else if (type == in)
		return (in_singleton(action, token));
	else if (type == out)
		return (out_singleton(action, token));
	return (NULL);
}
