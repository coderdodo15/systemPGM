#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// 파일의 상세 정보를 구조체로부터 읽어와 출력하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    struct stat file_stat;

    // stat 시스템 콜을 호출하여 file_stat 구조체에 파일 정보를 담음
    if (stat(argv[1], &file_stat) < 0) {
        perror("stat 조회 에러");
        return 1;
    }

    printf("  파일명: %s\n", argv[1]);
    printf("  파일 크기: %ld 바이트\n", file_stat.st_size);
    printf("  아이노드(Inode) 번호: %ld\n", file_stat.st_ino);
    printf("  파일 권한 플래그(모드): %o (8진수)\n", file_stat.st_mode & 0777);

    return 0;
}
