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

struct Node* reversing_list(struct Node* head)
{
    struct Node* temp=NULL;
    struct Node* temp2=NULL;
    while(head!=NULL)
    {
        temp2 = head->next;
        head->next=temp;
        temp = head;
        head = temp2;
    }
    head=temp;
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
    head->next->next=create_node(3);
    head->next->next->next=create_node(4);
    head->next->next->next->next=create_node(5);    
    head->next->next->next->next->next=create_node(6);

printf("list before reversing\n");
print_list(head);

head = reversing_list(head); 
printf("list after reversing\n");
print_list(head);

return 0;
}   