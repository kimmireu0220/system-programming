/*
VI Editor Practice - lec3
*/

/* 1) Create a file named f1 using vi */
// Command: vi f1
// (If prompted with Open/Edit, type 'e')

/* 2) Press 'i' to enter insertion mode and type: */
// Hello, this is my first session in the vi editor.
// This is the second line of text.

/* 3) Press 'ESC' to exit insertion mode, then type :wq to save and quit */
// Command: :wq

/* 4) Reopen file f1 */
// Command: vi f1

/* 5) Use j/k/h/l to move cursor. Delete 'first' using 'x'. */
// Result: Hello, this is my session in the vi editor.

/* 6) Move cursor and insert 'third' using 'i' */
// Result: Hello, this is my third session in the vi editor.

/* 7) Add new line using 'o' */
// Insert a new line here.

/* 8) Change "Hello" to "Hi there" using 'x' and 'i' */
// Hi there, this is my third session in the vi editor.

/* 9) Add text at end of line using 'a' */
// Hi there, this is my third session in the vi editor. Adding more at the end.

/* 10) Delete the last line using 'dd' */
// Remaining:
// Hi there, this is my third session in the vi editor. Adding more at the end.
// Insert a new line here.

/* 11) Add lines using 'o' */
// One more line.
// Another line.
// And yet another line.

/* 12) Change last line */
// And yet another but last line. And this is the end.

/* 13) Copy 2 lines using '2yy' and paste with 'p' */
// (Place cursor where needed and perform operation)

/* 14) Go to line 6 using :6 and change line */
// The 6th line.

/* 15) Create a C program, compile and run */

// Command:
// vi ex1.c

// Code:
#include <stdio.h>
void main() {
    printf("hi there\n");
}

// Compile:
// gcc -o ex1 ex1.c

// Run:
// ./ex1
// Output: hi there