#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

int requestQueue[MAX_QUEUE_SIZE];
int queueLength = 0;

void addRequest(int track)
{
    requestQueue[queueLength] = track;
    queueLength++;
}

int getHeadMovement(int initialHeadPosition)
{
    int i, headMovement = 0;
    for (i = 0; i < queueLength; i++) {
        headMovement += abs(requestQueue[i] - initialHeadPosition);
        initialHeadPosition = requestQueue[i];
    }
    return headMovement;
}

int main()
{
    int numTracks, initialHeadPosition, i, track;

    printf("Enter the number of tracks: ");
    scanf("%d", &numTracks);

    printf("Enter the initial head position: ");
    scanf("%d", &initialHeadPosition);

    printf("Enter the track positions: ");
    for (i = 0; i < numTracks; i++) {
        scanf("%d", &track);
        addRequest(track);
    }

    int headMovement = getHeadMovement(initialHeadPosition);
    printf("Average head movement: %f\n", (float)headMovement/queueLength);

    return 0;
}
