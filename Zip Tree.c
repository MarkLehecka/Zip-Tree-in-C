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

Node* insert(Node* x, Node *root){

    //x->key = x; need to make sure i create the node with a key value before
    // need to make sure a node is created before insertion probably

    if(root == NULL){  
        
        
        x->right = NULL;
        x->left = NULL;
        x->rank = randomRank();
        return x;
    }

    if(x < root->key){

        if(insert(x, root->left) == x){   
            if(x->rank < root-> rank){
                root->left = x; 
            }else{
                root->left = x->right; 
                x->right =root; 
                return x;
            }
        }
            

    }else{

        if(insert(x, root->right) == x){
             if(x->rank <= root-> rank){
                root->right = x;
            }
            else{
                root->right = x->left; 
                x->left=root; 
                return x;
            }


        }
    }
}

Node* zip(Node *x, Node *y){

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

Node* delete(Node* x, Node* root){

    if(x == root->key){
        return zip(root->left, root->right);
    }

    if(x < root->key){

        if(x->key == root->left->key){

            root->left = zip(root->left->left, root->left->right);

        }else{
            delete(x, root->left);
        }
    }else{

        if(x->key == root->right->key){

            root->right = zip(root->right->left, root->right->right);

        }else{
            delete(x, root->right);
        }
    }

    return root;
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

    Node* root = NULL;

}