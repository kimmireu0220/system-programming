/*
Linux Background - lec2
*/

/*
1. pwd: 현재 디렉토리 출력
*/
// 사용 예:
// $ pwd
// /home/inha

/*
2. whoami: 현재 사용자 ID 확인
*/
// 사용 예:
// $ whoami
// inha

/*
3. echo, cat, ls -l: 파일 생성, 내용 확인, 권한 보기
*/
// $ echo hello > f1     // f1 파일에 hello 입력
// $ cat f1              // 파일 내용 출력
// $ ls -l f1            // 파일 정보 확인

/*
4. chmod: 파일 권한 변경
   - chmod 000 f1: 모든 권한 제거
   - chmod 777 f1: 모든 권한 부여
*/
// $ chmod 000 f1
// $ ls -l f1
// ---------- 1 inha inha 6 ... f1
// $ chmod 777 f1
// $ ls -l f1
// -rwxrwxrwx 1 inha inha 6 ... f1

/*
5. cd: 디렉토리 이동
   - cd /        : 루트로 이동
   - cd          : 홈 디렉토리로 이동
   - cd ..       : 상위 디렉토리로 이동
   - cd ./d1     : 현재 디렉토리 기준 상대경로 이동
*/

/*
6. 파일과 디렉토리 구분
   - ls -l
   - file *
*/
// $ ls -l
// $ file *

/*
7. 와일드카드: *는 모든 파일을 의미
   - file *   : 현재 디렉토리의 모든 파일 정보 표시
   - file b*  : b로 시작하는 파일 정보 표시
*/

/*
8. mkdir, cp, rm: 디렉토리 생성, 복사, 삭제
*/
// $ mkdir d1        // 디렉토리 생성
// $ cp f1 d1/f2     // f1을 d1 디렉토리에 f2 이름으로 복사
// $ rm f2           // f2 삭제

/*
9. grep: 특정 문자열 검색
*/
// $ grep -nr "he" *     // 현재 디렉토리 내 파일에서 "he" 검색

/*
10. ps: 현재 실행 중인 프로세스 확인
*/
// $ ps         // 현재 터미널에서 실행 중인 프로세스
// $ ps -ef     // 시스템 전체 프로세스

/*
11. xxd: 바이너리 파일을 16진수(hex)로 출력
*/
// $ xxd f1     // f1 파일을 16진수로 출력

/*
12. 기타 자주 쓰이는 명령어 개요
chmod     // 권한 변경
clear     // 터미널 화면 지움
date      // 현재 날짜/시간 출력
dd        // 디스크/파일 복사
file      // 파일 형식 확인
head/tail // 파일 앞/뒤 출력
ping      // 네트워크 연결 확인
stat      // 파일의 상세 정보
whoami    // 현재 사용자 확인
tty       // 현재 터미널 확인
*/

// 각 명령어는 man으로 도움말 확인 가능
// $ man chmod
// $ man ps
// $ man 1 kill
