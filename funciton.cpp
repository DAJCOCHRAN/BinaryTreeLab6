#include"header.h"
//main funcitons
//initialize tree root in heap
TreeType::TreeType(){
    root = new TreeNode;
}
//destroy initial root
/*----------------------------------
MUST DELETE NODES WHEN ADDED!!!!!
------------------------------------*/
TreeType::~TreeType(){
    static int count = 0;
    while(root->left != nullptr){
        static TreeNode * node = root->left;
        static TreeNode * prev = root;
        if((node->left == nullptr) && (node->right == nullptr)){
            cout << node->Info << " Deleted!" << endl;
            delete node;
            count++;
            node = prev;
            if(prev !=root){
                prev = prev->ancestor;
            }
        }
        else if((node->left != nullptr) && (node->right == nullptr)){
            prev = node;
            node = node->left;
        }
        else if((node->left == nullptr) && (node->right != nullptr)){
            prev = node;
            node = node->right;
        }
        //priority of shifting left if left and right pointers are valid
        else if((node->left != nullptr) && (node->right != nullptr)){
            prev = node;
            node = node->left;
        }
        else{
            cout << "error" <<endl;
        }
    }
    cout << "left Tree cleared!" <<endl;
    while(root->right != nullptr){
        static TreeNode * node = root->right;
        static TreeNode * prev = root;
        if((node->left == nullptr) && (node->right == nullptr)){
            delete node;
            node = prev;
            prev = prev->ancestor;
            count++;
        }
        else if((node->left != nullptr) && (node->right == nullptr)){
            prev = node;
            node = node->left;
        }
        else if((node->left == nullptr) && (node->right != nullptr)){
            prev = node;
            node = node->right;
        }
        //priority of shifting left if left and right pointers are valid
        else if((node->left != nullptr) && (node->right != nullptr)){
            prev = node;
            node = node->left;
        }
        else{
            cout << "error" <<endl;
        }
    }
    cout << "right Tree cleared!" <<endl;
    delete root;
    count++;
    cout << count << " Nodes deleted from tree" << endl;
}



//set the root of our tree
//must return int for position to ignore
int TreeType::setRoot(string input){
    //searching mid alphabet lowercase first
    for(int i=0; i<input.length(); i++){
        if(input[i] > 'I' && input[i] < 'R'){
            root->Info = input[i];
            cout << "Root " << input[i] << " has been placed as root" <<endl;
            return i;
        }
    }
    //then upper
    for(int i=0; i<input.length(); i++){
        if(input[i] > 'Q'){
            root->Info = input[i];
            cout << "Root" << input[i] << " has been placed" <<endl;
            return i;
        }
    }
    //then lower
    for(int i=0; i<input.length(); i++){
        if(input[i] > 'A'){
            root->Info = input[i];
            cout << "Root" << input[i] << " has been placed" <<endl;
            return i;
        }
    }
    //then numeric
    for(int i=0; i<input.length(); i++){
        if(input[i] > '0'){
            root->Info = input[i];
            cout << "Root" << input[i] << " has been placed" <<endl;
            return i;
        }
    }
    //then any other character
    root->Info = input[0]; 
    cout << "Root" << input[0] << " has been placed" <<endl;
    return 0;
}

void TreeType::fillTree(string input, int ignore){ 
        static TreeNode * node = root;
        static TreeNode * prev = root;
        static int pos = 0;
        //our position is past the last character
        if(pos == input.length()){
        cout << "works" <<endl;
            return;
        }
        else if(pos == ignore){
            cout << "skipped root position" <<endl;
            pos++;
            fillTree(input, ignore);
        }
        //source node is greater than character and is a leaf --LEFT
        else if((node->Info > input[pos]) && (node->left == nullptr)){
            TreeNode * leftLeaf = new TreeNode;
            leftLeaf->Info = input[pos];
            node->left = leftLeaf;
            leftLeaf->ancestor = node;
            //prepare next recursion with new character
            cout << leftLeaf->Info <<" has been placed left of " << prev->Info <<endl;
            prev = root;
            node = root;
            pos++;
            fillTree(input, ignore);
        }
        //source node is greater and is a branch --LEFT
        else if((node->Info > input[pos]) && (node->left != nullptr)){
            prev = node;
            node = node->left;
            cout << "skipped left" <<endl;
            fillTree(input, ignore);
        }
        //source node is less/equal than character and is a leaf --RIGHT
        else if((node->Info <= input[pos]) && (node->right == nullptr)){
            TreeNode * rightLeaf = new TreeNode;
            rightLeaf->Info = input[pos];
            node->right = rightLeaf;
            rightLeaf->ancestor = node;
            //prepare next cycle with new character
            cout << rightLeaf->Info <<" has been placed right of " << prev->Info <<endl;
            prev = root;
            node = root;
            pos++;
            fillTree(input, ignore);
        }
        //source node is less/equal and is a branch --RIGHT
        else if((node->Info <= input[pos]) && (node->left != nullptr)){
            prev = node;
            node = node->right;
            cout << "skipped right" <<endl;
            fillTree(input, ignore);
        }
        else{
            cout << "error" <<endl;
            return;
        }
    return;
}

string toUpper(string input){
    for (int i=0; i<input.length(); i++){
        input[i] = toupper(input[i]);
    }
    return input;
}