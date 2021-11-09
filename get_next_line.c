/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 07:11:20 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/21 01:14:47 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1)
		s1 = "";
	i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

static char	*gnl_copy(char const *remain)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	str = malloc(sizeof (char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (remain[j] != '\n' && remain[j] != '\0')
	{
		str[j] = remain[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_clean(char *remain)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = "";
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	if (remain[i] == '\0')
	{
		free(remain);
		return (NULL);
	}
	if (remain[i++] == '\n')
	{
		tmp = malloc(sizeof(char) * (ft_strlen(remain) - i) + 1);
		if (!tmp)
			return (NULL);
		while (remain[i] != '\0')
			tmp[j++] = remain[i++];
	}
	tmp[j] = '\0';
	free(remain);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	*remain;
	size_t		read_size;
	char		*buf;
	char		*tmp;

	read_size = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	buf = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	while ((remain == NULL || !ft_strchr(remain, '\n')) && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		tmp = remain;
		remain = gnl_strjoin(remain, buf);
		if (tmp)
			free(tmp);
	}
	*line = gnl_copy(remain);
	remain = ft_clean(remain);
	free(buf);
	if (read_size == 0)
		return (0);
	return (1);
}
