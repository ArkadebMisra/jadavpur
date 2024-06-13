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

#define NUM_VALUES 10

void generateRandomNumbers(double* numbers) {
    srand(time(NULL));
    for (int i = 0; i < NUM_VALUES; i++) {
        numbers[i] = rand() % 1000;
    }
}

int main() {
    int size = (NUM_VALUES+5)*(sizeof(double));

    const char *name="a5q1";
    int shm_fd = shm_open(name, O_CREAT|O_RDWR, 0666);
    ftruncate(shm_fd, size);

    double *ptr = (double *)mmap(0, size, PROT_READ|PROT_WRITE, MAP_SHARED, shm_fd, 0);

    int s1 = semGet(420, 1);
    int s2 = semGet(421, 1);

    setVal(s1, 0, 0);


    if(fork()==0){
        //child
        wait(s1, 0);

        double m=ptr[0];
        double mx = ptr[0];
        double s=0;

        for(int i=0;i<NUM_VALUES;i++){
            if(ptr[i]<m){
                m=ptr[i];
            }
            if(ptr[i]>mx){
                mx = ptr[i];
            }
            s += ptr[i];
        }

        ptr[NUM_VALUES] = m;
        ptr[NUM_VALUES+1] = mx;
        ptr[NUM_VALUES+2] = s/NUM_VALUES;
        signal(s2, 0);

    }
    else{
        // parent
        double rand_num[NUM_VALUES];

        generateRandomNumbers(rand_num);

        for (int i=0;i<NUM_VALUES;i++){
            ptr[i] = rand_num[i];
        }

        signal(s1, 0);
        wait(s2, 0);

        printf("%lf %lf %lf", ptr[NUM_VALUES], ptr[NUM_VALUES+1], ptr[NUM_VALUES+2]);

        shm_unlink(name);



    }

    return 0;
}






