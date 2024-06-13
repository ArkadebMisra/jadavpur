#include"sema.h"
#include<stdio.h>
#include<unistd.h>


#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

void p1f(int p1, int p2){
    // printf("%d %d\n", getVal(p1, 0), getVal(p2, 0));
    for(int i=0;i<20;i++){
        // printf("%d %d\n", getVal(p1, 0), getVal(p2, 0));
        wait(p1, 0);
        printf("A");
        fflush(stdout);
        signal(p2,0);
    }

}


void p2f(int p1, int p2, int p3){
    int turn=0;
    for(int i=0;i<20;i++){
        wait(p2, 0);
        printf("B");
        fflush(stdout);
        if(turn==0){
            signal(p3,0);
            turn=1;
        }else{
            signal(p1, 0);
            turn=0;
        }
    }    
    
}

void p3f(int p1, int p2, int p3){
    int turn=0;
    for(int i=0;i<20;i++){
        wait(p3, 0);
        printf("C");
        fflush(stdout);
        if(turn==0){
            signal(p3,0);
            turn=1;
        }else{
            signal(p1, 0);
            turn=0;
        }
    } 

    
}
int main(){

    int p1, p2, p3;
    p1 = semGet(1234, 1);
    p2 = semGet(5678, 1);
    p3 = semGet(9101, 1);

    setVal(p1, 0, 1);
    setVal(p2, 0, 0);
    setVal(p3, 0, 0);

    if(fork()==0){
        p1f(p1, p2);
        exit(0);
    }

    if(fork()==0){
        p2f(p1, p2, p3);
        exit(0);
    }

    if(fork()==0){
        p3f(p1, p2, p3);
        exit(0);
    }
    while(1){

    }

    return 0;
}