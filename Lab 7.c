/*
Alexander Charlston
COP3506
UCF Lab 7
*/



#include <stdio.h>

// (Bubble sort function remains unchanged)

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                // Count swaps for each value
                swaps[arr[j]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap elements
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        // Count swaps for each value
        swaps[arr[i]]++;
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    
    int swaps1[101] = {0}; // Assuming values in array1 are between 1 and 100
    int swaps2[101] = {0}; // Assuming values in array2 are between 1 and 100
    
    // Perform bubble sort and count swaps
    bubbleSort(array1, n1, swaps1);
    bubbleSort(array2, n2, swaps2);

    printf("array1: Bubble\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d swaps\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total number of swaps: %d\n", swaps1[0]); // 0 index stores the total swaps

    printf("\narray2: Bubble\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d swaps\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total number of swaps: %d\n", swaps2[0]); // 0 index stores the total swaps

    // Perform selection sort and count swaps
    selectionSort(array1, n1, swaps1);
    selectionSort(array2, n2, swaps2);
    
    printf("array1:Selection sort\n");
    for (int i = 0; i < n1; i++) {
        printf("%d: %d swaps\n", array1[i], swaps1[array1[i]]);
    }
    printf("Total number of swaps: %d\n", swaps1[0]); // 0 index stores the total swaps

    printf("\narray2:Selection sort\n");
    for (int i = 0; i < n2; i++) {
        printf("%d: %d swaps\n", array2[i], swaps2[array2[i]]);
    }
    printf("Total number of swaps: %d\n", swaps2[0]); // 0 index stores the total swaps
    
    return 0;
}
