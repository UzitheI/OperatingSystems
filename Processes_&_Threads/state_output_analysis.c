//this particular problem is to analyse round roibin or similar algorithm working to simultaneously provide cpu time to process

#include<stdio.h>
#include<unistd.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        for(;;)
        printf("I am a child.");
    }
    else if (pid>0)
    {
        printf("I am a parent."); 
    }
    return 0;
}