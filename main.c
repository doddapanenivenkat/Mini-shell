#include "main.h"

//create an array
char prompt[100] = {"venkat21@LAPTOP/MINISHELL$"};
char input_string[100];

int main()
{
    //implement clear commad to clear the section

    system("clear");

    scan_input(prompt, input_string);

    return 0;
}

void signal_handler(int signum)
{
    if (signum == SIGINT)
    {
	printf("\n%s",prompt);
	fflush(stdout);
    }

    if (signum == SIGTSTP)
    {
	if (*input_string)
	{
	    signal_to_list(input_string, pid);
	}
	else if (signum == SIGCHLD)
	{
	    printf("\n%s",prompt);
	}
	else
    	    printf("\n%s",prompt);
	fflush(stdout);
    }
}


