#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Merge two sorted portions using a shared temporary array
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

// Sequential Merge Sort
void mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);

    merge(arr, temp, left, mid, right);
}

// Check whether the array is sorted
int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {

    int n = 1000000;

    int *arr = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));

    if (arr == NULL || temp == NULL) {
        printf("Memory allocation failed.\n");

        free(arr);
        free(temp);

        return 1;
    }

    // Generate the same data as the parallel version
    srand(42);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    printf("Generated %d random elements.\n", n);

    // Start timing
    double start = omp_get_wtime();

    // Sequential Merge Sort
    mergeSort(arr, temp, 0, n - 1);

    // Stop timing
    double end = omp_get_wtime();

    printf("Sequential execution time: %.6f seconds\n",
           end - start);

    // Verify correctness
    if (isSorted(arr, n)) {
        printf("Result: Array is sorted correctly.\n");
    } else {
        printf("Result: Sorting failed.\n");
    }

    free(arr);
    free(temp);

    return 0;
}
