#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX 20

void bubble_asc(int arr[], int n) { 
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubble_dsc(int arr[], int n) { 
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\t%d", arr[i]);
    }
    printf("\n\n");
}

int main() {
    int i, n, arr[MAX];
    pid_t pid;

    printf("\nHOW MANY NOS DO YOU WANT IN ARRAY: ");
    scanf("%d", &n);
    printf("ENTER ARRAY ELEMENTS: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid = fork();

    if (pid == 0) {  /* Child Process */
        printf("\n\t\t**********ORPHAN STATE**************\n");
        sleep(5);
        printf("\n\tCHILD PROCESS PID: %d", getpid());
        printf("\n\tPARENT PROCESS PPID: %d", getppid());
        system("ps -el | grep init");

        printf("\n\nARRAY IN ASCENDING ORDER: ");
        bubble_asc(arr, n);
        print(arr, n);
    } else if (pid > 0) {  /* Parent Process */
        printf("\n\t\t**********ZOMBIE STATE**************\n");
        system("ps -el | grep Z");
        wait(NULL);
        
        printf("\n\tTERMINATED CHILD PID: %d", pid);
        printf("\n\tPARENT PID (MAIN): %d", getpid());
        printf("\n\tPARENT'S PARENT PPID (BASH): %d", getppid());
        printf("\n\nARRAY IN DESCENDING ORDER: ");
        bubble_dsc(arr, n);
        print(arr, n);
    } else {
        printf("\nERROR IN FORK!!");
    }

    return 0;
}
