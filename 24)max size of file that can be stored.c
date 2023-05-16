#define BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4

#define DIRECT_BLOCKS 12
#define SINGLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE) * (BLOCK_SIZE / POINTER_SIZE)
#define TRIPLE_INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE) * (BLOCK_SIZE / POINTER_SIZE) * (BLOCK_SIZE / POINTER_SIZE)

#define MAX_FILE_SIZE (DIRECT_BLOCKS + \
                        SINGLE_INDIRECT_BLOCKS + \
                        DOUBLE_INDIRECT_BLOCKS + \
                        TRIPLE_INDIRECT_BLOCKS) * BLOCK_SIZE

int main() {
    printf("Maximum file size: %lu bytes\n", MAX_FILE_SIZE);

    return 0;
}

