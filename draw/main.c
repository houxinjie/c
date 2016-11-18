#include <stdio.h>
#include <stdlib.h>
const int w = 23;
const int h = 12;

/*
circle
int f(int x, int y) {
    return (x - 10) * (x - 10) + (y - 10) * (y - 10) <= 8 * 8;
}
*/

int triangle(int x, int y) {
    return abs(x) <= y;
}

int f(int x, int y) {
    return triangle(y - 11, x) && triangle((y + x / 3 * 3 + 3) % 6 - 2, x % 3);
}

int main() {
    for (int x = 0; x < h; x++) {
        for (int y = 0; y < w; y++){
            printf(f(x, y) ? "* " : "  ");
        }
        printf("\n");
    }


    return 0;
}
