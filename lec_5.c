#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void problem1() {
    char x, y;
    x = 'a'; y = 97;
    printf("%d %c %d %c\n", x, x, y, y); // 'a'는 아스키 코드 97이므로 둘 다 동일
    char *x1 = "hello";
    printf("%s %p %s %p\n", x1, x1, "hello", "hello"); // 문자열 상수는 주소이므로 주소 동일
}

void problem2() {
    char x[10];
    x[0]='a'; x[1]='b'; x[2]='c'; x[3]='d'; x[4]='e';
    x[5]='f'; x[6]='g'; x[7]='h'; x[8]='i'; x[9]='j';
    for(int i = 0; i < 10; i++) {
        printf("%d %c \n", x[i], x[i]); // 각 문자의 아스키 값과 문자 출력
    }
}

void problem3() {
    char x[10];
    for(int i = 0; i < 10; i++) {
        x[i] = i + 97; // 아스키 코드 97부터 시작하는 문자들
    }
    for(int i = 0; i < 10; i++) {
        printf("%d %c \n", x[i], x[i]);
    }
}

void problem4() {
    char x[128];
    for(int i = 0; i < 128; i++) {
        x[i] = i;
    }
    for(int i = 0; i < 128; i++) {
        printf("%d %c %d\n", x[i], x[i], x[i]);
    }
}

void problem5() {
    char x[100];
    printf("Enter a string: ");
    scanf("%s", x);
    printf("The length is %ld\n", strlen(x));
}

void problem6() {
    char x[100];
    printf("Enter a string: ");
    scanf("%s", x);
    for(int i = 0; x[i] != '\0'; i++) {
        printf("%c\n", x[i]);
    }
}

void problem6_1() {
    char x[10];
    strcpy(x, "hello");
    strcpy(x, "hi");
    for(int i = 0; i < 10; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void problem6_2() {
    char x[100];
    printf("한글 문자열 입력 (예: 우리 나라): ");
    fgets(x, 100, stdin);
    int slen = strlen(x);
    for(int i = 0; i < slen; i++) {
        printf("%x ", (unsigned char)x[i]);
    }
    printf("\n");
}

void problem7() {
    char x[100];
    while (1) {
        printf("Enter a string: ");
        scanf("%s", x);
        printf("You entered %s. length=%ld\n", x, strlen(x));
        if (strcmp(x, "hello") == 0) {
            printf("Yes it is hello. Bye.\n");
            break;
        } else {
            printf("No it is not hello\n");
        }
    }
}

void problem8() {
    char x[100], a[100], b[100], c[100];
    printf("Enter a string: ");
    scanf("%s", x);
    strcpy(a, x); a[0] = 'a';
    strcpy(b, x); b[0] = 'b';
    strcpy(c, x); c[0] = 'c';
    printf("After copying and changing the first letter\n");
    printf("%s %s %s\n", a, b, c);
}

void problem9() {
    char *x = "hello", *y = "hi", *z = "bye";
    printf("%s %s %s\n", x, y, z);
    printf("%p %p %p\n", x, y, z);
}

void problem10() {
    // char x[20];
    // x = "hello";  // 에러: 배열에는 주소를 직접 할당할 수 없음
    // 수정 방법: strcpy(x, "hello");
}

void problem11() {
    // char *y;
    // strcpy(y, "hello2"); // y가 가리키는 공간이 없음
    // 수정 방법:
    char y[20];
    strcpy(y, "hello2");
    printf("%s\n", y);
}

void problem12() {
    // char *y;
    // scanf("%s", y); // 공간이 없음
    // 수정 방법:
    char y[100];
    printf("Enter a string: ");
    scanf("%s", y);
    printf("You entered %s\n", y);
}

void problem13() {
    char *x[10];
    x[0] = "hi"; x[1] = "bye"; x[2] = "hello";
    x[3] = (char *)malloc(50);
    strcpy(x[3], "there");
    x[4] = (char *)malloc(50);
    printf("Enter a string: ");
    scanf("%s", x[4]);
    for(int i = 0; i < 5; i++) {
        printf("%s\n", x[i]);
    }
}

void problem14() {
    char *x[10];
    int count = 0;
    while (1) {
        char temp[100];
        printf("Enter a string: ");
        scanf("%s", temp);
        if (strcmp(temp, "end") == 0) break;
        x[count] = (char *)malloc(strlen(temp) + 1);
        strcpy(x[count], temp);
        count++;
    }
    printf("Strings entered so far are\n");
    for(int i = 0; i < count; i++) {
        printf("%s ", x[i]);
    }
    printf("\n");
}

void problem15() {
    char x[100];
    printf("enter a sentence\n");
    gets(x);
    int slen = strlen(x);
    printf("sentence length after gets:%d\n", slen);
    for(int i = 0; i < slen; i++) {
        printf("%x ", x[i]);
    }
    printf("\nenter the same sentence\n");
    fgets(x, 99, stdin);
    slen = strlen(x);
    printf("sentence length after fgets:%d\n", slen);
    for(int i = 0; i < slen; i++) {
        printf("%x ", x[i]);
    }
    printf("\n");
}

void problem16() {
    char buf[100];
    char copy[100];
    char *tokens[50];
    printf("Enter a sentence: ");
    fgets(buf, 100, stdin);
    strcpy(copy, buf);

    int count = 0;
    char *tok = strtok(copy, " \n");
    while (tok != NULL) {
        tokens[count++] = tok;
        tok = strtok(NULL, " \n");
    }
    printf("You entered %s", buf);
    printf("There were %d words:\n", count);
    for(int i = 0; i < count; i++) {
        printf("%s\n", tokens[i]);
    }
    printf("The original sentence was: %s\n", buf);
}

void problem17() {
    char *x[10];
    int count = 0;
    while (1) {
        char temp[100];
        printf("Enter a name: ");
        fgets(temp, 100, stdin);
        temp[strcspn(temp, "\n")] = 0;
        if (strcmp(temp, "bye") == 0) break;
        x[count] = (char *)malloc(strlen(temp) + 1);
        strcpy(x[count], temp);
        count++;
    }
    printf("There were %d names.\n", count);
    for(int i = 0; i < count; i++) {
        printf("%s\n", x[i]);
    }
}

void problem18() {
    int x3;
    char x2[12];
    char x1[12];
    x1[0] = 33;
    x3 = 44;
    strcpy(x2, "abcdefghijkl");
    printf("%p %p %p %d %d %s\n", x1, x2, &x3, x1[0], x3, x2);
    // 이상하게 보이는 이유는 x2의 overflow로 인해 x3의 값이 덮여졌기 때문
}

void problem19() {
    // char * strarr[10] = {NULL};
    // strcpy(strarr[1], "bye"); // 공간 없음
    // 수정 방법:
    char *strarr[10] = {NULL};
    strarr[0] = "hello";
    strarr[1] = (char *)malloc(10);
    strcpy(strarr[1], "bye");
    printf("%s %s\n", strarr[0], strarr[1]);
}

// 문제 20 구현용 함수들
void get_sentence(char *buf) {
    printf("Enter a sentence: ");
    fgets(buf, 100, stdin);
    buf[strcspn(buf, "\n")] = 0;
}

int tokenize(char *buf, char *tokens[]) {
    int count = 0;
    char *tok = strtok(buf, " ");
    while (tok) {
        tokens[count++] = tok;
        tok = strtok(NULL, " ");
    }
    return count;
}

void display_tokens(char *tokens[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

int compute_unique_tokens(char *tokens[], int ntok, char *uniq[]) {
    int count = 0;
    for (int i = 0; i < ntok; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(tokens[i], uniq[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) uniq[count++] = tokens[i];
    }
    return count;
}

void compute_freq(char *tokens[], int ntok, char *uniq[], int nuniq, int freq[]) {
    for (int i = 0; i < nuniq; i++) freq[i] = 0;
    for (int i = 0; i < ntok; i++) {
        for (int j = 0; j < nuniq; j++) {
            if (strcmp(tokens[i], uniq[j]) == 0) freq[j]++;
        }
    }
}

void show_freq(int freq[], char *uniq[], int nuniq) {
    for (int i = 0; i < nuniq; i++) {
        printf("%s: %d\n", uniq[i], freq[i]);
    }
}

void show_max_freq_word(char *uniq[], int nuniq, int freq[]) {
    int max = freq[0];
    int idx = 0;
    for (int i = 1; i < nuniq; i++) {
        if (freq[i] > max) {
            max = freq[i];
            idx = i;
        }
    }
    printf("The word with the max freq: %s\n", uniq[idx]);
}

void problem20() {
    char buf[100];
    get_sentence(buf);
    char *tokens[50];
    int ntok = tokenize(buf, tokens);
    printf("You entered %s\n", buf);
    printf("There were %d words: ", ntok);
    display_tokens(tokens, ntok);

    char *uniq[50];
    int nuniq = compute_unique_tokens(tokens, ntok, uniq);
    printf("Unique tokens are: ");
    display_tokens(uniq, nuniq);

    int freq[50];
    compute_freq(tokens, ntok, uniq, nuniq, freq);
    show_freq(freq, uniq, nuniq);
    show_max_freq_word(uniq, nuniq, freq);
}

int main() {
    // problem1();
    return 0;
}