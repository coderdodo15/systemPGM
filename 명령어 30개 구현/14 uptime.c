#include <stdio.h>

// 시스템이 켜져 있던 시간을 출력하는 프로그램
int main() {
    // 리눅스는 가동 시간을 /proc/uptime 이라는 가상 파일에 초 단위로 기록해 둡니다.
    FILE *fp = fopen("/proc/uptime", "r");
    if (fp == NULL) {
        perror("uptime 에러");
        return 1;
    }

    double uptime_seconds;
    // 파일에서 첫 번째 실수(초)를 읽어옵니다.
    if (fscanf(fp, "%lf", &uptime_seconds) == 1) {
        printf("시스템 가동 시간: %.2f 초\n", uptime_seconds);
    }

    fclose(fp);
    return 0;
}
