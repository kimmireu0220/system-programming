/*
 * Lec 7 – 시스템 프로그래밍 오픈북 시험 대비 정리
 * 목적: WAV 파일 분석, 파일 조작, 디버깅 등의 실습 문제 정리
 */

/*
1) swvader03.wav 다운로드 후 xxd로 분석
*/
// $ cp /cygdrive/c/Users/your-user-name/Downloads/lect7/swvader03.wav .
// $ xxd swvader03.wav > x
// $ vi x
// 결과 예시:
// ChunkID: 52 49 46 46 → "RIFF"
// ChunkSize: 34 76 00 00 → 30260
// Format: 57 41 56 45 → "WAVE"
// Subchunk1ID: 66 6d 74 20 → "fmt "
// Subchunk1Size: 10 00 00 00 → 16
// ...

/*
2) swvader03.wav 헤더 필드 읽어 출력하는 프로그램
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int read_wav() {
    char ChunkID[10], Format[10];
    int ChunkSize;
    short AudioFormat;
    int x = open("swvader03.wav", O_RDONLY);
    int y;

    y = read(x, ChunkID, 4); ChunkID[y] = 0;
    y = read(x, &ChunkSize, 4);
    y = read(x, Format, 4); Format[y] = 0;
    y = read(x, &AudioFormat, 2);

    printf("ChunkID: %s\n", ChunkID);
    printf("ChunkSize: %d\n", ChunkSize);
    printf("Format: %s\n", Format);
    printf("AudioFormat: %d\n", AudioFormat);
    close(x);
    return 0;
}

/*
3) 위 내용을 파일로 출력하는 버전 (sw2-wav.txt)
*/
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int write_wav_info() {
    char ChunkID[10], Format[10];
    int ChunkSize;
    short AudioFormat;
    int x = open("swvader03.wav", O_RDONLY);
    FILE *fout = fopen("sw2-wav.txt", "w");
    int y;

    y = read(x, ChunkID, 4); ChunkID[y] = 0;
    y = read(x, &ChunkSize, 4);
    y = read(x, Format, 4); Format[y] = 0;
    y = read(x, &AudioFormat, 2);

    fprintf(fout, "ChunkID: %s\n", ChunkID);
    fprintf(fout, "ChunkSize: %d\n", ChunkSize);
    fprintf(fout, "Format: %s\n", Format);
    fprintf(fout, "AudioFormat: %d\n", AudioFormat);

    close(x); fclose(fout);
    return 0;
}

/*
4) swvader03.wav → sw2.wav로 복사 후 앞 절반 0으로 덮어쓰기 ("master"만 남기기)
*/
int mute_half() {
    int in = open("swvader03.wav", O_RDONLY);
    int out = open("sw2.wav", O_WRONLY | O_CREAT | O_TRUNC, 00777);
    char buf[2048];
    int y;
    while ((y = read(in, buf, sizeof(buf))) > 0) write(out, buf, y);
    close(in); close(out);

    out = open("sw2.wav", O_RDWR);
    lseek(out, 44, SEEK_SET); // WAV 헤더는 44바이트
    int zero_size = 30260 / 2;
    char zero[1024] = {0};
    for (int i = 0; i < zero_size / 1024; i++) write(out, zero, 1024);
    close(out);
    return 0;
}

/*
5) "master" 부분을 복제해 "master master"로 만들기
*/
int repeat_master() {
    int x = open("swvader03.wav", O_RDWR);
    lseek(x, 44 + 30260 / 2, SEEK_SET);
    char buf[30260];
    int y = read(x, buf, 30260 / 2);
    lseek(x, 44 + 30260, SEEK_SET);
    write(x, buf, y);
    close(x);
    return 0;
}

/*
6) 전체 사운드를 복제해 "Yes my master Yes my master"로 만들기
*/
int repeat_all() {
    int x = open("swvader03.wav", O_RDWR);
    lseek(x, 44, SEEK_SET);
    char buf[30260];
    int y = read(x, buf, 30260);
    lseek(x, 44 + 30260, SEEK_SET);
    write(x, buf, y);
    close(x);
    return 0;
}

/*
7) GDB로 디버깅 – 버그: x를 read()의 반환값으로 덮어씀 → open한 파일 디스크립터 유실
*/
// 수정 전:
// x = read(x, chunkID, 4);  // ❌ x가 덮임 → 이후 read 실패
// 수정 후:
// y = read(x, chunkID, 4);  // ✅ x는 유지, 결과는 y에 저장
