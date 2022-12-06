#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    
    int item;
    int key;
    int rank;
    struct node *left;
    struct node *right;
}Node;


void createNode(int x){

}



/*

function insert(x, root) if root=null then {x.left←x.right←null; x.rank←RandomRank; return x} if x.key<root.key then
       if {{insert(}}{\emph{x, root.left}}{{)}}=x then
             if x.rank<root.rank then root.left←x else {root.left←x.right; x.right←root; return x}
else
       if {{insert(}}{\emph{x, root.right}}{{)}}=x then
             if x.rank≤root.rank then root.right←x else {root.right←x.left; x.left←root; return x}
return root
*/

void insert(int x, Node *root){

    createNode(x);

    if(root == NULL){
        
    }

}


Node zip(Node *x, Node *y){

    if(x == NULL){
        return y;
    }
    if(y == NULL){
        return x;
    }


    if(x->rank < y->rank){
        y->left = zip(x, y->left);
        return y;
    }else{
        x->right = zip(x->right, y);
        return x;
    }


}





/*

function delete(x, root) if x.key=root.key then return zip(root.left, root.right) if x.key<root.key then
       if x.key=root.left.key then
            root.left←{{zip(}}{\emph{root.left.left, root.left.right}}{{%
)}}
      else delete(x, root.left)
else
       if x.key=root.right.key then
            root.right←{{zip(}}{\emph{root.right.left, root.right.right}}%
{{)}}
      else delete(x, root.right)
return root
*/

void delete(int x, Node *root){

    if(x == root->key){

    }

    if(x == root->key){

    }else{

    }

    

}

int search(int x, Node *root){
    
    if(x == root->key){
            
    }

}

int randomRank(){
    int count = 0;
    int coin = 0;
  
    while(coin != 1){
        coin = rand()/(RAND_MAX/3); 
        count++;

    }

    return count;

}



int main(void){
    
    srand(time());

    Node root = NULL;

}