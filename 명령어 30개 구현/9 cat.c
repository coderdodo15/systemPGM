#include <stdio.h>

// 파일의 내용을 읽어 화면에 출력하는 프로그램
int main(int argc, char *argv[]) {
    // 사용자가 파일명을 입력하지 않은 경우 예외 처리
    if (argc < 2) {
        printf("사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    // argv[1]에 담긴 파일명을 읽기(r) 모드로 열기
    FILE *fp = fopen(argv[1], "r");
    
    // 파일이 존재하지 않거나 열기 실패한 경우
    if (fp == NULL) {
        perror("cat error (파일을 열 수 없습니다)");
        return 1;
    }

    char ch;
    // 파일의 끝(EOF: End Of File)을 만날 때까지 한 글자씩 읽어서 출력
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    // 열었던 파일 닫기
    fclose(fp);
    return 0;
}
