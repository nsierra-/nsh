/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsierra- <nsierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 10:30:29 by nsierra-          #+#    #+#             */
/*   Updated: 2014/03/27 05:44:04 by nsierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <stddef.h>
# include <stdarg.h>
# include "qd_sh.h"

typedef struct passwd	t_passwd;
typedef struct utsname	t_utsname;

/*
** Specify a size and returns a char ** filled with NULL of size + 1.
** Returns NULL on failure.
*/
char			**env_create_new(size_t size);
/*
** Copies src into dst. If dst is NULL, then it will be malloc'd. Otherwise,
** make sure dst is big enough. Returns NULL on failure.
*/
char			**env_copy(const char **src, char **dst);
/*
** Looks for the variable ID specified by var (case-sensitive). Returns var
** index if var is found. Otherwise, it returns -1.
*/
int				env_is_set(const char **env, const char *var);
/*
** Returns the size of the NULL-terminated array pointed by env.
*/
size_t			env_get_size(const char **env);
/*
** Creates a new env, copies the old one into it and adds the couple var + val
** at the end of the array. On successfull, returns a pointer to the new env
** and frees the old one. Returns NULL on failure and does not free the old
** env.
*/
char			**env_add_var(char **env, const char *var, const char *value);
/*
** DO NOT USE THIS FUNCTION TO UPDATE A VARIABLE. INTERNAL USAGE ONLY.
** Looks for the index of the variable specified by var into env. On
** successfull, frees the old variable, sets a new couple var + val at
** this very index and returns the index.
** If you want to reset a variable, you need to use builtin_setenv.
** Returns -1 on failure.
*/
int				env_update_var(char **env, const char *var, const char *value);
/*
** Prints a null-terminated array of strings.
*/
void			env_print(const char **env);
/*
** Checks if var is a variable of format :
**	"VAR=value"
*/
int				is_var(const char *to_match, const char *var);
/*
** Creates a null-terminated array of size specified by size and puts
** every string after into it.
** Do not send anything different than string into this function.
*/
char			**create_args(size_t size, ...);
/*
** Frees a null-terminated array of strings.
*/
void			env_destroy(char **env);
/*
** Quickly sets a var.
*/
void			env_setenv_var(t_env *e, const char *var, char *value);
/*
** Duplicate value of var and returns it.
*/
char			*env_dup_var(char **env, const char *var_asked);
/*
** Returns a pointer to the value of variable contained into env.
** DO NOT USE THIS FUNCTION IF YOU PLAN ON MODIFYING THE VALUE.
** IF SO, USE env_dup_var().
*/
char			*env_get_var(char **env, const char *var_asked);

#endif
