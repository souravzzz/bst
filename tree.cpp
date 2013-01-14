#include "tree.h"
#include <iostream>

namespace tree {
    node::node(int d) : data(d), right(NULL), left(NULL) {}
    node::~node() {}
    
    tree::tree() {
        root = NULL;
    }
    
    tree::~tree() {
        deallocate(&root);
    }
    
    void tree::deallocate(node** current) {
        node* p = *current;
        if(p) {
            deallocate(&p->left);
            deallocate(&p->right);
            delete p;
            *current = NULL;
        }
    }
    
    void tree::insert(int d) {
        insert(&root, d);
    }
    
    void tree::insert(node** current, int d) {
        node* p = *current;
        if(!p) {
            p = new node(d);
            *current = p;
        } else {
            if(d < p->data)
                insert(&p->left, d);
            else if(d > p->data)
                insert(&p->right, d);
        }
    }
    
    bool tree::find(int d) {
        if(find(root, d))
            return true;
        else
            return false;
    }
    
    node* tree::find(node* current, int d) {
        node* result = current;
        if(current) {
            if(d < current->data)
                result = find(current->left, d);
            else if(d > current->data)
                result = find(current->right, d);
        }
        return result;
    }
    
    node* tree::findmin(node* current) {
        if(current->left)
            return findmin(current->left);
        else
            return current;
    }
    
    void tree::remove(int d) {
        if(d == root->data) {
            node* tmp = new node(0);
            tmp->left = root;
            remove(root, tmp, d);
            root = tmp->left;
            delete tmp;
        } else {
            remove(root, NULL, d);
        }
    }
    
    void tree::remove(node* current, node* parent, int d) {
        if(current) {
            if(d < current->data) {
                remove(current->left, current, d);
            } else if(d > current->data) {
                remove(current->right, current, d);
            } else {
                if(current->left && current->right) {
                    current->data = findmin(current->right)->data;
                    remove(current->right, current, d);
                } else if (current == parent->left) {
                    parent->left = current->left ? current->left : current->right;
                    delete current;
                } else if (current == parent->right) {
                    parent->right = current->left ? current->left : current->right;
                    delete current;
                }
            }
        }
    }
    
    void tree::traverse() {
        std::cout << std::endl;
        traverse(root);
        std::cout << std::endl;
    }
    
    void tree::traverse(node* current) {
        if(current) {
            traverse(current->left);
            std::cout << current->data << ' ';
            traverse(current->right);
        }
    }
}

