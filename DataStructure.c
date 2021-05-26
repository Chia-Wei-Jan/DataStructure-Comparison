#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "building_array.h"
#include "query_array.h"
#include "building_linkedlist.h"
#include "query_linkedlist.h"
#include "building_BST.h"
#include "query_BST.h"
#include "building_binarySearch.h"
#include "query_binarySearch.h"
#include "building_hash.h"
#include "query_hash.h"
#define TRUE 1
#define FALSE 0

struct lnode {
        int num;
        struct lnode *next;
};

struct Tnode {
        int num;
        struct Tnode* left;
        struct Tnode* right;
};

struct Hnode {
	int num;
	struct Hnode* next;
};

int main(int argc, char **argv) {
        int binary_search_tree = FALSE;
        int binary_search = FALSE;
        int arr = FALSE;
        int linkedlist = FALSE;
        int hash = FALSE;
        int building_cnt = 0;
        int query_cnt = 0;

        struct timeval start;
        struct timeval end;
        unsigned long diff;

        srand(time(NULL));

        for(int i = 1; i < argc; i++) {
                if(strcmp(argv[i], "-d") == 0) {
                        i++;
                        if(strcmp(argv[i], "1e4") == 0)
                                building_cnt = 10000;
                        else if(strcmp(argv[i], "1e5") == 0)
                                building_cnt = 100000;
                        else if(strcmp(argv[i], "1e6") == 0)
                                building_cnt = 1000000;
                }
                else if(strcmp(argv[i], "-q") == 0) {
                        i++;
                        if(strcmp(argv[i], "1e3") == 0)
                                query_cnt = 1000;
                        else if(strcmp(argv[i], "1e4") == 0)
                                query_cnt = 10000;
                        else if(strcmp(argv[i], "1e5") == 0)
                                query_cnt = 100000;
                }
                else if(strcmp(argv[i], "-bst") == 0) {
                        binary_search_tree = TRUE;
                }
                else if(strcmp(argv[i], "-bs") == 0) {
                        binary_search = TRUE;
                }
                else if(strcmp(argv[i], "-arr") == 0) {
                        arr = TRUE;
                }
                else if(strcmp(argv[i], "-ll") == 0) {
                        linkedlist = TRUE;
                }
                else if(strcmp(argv[i], "-hash") == 0) {
                        hash = TRUE;
                }
        }


        FILE *File1, *File2;
        File1 = fopen("dataset1.txt", "w");
        File2 = fopen("dataset2.txt", "w");

        if(building_cnt != 0) {
    		int i, j;
    		int *num = (int *) malloc(sizeof(int) * building_cnt);
    		for(i = 0; i < building_cnt; i++) {
        		do {    
            			num[i] = rand();
            			for(j = 0; j < i; j++) {
                			if(num[i] == num[j])	break;
            			}
        		}while(j != i);
        		fprintf(File1, "%d\n", num[i]);
    		}
	    	free(num);	
    	}

        if(query_cnt != 0) {
                for(int i = 0; i < query_cnt; i++) {
                        int n;
                        n = rand();
                        fprintf(File2, "%d\n", n);
                }
        }

        fclose(File1);
        fclose(File2);

        if(arr == TRUE) {
                printf("Array:\n");
                int *data = (int *) malloc(sizeof(int) * building_cnt);
                if(building_cnt != 0) {
                        gettimeofday(&start, NULL);
                        building_arr(data);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("building time: %f sec\n", diff/1000000.0);
                }
                if(query_cnt != 0) {
                        gettimeofday(&start, NULL);
                        query_arr(data, query_cnt);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("query time: %f sec\n", diff/1000000.0);
                }
                printf("\n");
        }

        if(linkedlist == TRUE) {
                struct lnode *list = NULL;
                printf("Linked List:\n");
                if(building_cnt != 0) {
                        gettimeofday(&start, NULL);
                        building_linkedlist(list);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("building time: %f sec\n", diff/1000000.0);
                }
                if(query_cnt != 0) {
                        gettimeofday(&start, NULL);
                        query_linkedlist(list);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("query time: %f sec\n", diff/1000000.0);
                }
                printf("\n");
        }

       if(binary_search == TRUE) {
                printf("Array with Binary Search:\n");
                int *data = (int *) malloc(sizeof(int) * building_cnt);
                if(building_cnt != 0) {
                        gettimeofday(&start, NULL);
                        building_bs(data, building_cnt);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("building time: %f sec\n", diff/1000000.0);
                }
                if(query_cnt != 0) {
                        gettimeofday(&start, NULL);
                        query_bs(data, query_cnt);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("query time: %f sec\n", diff/1000000.0);
                }
                printf("\n");       
       }

       if(binary_search_tree == TRUE) {
                struct Tnode *root = NULL;
                printf("Binary Search Tree:\n");
                if(building_cnt != 0) {
                        gettimeofday(&start, NULL);
                        building_BST(root);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("building time: %f sec\n", diff/1000000.0);
                }
                if(query_cnt != 0) {
                        gettimeofday(&start, NULL);
                        query_BST(root);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("query time: %f sec\n", diff/1000000.0);
                }
                printf("\n");
       }

       if(hash == TRUE) {
		struct Hnode **hashTable;
		int maxHash = 1 << 15;
		hashTable = (struct Hnode**) malloc(sizeof(struct Hnode*) * maxHash);
		
		for(int i = 0; i < maxHash; i++) {
			hashTable[i] = NULL;
		}

                printf("Hash:\n");
                if(building_cnt != 0) {
                        gettimeofday(&start, NULL);
                        building_hash(hashTable, maxHash);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("building time: %f sec\n", diff/1000000.0);
                }
                if(query_cnt != 0) {
                        gettimeofday(&start, NULL);
                        query_hash(hashTable, maxHash);
                        gettimeofday(&end, NULL);
                        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
                        printf("query time: %f sec\n", diff/1000000.0);
                }
                printf("\n");

       }

        return 0;
}
