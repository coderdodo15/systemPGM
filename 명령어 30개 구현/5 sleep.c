#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 입력된 시간만큼 대기하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <초>\n", argv[0]);
        return 1;
    }

    int seconds = atoi(argv[1]); // 문자열을 정수로 변환
    sleep(seconds);              // 지정된 초만큼 대기
    
    return 0;
}
