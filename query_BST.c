#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

struct Tnode {
        int num;
        struct Tnode* left;
        struct Tnode* right;
};

struct Tnode* find_BST(struct Tnode* root, int num) {
        struct Tnode* p = root;

        while(p) {
                if(num < p->num)
                        p = p->left;
                else if(num > p->num)
                        p = p->right;
                else    return p;
        }
        return NULL;
}

void query_BST(struct Tnode* root) {
        char line[MaxLineLen];

        FILE *File1 = fopen("dataset2.txt", "r");
        FILE *File2 = fopen("bst_query_result.txt", "w");
        int idx = 0;

        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                int n = atoi(line);
                if(find_BST(root, n)) {
                        fprintf(File2, "%d in the data.\n", n);
                        idx++;
                }
        }
        if(idx == 0) {
                fprintf(File2, "There is no number in the data.\n");
        }
        fclose(File1);
        fclose(File2);
}
