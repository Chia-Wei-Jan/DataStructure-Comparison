#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

void query_arr(int *data, int cnt)
{
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset2.txt", "r");
        FILE *File2 = fopen("array_query_result.txt", "w");
        int idx = 0;
        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                int n = atoi(line);
                for(int i = 0; i < cnt; i++) {
                        if(n == data[i]) {
                    //            fprintf(File2, "%d in the data.\n", n);
                                idx++;
                                break;
                        }
                }
        }
        if(idx == 0) {
                fprintf(File2, "There is no number in the data.\n");
        }

        fclose(File1);
        fclose(File2);
        return;
}
