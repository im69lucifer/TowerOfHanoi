#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    int stack[MAX_DISKS];
    int top;
} Rod;

void push(Rod* rod, int item) {
    rod->stack[++rod->top] = item;
}

int pop(Rod* rod) {
    return rod->stack[rod->top--];
}

void move_disk(char from_rod, char to_rod, int disk) {
    printf("Move disk %d from rod %c to rod %c\n", disk, from_rod, to_rod);
}

void tower_of_hanoi(int n, Rod* source, Rod* destination, Rod* auxiliary) {
    int total_moves = (1 << n) - 1;

    for (int i = n; i >= 1; i--) {
        push(source, i);
    }

    char s = 'A', d = 'C', a = 'B';
    if (n % 2 == 0) {
        d = 'B';
        a = 'C';
    }

    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            if (source->top == -1) {
                push(source, pop(auxiliary));
                move_disk(a, s, source->stack[source->top]);
            } else if (auxiliary->top == -1) {
                push(auxiliary, pop(source));
                move_disk(s, a, auxiliary->stack[auxiliary->top]);
            } else if (source->stack[source->top] < auxiliary->stack[auxiliary->top]) {
                push(auxiliary, pop(source));
                move_disk(s, a, auxiliary->stack[auxiliary->top]);
            } else {
                push(source, pop(auxiliary));
                move_disk(a, s, source->stack[source->top]);
            }
        } else if (i % 3 == 2) {
            if (source->top == -1) {
                push(source, pop(destination));
                move_disk(d, s, source->stack[source->top]);
            } else if (destination->top == -1) {
                push(destination, pop(source));
                move_disk(s, d, destination->stack[destination->top]);
            } else if (source->stack[source->top] < destination->stack[destination->top]) {
                push(destination, pop(source));
                move_disk(s, d, destination->stack[destination->top]);
            } else {
                push(source, pop(destination));
                move_disk(d, s, source->stack[source->top]);
            }
        } else if (i % 3 == 0) {
            if (destination->top == -1) {
                push(destination, pop(auxiliary));
                move_disk(a, d, destination->stack[destination->top]);
            } else if (auxiliary->top == -1) {
                push(auxiliary, pop(destination));
                move_disk(d, a, auxiliary->stack[auxiliary->top]);
            } else if (destination->stack[destination->top] < auxiliary->stack[auxiliary->top]) {
                push(auxiliary, pop(destination));
                move_disk(d, a, auxiliary->stack[auxiliary->top]);
            } else {
                push(destination, pop(auxiliary));
                move_disk(a, d, destination->stack[destination->top]);
            }
        }
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d",&num_disks);
    if (num_disks > MAX_DISKS) {
        printf("Error: Number of disks exceeds the maximum limit of %d\n", MAX_DISKS);
        return EXIT_FAILURE;
    }
    Rod source = { .top = -1 };
    Rod destination = { .top = -1 };
    Rod auxiliary = { .top = -1 };
    tower_of_hanoi(num_disks, &source, &destination, &auxiliary);
    return EXIT_SUCCESS;
}