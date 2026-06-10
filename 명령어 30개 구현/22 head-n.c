#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// head -n <라인수> <파일명> 형태로 실행하는 프로그램
int main(int argc, char *argv[]) {
    // 인자 개수 확인 (옵션이 들어가므로 최소 4개 필요)
    if (argc < 4 || strcmp(argv[1], "-n") != 0) {
        printf("사용법: %s -n <줄수> <파일명>\n", argv[0]);
        return 1;
    }

    int target_lines = atoi(argv[2]); // 출력할 줄 수 정수 변환
    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        perror("head -n 에러");
        return 1;
    }

    char line[256];
    int count = 0;

    // 지정한 target_lines 만큼만 반복해서 한 줄씩 출력
    while (fgets(line, sizeof(line), fp) != NULL && count < target_lines) {
        printf("%s", line);
        count++;
    }

    fclose(fp);
    return 0;
}
