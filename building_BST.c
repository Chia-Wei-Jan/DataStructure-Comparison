#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

struct Tnode {
        int num;
        struct Tnode* left;
        struct Tnode* right;
};

struct Tnode* insert_Tnode(struct Tnode* root, int num) {
        if(root == NULL) {
                struct Tnode* p = (struct Tnode*) malloc(sizeof(struct Tnode));
                p->num = num;
                p->left = NULL;
                p->right = NULL;
                return p;
        }
        if(num < root->num) {
                root->left = insert_Tnode(root->left, num);
        } 
        else {    
                root->right = insert_Tnode(root->right, num);
        }
        return root;
}
/*
void inorder_traversal(struct Tnode* root) {
        FILE *File = fopen("bst_building_result.txt", "w");

        if(root == NULL)    return;
        inorder_traversal(root->left);
        fprintf(File, "%d\n", root->num);
        inorder_traversal(root->right);

        fclose(File);
}
*/
void building_BST(struct Tnode* root) {
        char line[MaxLineLen];
        FILE *File = fopen("dataset1.txt", "r");

        while(fgets(line, MaxLineLen, File)) {
                line[strcspn(line, "\n")] = '\0';
                int n = atoi(line);
                root = insert_Tnode(root, n);
        }
  //      inorder_traversal(root);
        fclose(File);
}
