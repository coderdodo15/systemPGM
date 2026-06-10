#include <stdio.h>
#include <unistd.h>

// 하드 링크를 생성하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <원본파일> <링크파일>\n", argv[0]);
        return 1;
    }

    // link(원본, 생성할링크) 시스템 콜 호출
    if (link(argv[1], argv[2]) != 0) {
        perror("link error");
        return 1;
    }
    return 0;
}
