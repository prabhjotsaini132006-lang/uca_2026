#include <stdio.h>
#include <stdbool.h>

int findMin(int last_used[], int num_frames) {
    int min = last_used[0];
    int index = 0;

    for (int i = 1; i < num_frames; i++) {
        if (last_used[i] < min) {
            min = last_used[i];
            index = i;
        }
    }

    return index;
}

void simulate_lru(int page_requests[], int num_requests, int num_frames) {
    int frames[num_frames];
    int last_used[num_frames];
    int page_faults = 0;

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
        last_used[i] = -1;
    }

    for (int time = 0; time < num_requests; time++) {

        int page = page_requests[time];
        bool hit = false;

        for (int i = 0; i < num_frames; i++) {
            if (frames[i] == page) {
                hit = true;
                last_used[i] = time;
                break;
            }
        }

        if (!hit) {
            page_faults++;

            int empty_index = -1;

            for (int i = 0; i < num_frames; i++) {
                if (frames[i] == -1) {
                    empty_index = i;
                    break;
                }
            }

            if (empty_index != -1) {
                frames[empty_index] = page;
                last_used[empty_index] = time;
            }
            else {
                int lru_index = findMin(last_used, num_frames);

                frames[lru_index] = page;
                last_used[lru_index] = time;
            }
        }
    }

    printf("Total Page Faults: %d\n", page_faults);
}

int main() {
    
    int requests[] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};

    int num_requests = sizeof(requests) / sizeof(requests[0]);
    
    simulate_lru(requests, num_requests, 3);

    return 0;

    return 0;
}
