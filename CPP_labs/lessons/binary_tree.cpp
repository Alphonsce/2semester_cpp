#include <iostream>
#include <cstdio>
#include <stdlib.h>

typedef int treeT;      // чтобы тип в одном месте кода поменять

struct bin_tree {
    treeT data;
    bin_tree* left;
    bin_tree* right;
};

// указатель на корневую - root
// если меньше корневой - в левое поддерево, больше корневой - в правое.

void create_tree_node(bin_tree** root, treeT data) {    // двойной указатель, потому что первый указатель типо как изменяемая ссылка, чтобы передать в функцию, потому что мы собрались изменять указатель, а второй - это просто указатель на bin_tree
    // ниже * - это очевидно взятие значения по адресу
    *root = new bin_tree;
    (*root)->left = NULL;
    (*root)->right = NULL;
    (*root)->data = data;
}

void add_node(bin_tree **root, treeT data) {
    if (data == (*root)->data)
        return;
    if (data > (*root)->data) {
        if ((*root)->right)
            add_node(&((*root)->right), data);
        else
            create_tree_node(&((*root)->right), data);
    }
    else {
        if ((*root)->left)
            add_node(&((*root)->left), data);
        else
            create_tree_node(&((*root)->left), data);
    }
}

// Печать - это печать левого поддерева, потом текущего узла, потом правого поддерева
// Уровень - это глубина погружения в дерево, отсчет с 0 идет
void print_tree_level(bin_tree* root, int level) {  // здесь мы не будем изменять указатель, поэтому одинарный указатель передаем
    if (root->right)
        print_tree_level(root->right, level + 1);

    for (int i = 0; i < level; i ++) {
        printf("---");
    }
    printf("%d\n", root->data);     // %d - целое число
    if (root->left)
        print_tree_level(root->left, level + 1);
}

void print_tree(bin_tree* root) {
    print_tree_level(root, 0);
}

// удаление элемента:
void del_node(bin_tree* root, treeT key) {
    bin_tree* curr = root;
    bin_tree* parent = NULL;

    // обнаруживаем ноду со значением key
    while(curr && curr->data != key) {
        parent = curr;
        if (curr->data > key) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    if (!curr)
        return ;
    
    // первый случай: у ноды со занчением key, которую хотим удалить, слева NULL:
    if (curr->left == NULL) {
        if (parent && parent->left == curr)
            parent->left = curr->right;
        if (parent && parent->right == curr)
            parent->right = curr->right;
        delete curr;
        return;
    }
    // второй случай: справа NULL
    if (curr->right == NULL) {
        if (parent && parent->right == curr)
            parent->right = curr->left;
        if (parent && parent->left == curr)
            parent->left = curr->left;
        delete curr;
        return;
    }

    // если нет NULL в потомках: ищем самый левый справа или самый правый слева - неважно
    bin_tree* replace = curr ->right;
    while (replace->left) {
        replace = replace->left;
    }
    treeT replace_value = replace->data;
    del_node(curr, replace_value);
    curr->data = replace_value;
    return;
}

int main() {

    bin_tree* tree;
    const int n = 7;
    int elems_for_tree[n] = {42, 41, 10, 20, 56, 111, 48}; 

    create_tree_node(&tree, elems_for_tree[0]);
    for (int i = 1; i < n; i ++) {
        add_node(&tree, elems_for_tree[i]);
    }

    print_tree_level(tree, 0);

}