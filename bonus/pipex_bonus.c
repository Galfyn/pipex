/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:41:06 by galfyn            #+#    #+#             */
/*   Updated: 2021/11/15 18:40:40 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_heredoc(char *limited)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		ft_error("Pipe", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Fork", 1);
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(0, &line))
		{
			if (ft_strnstr(line, limited, ft_strlen(limited)))
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_child(char *cmd, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_error("Pipe", 1);
	pid = fork();
	if (pid == -1)
		ft_error("Pid", 1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(cmd, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	ft_open_file(char *path, int code)
{
	int	fd;

	fd = 0;
	if (code == 0)
	{
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (fd == -1)
			ft_error("File out", 1);
	}
	if (code == 1)
	{
		fd = open(path, O_RDONLY, 0777);
		if (fd == -1)
			ft_error("File out", 1);
	}
	if (code == 2)
	{
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd == -1)
			ft_error("File out", 1);
	}
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	f_in;
	int	f_out;

	if (argc < 6)
		ft_error("Error: Not enough arguments\n", 2);
	if (ft_strnstr(argv[1], "here_doc", 8))
	{
		i = 3;
		f_out = ft_open_file(argv[argc - 1], 0);
		ft_heredoc(argv[2]);
	}
	else
	{
		i = 2;
		f_out = ft_open_file(argv[argc - 1], 2);
		f_in = ft_open_file(argv[1], 1);
		dup2(f_in, STDIN_FILENO);
	}
	while (i < argc - 2)
		ft_child(argv[i++], envp);
	dup2(f_out, STDOUT_FILENO);
	ft_execute(argv[argc - 2], envp);
	exit(0);
}
