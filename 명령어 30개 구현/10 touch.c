#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h> 

// 빈 파일을 생성하거나 파일 수정 시간을 갱신하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    // 1. 추가(a) 모드로 파일을 열어 파일이 없으면 자동으로 생성
    FILE *fp = fopen(argv[1], "a"); 
    
    if (fp == NULL) {
        perror("touch 파일 열기 실패");
        return 1;
    }
    fclose(fp);

    // 2. 이미 존재하는 파일이거나 새로 만든 파일의 타임스탬프를 현재 시간으로 갱신
    // 두 번째 인자에 NULL을 주면 자동으로 '현재 시간'이 세팅.
    if (utime(argv[1], NULL) != 0) {
        perror("touch 시간 갱신 실패");
        return 1;
    }

    return 0;
}
