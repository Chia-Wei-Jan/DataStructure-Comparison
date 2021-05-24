all: DataStructure.c building_array.o query_array.o building_linkedlist.o query_linkedlist.o building_BST.o query_BST.o building_binarySearch.o query_binarySearch.o building_hash.o query_hash.o
	gcc DataStructure.c building_array.o query_array.o building_linkedlist.o query_linkedlist.o building_BST.o query_BST.o building_binarySearch.o query_binarySearch.o building_hash.o query_hash.o -o DataStructure

building_array.o: building_array.c building_array.h
	gcc -c building_array.c -o building_array.o

query_array.o: query_array.c query_array.h
	gcc -c query_array.c -o query_array.o

building_linkedlist.o: building_linkedlist.c building_linkedlist.h
	gcc -c building_linkedlist.c -o building_linkedlist.o

query_linkedlist.o: query_linkedlist.c query_linkedlist.h
	gcc -c query_linkedlist.c -o query_linkedlist.o

building_BST.o: building_BST.c building_BST.h
	gcc -c building_BST.c -o building_BST.o

query_BST.o: query_BST.c query_BST.h
	gcc -c query_BST.c -o query_BST.o

building_binarySearch.o: building_binarySearch.c building_binarySearch.h
	gcc -c building_binarySearch.c -o building_binarySearch.o

query_binarySearch.o: query_binarySearch.c query_binarySearch.h
	gcc -c query_binarySearch.c -o query_binarySearch.o

building_hash.o: building_hash.c building_hash.h
	gcc -c building_hash.c -o building_hash.o

query_hash.o: query_hash.c query_hash.h
	gcc -c query_hash.c -o query_hash.o

clean: 
	rm -f DataStructure building_array.o query_array.o building_linkedlist.o query_linkedlist.o building_BST.o query_BST.o building_binarySearch.o query_binarySearch.o building_hash.o query_hash.o


