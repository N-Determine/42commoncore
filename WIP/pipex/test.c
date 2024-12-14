#include <unistd.h>
#include <stdlib.h>

char *interpreter = "/bin/bash";

int main(int ac, char **av)
{
	char *args1[] = { interpreter, "-c", "echo Hello World", NULL };
	execve(interpreter, args1, NULL);
}
	
		
