#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left,*right;
};
void levelorder(struct Node* root) {
    if(root == NULL) {
        return;
    }
    queue < Node*> que;
    que.push(root);
    while(!que.empty()) {
        struct Node* temp = que.front();
        que.pop();
        cout << temp -> data << " ";
        if(temp->left)
            que.push(temp->left);
        if(temp->right)
            que.push(temp->right);
    }

}

Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int main() {
    Node* root = newNode(1);
    root->right = newNode(3);
    root->left = newNode(2);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelorder(root);
    return 0;
}
