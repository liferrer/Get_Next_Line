/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:51:29 by liferrer          #+#    #+#             */
/*   Updated: 2020/03/05 17:28:47 by liferrer         ###   ########.fr       */
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
	*line = ft_substr(*stock, 0, i - 1);
	tmp = *stock;
	*stock = ft_substr(*stock, i + 1, (ft_strlen(*stock) - i - 1));
	free(tmp);
	return (1);
}

int		dealwith_eof(char **stock, char **line)
{
	char			*tmp;

	*line = ft_strdup(*stock);
	tmp = *stock;
	*stock = ft_strdup("");
	free(tmp);
	if (ft_strchr(*stock, '\n'))
		return (1);
	return (0);

}

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*stock = NULL;
	char			*tmp;
	char			buffer[BUFFER_SIZE + 1];

	ret = 0;
	if (fd < 0 || fd > OPEN_MAX || !line || !fd)
		return (-1);

	if (!stock)
		stock = ft_strdup("");

	if (ft_strchr(stock, '\n'))
			return (get_stock_split(&stock, line));

	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	tmp = stock;
	stock = ft_strjoin(stock, buffer);
	free(tmp);

	if (ret < BUFFER_SIZE && !(ft_strchr(stock, '\n')))
		return (dealwith_eof(&stock, line));
	return (get_next_line(fd, line));
}

/*int		main(void)
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
	printf("|%d|%s", ret, line);
	free(line);
}*/
