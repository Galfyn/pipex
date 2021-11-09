#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

# ifndef	BUFFER_SIZE
# define	BUFFER_SIZE 32
# endif

char	*ft_command(char *argv, char **envp, int i);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_free_arr(char **arr);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		get_next_line(int fd, char **line);

#endif
