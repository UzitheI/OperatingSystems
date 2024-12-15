#include<stdio.h>
#include<unistd.h>

int main(){
    int pid, ppid;
    pid=getpid();
    ppid= getppid();
    printf("\n The Process ID is %d \n", pid);
    printf("\n The Parent Process ID is %d \n", ppid);
    return 0;
}
