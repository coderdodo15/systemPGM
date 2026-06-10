#include <stdio.h>
#include <string.h>

// 경로 문자열에서 맨 오른쪽 파일명만 파싱하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <전체경로>\n", argv[0]);
        return 1;
    }

    char *path = argv[1];
    // 문자열의 뒤에서부터 첫 번째로 나오는 슬래시('/') 위치를 찾
    char *last_slash = strrchr(path, '/');

    if (last_slash != NULL) {
        // 슬래시 바로 다음 글자부터가 진짜 파일 이름.
        printf("%s\n", last_slash + 1);
    } else {
        // 경로에 슬래시가 없다면 입력된 문자열 자체가 파일 이름.
        printf("%s\n", path);
    }

    return 0;
}
