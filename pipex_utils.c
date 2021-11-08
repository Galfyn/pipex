#include "pipex.h"
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (haystack == needle || ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (haystack[i] != '\0' && len > i)
	{
		n = 0;
		while (needle[n] != '\0' && haystack[i + n] == needle[n]
		&& i + n < len && haystack[i + n] != '\0')
			n++;
		if (n == ft_strlen(needle))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

