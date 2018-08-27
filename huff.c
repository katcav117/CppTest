//
//  huff.c
//  
//
//  Created by Kathleen Cavanagh on 1/21/18.
//
//learning to use git is hard but necessary

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct huffman_node {
    struct huffman_node *left; //0
    struct huffman_node *right; //1
    char letter;
} Node;

bool isLeaf(Node *n){
    if ((n->left == 0) && (n->right == 0)){
        return true;
    }
    else{
        return false;
    }
}

//what about hte pointers to the eliminated leaves?
void removeLeaf(Node *n){
    //Huffman encoding means you wont' have unbalanced leaves
    //so this is essentially *extra*
    if(n->left != 0){
        removeLeaf(n->left);
        n->left = 0;
    }
    if(n->right !=0){
        removeLeaf(n->right);
        n->right = 0;
    }
    free(n);
    
}

// test another comment down here!
int main(){
    int N;
    scanf("%i\n", &N);
    Node *root = malloc(sizeof(Node));
    root->left = 0;//not a real memory address!
    root->right = 0;
    for(int i = 0; i<N; i++){
        char c = getchar();//int, character
        //printf("%c", c);
        char next_char = getchar();
        //printf("%c", next_char);
        Node *curr_node_point = root;
        //build tree
        while(next_char != '\n'){
            if(next_char == '0'){
                if(curr_node_point->left ==0){
                    Node *temp = malloc(sizeof(Node));
                    temp->left = 0;
                    temp->right = 0;
                    curr_node_point->left = temp;
                    curr_node_point = temp;
                }
                else{
                    curr_node_point = curr_node_point->left;
                }
            }
            else if(next_char == '1'){
                if((*curr_node_point).right ==0){
                    Node *temp = malloc(sizeof(Node));
                    temp->left = 0;
                    temp->right = 0;
                    curr_node_point->right = temp;
                    curr_node_point = temp;
                }
                else{
                    curr_node_point = curr_node_point->right;
                }
            }
            else{
                printf("Failure!!");
            }
            next_char = getchar();
        }
        curr_node_point->letter = c;
    }
    
    //traverse tree
    Node *curr_node_point = root;
    char next_char = getchar();
    //needed end of file here for various inputs!
    while(next_char!= '\n'&& next_char != EOF){
        while(!isLeaf(curr_node_point)){
            if(curr_node_point!=root){
                next_char = getchar();
            }
            if(next_char == '1'){
                curr_node_point = curr_node_point->right;
            }
            else{
                curr_node_point = curr_node_point->left;
            }
        }
        //get letter
        printf("%c",curr_node_point->letter);
        curr_node_point = root;
        next_char = getchar();
    }
    printf("\n");
    
    //remove nodes to prevent memory leak
    removeLeaf(root);
    
    return 0;
}
