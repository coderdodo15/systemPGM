#include <stdio.h>
#include <time.h> // 시간 관련 헤더

// 현재 월을 알려주는 프로그램
int main() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t); // 현재 시간 구조체 획득

    // tm_mon은 0부터 시작하므로(0=1월) +1을 해줍니다.
    printf("   현재 대시보드 달력\n");
    printf("====== %d년 %d월 ======\n", tm_info->tm_year + 1900, tm_info->tm_mon + 1);
    return 0;
}
