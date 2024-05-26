


#include "includes/philosophers.h"



pthread_mutex_t mutix;
void *reutine(void *arg)
{
    pthread_mutex_lock(&mutix);
    printf("good lock\n");
    sleep(1);
    pthread_mutex_unlock(&mutix);

    return(NULL);
}




int main ()
{
    pthread_t tr[4];

    pthread_mutex_init(&mutix,NULL);
    for (int i = 0; i <  4; i++)
    {
        pthread_create(&tr[i], NULL, reutine, NULL);
    }
    
    for (int i = 0; i <  4; i++)
    {
        pthread_join(tr[i], NULL);
    }

}