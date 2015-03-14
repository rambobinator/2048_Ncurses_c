/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:57 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

#define BUF_SIZE 1024
#define NAME_SIZE 8

static void		request_name(int fd)
{
	int		status;
	int		pid;
	char	*cmds[3];

	cmds[0] = ft_strdup("/Applications/Pashua.app/Contents/MacOS/Pashua");
	cmds[1] = ft_strdup("conf");
	cmds[2] = NULL;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd, 1);
		dup2(fd, 2);
		execv(cmds[0], cmds);
	}
	else
		waitpid(pid, &status, 0);
	free(cmds[0]);
	free(cmds[1]);
	close(fd);
}

int				write_score(int score)
{
	int		fd;
	char	buf[BUF_SIZE];
	char	*tmp;

	ft_bzero(buf, BUF_SIZE);
	if ((fd = open(SCORES_FILE, O_WRONLY | O_CREAT | O_APPEND, 0666)) == -1)
		return (-1);
	request_name(fd);
	if ((fd = open(SCORES_FILE, O_RDWR | O_APPEND, 0666)) == -1)
		return (-1);
	tmp = ft_itoa(score);
	ft_strcat(buf, tmp);
	free(tmp);
	ft_strcat(buf, "\n");
	write(fd, buf, ft_strlen(buf));
	close(fd);
	return (0);
}
