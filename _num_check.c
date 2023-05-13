#include "monty.h"

char *_num_checker(char *number)
{
	int counter = 0;

	while (number[counter])
	{
		strtok(number, " \n");
		if (isdigit(number[counter]) == 0 && number[counter] != '-')
			exit(EXIT_FAILURE);
		counter++;
	}

	return (number);
}