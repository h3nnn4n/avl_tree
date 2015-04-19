#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tree.h"

int main(){
    int i;
    _tree_node *tree;
    _tree_data data;

    data.n='k';

    srand(time(NULL));

    tree=tree_init(&data);

    for(i=0;i<26;i++){
        data.n=rand()%26+'a';
        data.n=i+'a';
        tree_add_sorted(tree,&data);
    }

    tree_read_preorder(tree);puts("");
    tree_read_inorder(tree);puts("");
    tree_read_postorder(tree);puts("");

    return EXIT_SUCCESS;
}
