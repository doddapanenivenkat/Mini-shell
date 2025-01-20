#include "main.h"

char buffer[30];
int status;
//extern char buff[1024];

void scan_input(char *prompt, char *input_string)
{
    char *command;
    while (1)
    {
	signal(SIGINT,signal_handler);
	signal(SIGTSTP,signal_handler);
	printf("%s",prompt);
	scanf("%[^\n]",input_string);	
	getchar();
	if (!(strncmp("PS1",input_string,3)))
	{
	    if (input_string[3] == ' ' || input_string[5] == ' ' || input_string[4] == ' ')
	    {
		printf("Command not found\n");
	    }
	    else{
		strcpy(prompt,&input_string[4]);
	    }
	}
	
	command = get_command(input_string);

	int ret = check_command_type(command);

	if (ret == EXTERNAL)
	{


	    pid = fork();

	    if (pid == 0)
	    {
		//child process
		signal(SIGINT,SIG_DFL);
		signal(SIGTSTP,SIG_DFL);

		//execute external command
		if (strstr(input_string, "|") == NULL)	
	    	    execute_external_commands(input_string);
		else
		    execute_npipe(input_string);
	    }
	    else 
	    {
		//parent process
		waitpid(pid,&status,WUNTRACED);
	    }
	}
	else if (ret == BUILTIN)
	{
	    //execute internal commands
	    
	    execute_internal_commands(input_string);
	}

	//Implement echo 
	echo(input_string,status);

	if (strncmp("jobs",input_string,4) == 0)
	{
	    display();
	}

	if (strncmp("fg",input_string,2) == 0)
	{
	    cmd_buffer(buffer);
	}

	input_string[0] = 0;
    }
}

