#include <stdio.h>
#include <string.h>

// 문자열을 역순으로 출력하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <문자열>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    int len = strlen(str);

    // 문자열의 맨 끝 글자(len - 1)부터 시작해서 앞글자(0)까지 거꾸로 반복 출력
    for (int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    printf("\n");

    return 0;
}
