#include<stdio.h>
#include<unistd.h>

int main(){
    printf("This is to demonstrate the fork: \n");
    fork();
    fork();
    printf("Hi everybody.%d\n",pid());
    return 0;
}