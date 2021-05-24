unsigned int hash65(char *key);
struct Hnode *list_insert(struct Hnode *L, char *key);
void hash_insert(struct Hnode **hTab, int maxHash, char *key);
void building_hash(struct Hnode **hashtable, int maxHash);
