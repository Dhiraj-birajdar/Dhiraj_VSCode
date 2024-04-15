#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void cScan(int request[], int n, int start, int direction) {
    int totalHeadMovements = 0;
    int currHeadPos = start;
    int minVal = 0, maxVal = 199;

    sort(request, n);

    int i;
    for (i = 0; i < n; i++) {
        if (request[i] > start)
            break;
    }

    if (direction == 1) {
        printf("Order of service (Right): ");
        for (int j = i; j < n; j++) {
            printf("%d ", request[j]);
            totalHeadMovements += abs(currHeadPos - request[j]);
            currHeadPos = request[j];
        }
        if (i != 0) {
            printf("%d ", maxVal);
            totalHeadMovements += abs(currHeadPos - maxVal);
            currHeadPos = maxVal;
            printf("%d ", minVal);
            totalHeadMovements += abs(currHeadPos - minVal);
            currHeadPos = minVal;
        }
        for (int j = 0; j < i; j++) {
            printf("%d ", request[j]);
            totalHeadMovements += abs(currHeadPos - request[j]);
            currHeadPos = request[j];
        }
    }
    else {
        printf("Order of service (Left): ");
        for (int j = i-1; j >= 0; j--) {
            printf("%d ", request[j]);
            totalHeadMovements += abs(currHeadPos - request[j]);
            currHeadPos = request[j];
        }
        if (i != n) {
            printf("%d ", minVal);
            totalHeadMovements += abs(currHeadPos - minVal);
            currHeadPos = minVal;
            printf("%d ", maxVal);
            totalHeadMovements += abs(currHeadPos - maxVal);
            currHeadPos = maxVal;
        }
        for (int j = n-1; j >= i; j--) {
            printf("%d ", request[j]);
            totalHeadMovements += abs(currHeadPos - request[j]);
            currHeadPos = request[j];
        }
    }

    printf("\nTotal Head Movements: %d\n", totalHeadMovements);
}

int main() {
    int n;
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk request string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    int start, direction;
    printf("Enter the starting head position: ");
    scanf("%d", &start);
    printf("Enter the direction (1 for Right, 0 for Left): ");
    scanf("%d", &direction);

    cScan(request, n, start, direction);

    return 0;
}
