#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t kb_interrupt = 0;

void kb_interrupt_handler(int sig) {
  printf("Received kb interrupt\n");
  kb_interrupt = 1;
}

int fibo(int n) {
  int a, b;
  if (kb_interrupt) return -1;
  else if (n < 2) return n;
  else if ((a = fibo(n - 1)) < 0) return -1;
  else if ((b = fibo(n - 2)) < 0) return -1;
  else return a + b;
}

int main() {
  int n;
  signal(SIGINT, kb_interrupt_handler);
  printf("Number: ");
  fflush(stdout);
  scanf("%d", &n);
  printf("Fibo(%d) = %d\n", n, fibo(n));
}

