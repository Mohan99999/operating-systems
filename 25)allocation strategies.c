#define FILE_BLOCKS 100
int contiguousAllocation(int blockPosition) {
    return 1; 
}
int linkedAllocation(int blockPosition) {
    return 1;
}
int indexedAllocation(int blockPosition) {
    if (blockPosition == 0 || blockPosition == FILE_BLOCKS - 1)
        return 2; 
    else
        return 3;  
}
int main() 
{
    int blockPosition;
    printf("Enter the position of the block (0-%d): ", FILE_BLOCKS - 1);
    scanf("%d", &blockPosition);
    printf("Contiguous Allocation: %d disk I/O operations\n", contiguousAllocation(blockPosition));
    printf("Linked Allocation: %d disk I/O operations\n", linkedAllocation(blockPosition));
    printf("Indexed Allocation: %d disk I/O operations\n", indexedAllocation(blockPosition));
    return 0;
}
