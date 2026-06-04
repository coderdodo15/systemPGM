6/4
[9장 프로세스 생성]
컴퓨터 밑 실행 창에 떠있는 여러 실행되어 있는 어플들이 바로 프로세스.

프로세스 생성: 부모 프로세스가 자식 프로세스 생성.
fork: 부모를 복제하여 새로운 자식 프로세스 생성.(자기 복제)
 #include <sys/types.h>
 #include <unistd.h>
 pid_t fork(void); 
 새로운 자식 프로세스를 생성한다. 자식 프로세스에게는 0을 리턴하고 부모
 프로세스에게는 자식 프로세스 ID를 리턴한다.

fork2: 부모와 자식 프로세스 구분.

#include <stdlib.h>
#include <stdio.h>
#include <unistd,h>

/* 부모 프로세스가 자식 프로세스를 생성하고 서로 다른 메시지를 프린트 */
int main()
{
int pid;
pid = fork();
if (pid ==0) { // 자식 프로세스
printf("[Child] : Hello, world pid=%d\n", getpid());
}
else { // 부모 프로세스
printf("[Parent] : Hello, world pid=%d\n", getpid());
}
}

실행 결과: 
$ fork2
[Parent] Hello, world! pid= n
[Child] Hello, world! pid= n+1

wait: 자식 프로세스중 하나가 끝날 때까지 기다림. 종료 코드가 status에 저장되고, 끝난 자식 프로세스의 번호를 리턴.

exec: 프로그램 내의 프로그램이 완전히 새로운 걸로 대체.
fork/exec: fork 후에 exec 호출. 호출 성공시 자식은 새로운 프로그램을 생성하게 되고, 부모는 계속해서 다음 코드를 생성.

system: 명령어를 전부 이곳에서 적을 수 있음.

