/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:10 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

int			end_game(t_env *env)
{
	char		buff[1024];
	char		*score;

	clear();
	ft_bzero(buff, 1024);
	if (env->games->win == WIN_MAP)
	{
		ft_strcat(buff, "# VICTORY SCORE: ");
		score = ft_itoa(env->games->maps->score);
		ft_strcat(buff, score);
		free(score);
		display(buff, 1, 0, STRING);
	}
	else if (env->games->end == LOOSE_MAP)
	{
		ft_strcat(buff, "# YOUR FINAL SCORE : ");
		score = ft_itoa(env->games->maps->score);
		ft_strcat(buff, score);
		free(score);
		display(buff, 1, 0, STRING);
	}
	write_score(env->games->maps->score);
	return (CONTINUE_GAME);
}
