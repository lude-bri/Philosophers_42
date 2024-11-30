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
	pthread_t	baristas[10];

	for (int i = 0; i < 10; ++i)
		pthread_create(baristas + i, NULL, make_coffee, NULL);

	for (int i = 0; i < 10; ++i)
		printf("Identifier-> %lu\n", baristas[i]);

	for (int i = 0; i < 10; ++i)
		pthread_join(baristas[i], NULL);
}
