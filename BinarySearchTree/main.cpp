#include<iostream>
using namespace std;


class Node {

public:
	int data;
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) {

        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
}

Node* Insert(Node* root,int data) {

	if(root == NULL) { // empty tree
		root = GetNewNode(data);

	}else if(data <= root->data) {

		root->left = Insert(root->left,data);
	}else {

		root->right = Insert(root->right,data);
	}
	return root;
}

bool Search(Node* root,int data) {
	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
int main() {

	Node* root = 0;
	root = Insert(root,15);
	root = Insert(root,10);
	root = Insert(root,20);
	root = Insert(root,25);
	root = Insert(root,8);
	root = Insert(root,12);

	int number;
	cout<<"Enter number want be searched\n";
	cin>>number;

	if(Search(root,number) == true)
        cout << number <<" is Found\n";
	else
        cout << number <<" is Not Found\n";

	return 0;
}
