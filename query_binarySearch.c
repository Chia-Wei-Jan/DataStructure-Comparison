#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

int binarySearch(int *arr, int left, int right, int num) {
        while (left <= right) {
                int mid = left + (right - left) / 2;

                if (arr[mid] == num)    return mid;
                if (arr[mid] < num)    left = mid + 1;
                else    right = mid - 1;
        }
        return -1;
}

void query_bs(int *data, int cnt) {
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset2.txt", "r");
        FILE *File2 = fopen("bs_query_result.txt", "w");
        int idx = 0;

        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                int n = atoi(line);
                int result = binarySearch(data, 0, cnt - 1, n);
                if(result != -1) {
                        fprintf(File2, "%d in the data.\n", result);
                        idx++;
                }
        }
        if(idx == 0) {
                fprintf(File2, "There is no number in the data.\n");
        }

        fclose(File1);
        fclose(File2);
        return;
}
