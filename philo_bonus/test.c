#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <fcntl.h>          
#include <sys/stat.h> 

#define NBR 20

sem_t *semaphore;


void* routine(void* arg) {
    int index = *(int*)arg;
    printf("value of semaphore is |%d|\n", SEM_VALUE);
    sleep(1);
    printf("player %d is loginn\n", index);
    sem_post(semaphore);
    printf("player %d is log out\n", index);
    return NULL;
}

int main() {
    pthread_t th[NBR];
    sem_unlink("/mysemaphore");
    semaphore = (sem_open("/mysemaphore", O_CREAT, 0644, 2));
    for (int i = 0; i < NBR; i++) {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&th[i], NULL, &routine, a);
    }
    sem_wait(semaphore);
        for (int i = 0; i < NBR; i++) {
            pthread_join(th[i], NULL);
        }
    return 0;
}