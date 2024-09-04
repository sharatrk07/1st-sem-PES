#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int key;
    int data;
} HashEntry;

HashEntry *hashTable[SIZE];

void initHashTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int data) {
    int index = hashFunction(key);

    while (hashTable[index] != NULL) {
        index = (index + 1) % SIZE; // Linear probing
    }

    hashTable[index] = (HashEntry *)malloc(sizeof(HashEntry));
    hashTable[index]->key = key;
    hashTable[index]->data = data;
}

int search(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != NULL) {
        if (hashTable[index]->key == key) {
            return hashTable[index]->data;
        }
        index = (index + 1) % SIZE; // Linear probing
    }

    return -1; // Key not found
}

int main() {
    initHashTable();

    insert(5, 1);
    insert(15, 2);
    insert(25, 3);
    insert(35, 4);

    printf("Data at key 5: %d\n", search(5));
    printf("Data at key 15: %d\n", search(15));
    printf("Data at key 25: %d\n", search(25));
    printf("Data at key 35: %d\n", search(35));

    return 0;
}