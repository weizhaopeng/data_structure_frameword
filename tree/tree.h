#ifndef _TREE_H_
#define _TREE_H_

typedef struct BT_node{
    BT_data        *data;
    struct BT_node *lchild;
    struct BT_node *rchild;
    struct BT_node *parent;
} BT_node;

typedef struct Btree {
    BT_node *root;
    uint32_t BT_hei;
    uint32_t BT_capacity;

    Btree *(*tree_create)(int capacity);
    int  (*tree_make)(Btree *bt, Btree *lbt, Btree *rbt);
    int  (*tree_destroy)(Btree *bt);
}Btree;

enum {
	int pre_ord = 0x00;
	int in_ord  = 0x01;
	int post_ord = 0x02;
}trav_type;

#endif

