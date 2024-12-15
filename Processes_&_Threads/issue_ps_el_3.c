//execute the program and issue the command ps-el three times in every 10 seconds and analyze their output 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

void execute_ps_command(int iteration){
    printf("\n Iteration %d: Executing 'ps -el' command...\n",iteration);
    system("ps -el");
}
int main(){
    pid_t pid;
    int status;
    pid=fork();
    if(pid<0){
        fprintf(stderr,"Fork Failed\n");
        return 1;
    }
    else if(pid==0){
        printf("Child Process: Executing 'threadsum' program ...\n");
        execl("./threadsum","threadsum",(char*)NULL);
        fprintf(stderr, "Failed to execute threadsum\n"); 
        exit(1);
    }
    else{
        for(int i=1;i<=3;i++){
            execute_ps_command(i);
            sleep(10);
        }
        waitpid(pid, &status, 0);
        if(WIFEXITED(status)){
            printf("Child process exited with status %d\n",WEXITSTATUS(status));
        }
        else{
            printf("Child process did not exit normally\n"); 
        }
    }
    return 0;
}