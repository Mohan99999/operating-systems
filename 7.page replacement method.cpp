#include <stdio.h>
int findIndex(int page, int frame[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (frame[i] == page) {
            return i;
        }
    }
    return -1;
}

int main() {
    int page_faults = 0, m, n, i, j;
    int pages[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int page_frames[3] = {-1, -1, -1};
    int frame_count = 0;
    for (i = 0; i < 20; i++) {
        int index = findIndex(pages[i], page_frames, frame_count);
        if (index == -1) {
   
            page_faults++;
            if (frame_count < 3) {
                page_frames[frame_count] = pages[i];
                frame_count++;
            }
            else {
                int min = 20;
                for (j = 0; j < 3; j++) {
                    int k;
                    for (k = i - 1; k >= 0; k--) {
                        if (page_frames[j] == pages[k]) {
                            if (k < min) {
                                min = k;
                                m = j;
                            }
                            break;
                        }
                    }
                }
                page_frames[m] = pages[i];
            }
        }
    }
    printf("Number of Page Faults = %d\n", page_faults);
    return 0;
}
