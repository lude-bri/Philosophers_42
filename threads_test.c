#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	make_coffee(char *name)
{
	printf("Barista %s is making coffee...\n", name);
	sleep(3);
	printf("coffee ready!\n");
}

int	main(int ac, char **av)
{
	make_coffee("Luca");
	make_coffee("Paolo");
}
