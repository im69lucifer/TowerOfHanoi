#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100
int main() {
    int source[MAX_DISKS], destination[MAX_DISKS], auxiliary[MAX_DISKS];
    int top_source = -1, top_destination = -1, top_auxiliary = -1;
    int num_disks;
    int total_moves;
    char s = 'A', d = 'C', a = 'B';
    
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks > MAX_DISKS) {
        printf("Error: Number of disks exceeds the maximum limit of %d\n", MAX_DISKS);
        return EXIT_FAILURE;
    }
    total_moves = (1 << num_disks) - 1;
    for (int i = num_disks; i >= 1; i--) {
        source[++top_source] = i;
    }

    
    if (num_disks % 2 == 0) {
        d = 'C';
        a = 'B';
    }

    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            if (top_source == -1) {
                source[++top_source] = auxiliary[top_auxiliary--];
                printf("Move disk %d from rod %c to rod %c\n", source[top_source], a, s);
            } else if (top_auxiliary == -1) {
                auxiliary[++top_auxiliary] = source[top_source--];
                printf("Move disk %d from rod %c to rod %c\n", auxiliary[top_auxiliary], s, a);
            } else if (source[top_source] < auxiliary[top_auxiliary]) {
                auxiliary[++top_auxiliary] = source[top_source--];
                printf("Move disk %d from rod %c to rod %c\n", auxiliary[top_auxiliary], s, a);
            } else {
                source[++top_source] = auxiliary[top_auxiliary--];
                printf("Move disk %d from rod %c to rod %c\n", source[top_source], a, s);
            }
        } else if (i % 3 == 2) {
            if (top_source == -1) {
                source[++top_source] = destination[top_destination--];
                printf("Move disk %d from rod %c to rod %c\n", source[top_source], d, s);
            } else if (top_destination == -1) {
                destination[++top_destination] = source[top_source--];
                printf("Move disk %d from rod %c to rod %c\n", destination[top_destination], s, d);
            } else if (source[top_source] < destination[top_destination]) {
                destination[++top_destination] = source[top_source--];
                printf("Move disk %d from rod %c to rod %c\n", destination[top_destination], s, d);
            } else {
                source[++top_source] = destination[top_destination--];
                printf("Move disk %d from rod %c to rod %c\n", source[top_source], d, s);
            }
        } else if (i % 3 == 0) {
            if (top_destination == -1) {
                destination[++top_destination] = auxiliary[top_auxiliary--];
                printf("Move disk %d from rod %c to rod %c\n", destination[top_destination], a, d);
            } else if (top_auxiliary == -1) {
                auxiliary[++top_auxiliary] = destination[top_destination--];
                printf("Move disk %d from rod %c to rod %c\n", auxiliary[top_auxiliary], d, a);
            } else if (destination[top_destination] < auxiliary[top_auxiliary]) {
                auxiliary[++top_auxiliary] = destination[top_destination--];
                printf("Move disk %d from rod %c to rod %c\n", auxiliary[top_auxiliary], d, a);
            } else {
                destination[++top_destination] = auxiliary[top_auxiliary--];
                printf("Move disk %d from rod %c to rod %c\n", destination[top_destination], a, d);
            }
        }
    }
    return EXIT_SUCCESS;
}