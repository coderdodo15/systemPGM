#include <stdio.h>

// 터미널 화면을 지우는 프로그램
int main() {
    // ANSI 이스케이프 코드를 사용하여 화면을 지우고(J) 커서를 홈 위치로(H) 이동
    printf("\033[H\033[J");
    return 0;
}
