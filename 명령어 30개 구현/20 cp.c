#include <stdio.h>

// 파일을 복사하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("사용법: %s <원본파일> <대상파일>\n", argv[0]);
        return 1;
    }

    FILE *src = fopen(argv[1], "rb"); // 원본 파일 열기 (이진 읽기 모드)
    if (src == NULL) {
        perror("cp 에러 (원본 파일을 열 수 없습니다)");
        return 1;
    }

    FILE *dst = fopen(argv[2], "wb"); // 대상 파일 열기 (이진 쓰기 모드)
    if (dst == NULL) {
        perror("cp 에러 (대상 파일을 생성할 수 없습니다)");
        fclose(src);
        return 1;
    }

    char buffer[1024];
    size_t n;
    // 원본 파일에서 버퍼 크기만큼 읽어서 대상 파일에 그대로 쓰기
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }

    fclose(src);
    fclose(dst);
    return 0;
}
