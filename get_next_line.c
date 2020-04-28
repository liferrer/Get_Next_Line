/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:51:29 by liferrer          #+#    #+#             */
/*   Updated: 2020/03/12 13:42:45 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_stock_split(char **stock, char **line)
{
	int				i;
	char			*tmp;

	i = 0;
	while ((*stock)[i] != '\n')
		i++;
	*line = ft_substr(*stock, 0, i);
	tmp = *stock;
	*stock = ft_substr(*stock, i + 1, (ft_strlen(*stock) - i - 1));
	free(tmp);
	return (1);
}

int		dealwith_eof(char **stock, char **line)
{
	char			*tmp;
	int				i;

	i = 0;
	*line = ft_strdup(*stock);
	tmp = *stock;
	*stock = ft_strdup("");
	free(tmp);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			buffer[BUFFER_SIZE + 1];
	static char		*stock = NULL;

	ret = 0;
	if (!fd || fd < 0 || fd > OPEN_MAX || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	if (!stock)
		stock = ft_strdup("");
	if (!ft_strchr(stock, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	if (ft_strchr(stock, '\n'))
		return (get_stock_split(&stock, line));
	else if (ft_strlen(stock) != 0 && ret == 0)
		return (dealwith_eof(&stock, line));
	return (get_next_line(fd, line));
}

/* int		main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf("error\n");
			return (-1);
		}
		printf("|%d|%s\n", ret, line);
		free(line);
	}
	printf("|%d|", ret);
	free(line);
}*/
