#include"header.h"
#include<cctype>
void assignList(string myString);

string toUpper(string input);

int main(){
    //prompt string input
    char input;
    string statement;
    int nodesAtLevel;
    TreeType tree;
    TreeNode * root = tree.getRoot();
    TreeNode * mostLeft = root;
    int posToIgnore = 0;
    int inputLevel = 0;
    int currLevel = 0;
    int nodeCount = 0;
    int pos = 0;
    ItemType myArr[50]; 
    //CHECK FUNCTION INSTRUCTIONS FOR BEST GRADE
    while(input != 'q'){
    cout<<"--------------MENU--------------------" <<endl;
    //fillTree()
    cout<<"f)Fill the tree with Nodes"<< endl;
    //full tree 2 level combo: mdajrqt
    //IsFullTree()
    cout<<"1) Is the tree full?"<<endl;
    //IsBST()
    cout<<"2) Check that tree is orgainized"<<endl;
    //GetNodesAtLevel
    cout<<"3) Get Node count at a certain level from 0 to N level"<<endl;
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
            //posToIgnore for element used as root
            posToIgnore = tree.setRoot(statement);
            tree.fillTree(root, statement, posToIgnore);
            break;
        case '1':
            tree.IsFullTree(root, statement.length());
            break;
        case '3':
            cout<<"what level would you like to check"<<endl;
            cin >> inputLevel;
            //find first most left valid
                
            nodeCount = tree.getNodesAtLevel(root, inputLevel, myArr);
            cout<<"Node Count is " << nodeCount<< endl;
            cout<<"at level " << inputLevel << endl;
            break;
        case 'q':
            return 0;
        default: 
            cout<< "mistake has been made" <<endl;
    }
    }
    //menu
    return 0;
}