/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <galfyn@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 10:44:23 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/21 01:18:33 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countWord(char const *s, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			size++;
		}
	}
	return (size);
}

static	int	ft_countChr(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void	*ft_clear(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		lenWord;

	if (!s)
		return (NULL);
	lenWord = ft_countWord(s, c);
	i = 0;
	result = (char **)malloc(sizeof(char *) * (lenWord + 1));
	if (result == NULL)
		return (NULL);
	while (i < lenWord)
	{
		while (*s == c && *s != '\0')
			s++;
		result[i] = ft_substr(s, 0, ft_countChr(s, c));
		if (result[i] == NULL)
			return (ft_clear(result, i));
		s = s + ft_countChr(s, c);
		i++;
	}
	result[i] = NULL;
	return (result);
}
