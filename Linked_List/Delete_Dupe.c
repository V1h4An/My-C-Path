#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data =data;
    new_node->next =NULL;
    return new_node;
}

struct Node* delete_dupe(struct Node* head)
{
    struct Node *current = head;
    while (current != NULL && current->next != NULL)
    {
        if (current->data == current->next->data)
        {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        }
        else
        {
            current = current->next;
        }
    }
return head;
}

void print_list(struct Node* head)
{
    struct Node* current = head;
    while(current!=NULL)
    {
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL\n");
}


int main()
{
    struct Node* head =create_node(1);
    head->next=create_node(2);
    head->next->next=create_node(8);
    head->next->next->next=create_node(2);
    head->next->next->next->next=create_node(3);    
    head->next->next->next->next->next=create_node(5);

printf("list before deleting dupe\n");
print_list(head);

printf("list after deleting dupe\n");
delete_dupe(head);
print_list(head);

return 0;
}   