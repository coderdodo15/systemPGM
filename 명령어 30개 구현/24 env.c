#include <stdio.h>

// 시스템의 전역 환경 변수 배열을 외부(extern)에서 참조합니다.
extern char **environ;

int main() {
    // env 명령어는 인자 없이 실행하며, environ 배열의 끝(NULL)까지 돌며 출력합니다.
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
    return 0;
}
