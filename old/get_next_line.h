/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:32:31 by liferrer          #+#    #+#             */
/*   Updated: 2020/02/24 13:35:59 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_fd
{
	int				fd;
	char			*reste;
	struct s_fd		*next;
}					t_fd;

char			*ft_strchr(const char *s, int c);
char			*ft_strcat(char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
char			*ft_strdup( char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				get_next_line(const int fd, char **line);
#endif
