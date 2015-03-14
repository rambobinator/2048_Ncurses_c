/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:30 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFF_SIZE 1024

static void		get_next_line_ret(char **line, char **str)
{
	size_t		length;
	char		*tmp;

	length = ft_strchr(*str, '\n') - *str;
	*line = ft_strsub(*str, 0, length);
	tmp = *str;
	*str = ft_strsub(tmp, length + 1, ft_strlen(tmp) - length - 1);
	free(tmp);
}

int				get_next_line_end(char *str, char **line)
{
	*line = ft_strdup(str);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str;
	char		*tmp;

	if (fd == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (str == NULL && (str = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	while (str != NULL && ft_strchr(str, '\n') == NULL
			&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	if (ret == -1)
		return (-1);
	if (ret == 0 && ft_strchr(str, '\n') == NULL)
		return (get_next_line_end(str, line));
	get_next_line_ret(line, &str);
	return (1);
}
