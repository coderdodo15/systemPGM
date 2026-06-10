#include <stdio.h>

// 파일의 총 줄(Line) 수를 세는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("wc 에러");
        return 1;
    }

    char ch;
    int lines = 0;
    // 파일을 한 글자씩 읽으면서 줄바꿈 문자('\n')를 만날 때마다 카운트 증가
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }

    printf("%d %s\n", lines, argv[1]);
    fclose(fp);
    return 0;
}
