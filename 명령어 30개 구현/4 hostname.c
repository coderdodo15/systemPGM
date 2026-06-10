#include <stdio.h>
#include <unistd.h>

// 호스트 이름을 출력하는 프로그램
int main() {
    char hostname[256];
    
    // 호스트 이름을 버퍼에 저장 (성공 시 0 반환)
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("%s\n", hostname);
    } else {
        perror("gethostname() error");
        return 1;
    }
    return 0;
}
