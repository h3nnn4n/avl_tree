#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"

_tree_node *tree_init(_tree_data *data){
    _tree_node *t=(_tree_node*)malloc(sizeof(_tree_node));
    _tree_data *datanew=(_tree_data*)malloc(sizeof(_tree_data));
    t->right=NULL;
    t->left=NULL;
    t->data=datanew;
    memcpy(t->data,data,sizeof(_tree_data));
    return t;
}

void list_add_left(_tree_node *p,_tree_data *data){
    if(p==NULL){
        //fprintf(stderr,"NULL Pointer\n");
    }else if(p->left!=NULL){
        //fprintf(stderr,"Not free pointer\n");
    }else{
        p->left = tree_init(data);
    }
}

void list_add_right(_tree_node *p,_tree_data *data){
    if(p==NULL){
        //fprintf(stderr,"NULL Pointer\n");
    }else if(p->right!=NULL){
        //fprintf(stderr,"Not free pointer\n");
    }else{
        p->right=tree_init(data);
    }
}

int tree_info(_tree_node *tree){
    if(tree!=NULL){
        return (int)tree->data->n;
    }
}

void tree_add_sorted(_tree_node *t,_tree_data *data){
    _tree_node *tree,*p,*q;
    q=t;
    p=t;

    while(q!=NULL && data->n != q->data->n){
        p = q;
        if(data->n<tree_info(p)){
            q = p->left;
        }else{
            q = p->right;
        }
    }
    if(data->n == p->data->n){

    }else if(data->n < tree_info(p)){
        list_add_left(p,data);
    }else{
        list_add_right(p,data);
    }
}

void tree_read_preorder(_tree_node *n){
    if(n!=NULL){
        fprintf(stdout,"%c",tree_info(n));
        tree_read_preorder(n->left);
        tree_read_preorder(n->right);
    }
}

void tree_read_inorder(_tree_node *n){
    if(n!=NULL){
        tree_read_preorder(n->left);
        fprintf(stdout,"%c",tree_info(n));
        tree_read_preorder(n->right);
    }
}

void tree_read_postorder(_tree_node *n){
    if(n!=NULL){
        tree_read_preorder(n->left);
        tree_read_preorder(n->right);
        fprintf(stdout,"%c",tree_info(n));
    }
}

_tree_node *tree_seek(_tree_node *node,_tree_data *data){
    if(node==NULL){
        return NULL;
    }

    if(data->n<node->data->n){
        return tree_seek(node->left,data);
    }else if(data->n<node->data->n){
        return tree_seek(node->right,data);
    }
    return node;
}

/*void tree_remove(_tree_node *node,_tree_data *data){
  _tree_data *n=tree_seek(node,data);

  }*/
