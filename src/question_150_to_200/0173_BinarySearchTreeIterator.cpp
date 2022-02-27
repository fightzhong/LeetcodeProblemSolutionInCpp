//
// Created by 钟胜龙 on 2022/2/27.
//

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(), left(), right() {}
};


class BSTIterator {
public:
    stack<TreeNode *> data;

    BSTIterator(TreeNode* root) {
        addEle(root);
    }

    int next() {
        TreeNode* node = data.top();
        data.pop();
        addEle( node->right );
        return node->val;
    }

    bool hasNext() {
        return !data.empty();
    }
private:
    void addEle(TreeNode* node) {
        if ( node == NULL ) {
            return;
        }

        data.push( node );
        addEle( node->left );
    }
};

int main() {
    TreeNode root;
    root.val = 10;

    TreeNode left;
    left.val = 5;

    TreeNode right;
    right.val = 20;

    root.left = &left;
    root.right = &right;

    BSTIterator bstIterator(&root);
    while( bstIterator.hasNext() ) {
        cout << bstIterator.next() << endl;
    }
}


