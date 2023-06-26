#include <stdio.h>
#include <stdbool.h>

#define BLOCK_SIZE 1024
#define TOTAL_BLOCKS 16
#define INODE_BLOCKS 8
#define DATA_BLOCKS (TOTAL_BLOCKS - INODE_BLOCKS)
#define MIN_FILE_SIZE 1

bool isContiguousFree(int blocks[], int startBlock, int numBlocks) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (blocks[i] != 0) {
            return false;
        }
    }
    return true;
}

void allocateBlocks(int blocks[], int startBlock, int numBlocks) {
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        blocks[i] = 1;
    }
}

int main() {
    int blocks[TOTAL_BLOCKS] = {0};

    int numFiles;
    printf("Enter the number of files: ");
    scanf("%d", &numFiles);

    for (int i = 0; i < numFiles; i++) {
        int fileSize;
        printf("Enter the size of file %d (in KB): ", i + 1);
        scanf("%d", &fileSize);

        if (fileSize < MIN_FILE_SIZE) {
            printf("File size should be at least %d KB\n", MIN_FILE_SIZE);
            return 0;
        }

        int numBlocksRequired = fileSize / BLOCK_SIZE;
        if (fileSize % BLOCK_SIZE != 0) {
            numBlocksRequired++;
        }

        int startBlock = -1;
        for (int j = DATA_BLOCKS - numBlocksRequired; j >= 0; j--) {
            if (isContiguousFree(blocks, j, numBlocksRequired)) {
                startBlock = j;
                break;
            }
        }

        if (startBlock == -1) {
            printf("Not enough contiguous blocks available for file %d\n", i + 1);
            return 0;
        }

        allocateBlocks(blocks, startBlock, numBlocksRequired);
        printf("File %d allocated from block %d to %d\n", i + 1, startBlock, startBlock + numBlocksRequired - 1);
    }

    return 0;
}
