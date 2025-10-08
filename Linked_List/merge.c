/*Given two singly linked lists, each of which is sorted in ascending order, write a function 
to merge these two linked lists into a third linked list that is also sorted in ascending order.*/

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* merge_sorted_lists(struct Node* list1, struct Node* list2) {
    struct Node* merged_head = NULL;
    struct Node* merged_tail = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct Node* new_node = NULL;
        if (list1->data <= list2->data) {
            new_node = create_node(list1->data);
            list1 = list1->next;
        } else {
            new_node = create_node(list2->data);
            list2 = list2->next;
        }

        if (merged_head == NULL) {
            merged_head = new_node;
            merged_tail = new_node;
        } else {
            merged_tail->next = new_node;
            merged_tail = new_node;
        }
    }

    while (list1 != NULL) {
        struct Node* new_node = create_node(list1->data);
        merged_tail->next = new_node;
        merged_tail = new_node;
        list1 = list1->next;
    }

    while (list2 != NULL) {
        struct Node* new_node = create_node(list2->data);
        merged_tail->next = new_node;
        merged_tail = new_node;
        list2 = list2->next;
    }

    return merged_head;
}

void print_list(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* list1 = create_node(1);
    list1->next = create_node(3);
    list1->next->next = create_node(5);

    struct Node* list2 = create_node(2);
    list2->next = create_node(4);
    list2->next->next = create_node(6);

    struct Node* merged_list = merge_sorted_lists(list1, list2);

    print_list(merged_list);

    return 0;
}
