#include "main.h"

void echo(char *input_string, int status)
{
    if (strncmp("echo $?",input_string,7) == 0)
    {
	//exit status of last command
	printf("%d\n",status);

    }

    if (strncmp("echo $$",input_string,7) == 0)
    {
	//PID of minishell

	printf("%d\n",getpid());
    }

    if (strncmp("echo $SHELL",input_string,11) == 0)
    {
	//shell name

	char *ptr = getenv("SHELL");
	printf("%s\n",ptr);
    }

}

