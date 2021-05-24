#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

int Partition(int *arr, int front, int end){
        int pivot = arr[end];
        int i = front -1;
        for (int j = front; j < end; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        i++;
        swap(&arr[i], &arr[end]);
        return i;
}

void quicksort(int *arr, int front, int end){
        if (front < end) {
            int pivot = Partition(arr, front, end);
            quicksort(arr, front, pivot - 1);
            quicksort(arr, pivot + 1, end);
        }
}

void building_bs(int *data, int cnt) {
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset1.txt", "r");
        FILE *File2 = fopen("bs_building_result.txt", "w");

        int i = 0;
        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                data[i] = atoi(line);
                i++;
        }

        quicksort(data, 0, cnt - 1);
        for(int i = 0; i < cnt; i++) {
                fprintf(File2, "%d\n", data[i]);
        }

        fclose(File1);
        fclose(File2);
        return;
}
