/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hall_of_fame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:36 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void	sort_dbl(char **name, int *score, int len)
{
	int		i;
	char	*c_tmp;
	int		i_tmp;

	i = 0;
	while (i + 1 < len)
	{
		if (score[i] < score[i + 1])
		{
			i_tmp = score[i];
			score[i] = score[i + 1];
			score[i + 1] = i_tmp;
			c_tmp = name[i];
			name[i] = name[i + 1];
			name[i + 1] = c_tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	norme_made_me_do_it(t_menu *menu, char *buff)
{
	menu->select = 0;
	menu->str = ft_strdup(buff);
	menu->menu_cmd = NULL;
	menu->ret = CONTINUE_APP;
}

static void	print_dbl(char **name, int *score, int len, t_env *env)
{
	int		i;
	char	buff[4000];
	t_menu	menu[10];
	char	*tmp;

	i = -1;
	while (++i < len && i < 10)
	{
		ft_bzero(buff, 4000);
		tmp = ft_itoa(i + 1);
		ft_strcat(buff, tmp);
		free(tmp);
		ft_strcat(buff, ": ");
		ft_strcat(buff, ft_strchr(name[i], '=') + 1);
		ft_strcat(buff, " ");
		tmp = ft_itoa(score[i]);
		ft_strcat(buff, tmp);
		free(tmp);
		ft_strcat(buff, "\n");
		norme_made_me_do_it(&menu[i], buff);
	}
	handle_keyboard_menu_event(env, menu, i);
	i = -1;
	while (++i < len && i < 10)
		free(menu[i].str);
}

static void	treat_hall(int nb, t_env *env)
{
	int		l_count;
	char	*line;
	char	*name[nb / 2 + 1];
	int		score[nb / 2 + 1];
	int		fd;

	l_count = 0;
	if ((fd = open(SCORES_FILE, O_RDONLY)) == -1)
		return ;
	while (get_next_line(fd, &line))
	{
		if (l_count % 2 == 0)
			name[l_count / 2] = ft_strdup(line);
		else
			score[l_count / 2] = ft_atoi(line);
		free(line);
		l_count++;
	}
	close(fd);
	sort_dbl(name, score, nb / 2);
	print_dbl(name, score, nb / 2, env);
	fd = -1;
	while (++fd < nb / 2)
		free(name[fd]);
}

int			display_hall_of_fame(t_env *env)
{
	int		fd;
	char	*line;
	int		nb;

	nb = 0;
	if ((fd = open(SCORES_FILE, O_RDONLY)) == -1)
		return (-1);
	while (get_next_line(fd, &line))
	{
		nb++;
		free(line);
	}
	close(fd);
	treat_hall(nb, env);
	return (0);
}
