#include "pipex.h"

static void ft_child(char **argv, char **envp, int *fd)
{
	int		fd_input;
	char 	**command;
	char 	*path;

	fd_input = open(argv[1], O_RDONLY, 0777);
	if (fd_input == -1)
		perror("In file");
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	close(fd[0]);
	command = ft_split(argv[2], ' ');
	path = ft_command(command[0], envp, 0);
	if (execve(path, command, envp) == -1)
		perror("Command");
	ft_free_arr(command);
	free(path);
}

static void ft_parent(char **argv, char **envp, int *fd)
{
	int		fd_out;
	char	**command;
	char 	*path;

	fd_out = open(argv[4], O_WRONLY| O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		perror("Out file");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(fd[1]);
	command = ft_split(argv[3], ' ');
	path = ft_command(command[0], envp, 0);
	if (execve(path, command, envp) == -1)
		perror("Command2");
	ft_free_arr(command);
	free(path);
}

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	int pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("Pipe");
		pid = fork();
		if (pid == -1)
			perror("Pid");
		if (pid == 0)
			ft_child(argv, envp, fd);
		waitpid(pid, NULL, 0);
		ft_parent(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
	}
	else
		exit(1);

	return 0;
}
