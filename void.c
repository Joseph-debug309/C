# include <stdio.h>
// Returns nothing -> starts with void
void printHeader(void) {
    printf("====================\n");
    printf("   Welcome to C    \n");
    printf("====================\n");
}

int main(void) {
    printHeader(); // Called without storing a return value
    return 0;
}