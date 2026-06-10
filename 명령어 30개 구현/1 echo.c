#include <stdio.h>

// 입력한 문자열을 화면에 출력하는 프로그램
int main(int argc, char *argv[]) {
    // argv[1]부터 마지막 인자까지 공백으로 구분하여 출력
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
        if (i < argc - 1) {
            printf(" ");
        }
    }
    printf("\n"); // 줄바꿈
    return 0;
}
