#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_1(void *arg)
{
	printf("Nous sommes dans le thread 1\n");

	/* Pour enlever le warning */
	(void) arg;
	pthread_exit(NULL);
}

void *thread_2(void *arg)
{
	printf("Nous sommes dans le thread 2\n");

	/* Pour enlever le warning */
	(void) arg;
	pthread_exit(NULL);
}

void *thread_3(void *arg)
{
	printf("Nous sommes dans le thread 3\n");

	/* Pour enlever le warning */
	(void) arg;
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	printf("Avant la création du thread.\n");

	if (pthread_create(&thread1, NULL, thread_1, NULL)) {
		perror("pthread_create");
		return EXIT_FAILURE;
	}

	if (pthread_join(thread1, NULL)) {
		perror("pthread_join");
		return EXIT_FAILURE;
	}

	if (pthread_create(&thread2, NULL, thread_2, NULL)) {
		perror("pthread_create");
		return EXIT_FAILURE;
	}

	if (pthread_join(thread2, NULL)) {
		perror("pthread_join");
		return EXIT_FAILURE;
	}

	if (pthread_create(&thread3, NULL, thread_3, NULL)) {
		perror("pthread_create");
		return EXIT_FAILURE;
	}

	if (pthread_join(thread3, NULL)) {
		perror("pthread_join");
		return EXIT_FAILURE;
	}

	printf("Après la création du thread.\n");

	return EXIT_SUCCESS;
}

