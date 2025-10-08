  #include <stdio.h>

  #define TABLE_SIZE 10

  // Hash function
  int hash(int key, int table_size) {
      return key % table_size;
  }

  // Insert key using linear probing
  void insert(int hashTable[], int key) {
      int index = hash(key, TABLE_SIZE);

      // Search for the next available slot
      while (hashTable[index] != -1) {
          index = (index + 1) % TABLE_SIZE;
      }

      hashTable[index] = key;
  }

  // Search for a key using linear probing
  int search(int hashTable[], int key) {
      int index = hash(key, TABLE_SIZE);
      int start_index = index;  // Keep track of the starting index to avoid infinite loop

      // Search for the key
      while (hashTable[index] != -1) {
          if (hashTable[index] == key) {
              return index;
          }
          index = (index + 1) % TABLE_SIZE;
          if (index == start_index) {
              break;  // If we loop back to the starting index, the table is full
          }
      }

      return -1;  // Key not found
  }

  // Display the hash table
  void display(int hashTable[]) {
      for (int i = 0; i < TABLE_SIZE; i++) {
          if (hashTable[i] != -1) {
              printf("Index %d: %d\n", i, hashTable[i]);
          } else {
              printf("Index %d: NULL\n", i);
          }
      }
  }

  int main() {
      int hashTable[TABLE_SIZE];
      for (int i = 0; i < TABLE_SIZE; i++) {
          hashTable[i] = -1;  // Initialize the hash table with -1 (indicating empty slots)
      }

      // Insert keys into the hash table
      insert(hashTable, 15);
      insert(hashTable, 25);
      insert(hashTable, 35);
      insert(hashTable, 45);

      display(hashTable);  // Display the hash table

      // Search for a key
      int key = 25;
      int result = search(hashTable, key);
      if (result != -1) {
          printf("Key %d found at index %d.\n", key, result);
      } else {
          printf("Key %d not found.\n", key);
      }

      return 0;
  }
