


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
       #include <fcntl.h>          
       #include <sys/stat.h>        
#define NBR 4

sem_t *semaphore;

void* routine(void* arg) {
    int index = *(int*)arg;
    puts("==========");
    sem_wait(semaphore);
    sleep(1);
    printf("Thread %d in critical section\n", index);
    sem_post(semaphore);

    return NULL;
}

int main() {
    pthread_t th[NBR];
    sem_unlink("/mysemaphore");

    semaphore = (sem_open("/mysemaphore", O_CREAT, 0644, 1));
    for (int i = 0; i < NBR; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &routine, a);
    }
        for (int i = 0; i < NBR; i++) {
            pthread_join(th[i], NULL);
        }
    return 0;
}