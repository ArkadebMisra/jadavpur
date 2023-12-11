#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct time{
    int hour;
    int min;
    int sec;
}TIME;


TIME add(TIME time1, TIME time2){

    TIME time3;
    time3.hour = time1.hour + time2.hour;
    time3.min = time1.min + time2.min;
    time3.sec = time1.sec + time2.sec;

    if(time3.sec>60){
        time3.min += time3.sec/60;
        time3.sec  = time3.sec%60;
    }


    if(time3.min>60){
        time3.hour += time3.min/60;
        time3.min  = time3.min%60;
    }
    return time3;
}

int main(){
    TIME time1, time2, time3;
    printf("Enter hour minute second\n");
    scanf("%d %d %d", &time1.hour, &time1.min, &time1.sec);

    fflush(stdin);

    printf("Enter hour minute second\n");
    scanf("%d %d %d", &time2.hour, &time2.min, &time2.sec);

    time3 = add(time1, time2);

    printf("%d %d %d\n", time3.hour, time3.min, time3.sec);

    
    return 0;
}