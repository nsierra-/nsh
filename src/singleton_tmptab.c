/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton_tmptab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 04:41:28 by nsierra-          #+#    #+#             */
/*   Updated: 2014/05/19 09:21:28 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <singleton.h>

static void			init_tmptab(t_tmptab *tmptab)
{
	int				i;

	i = 0;
	tmptab->i = 0;
	while (i < TMPTAB_SIZE)
		tmptab->tab[i++] = NULL;
}

static t_tmptab		*in_singleton(t_action action, char *token)
{
	static t_tmptab	tab;

	if (action == init)
		init_tmptab(&tab);
	if (action == get)
		return (&tab);
	else if (action == set)
		tab.tab[tab.i++] = token;
	else if (action == reset)
	{
		while (tab.i >= 0)
			tab.tab[tab.i--] = NULL;
		tab.i = 0;
	}
	return (&tab);
}

static t_tmptab		*out_singleton(t_action action, char *token)
{
	static t_tmptab	tab;

	if (action == init)
		init_tmptab(&tab);
	if (action == get)
		return (&tab);
	else if (action == set)
		tab.tab[tab.i++] = token;
	else if (action == reset)
	{
		while (tab.i >= 0)
			tab.tab[tab.i--] = NULL;
		tab.i = 0;
	}
	return (&tab);
}

static t_tmptab		*cmd_singleton(t_action action, char *token)
{
	static t_tmptab	tab;

	if (action == init)
		init_tmptab(&tab);
	if (action == get)
		return (&tab);
	else if (action == set)
		tab.tab[tab.i++] = token;
	else if (action == reset)
	{
		while (tab.i >= 0)
			tab.tab[tab.i--] = NULL;
		tab.i = 0;
	}
	return (&tab);
}

t_tmptab			*singleton(t_action action, t_stype type, char *token)
{
	static int		not_initialized = 1;

	if (type == cmd)
		return (cmd_singleton(action, token));
	else if (type == in)
		return (in_singleton(action, token));
	else if (type == out)
		return (out_singleton(action, token));
	else if (not_initialized == 1 && type == all && action == init)
	{
		cmd_singleton(init, NULL);
		out_singleton(init, NULL);
		in_singleton(init, NULL);
		not_initialized = 0;
	}
	else if (type == all && action == reset)
	{
		cmd_singleton(reset, NULL);
		out_singleton(reset, NULL);
		in_singleton(reset, NULL);
	}
	return (NULL);
}
