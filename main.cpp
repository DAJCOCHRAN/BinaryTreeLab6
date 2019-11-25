#include"header.h"
#include<cctype>
void assignList(string myString);

string toUpper(string input);

int main(){
    //prompt string input
    char input;
    string statement;
    TreeType tree;
    TreeNode * root = tree.getRoot();
    int posToIgnore = 0;
    int level = 0;
    //CHECK FUNCTION INSTRUCTIONS FOR BEST GRADE
    while(input != 'q'){
    cout<<"--------------MENU--------------------" <<endl;
    cout<<"f)Fill the tree with Nodes"<< endl;
    //full tree 2 level combo: mdajrqt
    //IsFullTree()
    cout<<"1) Is the tree full?"<<endl;
    //IsBST()
    cout<<"2) Check that tree is orgainized"<<endl;
    //GetNodesAtLevel
    cout<<"3) Print Nodes at a certain level"<<endl;
    //PringAncestors
    cout<<"4) Print Node ancestors" <<endl;
    //GetSmallest()
    cout<<"5) Print smallest element of the tree"<<endl;
    //DeleteNode()
    cout<<"6) Delete a node"<<endl;
    cout<<"q) Quit"<<endl;
    cout<<"~---------------------------------------~"<<endl << endl;
    cout<<"What would you like to do?"<<endl;
    cin>>input;
    switch(input){
        case 'f': 
            cout << "What is the statement that you want loaded into the binary tree?" << endl;
            cin >> statement;
            statement = toUpper(statement);
            posToIgnore = tree.setRoot(statement);
            cout << posToIgnore <<endl;
            tree.fillTree(statement, posToIgnore);
            break;
        case '1':
            tree.IsFullTree(root, statement.length());
            break;
        case '3':
            cout<<"what level would you like to check"<<endl;
            cin >> level;
            tree.getNodesAtLevel(root, level);
        case 'q':
            return 0;
        default: 
            cout<< "mistake has been made" <<endl;
    }
    }
    //menu
    return 0;
}