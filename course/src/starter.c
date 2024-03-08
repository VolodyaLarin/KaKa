
#include <stdio.h>
#include <time.h>

int main_main();


int main() {
    clock_t start_time = clock();
    int res = main_main();
    clock_t end_time = clock();

    printf("\n\nRuns %.2lf ms \nResult code: %d\n", (1000.0 * (end_time - start_time)) / CLOCKS_PER_SEC, res);
}