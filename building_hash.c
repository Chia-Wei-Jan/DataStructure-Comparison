#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLineLen 16

struct Hnode {
	int num;
    	struct Hnode *next;
};

unsigned int hash65(char *key) {
	unsigned int hv = 0;
	char *ptr = key;

	while(*ptr) {
		hv = hv * 65 + *ptr;
		ptr++;
	}
	return hv;
}

struct Hnode *list_insert(struct Hnode *L, char *key)
{
	struct Hnode *p = (struct Hnode*)malloc(sizeof(struct Hnode));
	p->num = atoi(key);
	p->next = L;
    	return p;
}

void hash_insert(struct Hnode **hTab, int maxHash, char *key)
{
    	unsigned int hv;
    	hv = hash65(key) % maxHash;
    	struct Hnode *L = hTab[hv];
    	hTab[hv] = list_insert(L, key);
}

void building_hash(struct Hnode **hashTable, int maxHash) {
	char line[MaxLineLen];
        FILE *File1 = fopen("dataset1.txt", "r");
        
        while(fgets(line, MaxLineLen, File1)) {
                line[strcspn(line, "\n")] = '\0';
                hash_insert(hashTable, maxHash, line);   
        }

	fclose(File1);
}


