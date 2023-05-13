#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int main()
{
int count = 0;
int in = 0;
int out = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t not_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t not_empty = PTHREAD_COND_INITIALIZER;
void *producer(void *arg) 
{
    int i;
    for (i = 0; i < 4; i++) {
        pthread_mutex_lock(&mutex);
        while (count == BUFFER_SIZE) {
            printf("Buffer is full, waiting...\n");
            pthread_cond_wait(&not_full, &mutex);
        }
        buffer[in] = i;
        printf("Produced %d\n", i);
        in = (in + 1) % BUFFER_SIZE;
        count++;
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void *consumer(void *arg) {
    int item, i;
    for (i = 0; i < 4; i++) {
        pthread_mutex_lock(&mutex);
        while (count == 0) {
            printf("Buffer is empty, waiting...\n");
            pthread_cond_wait(&not_empty, &mutex);
        }
        item = buffer[out];
        printf("Consumed %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        count--;
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main() {
    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    Return 0;
}
