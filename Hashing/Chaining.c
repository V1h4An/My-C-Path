 #include <stdio.h>
 #include <stdlib.h>

 // Define the structure for the linked list used in chaining
 struct Node {
     int key;
     struct Node* next;
 };

 // Hash function
 int hash(int key, int table_size) {
     return key % table_size;
 }

 // Function to create a new node
 struct Node* createNode(int key) {
     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->key = key;
     newNode->next = NULL;
     return newNode;
 }

 // Insert key into the hash table using chaining
 void insert(struct Node* hashTable[], int key, int table_size) {
     int index = hash(key, table_size);
     struct Node* newNode = createNode(key);

     // Insert the node at the beginning of the linked list at the hashed index
     newNode->next = hashTable[index];
     hashTable[index] = newNode;
 }

 // Search for a key in the hash table
 struct Node* search(struct Node* hashTable[], int key, int table_size) {
     int index = hash(key, table_size);
     struct Node* current = hashTable[index];

     while (current != NULL) {
         if (current->key == key) {
             return current;  // Key found
         }
         current = current->next;
     }
     return NULL;  // Key not found
 }

 // Delete a key from the hash table
 void deleteKey(struct Node* hashTable[], int key, int table_size) {
     int index = hash(key, table_size);
     struct Node* current = hashTable[index];
     struct Node* prev = NULL;

     while (current != NULL && current->key != key) {
         prev = current;
         current = current->next;
     }

     // If key is not found
     if (current == NULL) return;

     // If the key is the first node in the list
     if (prev == NULL) {
         hashTable[index] = current->next;
     } else {
         prev->next = current->next;
     }

     free(current);
 }

 // Display the hash table with chaining
 void display(struct Node* hashTable[], int table_size) {
     for (int i = 0; i < table_size; i++) {
         printf("Index %d: ", i);
         struct Node* current = hashTable[i];
         while (current != NULL) {
             printf("%d -> ", current->key);
             current = current->next;
         }
         printf("NULL\n");
     }
 }

 int main() {
     int table_size = 10;
     struct Node* hashTable[10] = {NULL};  // Initialize hash table with NULL pointers

     // Insert keys into the hash table
     insert(hashTable, 15, table_size);
     insert(hashTable, 25, table_size);
     insert(hashTable, 35, table_size);
     insert(hashTable, 45, table_size);
     insert(hashTable, 55, table_size);

     display(hashTable, table_size);  // Display the hash table

     // Search for a key
     int key = 25;
     if (search(hashTable, key, table_size)) {
         printf("Key %d found.\n", key);
     } else {
         printf("Key %d not found.\n", key);
     }

     // Delete a key
     deleteKey(hashTable, 25, table_size);
     display(hashTable, table_size);  // Display the hash table after deletion

     return 0;
 }
