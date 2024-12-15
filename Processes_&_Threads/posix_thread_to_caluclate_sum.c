#include<stdio.h>
#include<pthread.h>
typedef struct 
{
    int n;
    long sum;
} ThreadData;

void * calculate_sum(void* arg){
    ThreadData * data= (ThreadData*)arg;
    data->sum=0;
    printf("Here are our numbers:\n");
    for(int i=1;i<=data->n;i++){    
        printf("%d\t\n",i);
        data->sum +=i;
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t thread;
    ThreadData data;
    printf("Enter a positive number\n");
    scanf("%d",&data.n);
    pthread_create(&thread ,NULL, calculate_sum,(void*) &data );
    pthread_join(thread, NULL);
    printf("The sum of numbers up to %d is: %ld\n", data.n, data.sum);
    return 0;
}
