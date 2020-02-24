/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:26:48 by liferrer          #+#    #+#             */
/*   Updated: 2020/02/24 16:05:10 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_del_current(t_fd **first_fd, t_fd **current)
{
	t_fd	*preview;

	preview = *first_fd;
	if (*current == *first_fd)
		*first_fd = (*first_fd)->next;
	else
	{
		while (preview->next != *current)
			preview = preview->next;
		preview->next = (*current)->next;
	}
	free((*current)->reste);
	free(*current);
}

t_fd		*ft_diff_fd(t_fd **first_fd, int fd)
{
	t_fd	*new;

	new = *first_fd;
	while (new)
	{
		if (new->fd == fd)
			return (new);
		new = new->next;
	}
	if (!(new = (t_fd*)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->reste = ft_strdup("");
	new->next = *first_fd;
	*first_fd = new;
	return (new);
}

static int	ft_suite_gnl(t_fd *current, char **line, t_fd **first_fd)
{
	int	i;

	i = 0;
	if (ft_strlen(current->reste) == 0)
		return (0);
	if (ft_strchr(current->reste, '\n'))
	{
		while ((current->reste)[i] && (current->reste)[i] != '\n')
			i++;
		if (!(*line = ft_substr(current->reste, 0, i)))
			return (-1);
		current->reste = ft_strdup(current->reste + i + 1);
		return (1);
	}
	if (!(*line = ft_strdup(current->reste)))
		return (-1);
	ft_del_current(first_fd, &current);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	t_fd			*current;
	static t_fd		*first_fd;
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	if ((read(fd, NULL, 0) < 0) || !line ||
			(!(current = ft_diff_fd(&first_fd, fd))))
		return (-1);
	while ((!(ft_strchr(current->reste, '\n'))) &&
			((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		tmp = current->reste;
		if (!(current->reste = ft_strjoin(current->reste, buff)))
			return (-1);
		free(tmp);
	}
	return (ft_suite_gnl(current, line, &first_fd));
}
