#include <stdio.h>

void recursiveLoop(int n){
    if (n > 0) {
        printf("%i\n", n);
        recursiveLoop(n-1);
    }
}

void main() {
    int n = 10;
    recursiveLoop(n);
}