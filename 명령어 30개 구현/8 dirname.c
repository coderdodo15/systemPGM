#include <stdio.h>
#include <string.h>

// 경로에서 디렉토리 부분만 추출하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <경로>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    char *last_slash = strrchr(path, '/'); // 뒤에서부터 '/' 위치 찾기

    if (last_slash != NULL) {
        *last_slash = '\0'; // '/' 위치를 문자열의 끝으로 만들어 자름
        printf("%s\n", path);
    } else {
        printf(".\n"); // '/'가 없으면 현재 디렉토리(.) 출력
    }
    return 0;
}
