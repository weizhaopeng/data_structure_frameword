#include "tree.h"

//创造二叉树（空二叉树）
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

//根据左子树和右子树和父节点生成新二叉树
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

//TODO:释放点二叉树
int tree_free(Btree *bt)
	
//二叉树的遍历算法
int BT_tra(Btree *bt, trav_type tt, int (*BT_oper)(BT_node *bt_node))
{
	BT_node *bt_root = bt->root;
	if (bt_root == NULL)
		return ENOMEM;

	int ret;
	switch (tt) {
		case pre_ord:
			ret = pre_order(bt_root, bt_oper);
			break;
		case in_ord:
			ret = in_order(bt_root, bt_oper);
			break;
		case post_ord:
			ret = post_order(bt_root, bt_oper);
			break;
		default:
			break;
	}
	if (ret == -1)
		return -1;
	else
		return 0;
}

//先序，中序，后序递归遍历二叉树算法
int pre_order(BT_node *bt_node, int (*bt_oper)(BT_node *bt_node))
{
	int ret;
	ret = bt_oper(bt_node);

	if (bt_node->lbt != NULL)
		ret = pre_order(bt_node->lbt);

	if (bt_node->rbt != NULL)
		ret = pre_order(bt_node->rbt);
		
	return ret;
}
	
int in_order  (BT_node *bt_node, int (*bt_oper)(BT_node *bt_node))
{
	int ret;

	if (bt_node->lbt != NULL)
		ret = in_order(bt_node->lbt);

	ret = bt_oper(bt_node);

	if (bt_node->rbt != NULL)
		ret = in_order(bt_node->rbt);
		
	return ret;
}

int post_order(BT_node *bt_node, int (*bt_oper)(BT_node *bt_node))
{
	int ret;

	if (bt_node->lbt != NULL)
		ret = post_order(bt_node->lbt);

	ret = bt_oper(bt_node);

	if (bt_node->rbt != NULL)
		ret = post_order(bt_node->rbt);
		
	return ret;
}

//先序，中序，后序二叉树的非递归遍历算法


        
