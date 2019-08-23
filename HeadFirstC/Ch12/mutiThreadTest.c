//This program is to test mutilthreads

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <pthread.h>



void error(char *msg){
    fprintf(stderr, "%s, %s\n", msg, strerror(errno));
    exit(1);
}

void* does_not(void *a){
    int i=0;
    for(i=0;i<5;i++){
        sleep(1);
        puts("NO!");
    }
    return NULL;
}


void* does_yes(void *a){
    int i=0;
    for(i=0;i<5;i++){
        sleep(1);
        puts("YES!");
    }
    return NULL;
}

int main(){
    // thread var
    pthread_t t0;
    pthread_t t1;
    if(pthread_create(&t0, NULL, does_not, NULL)==-1)
        error("Can't create thread t0 Does_not!");
    if(pthread_create(&t1, NULL, does_yes, NULL)==-1)
        error("Can't create thread t1 Does_yes!");

    //waiting not killed threads
    // join function waiting thread finish then exit program
    void* result;
    if(pthread_join(t0, &result)==-1)
        error("Can't join thread t0");

    if(pthread_join(t1, &result)==-1)
        error("Can't join thread t1");


    return(0);

}



