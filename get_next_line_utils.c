/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liferrer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:02:15 by liferrer          #+#    #+#             */
/*   Updated: 2020/03/11 16:49:46 by liferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;
	int	i;

	str = (char *)s;
	i = 0;
	if (c == 0)
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (i--)
				str++;
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int	i;

	i = 0;
	if (!(str = (char *)malloc((ft_strlen((char*)s1) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	if (s1)
	{
		s1 = NULL;
		free(s1);
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	j;
	char	*cpy;

	i = 0;
	j = 0;
	if (!(cpy = (char *)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		cpy[i] = s2[j];
		i++;
		j++;
	}
	cpy[i] = '\0';
	if (s1)
		free(s1);
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char	*str;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i < start + len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
