#include <stdio.h>
#include <sys/utsname.h>

// 시스템 아키텍처를 출력하는 프로그램
int main() {
    struct utsname buffer;

    if (uname(&buffer) != 0) {
        perror("arch 에러");
        return 1;
    }

    // 구조체 멤버 중 machine(하드웨어 아키텍처 정보) 출력
    printf("%s\n", buffer.machine);
    return 0;
}
