#include <stdio.h>
#include <sys/utsname.h> // 리눅스 시스템 정보 구조체가 담긴 헤더

// 커널 이름을 출력하는 프로그램
int main() {
    struct utsname buffer;

    // uname 시스템 콜을 호출하여 buffer 구조체에 시스템 정보를 채움
    if (uname(&buffer) != 0) {
        perror("uname 에러");
        return 1;
    }

    // 구조체 멤버 중 sysname(운영체제 이름) 출력
    printf("%s\n", buffer.sysname);
    return 0;
}
