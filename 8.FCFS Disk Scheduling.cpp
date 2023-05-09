#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n, head, i, sum = 0;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    int tracks[n];
    printf("Enter the track positions: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &tracks[i]);
    }
    printf("Enter the head position: ");
    scanf("%d", &head);
    sum += abs(head - tracks[0]);
    for (i = 1; i < n; i++) {
        sum += abs(tracks[i] - tracks[i-1]);
    }
    printf("Average head movement: %.2f\n", (float) sum / n);
    return 0;
}
