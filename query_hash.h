unsigned int hash_65(char *key);
struct Hnode *list_find(struct Hnode *L, char *key);
struct Hnode *hash_find(struct Hnode **hashTab, int maxHash, char *key);
void query_hash(struct Hnode **hashTable, int maxHash);
