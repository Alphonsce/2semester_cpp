#include <iostream>

struct node {

    int data;
    node* next;
    node* prev;

};

// appends a node to the end
void append(node** head_ref, int new_data)
{
    node* new_node = new node;
 
    node* last = *head_ref;
 
    new_node->data = new_data;
 
    new_node->next = NULL;
 
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
 
    new_node->prev = last;
 
    return;
}

// add new node to the front
void push(node** head_ref, int new_data)
{
    // I need to pass **head, because I need to change prev of head
    node* new_node = new node;
 
    new_node->data = new_data;
 
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    (*head_ref) = new_node;
}

void printList(node* tmp)
{
    node* last;
    std::cout<<" Проход прямо \n";
    while (tmp != NULL)
    {
        std::cout << " " << tmp->data <<" ";
        last = tmp;     // запоминаем последний
        tmp = tmp->next;
    }
    std::cout << std::endl;
 
    std::cout<< " Проход в обратном направлении  \n";
    while (last != NULL)
    {
        std::cout<<" "<<last->data<<" ";
        last = last->prev;
    }
    std::cout << std::endl;
}

int main() {

    node* head = NULL;
 
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
 
    // Insert 7 at the beginning
    // linked list becomes 7->6->NULL
    push(&head, 7);
 
    // Insert 1 at the beginning
    // linked list becomes 1->7->6->NULL
    push(&head, 1);
 
    // Insert 4 at the end. So linked
    // list becomes 1->7->6->4->NULL
    append(&head, 4);
 
    printList(head);



    return 0;
}