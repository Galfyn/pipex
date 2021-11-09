#include "pipex.h"

static void ft_herdoc(char *limited)
{
	int fd[2];
	pid_t pid;
	char *line;

	if (pipe(fd) == -1)
		perror("Pipe");
	pid = fork();
	if (pid == -1)
		perror("Pid");
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(0, &line))
		{
			if (ft_strnstr(line, limited, ft_strlen(limited)) == 0)
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

static void ft_child(char *cmd, char **envp)
{
	int fd[2];
	int pid;
	char **command;
	char *path;

	if (pipe(fd) == -1)
		perror("Pipe");
	pid = fork();
	if (pid == -1)
		perror("Pid");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		command = ft_split(cmd, ' ');
		path = ft_command(command[0], envp, 0);
		execve(path, command, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int main(int argc, char **argv, char **envp)
{
	int i;
	int f_in;
	int f_out;
	char **command;
	char *path;

	if (argc >= 5)
	{
		if (ft_strnstr(argv[1], "here_doc", 8) == 0)
		{
			i = 2;
			f_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
			ft_herdoc(argv[2]);
		}
		else
		{
			i = 1;
			f_in = open(argv[1], O_RDONLY, 0777);
			f_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			dup2(f_in, STDIN_FILENO);
		}
		while (++i < argc - 2)
			ft_child(argv[i], envp);
		dup2(f_out, STDOUT_FILENO);
		command = ft_split(argv[argc - 2], ' ');
		path = ft_command(command[0], envp, 0);
		execve(path, command, envp);
	}
}