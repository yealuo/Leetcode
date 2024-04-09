#include <cstdio>

void bubble_sort(int *arr, int length) {
    for (int i = length - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j + 1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3, 5, 6, 1, 2};
    bubble_sort(arr, sizeof(arr) / sizeof(int));
    for (int i: arr) {
        printf("%d", i);
    }
    return 0;
}