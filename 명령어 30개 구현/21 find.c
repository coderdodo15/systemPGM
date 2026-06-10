#include <stdio.h>
#include <string.h>
#include <dirent.h> // 디렉토리 탐색용 헤더

// 현재 디렉토리에서 특정 파일이 있는지 검색하는 프로그램
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("사용법: %s <찾을파일명>\n", argv[0]);
        return 1;
    }

    // 현재 디렉토리(".") 열기
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("find 디렉토리 열기 실패");
        return 1;
    }

    struct dirent *entry;
    int found = 0;

    // 디렉토리 안의 파일들을 하나씩 읽으며 사용자가 입력한 이름(argv[1])과 비교
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, argv[1]) == 0) {
            printf("./%s (파일을 찾았습니다)\n", entry->d_name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("'%s' 파일을 찾을 수 없습니다.\n", argv[1]);
    }

    closedir(dir);
    return 0;
}
