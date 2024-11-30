#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#define TH 100

uint64_t	ledger = 0;

pthread_mutex_t		ledger_lock;

void	*update_ledger(void *data)
{
	pthread_mutex_lock(&ledger_lock);
	ledger += 1;
	pthread_mutex_unlock(&ledger_lock);
	return (NULL);
}

int	main(void)
{
	pthread_t	waiters[TH];

	// pthread_mutex_init(&legder_lock, NULL);
	for (int i = 0; i < TH; i++)
		pthread_create(waiters + i, NULL, update_ledger, NULL);
	for (int i = 0; i < TH; i++)
		pthread_join(waiters[i], NULL);
	printf("\t%lu\n", ledger);
}
