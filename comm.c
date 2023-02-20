#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void shell_loop(void)
{
	char *command = NULL;
	size_t command_size = 0;
	pid_t pid;
	int status;

		while (1)
		{
			printf("$ ");
			if (getline(&command, &command_size, stdin) == -1)
			{
				if (feof(stdin))
				{
					exit(EXIT_SUCCESS);
				}
				else
				{
					perror("getline");
					exit(EXIT_FAILURE)
				}
			}
			if (command[strlen(command) - 1] == '\n')
			{
				command[strlen(command) - 1] = '\0';
			}
			char *args[BUFFER_SIZE];
			int i = 0;

			args[i] = strtok(command, " ");
			while (args[i] != NULL)
			{
				i++;
				args[i] = strtok(NULL, " ");
			}
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			execvp(args[0], args);
			perror("exec");
			exit(EXIT_FAILURE);

			else
			{
				waitpid(pid, &status, 0);
			}
		}
		free(command);
}
int main(int argc, char *argv[])
{
	shell_loop();
		return EXIT_SUCCESS;
}
