#include "main.h"

SignalNode *head = NULL;
int status;
void signal_to_list(char *input_string, int pid)
{

    SignalNode *new = malloc(sizeof(SignalNode));

    if (new == NULL)
    {
	perror("Insertion Failure\n");
	return;
    }

    strcpy(new->command,input_string);
    new->pid = pid;
    new->next = head;
    head = new;
} 
void cmd_buffer(char *buffer)
{
    if (head != NULL)
    {
	signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	strcpy(buffer, head->command);
	pid = fork();
	if (pid == 0)
	{
	    execute_external_commands(buffer);
	}
	else
	{
	    waitpid(pid, &status, WUNTRACED);
	}
	head = head->next;
    }
    else
    {
	printf("\nNo command");
	return;
    }
}
void display()
{
    SignalNode *temp = head;

    while (temp)
    {
	printf("%s\t%d\n",temp->command,temp->pid);
	temp = temp->next;
    }
}
