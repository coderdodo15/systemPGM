#include <stdio.h>

// 파일의 앞부분 5줄만 출력하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("head 에러");
        return 1;
    }

    char line[256];
    int count = 0;

    // 파일에서 한 줄씩 읽어오되, 딱 5번만 반복하고 종료
    while (fgets(line, sizeof(line), fp) != NULL && count < 5) {
        printf("%s", line);
        count++;
    }

    fclose(fp);
    return 0;
}
