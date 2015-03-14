/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:04 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static int		catch_error(int error, t_env *env)
{
	t_error		error_tab[ERROR_NBR];

	error_tab[0].ret = END_APP;
	error_tab[0].code = FATAL_ERROR;
	error_tab[0].str = "Undefined error";
	(void)env;
	if (error_tab[error].str)
		ft_putendl(error_tab[error].str);
	return (error_tab[error].ret);
}

int				handle_error(int error, t_env *env)
{
	if ((error >= ERROR_NBR) || (error < 0))
		return (catch_error(UNDEFINED_ERROR, env));
	else
		return (catch_error(error, env));
}
