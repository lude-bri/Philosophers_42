#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*make_coffee(void *data)
{
	printf("Barista is making coffee...\n");
	sleep(3);
	printf("coffee ready!\n");
	return (NULL);
}

int	main(int ac, char **av)
{
	pthread_t	barista_1;
	pthread_t	barista_2;

	pthread_create(&barista_1, NULL, make_coffee, NULL);
	pthread_create(&barista_2, NULL, make_coffee, NULL);
	
	pthread_join(barista_1, NULL);
	pthread_join(barista_2, NULL);
}
