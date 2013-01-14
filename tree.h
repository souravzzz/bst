#ifndef tree_h__
#define tree_h__

namespace tree {
    class node {
        public:
            node(int);
            ~node();
            int data;
            node* right;
            node* left;
    };
        
    class tree {
        public:
            tree();
            ~tree();
            void insert(int);
            void remove(int);
            void traverse();
            bool find(int);
        private:
            node* root;
            void insert(node**, int);
            void remove(node*, node*, int);
            void traverse(node*);
            void deallocate(node**);
            node* find(node*, int);
            node* findmin(node*);
    };
}

#endif

