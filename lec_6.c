/*
1) Make a file, "f1", and fill it with more than 20 bytes.
*/

// 사용한 명령어:
// $ vi f1
// (vi 편집기에서 아래 내용을 입력 후 :wq 로 저장)
// I have a dream
// that one day this nation
// will rise up and
// live out the true 
// meaning of its creed
// that all men are created equal.

// 설명:
// vi를 이용해 20바이트 이상 텍스트를 입력한 파일 f1을 생성.

/*
2) Try the code in 6-0), 6-1), 6-2), 6-3), 6-4), 6-5). For 6-3) explain the strange output.
*/

// 각각 별도의 프로그램으로 실습하고 6-3)의 이상한 출력은 read()에서 받은 y값이 아닌 20바이트 고정으로 write()를 했기 때문입니다.

/*
3) Find the byte size of f2 with “ls –l f2”. Use xxd to find out the actual data stored in f2.
*/

// $ ls -l f2
// $ xxd f2

// 설명: ls -l은 파일 크기를, xxd는 내용의 16진수 표현을 보여줍니다.

/*
3-1) Write a program that counts the number of bytes in f2.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int x = open("f2", O_RDONLY);
    char buf[1];
    int cnt = 0;
    while (read(x, buf, 1)) {
        cnt++;
    }
    close(x);
    printf("f2 byte count: %d\n", cnt);
    return 0;
}

/*
4) Write a program "hw4.c" that opens f2 and shows each byte of it in hexadecimal number, decimal number, and character.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int x = open("f2", O_RDONLY);
    unsigned char buf[1];
    while (read(x, buf, 1)) {
        printf("%02x %d %c\n", buf[0], buf[0], buf[0]);
    }
    close(x);
    return 0;
}

/*
5) Compile hw4.c with -g option and run gdb to execute each instruction one by one.
*/

// 사용 명령어:
// $ gcc -g -o hw4 hw4.c
// $ gdb hw4
// (gdb 내 명령어 예시)
// b main
// r
// n
// p x
// x/4xb buf

// 설명:
// gdb를 사용해 디버깅하며 변수의 값과 메모리 상태를 확인할 수 있습니다.

/*
6) Write a program that creates a file and writes “how are you doing?” in it.
*/

#include <fcntl.h>
#include <unistd.h>

int main() {
    int x = open("f3", O_RDWR | O_CREAT | O_TRUNC, 00777);
    write(x, "how are you doing?", 18);
    close(x);
    return 0;
}

/*
6-1) Repeat Problem 6 but pass a string variable to "write" this time.
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int x = open("f3", O_RDWR | O_CREAT | O_TRUNC, 00777);
    char y[] = "how are you doing?";
    write(x, y, strlen(y));
    close(x);
    return 0;
}

/*
7) Copy hw4.c into another file cphw4.c using open(), read(), and write().
*/

#include <fcntl.h>
#include <unistd.h>

int main() {
    int x1 = open("hw4.c", O_RDONLY);
    int x2 = open("cphw4.c", O_RDWR | O_CREAT | O_TRUNC, 00777);
    char buf[20];
    int y;
    while ((y = read(x1, buf, 20))) {
        write(x2, buf, y);
    }
    close(x1);
    close(x2);
    return 0;
}

/*
8) Make a copy of "hw4" (binary) into another file "cphw4".
*/

// 위와 동일한 코드를 파일명만 변경하여 사용.

/*
9) Repeat 7) but get file names from user.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char src[50], dest[50];
    printf("Enter src file name\n");
    scanf("%s", src);
    printf("Enter dest file name\n");
    scanf("%s", dest);
    int x1 = open(src, O_RDONLY);
    int x2 = open(dest, O_RDWR | O_CREAT | O_TRUNC, 00777);
    char buf[20];
    int y;
    while ((y = read(x1, buf, 20))) {
        write(x2, buf, y);
    }
    close(x1);
    close(x2);
    printf("%s is copied into %s successfully.\n", src, dest);
    return 0;
}

/*
10) Write "mycat" that displays the contents of a file in characters.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char fname[50];
    printf("Enter file name\n");
    scanf("%s", fname);
    int x = open(fname, O_RDONLY);
    char buf[1];
    while (read(x, buf, 1)) {
        write(1, buf, 1);
    }
    close(x);
    return 0;
}

/*
11) Write "myxxd" that displays file contents in hexadecimal.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char fname[50];
    printf("Enter file name\n");
    scanf("%s", fname);
    int x = open(fname, O_RDONLY);
    unsigned char buf[1];
    while (read(x, buf, 1)) {
        printf("%02x ", buf[0]);
    }
    close(x);
    return 0;
}

// 12) Run following code and display f8 with cat and xxd respectively. Explain the results.
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int x = open("f8", O_CREAT|O_RDWR|O_TRUNC, 00777);
    write(x, "ab", 2);
    int y = 10;
    write(x, &y, 4);
    write(x, "cd", 2);
    y = 235;
    write(x, &y, 4);
    return 0;
}
// 설명: 파일 f8에 문자열 'ab'를 쓰고, 정수 10(4바이트), 문자열 'cd', 그리고 정수 235(4바이트)를 순서대로 저장한다.
// 실행 명령어 및 결과:
// $ gcc -o hw12 hw12.c
// $ ./hw12
// $ cat f8 → abcd (일부 바이너리 데이터는 cat으로 보이지 않음)
// $ xxd f8 → 헥사값으로 데이터 확인 가능


// 12-1) Run following code and display f8 with cat and xxd respectively. Explain the results.
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int x = open("f8", O_CREAT|O_RDWR|O_TRUNC, 00777);
    write(x, "ab", 2);
    int y = 10;
    write(x, &y, 8);
    write(x, "cd", 2);
    y = 235;
    write(x, &y, 8);
    return 0;
}
// 설명: 정수 y를 8바이트로 쓰기 때문에 총 파일 크기가 더 커짐. 시스템에 따라 값의 위치 및 정렬이 다를 수 있다.


// 13) Write a program that divides a given file into three small files of roughly equal size. Use fstat() to find out the size of a file.
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    char fname[] = "f9";
    int x = open(fname, O_RDONLY);
    struct stat st;
    fstat(x, &st);
    int total = st.st_size;
    int part = total / 3;
    int remain = total % 3;
    char buf[100];

    for(int i=0; i<3; i++){
        char newname[10];
        sprintf(newname, "f9%d", i+1);
        int y = open(newname, O_CREAT|O_RDWR|O_TRUNC, 00777);
        int len = (i < 2) ? part : part + remain;
        read(x, buf, len);
        write(y, buf, len);
        close(y);
    }
    close(x);
    return 0;
}


// 13-1) Modify your code in Problem 13 so that the user can specify the number of small files.
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(){
    char fname[20];
    int n;
    printf("Enter file name to split\n");
    scanf("%s", fname);
    printf("How many small files you want to split it into?\n");
    scanf("%d", &n);

    int x = open(fname, O_RDONLY);
    struct stat st;
    fstat(x, &st);
    int total = st.st_size;
    int part = total / n;
    int remain = total % n;
    char buf[1024];

    for(int i=0; i<n; i++){
        char newname[20];
        sprintf(newname, "f9%d", i+1);
        int y = open(newname, O_CREAT|O_RDWR|O_TRUNC, 00777);
        int len = (i < n-1) ? part : part + remain;
        read(x, buf, len);
        write(y, buf, len);
        close(y);
    }
    close(x);
    return 0;
}


// 14) What is wrong with following program?
// 원인: temp1[0]과 temp2[0]이 같은 주소(temp0)를 가리키기 때문에, 두 입력값이 겹침
// 해결: temp0의 값을 각각 다른 메모리로 복사해줘야 함

#include <stdio.h>
#include <string.h>

int main(){
    char temp0[20], *temp1[10], *temp2[10];
    char t1[20], t2[20];
    printf("enter src file name\n");
    gets(temp0);
    strcpy(t1, temp0);
    temp1[0] = t1;
    printf("enter dest file name\n");
    gets(temp0);
    strcpy(t2, temp0);
    temp2[0] = t2;
    printf("src file:%s dest file:%s\n", temp1[0], temp2[0]);
    return 0;
}


// 15) What is wrong with following program. Find the problem with GDB and fix it.
// 문제점: write 시 buf에는 마지막 1바이트만 남아 있어서, cnt 바이트 전체가 아닌 한 바이트만 기록됨
// 해결 방법: 모든 데이터를 buf에 저장하고 cnt 바이트를 기록하거나, 파일 포인터를 처음부터 다시 읽도록 처리

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    int x = open("f1", O_RDONLY, 00777);
    int x1 = open("f2", O_WRONLY | O_CREAT | O_TRUNC, 00777);
    char buf[512];
    int cnt = 0, y;
    char all[512];

    while ((y = read(x, buf, 1)) > 0) {
        all[cnt++] = buf[0];
    }
    write(x1, all, cnt);
    close(x);
    close(x1);
    return 0;
}
