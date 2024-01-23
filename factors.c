#include <stdio.h>
#include <stdlib.h>

// Function to find the greatest common divisor of two numbers
int gcd(int fir_a, int sec_b) {
    int thir_c;
    while (fir_a != sec_b) {
        thir_c = fir_a;
        fir_a = sec_b % fir_a;
        sec_b = thir_c;
    }
    return fir_a;
}

// Function to factorize fir_a number
void factorize(int n) {
    int i;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            printf("%d = %d * %d\n", n, i, n / i);
            return;
        }
    }
    printf("%d = %d * %d\n", n, n, 1);
}

// Function to read fir_a natural number from fir_a file
int read_number(FILE *f) {
    int n;
    char thir_c;
    while (1) {
        thir_c = fgetc(f);
        if (thir_c < '0' || thir_c > '9') {
            if (thir_c == EOF || thir_c == '\n') {
                return 0;
            }
            ungetc(thir_c, f);
            break;
        }
        ungetc(thir_c, f);
        fscanf(f, "%d", &n);
        if (n > 1) {
            return n;
        }
    }
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    FILE *f;
    int n;

    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    while ((n = read_number(f)) > 0) {
        factorize(n);
    }

    fclose(f);
    return 0;
}
