/*
Program in C++ to scan one text file (input.txt) and count the number of occurrences of each word in this file.
Print the number of distinct words. Binary search tree to keep track of all words.
When the input file has been scanned, print out the results to an output file (output.txt).
After reading a word from an input file, search for it in the tree and add it to the tree if it is not found. If it is found, increment the counter of the node.
*/

#include <fstream>
#include <sstream>
#include "linklist.h"
#include "binary_tree.h"

LinkList<string> readFile(string path);
BinaryTree<string> insertWords(LinkList<string> lines);
string stripAndNormalize(string word);
void writeFile(BinaryTree<string> text, string path);

int main() {
    LinkList<string> text = readFile(".../input.txt");
    //text.print();
    BinaryTree<string> binaryTree = insertWords(text);
    //binaryTree.printTree(binaryTree.root);
    //stripAndNormalize(binaryTree.root);
    writeFile(binaryTree, ".../sample.txt");
    return 0;
}

void writeFile(BinaryTree<string> text, string path){

	BinaryTree<string> binaryTree = BinaryTree<string>();
	ofstream write_file;
	write_file.open(path);
	if (!write_file.is_open()) {
        cerr << "File  could not be opened" << endl;
        exit(1);
    }
    while(true){
    	BinaryTreeNode<string> *tempHead = BinaryTree<string>(root);
    	write_file <<  tempHead->data << "\n";
    	tempHead = tempHead->next;
	}
	write_file.close();
	
}

string stripAndNormalize(string word){
	int m=0;
	for (int i = 1; i < word.length() ; i++) {
		//This implementation also check char is english character or not
		if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            word[m]==word[i];
			m++;
        }else{
        	continue;
		}
        /* This implementation can not include erasing '(apostrophe)
		if(word[i] == '!' || word[i] == ' ' || word[i] == '.'){
        	continue;
		}else{
			word[m]==word[i];
			m++;
		}
		*/
    }
}

BinaryTree<string> insertWords(LinkList<string> lines){
	BinaryTree<string> binaryTree = BinaryTree<string>();
	LinkListNode<string> *tempHead = lines.head;
	while (tempHead != NULL) {
        BinaryTreeNode<string> *binaryTreeNode = new BinaryTreeNode<string>(tempHead->data);
          
        binaryTree.insert(binaryTreeNode);
        tempHead = tempHead->next;
    }
     
	return binaryTree;   
}

LinkList<string> readFile(string path) {
    LinkList<string> text = LinkList<string>();
    ifstream read_file;
    read_file.open(path);

    if (!read_file.is_open()) {
        cerr << "File  could not be opened" << endl;
        exit(1);
    }
    
    string line;
    string word;
	while(getline(read_file, line)){
    	stringstream line_stream(line);
        while (getline(line_stream, word, ' ')) {
            LinkListNode<string> *node = new LinkListNode<string>(word);
            text.insertFirst(node);
        }
	}
    read_file.close();
    return text;
}
