#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tail -n <라인수> <파일명> 형태로 실행하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 4 || strcmp(argv[1], "-n") != 0) {
        printf("사용법: %s -n <줄수> <파일명>\n", argv[0]);
        return 1;
    }

    int target_lines = atoi(argv[2]);
    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL) {
        perror("tail -n 에러");
        return 1;
    }

    char lines[100][256];
    int count = 0;

    while (fgets(lines[count], sizeof(lines[count]), fp) != NULL) {
        count++;
    }
    fclose(fp);

    // 사용자가 요청한 target_lines 만큼 뒤에서부터 시작 위치 계산
    int start = (count > target_lines) ? count - target_lines : 0;

    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}
