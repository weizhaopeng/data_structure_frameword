#include "tree.h"

Btree *tree_create(void) 
{
    Btree *bt = NULL;

    bt = malloc(sizeof(Btree));
    if (bt == NULL)       
        return ENOMEM;

    bt->BT_node = malloc(sizeof(BT_node));
    if (BT_node == NULL) {
        node_free(bt);
        return ENOMEM;
    }
    
    bt->root        = NULL;
    bt->BT_hei      = 1;
    bt->BT_capacity = 1;

    return bt;
}

int tree_make(BT_node *bt_node, Btree *lchild, Btree *rchild)
{
    if (bt_node == NULL)
        return -1; 
    
    bt_node->lbt = lchild;
    bt_node->rbt = rchild;

    if (lchild != NULL)
        lchild->parent = bt_node;
    if (rchild != NULL)
        rchild->parent = bt_node;

    lchild = NULL;
    rchild = NULL;
    return 0;
}

int tree_free(Btree *bt)
{
    if (bt != NULL) {
        
