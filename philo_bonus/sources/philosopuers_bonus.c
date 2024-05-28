


// int main (int argc , char **argv)
// {
//     t_data data;
//     t_philo *philo;


// 	if (check_arguments(argc, argv, &data) != 0)
// 		return (1);
//     philo = initialize_philosophers(&data);
//     if (philo == NULL)
//         return(1);
// }

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#define NBR 4

sem_t *semaphore;

void* routine(void* arg) {
    int index = *(int*)arg;// Free the allocated memory
    puts("==========");
    // Use the semaphore
    sem_wait(semaphore);
    printf("Thread %d in critical section\n", index);
    sem_post(semaphore);

    return NULL;
}

int main() {
    pthread_t th[NBR];
    semaphore = (sem_open("/mysemaphore", O_CREAT, 2, 1));
    if (semaphore == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < NBR; i++) {
        int *a = malloc(sizeof(int));
        if (a == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) {
            perror("pthread_create");
            free(a);
            exit(EXIT_FAILURE);
        }
            for (int i = 0; i < NBR; i++) {
                pthread_join(th[i], NULL);
        }
    }

    return 0;
}