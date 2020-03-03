/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:51:29 by liferrer          #+#    #+#             */
/*   Updated: 2020/03/03 14:32:58 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			i;
	int			ret;
	char		*stock;
	char		*tmp;
	static char	*buffer[BUFFER_SIZE];

	i = 0;
	stock = NULL;
	ret = 0;
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!stock)
		stock = ft_strdup("");
	if (stock)
	{
		printf("boucle stock test\n");
			printf("stock1 = %s \n", stock);
		if (ft_strchr(stock, '\n'))
		{
		printf("boucle stock test 2\n");
			while (stock[i] != '\n')
				i++;
			*line = ft_substr(stock, 0, i);
			printf("stock1 = %s \n", stock);
			stock = ft_substr(stock, i + 1, ft_strlen(stock));
			printf("stock2 = %s \n", stock);
			return (1);
		}
		if (ret < BUFFER_SIZE)
		{
			*line = ft_strdup(stock);
			return (0);
		}
	}
	while ((ret = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		if (!(ft_strchr((char*)buffer, '\n')))
			*line = ft_strjoin(*line, (char*)buffer);
		tmp = stock;
		stock = ft_strjoin(stock, (char*)buffer);
		free(tmp);
	}
	return (get_next_line(fd, line));
}


/*int		get_next_line(int fd, char **line)
{
	int			i;
	int			ret;
	static char	*buffer[BUFFER_SIZE];

	i = 0;
	ret = 0;
	*line = NULL;
	if (*line == NULL)
		*line = ft_strdup("");
	if (fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		printf("buffer = %s\n", (char*)buffer);
		*line = ft_strjoin(*line, (char*)buffer);
	}
	return (0);
}*/

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
		printf("%s\n", line);
		free(line);
	}
	printf("end ret: %d\n", ret);
}
