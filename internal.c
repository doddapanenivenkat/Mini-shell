#include "main.h"

extern char prompt[100];
void execute_internal_commands(char *input_string)
{
    if (strncmp("exit",input_string,4) == 0)
    {
	exit(1);
    }

    if (strncmp("pwd",input_string,3) == 0)
    {
	char buffer[100];

	getcwd(buffer,sizeof(buffer));

	printf("%s\n",buffer);
    }

    if (strncmp("clear",input_string,5) == 0)
    {
	system("clear");
    }

    if (strncmp("cd",input_string,2) == 0)
    {
	int i,flag = 0;

	for (i = 2;input_string[i] == ' ';i++)
	{
	    flag++;
	}

	char *path = &input_string[2 + flag];

	if (strlen(path) == 0)
	{
	    perror("cd : Error\n");
	    exit(1);
	}
	else
	{
	    if (chdir(path) == 0)
	    {
		strcat(prompt,"/");
		strcat(prompt,path);
	    }
	    else
	    {
		perror("cd Error\n");
	    }
	}
    }
}
