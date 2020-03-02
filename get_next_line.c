/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:51:29 by liferrer          #+#    #+#             */
/*   Updated: 2020/03/02 17:11:12 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			i;
	int			ret;
	static char	*buffer[BUFF_SIZE];

	i = 0;
	if (fd < 0 || !line || !(buffer = ft_strdup("")))
		return (-1);
	if (buffer[0] != '\0')
	{
		if (ft_strchr(buffer, '\n'))
		{
			while (buffer[i] != '\n')
				i++;
			*line = ft_substr(buffer, 0, i + 1);
			buffer = ft_substr(buffer, i + 1, ft_strlen(buffer + 1));
			return (line);
		}
		if (ret < BUFF_SIZE)
		{
			*line = ft_strdup(buffer);
			return (0);
		}
	}
	while ((ret = read(fd, buffer, BUFF_SIZE) < 0))
	{
		
	}
}
