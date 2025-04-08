/*
 * Lec 8 – 시스템 프로그래밍 오픈북 시험 대비 정리
 */

/*
0) 현재 디렉토리(.)를 PATH에 추가 (macOS의 경우 .zprofile에 설정)
*/
// $ cd ~
// $ ls -a
// .zprofile 또는 .bashrc, .bash_profile 파일이 있는지 확인
// .bash_profile에 다음 추가:
// if [ -f ~/.bashrc ]; then
//    source ~/.bashrc
// fi
// .bashrc 또는 .zprofile에 다음 추가:
// export PATH=$PATH:.
// $ source ~/.zprofile  (또는 .bashrc)
// $ echo $PATH → PATH 끝에 . 포함되어야 함

/*
1) 명령줄 인자를 받지 않는 프로그램
*/
#include <stdio.h>
int main() {
    printf("hi\n");
    return 0;
}

/*
2) 명령줄 인자 1개를 받는 프로그램
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("hi\n");
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    return 0;
}

/*
3) 명령줄 인자 2개를 받는 프로그램
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("hi\n");
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    return 0;
}

/*
4) 명령줄 인자 3개를 받는 프로그램
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("hi\n");
    printf("%d\n", argc);
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);
    printf("%s\n", argv[2]);
    return 0;
}

/*
5) 가변 인자 수를 받는 프로그램
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    int i;
    printf("argc is %d\n", argc);
    for (i = 0; i < argc; i++) {
        printf("argv[%d] is %s\n", i, argv[i]);
    }
    return 0;
}

/*
6) myecho와 echo의 차이
*/
#include <stdio.h>
int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}

/*
7) mycat - cat과 유사한 기능
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    int x, y;
    char buf[20];
    x = open(argv[1], O_RDONLY);
    if (x == -1) {
        perror("mycat");
        exit(1);
    }
    while ((y = read(x, buf, 20)) > 0) {
        write(1, buf, y);
    }
    close(x);
    return 0;
}

/*
7-2) 환경변수 인식하는 myecho
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '%') {
            char *val = getenv(&argv[i][1]);
            if (val) printf("%s ", val);
        } else {
            printf("%s ", argv[i]);
        }
    }
    printf("\n");
    return 0;
}

/*
8) mycat2 - 함수 분리 버전
*/
void display_content(int x) {
    char buf[20];
    int y;
    while ((y = read(x, buf, 20)) > 0) write(1, buf, y);
}
int main(int argc, char *argv[]) {
    int x = open(argv[1], O_RDONLY);
    if (x == -1) { perror("error in open"); exit(1); }
    display_content(x);
    close(x);
    return 0;
}

/*
9) mycat3 - show_file 함수로 분리
*/
void show_file(char *fname) {
    int x = open(fname, O_RDONLY);
    if (x == -1) { perror("error in open"); exit(1); }
    display_content(x);
    close(x);
}
int main(int argc, char *argv[]) {
    show_file(argv[1]);
    return 0;
}

/*
10) gdb로 mycat3 디버깅
*/
// $ gcc -g -o mycat3 mycat3.c
// $ gdb mycat3
// (gdb) b main
// (gdb) r f1 f2 f3
// (gdb) s / n / p 변수명 등으로 확인

/*
10-1) 무한 루프 문제 디버깅: if (y=0) → 잘못된 조건문 (y == 0 으로 수정 필요)
*/

/*
11) 두 개의 파일을 출력하는 mycat
*/
// $ mycat f1 f2
// → f1, f2의 내용을 순서대로 출력

/*
12) mycat이 임의 개수의 파일을 출력하도록 수정
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    char buf[20];
    int y;
    for (int i = 1; i < argc; i++) {
        int x = open(argv[i], O_RDONLY);
        if (x == -1) { perror(argv[i]); continue; }
        while ((y = read(x, buf, 20)) > 0) write(1, buf, y);
        close(x);
    }
    return 0;
}

/*
13) mycp - 파일 복사
*/
int docopy(const char *src, const char *dst) {
    int x1 = open(src, O_RDONLY);
    int x2 = open(dst, O_WRONLY | O_CREAT | O_TRUNC, 00777);
    char buf[1024];
    int y;
    while ((y = read(x1, buf, 1024)) > 0) write(x2, buf, y);
    close(x1); close(x2);
    return 0;
}

/*
14) myxxd - 파일을 16진수로 출력
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    int x = open(argv[1], O_RDONLY);
    unsigned char buf[1];
    while (read(x, buf, 1)) {
        printf("%02x ", buf[0]);
    }
    printf("\n");
    close(x);
    return 0;
}

/*
15) mycat 다양한 옵션 처리 (-o, -x, -p, -d)
*/
// -o: 파일 복사 → mycat -o f1 f2
// -x: 16진수 출력 → mycat -x f1
// -p: /etc/passwd 파싱 출력 → fopen(), fgets(), strtok() 활용
// -d: 디렉토리 내부 파일 출력 → opendir(), readdir() 사용
// 참고: man 5 passwd, man 3 opendir, man 3 readdir
