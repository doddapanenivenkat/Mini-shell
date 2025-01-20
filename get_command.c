#include "main.h"

char *get_command(char *input_string)
{

    char *ptr = malloc(25 * sizeof(char));

    if (ptr == NULL)
    {
	perror("Memory not allocated\n");
	exit(0);
    }
    int i = 0;
    while (input_string[i] != ' ' && input_string[i] != '\0')
    {
        ptr[i] = input_string[i];
        i++;
    }
    ptr[i] = '\0';
    return ptr;
}

