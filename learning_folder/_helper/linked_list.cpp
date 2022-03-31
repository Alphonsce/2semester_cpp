#include <iostream>

// Вся фишка линкед листа в том, что мы не работает с node, мы работаем лишь с указателями на node

struct node
{
    int data;
    node* next;
};

class linked_list {

    private:
        node* head;
        node* tail;
    public:
        linked_list() {  // constructor
            head = nullptr;
            tail = nullptr;
        }

        void print_list() {
            node* current = new node;
            current = head;
            while (current != tail->next) {
                std::cout << current->data << ' ';
                current = current->next;
            }

            std::cout << std::endl;

            // std::cout << head->next->next->next->next->data << std::endl;
        }

        void push_back(int n) {
            node* tmp = new node;
            tmp->data = n;
            tmp->next = nullptr;

            if (head == nullptr) {    // checking emptyness and filling up the head
                head = tmp;
                tail = tmp;     // они оба являются одним и тем же указателем, пока список размера 1
            }
            else {
                tail->next = tmp;
                tail = tail->next;
            }
        }

        void push_front(int n) {
            node* tmp = new node;
            tmp->data = n;
            tmp->next = nullptr;

            if (head == nullptr) {    // checking emptyness and filling up the head
                head = tmp;
                tail = tmp;     // они оба являются одним и тем же указателем, пока список размера 1
            } 
            else {
                node* head_old = head;
                head = tmp;
                head->next = head_old;
            }
        }
};

int main() {
    linked_list list;
    int size = 5;

    for (int i = 0; i < size; i++) {
        list.push_back(i * i);
    }

    list.push_front(555);

    list.print_list();

    return 0;
}