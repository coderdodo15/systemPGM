#include <stdio.h>
#include <stdlib.h>

// 현재 사용자 이름을 출력하는 프로그램
int main() {
    char *username = getenv("USER"); // User 환경 변수 값 읽어들이기.
    
    if (username != NULL) {
        printf("%s\n", username);
    } else {
        perror("사용자 정보를 찾을 수 없습니다!"); // 에러 발생 시 메시지 출력
        return 1;
    }
    return 0;
}
