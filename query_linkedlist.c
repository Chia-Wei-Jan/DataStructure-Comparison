#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

struct lnode {
        int num;
        struct lnode *next;
};

struct lnode* find(struct lnode* list, int num) {
        struct lnode* p = list;

        while(p) {
                if(p->num == num)    return p;
                p = p->next;
        }
        return NULL;
}

void query_linkedlist(struct lnode* list) {
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset2.txt", "r");
        FILE *File2 = fopen("linkedlist_query_result.txt", "w");
        int idx = 0;
	int j = 0;
        while(fgets(line, MaxLineLen, File1)) {
                int n;
                line[strcspn(line, "\n")] = '\0';
                n = atoi(line);
                if(find(list, n) != NULL) {
                    	idx++;
                    	fprintf(File2, "%d in the data.\n", n);
                }
	}
	if(idx == 0) {
                fprintf(File2, "There is no number in the data.\n");
        }
}
