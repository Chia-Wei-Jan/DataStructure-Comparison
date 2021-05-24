#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

struct Hnode {
        int num;
        struct Hnode *next;
};

unsigned int hash_65(char *key) {
        unsigned int hv = 0;
        char *ptr = key;

        while(*ptr) {
                hv = hv * 65 + *ptr;
                ptr++;
        }
        return hv;
}

struct Hnode *list_find(struct Hnode *L, char *key)
{
    	if(L == NULL)   return NULL;

    	struct Hnode *p = L;
    	while(p) {
        	if(p->num == atoi(key))    return p;
       		p = p->next;
    	}
    	return NULL;
}

struct Hnode *hash_find(struct Hnode **hashTab, int maxHash, char *key)
{
    	unsigned int hv = 0;
    	hv = hash_65(key) % maxHash;
    	struct Hnode *L = hashTab[hv];
    	return list_find(L, key);
}

void query_hash(struct Hnode **hashTable, int maxHash) {
        char line[MaxLineLen];
        FILE *File1 = fopen("dataset2.txt", "r");
	FILE *File2 = fopen("hash_query_result.txt", "w");
	int idx = 0;

        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                if(hash_find(hashTable, maxHash, line) != NULL) {
			fprintf(File2, "%d in the data.\n", atoi(line));
			idx++;
		}
        }
	if(idx == 0)
		fprintf(File2, "There is no number in the data.\n");

        fclose(File1);
	fclose(File2);
}
 
