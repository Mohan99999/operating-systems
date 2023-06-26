#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int isPrime(int num) {
    if (num <= 1)
        return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
void generateFibonacci(int n) {
    int a = 0, b = 1;
    printf("Fibonacci Series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}
int main() {
    pid_t pid;
    int status;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        generateFibonacci(10);
    } else {
        wait(&status);
        printf("Prime Numbers: ");
        for (int i = 2; i <= 20; i++) {
            if (isPrime(i))
                printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
