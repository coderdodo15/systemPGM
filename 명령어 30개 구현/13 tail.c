#include <stdio.h>
#include <string.h>

// 파일의 맨 뒷부분 5줄만 출력하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("tail 에러");
        return 1;
    }

    char lines[100][256]; // 최대 100줄까지 임시 저장할 배열
    int count = 0;

    // 파일을 끝까지 읽으며 배열에 한 줄씩 저장
    while (fgets(lines[count], sizeof(lines[count]), fp) != NULL) {
        count++;
    }
    fclose(fp);

    // 전체 줄 수 중에서 마지막 5줄만 역산해서 출력 시작 위치 계산
    int start = (count > 5) ? count - 5 : 0;

    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
    }

    return 0;
}
