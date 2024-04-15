#include <stdio.h>
#include <stdlib.h>

#define MAX_DIR_SIZE 20
#define MAX_NUM_OF_BLOCKS 30

typedef struct Block {
    int blockNumber;
    struct Block *next;
} Block;

typedef struct File {
    int file_id;
    Block *Blocks;
} File;

int getValidRandomBlockNumber(int bitVector[], int n) {
    while (1) {
        int num = rand() % n;
        if (bitVector[num] == 0) {
            bitVector[num] = 1;
            return num;
        }
    }
}

Block *insertNewBlock(Block *head, int bitVector[], int n) {
    Block *newBlock = (Block *)malloc(sizeof(Block));
    newBlock->blockNumber = getValidRandomBlockNumber(bitVector, n);
    newBlock->next = head;
    return newBlock;
}

void createNewFile(File directory[], int *total_files, int bitVector[], int n, int *free_blocks) {
    int file_id, total_blocks;
    printf("Enter file id: ");
    scanf("%d", &file_id);
    printf("Enter total blocks: ");
    scanf("%d", &total_blocks);

    if (total_blocks > *free_blocks) {
        printf("Not enough free blocks available. Please choose a smaller number of blocks.\n");
        return;
    }

    directory[*total_files].file_id = file_id;
    directory[*total_files].Blocks = NULL;

    for (int i = 0; i < total_blocks; i++) {
        directory[*total_files].Blocks = insertNewBlock(directory[*total_files].Blocks, bitVector, n);
        (*free_blocks)--;
    }

    (*total_files)++;
}

void showDirectory(File directory[], int total_files) {
    printf("Directory:\n");
    for (int i = 0; i < total_files; i++) {
        printf("File %d - Blocks: ", directory[i].file_id);

        for (Block *currentBlock = directory[i].Blocks; currentBlock != NULL; currentBlock =
            currentBlock->next) {
            printf("%d ", currentBlock->blockNumber);
        }

        printf("\n");
    }
}

void showBitVector(int bitVector[], int n) {
    printf("Bit vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bitVector[i]);
    }
    printf("\n");
}

int main() {
    File directory[MAX_DIR_SIZE];
    int total_files = 0;
    int n;
    int bitVector[MAX_NUM_OF_BLOCKS] = {0};

    printf("Enter the number of blocks on the disk: ");
    scanf("%d", &n);

    int free_blocks = n;

    while (1) {
        printf("\nMenu\n");
        printf("1. Show bit vector\n");
        printf("2. Create new file\n");
        printf("3. Show Directory\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showBitVector(bitVector, n);
                break;
            case 2:
                createNewFile(directory, &total_files, bitVector, n, &free_blocks);
                break;
            case 3:
                showDirectory(directory, total_files);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
