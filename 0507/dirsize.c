while ((d = readdir(dp)) != NULL) { //디렉터리 내의 각 파일
sprintf(path, "%s/%s", dir, d->d_name); // 파일경로명 만들기
if (lstat(path, &st) < 0) // 파일 상태 정보 가져오기
perror(path);
printf("%5d %s", st->st_size, d->name); // 블록 수, 파일 이름 출력
putchar('\n');
}

