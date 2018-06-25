/*Time complexity : O(n)
  Data Structure : Using Two Stacks----> (1 stack for current level nodes, other for the next level nodes)

*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void zigzagtraversal(struct Node* root) {
    if(root == NULL) {
        return;
    }
    stack<struct Node*> currlevel;
    stack<struct Node*> nextlevel;
    currlevel.push(root);
    bool lefttoright = true;
    while(!currlevel.empty()) {
        struct Node* temp = currlevel.top();
        currlevel.pop();
        if(temp != NULL) {
            cout << temp->data << " ";
            if(lefttoright) {
                if(temp->left)
                    nextlevel.push(temp->left);
                if(temp->right)
                    nextlevel.push(temp->right);

            }
            else {
                if(temp->right)
                    nextlevel.push(temp->right);
                if(temp->left)
                    nextlevel.push(temp->left);
            }

        }
        if(currlevel.empty()) {
            lefttoright = !lefttoright;                   //--------> to maintain the zig zag order  
            swap(currlevel, nextlevel);                  //---------> to get ready for next level
        }

    }

}
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    zigzagtraversal(root);
    return 0;
}
