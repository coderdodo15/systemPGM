#include <stdio.h>
#include <unistd.h>

// 빈 디렉토리를 삭제하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <디렉토리명>\n", argv[0]);
        return 1;
    }

    // 디렉토리 삭제 시스템 콜 호출 (성공 시 0, 실패 시 -1)
    if (rmdir(argv[1]) != 0) {
        perror("rmdir error"); // 실패 원인 출력 (예: 디렉토리가 비어있지 않음 등)
        return 1;
    }
    return 0;
}
