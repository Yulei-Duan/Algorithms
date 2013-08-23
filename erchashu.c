#include <stdio.h>

typedef struct TTree {
    int left, right, key, p;
}Tree;

Tree tree[1000];
int root;

void insert(int z) {
    int x, y;
    y = -1;
    x = root;

    while(x != -1) {
        y = x;
        if(tree[z].key < tree[x].key)
            x = tree[x].left;
        else
            x = tree[x].right;
    }
    tree[z].p = y; ///*******
    if(y == -1)
        root = z;
    else {
        if(tree[z].key < tree[y].key)
            tree[y].left = z;
        else
            tree[y].right = z;
    }
}

int find(int z) {
    int y = root;
    while(y != -1) {
        if(tree[z].key < tree[y].key)
            y = tree[y].left;
        else if(tree[z].key > tree[y].key)
            y = tree[y].right;
        else return 1;
    }
    return 0;
}

void build() {
    int x;
    int k = 0;
    root = -1;
    while(1) {
        scanf("%d", &x);
        if(x == -1)
            break;
        tree[k].key = x;
        tree[k].left = tree[k].right = tree[k].p = -1;   ///********
        if(!find(k)) {
            insert(k);
            k++;
        }
    }
}

void pre_order(int z){
    if(z == -1)
        return;
    printf("%d ", tree[z].key);
    pre_order(tree[z].left);
    pre_order(tree[z].right);
}

void post_order(int z){
    if(z == -1) return;
    post_order(tree[z].left);
    post_order(tree[z].right);
    printf("%d ",tree[z].key);
}

void in_order(int z) {
    if(z == -1)
        return;
    in_order(tree[z].left);
    printf("%d ", tree[z].key);
    in_order(tree[z].right);
}

int maximum(int z){
    if(z == -1) return 0;
    while(tree[z].right!=-1)
        z = tree[z].right;
    ///return tree[z].key;
    return z;
}

int minimum(int z){
    if(z == -1) return 0;
    while(tree[z].left!=-1)
        z = tree[z].left;
    ///return tree[z].key;
    return z;
}

int successor(int x) {
    if(tree[x].right != -1)
        return minimum(tree[x].right);
    int y = tree[x].p;
    while(y != -1 || x != tree[y].left) {
        x = y;
        y = tree[y].p;
    }
    return y;
}

void delet(int z) {
    int x, y;
    /// y is the true node to delete

    if(tree[z].left == -1 || tree[z].right == -1)
        y = z;
    else
        y = successor(z);

    if(tree[y].left != -1)
        x = tree[y].left;
    else
        x = tree[y].right;

    if(y != z)
        tree[z].key = tree[y].key;

    if(x != -1)
        tree[x].p = tree[y].p;

    if(tree[y].p == -1)
        root = x;
    else if(y == tree[tree[y].p].left)
        tree[tree[y].p].left = x;
    else 
        tree[tree[y].p].right = x;
    /*
    if(x != -1) {
        tree[x].p = tree[y].p;
        if(y == tree[tree[y].p].left)
            
        else
            tree[tree[y].p].right = x;
    }
    */
}

int main() {
    build();
    in_order(root);
    printf("\n\n");
    //printf("\nmin = %d, max = %d\n", minimum(root), maximum(root));
    delet(3);
    delet(5);
    in_order(root);
    printf("\n\n");
    return 0;
}
