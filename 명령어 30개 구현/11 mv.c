#include <stdio.h>

// 파일의 이름이나 경로를 변경하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <원본파일> <대상파일/경로>\n", argv[0]);
        return 1;
    }

    // rename(기존이름, 새이름) 함수 호출 (성공 시 0)
    if (rename(argv[1], argv[2]) != 0) {
        perror("mv 에러 (이동/변경 실패)");
        return 1;
    }

    return 0;
}
