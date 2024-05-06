#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
    time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
   if (stat1.st_size > stat2.st_size)
      printf("text1 is bigger\n\n");
   else if (stat1.st_size < stat2.st_size)
      printf("text2 is bigger\n\n");
   else
      printf("sizes are equal\n\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    stat("text1", &stat1);
      stat("text2", &stat2);
   
   printf("block compare\n");
   if(stat1.st_blocks > stat2.st_blocks)
      printf("text1 is bigger\n\n");
   else if(stat1.st_blocks < stat2.st_blocks)
      printf("text2 is bigger\n\n");
   else
      printf("blocks are equal\n\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {
    int mon1, mon2, day1, day2;

    mon1 = time1->tm_mon + 1;
    mon2 = time2->tm_mon + 1;
    day1 = time1->tm_mday;
    day2 = time2->tm_mday;

    printf("date compare\n");
    if (mon1 > mon2) {
        printf("text2 is early\n\n");
    }
    else if (mon1 < mon2) {
        printf("text1 is early\n\n");
    }
    else {
        if (day1 > day2) {
            printf("text2 is early\n\n");
        }
        else if (day1 < day2) {
            printf("text1 is early\n\n");
        }
        else {
            printf("same date\n\n");
        }
    }
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {
    int time_1 = time1->tm_hour * 60 + time1->tm_min;
    int time_2 = time2->tm_hour * 60 + time2->tm_min;

    printf("time compare\n");
    if (time_1 > time_2) {
        printf("text2 is early\n\n");
    }
    else if (time_2 > time_1) {
        printf("text1 is early\n\n");
    }
    else {
        printf("same time\n\n");
    }
}