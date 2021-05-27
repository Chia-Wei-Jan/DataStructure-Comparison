#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

struct lnode {
        int num;
        struct lnode *next;
};

struct lnode* insert_lnode(struct lnode* list, int num) {
       struct lnode* p = (struct lnode*) malloc(sizeof(struct lnode));
       p->num = num;
       p->next = list;
       return p;
}

struct lnode* building_linkedlist(struct lnode* list) {
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset1.txt", "r");
        FILE *File2 = fopen("linkedlist_building_result.txt", "w");

        while(fgets(line, MaxLineLen, File1)) {
                int n;
                line[strcspn(line, "\n")] = '\0';
                n = atoi(line);
                list = insert_lnode(list, n);
		fprintf(File2, "%d\n", n);
        }
	return list;
}
