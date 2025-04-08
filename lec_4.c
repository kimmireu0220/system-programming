/*
Linux 시스템 프로그래밍 과제 (Lec4 정리)
*/

#include <stdio.h>
#include <string.h>

int main() {
    // 1) 현재 디렉토리 확인 및 파일 목록 보기
    // $ pwd
    // $ ls
    // -> 현재 로그인 디렉토리와 파일 확인

    // 2) /etc 디렉토리 이동 및 텍스트 파일 필터링
    // $ cd /etc
    // $ file * | grep text

    // 3) /etc/passwd, stdio.h, ls의 위치 확인 및 차이 비교
    // $ whereis passwd
    // $ whereis stdio.h
    // $ whereis ls
    // $ ls -l /usr/bin/passwd /etc/passwd
    // $ file /usr/bin/passwd /etc/passwd
    // -> /usr/bin/passwd는 실행파일, /etc/passwd는 텍스트 파일

    // 4) ex1.c 작성 및 실행
    // $ vi ex1.c
    // 내용:
    // #include <stdio.h>
    // void main() { printf("hello\n"); }
    // $ gcc -o ex1 ex1.c
    // $ ./ex1

    // 5) 파일 내용 확인 및 ASCII 확인
    // $ cat ex1.c
    // $ xxd ex1.c

    // 6) 실행파일은 cat으로 확인 불가, objdump로 확인 가능
    // $ objdump -D -M intel ex1 > x
    // $ vi x
    // -> main 함수 검색

    // 6-1) 기계어 코드 주소 확인
    // $ xxd ex1 > x
    // $ vi x (ex: /5548 로 검색)

    // 7) 파일 복사 및 삭제/이름 변경
    // $ cp ex1.c ex2.c
    // $ cp ex1.c ex3.c
    // $ cp ex1.c ex4.c
    // $ rm ex2.c
    // $ mv ex3.c y.c

    // 8) 디렉토리 생성 및 파일 이동
    // $ mkdir d1
    // $ cp y.c d1

    // 9) 표준 출력 리다이렉션
    // $ ./ex1 > f1
    // $ cat f1

    // 10) grep으로 "hello" 검색
    // $ grep -nr "hello" *

    // 11) 전체 프로세스 확인
    // $ ps -ef

    // 12) 현재 터미널 확인
    // $ tty

    // 13) 두 수 입력받아 합 출력
    int a, b;
    printf("두 수를 입력하세요: ");
    scanf("%d %d", &a, &b);
    printf("합: %d\n", a + b);

    // 14) 무한 루프 추가
    printf("hello\n");
    fflush(stdout);
    for(;;);

    // 15~17) 백그라운드 실행 및 프로세스 제어
    // $ ./ex1 &
    // $ ps
    // $ kill <PID>
    // 새 터미널에서 확인 및 종료

    // 18) gets vs fgets 차이
    char buf[20];
    printf("enter a sentence\n");
    gets(buf);
    printf("I got %s from you. length:%ld\n", buf, strlen(buf));
    printf("enter the same sentence again\n");
    fgets(buf, 20, stdin);
    printf("I got %s from you. length:%ld\n", buf, strlen(buf));

    // 19) 문장 그대로 출력
    char line[100];
    printf("Enter a sentence\n");
    fgets(line, 100, stdin);
    printf("You entered %s\n", line);

    // 20) ex1.c 의 처음 20바이트 보기
    // $ xxd ex1.c

    // 21) ELF 포맷 확인
    // $ xxd ex1 | head
    // -> 7f 45 4c 46 = \x7F E L F

    // 22) Cygwin 사용자는 PE 포맷 확인
    // -> DOS header: 4d 5a (MZ)

    // 23) Mac 사용자는 Mach-O 포맷 확인
    // -> file ex1

    return 0;
}
