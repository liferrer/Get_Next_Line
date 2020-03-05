/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:51:29 by liferrer          #+#    #+#             */
/*   Updated: 2020/03/05 12:17:43 by liferrer         ###   ########.fr       */
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

}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*stock = NULL;
	char			*tmp;
	char			buffer[BUFFER_SIZE + 1];

	ret = 0;
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!stock)
		stock = ft_strdup("");
	if (stock[0] != '\0' && ft_strchr(stock, '\n'))
		return (get_stock_split(&stock, line));
	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	tmp = stock;
	stock = ft_strjoin(stock, buffer);
	free(tmp);
	if (ret < BUFFER_SIZE)
	{
		*line = ft_strdup(stock);
		tmp = stock;
		stock = ft_strdup("");
		free(tmp);
		return (0);
	}
	return (get_next_line(fd, line));
}

int		main(void)
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
			return(-1);
		}
		printf("|%d|%s\n", ret, line);
		free(line);
	}
	printf("|%d|%s\n", ret, line);
	while (1);
	free(line);
}
