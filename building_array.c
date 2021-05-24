#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

void building_arr(int *data)
{
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset1.txt", "r");
        FILE *File2 = fopen("array_building_result.txt", "w");

        int i = 0;
        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                data[i] = atoi(line);
                fprintf(File2, "%d\n", data[i]);
                i++;
        }
        fclose(File1);
        fclose(File2);
        return;
}
