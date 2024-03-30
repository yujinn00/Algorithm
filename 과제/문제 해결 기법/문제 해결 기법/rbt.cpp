// https://velog.io/@e_juhee/c%EC%96%B8%EC%96%B4-Red-Black-Tree-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0#1-tree-%EC%83%9D%EC%84%B1

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

enum Color { RED, BLACK };

typedef int Key;

struct Node {
    Color color;
    Key key;
    Node* parent, * left, * right;
};

struct RBT {
    Node* root;
    Node* leaf;
};

RBT* createTree(void) {
    RBT* tree = new RBT;
    tree->root = tree->leaf = new Node;
    tree->leaf->color = BLACK;
    return tree;
}

void traverseDelete(RBT* tree, Node* node) {
    if (node->left != tree->leaf) traverseDelete(tree, node->left);
    if (node->right != tree->leaf) traverseDelete(tree, node->right);
    delete node;
}

void deleteTree(RBT* tree) {
    Node* node = tree->root;
    if (node != tree->leaf) traverseDelete(tree, node);
    delete tree->leaf;
    delete tree;
}

void rotateRight(RBT* tree, Node* node) {
    Node* parent = node->parent;
    Node* grandParent = parent->parent;
    Node* rightChild = node->right;

    if (parent == tree->root) tree->root = node;
    else {
        if (grandParent->left == parent) grandParent->left = node;
        else grandParent->right = node;
    }

    node->parent = grandParent;
    parent->parent = node;
    node->right = parent;
    rightChild->parent = parent;
    parent->left = rightChild;
}

void rotateLeft(RBT* tree, Node* node) {
    Node* parent = node->parent;
    Node* grandParent = parent->parent;
    Node* leftChild = node->left;

    if (parent == tree->root) tree->root = node;
    else {
        if (grandParent->left == parent) grandParent->left = node;
        else grandParent->right = node;
    }

    node->parent = grandParent;
    parent->parent = node;
    node->left = parent;
    parent->right = leftChild;
    leftChild->parent = parent;
}

void swapColor(Node* a, Node* b) {
    int tmp = a->color;
    a->color = b->color;
    b->color = (tmp == BLACK) ? BLACK : RED;
}

void fixInsert(RBT* tree, Node* node) {
    Node* parent = node->parent;
    Node* grandParent = parent->parent;
    Node* uncle;

    int isLeft = node == parent->left;
    int isParentLeft;

    if (node == tree->root) {
        node->color = BLACK;
        return;
    }

    if (parent->color == BLACK) return;

    isParentLeft = grandParent->left == parent;
    uncle = (isParentLeft) ? grandParent->right : grandParent->left;

    if (uncle->color == RED) {
        parent->color = BLACK;
        uncle->color = BLACK;
        grandParent->color = RED;
        fixInsert(tree, grandParent);
        return;
    }

    if (isParentLeft) {
        if (isLeft) {
            rotateRight(tree, parent);
            swapColor(parent, parent->right);
            return;
        }

        rotateLeft(tree, node);
        rotateRight(tree, node);
        swapColor(node, node->right);
        return;
    }

    if (isLeft) {
        rotateRight(tree, node);
        rotateLeft(tree, node);
        swapColor(node, node->left);
        return;
    }

    rotateLeft(tree, parent);
    swapColor(parent, parent->left);
}

Node* insertNode(RBT* tree, const Key key)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->color = RED;
    newNode->left = newNode->right = tree->leaf;

    Node* curNode = tree->root;
    while (curNode != tree->leaf) {
        if (key < curNode->key) {
            if (curNode->left == tree->leaf) {
                curNode->left = newNode;
                break;
            }
            curNode = curNode->left;
        } else {
            if (curNode->right == tree->leaf) {
                curNode->right = newNode;
                break;
            }
            curNode = curNode->right;
        }
    }

    newNode->parent = curNode;

    if (curNode == tree->leaf) tree->root = newNode;

    fixInsert(tree, newNode);

    return newNode;
}

Node* findNode(const RBT* tree, const Key key) {
    Node* curNode = tree->root;
    while (curNode != tree->leaf) {
        if (key == curNode->key) return curNode;
        else curNode = (key < curNode->key) ? curNode->left : curNode->right;
    }
    return NULL;
}

Node* successor(const RBT* tree, Node* p) {
    Node* curNode = p->right;
    if (curNode == tree->leaf) {
        curNode = p;
        while (true) {
            if (curNode->parent->right == curNode) curNode = curNode->parent;
            else return curNode->parent;
        }
    }
    while (curNode->left != tree->leaf) curNode = curNode->left;
    return curNode;
}

void fixDelete(RBT* tree, Node* parent, int isLeft) {
    Node* leftRight = isLeft ? parent->left : parent->right;
    if (leftRight->color == RED) {
        leftRight->color = BLACK;
        return;
    }

    Node* sibling = isLeft ? parent->right : parent->left;
    Node* siblingLeft = sibling->left;
    Node* siblingRight = sibling->right;

    if (sibling->color == RED) {
        if (isLeft) rotateLeft(tree, sibling);
        else rotateRight(tree, sibling);

        swapColor(sibling, parent);
        fixDelete(tree, parent, isLeft);
        return;
    }

    Node* close = isLeft ? siblingLeft : siblingRight;
    Node* far = isLeft ? siblingRight : siblingLeft;

    if (isLeft && close->color == RED && far->color == BLACK) {
        rotateRight(tree, close);
        swapColor(sibling, close);
        fixDelete(tree, parent, isLeft);
        return;
    }

    if (isLeft && far->color == RED) {
        rotateLeft(tree, sibling);
        swapColor(sibling, parent);
        far->color = BLACK;
        return;
    }

    if (close->color == RED && far->color == BLACK) {
        rotateLeft(tree, close);
        swapColor(sibling, close);
        fixDelete(tree, parent, isLeft);
        return;
    }

    if (far->color == RED) {
        rotateRight(tree, sibling);
        swapColor(sibling, parent);
        far->color = BLACK;
        return;
    }

    sibling->color = RED;

    if (parent != tree->root) fixDelete(tree, parent->parent, parent->parent->left == parent);
}

int removeNode(RBT* tree, Node* deletes) {
    Node* remove;
    Node* removeParent, * replaceNode;
    int isRemoveBlack, isRemoveLeft;

    if (deletes->left != tree->leaf && deletes->right != tree->leaf) {
        remove = successor(tree, deletes);
        replaceNode = remove->right;
        deletes->key = remove->key;
    }
    else {
        remove = deletes;
        replaceNode = (remove->right != tree->leaf) ? remove->right : remove->left;
    }
    removeParent = remove->parent;

    if (remove == tree->root) {
        tree->root = replaceNode;
        tree->root->color = BLACK;
        delete remove;
        return 0;
    }

    isRemoveBlack = remove->color;
    isRemoveLeft = removeParent->left == remove;

    if (isRemoveLeft) removeParent->left = replaceNode;
    else removeParent->right = replaceNode;

    replaceNode->parent = removeParent;
    delete remove;

    if (isRemoveBlack) fixDelete(tree, removeParent, isRemoveLeft);
    return 0;
}

int main() {
    ifstream fin("rbt.inp");
    ofstream fout("rbt.out");

    RBT* tree = createTree();

    char op;
    int key;

    while (fin >> op >> key) {
        switch (op) {
        case 'i':
            insertNode(tree, key);
            break;
        case 'd': {
            Node* node = findNode(tree, key);
            if (node != NULL) removeNode(tree, node);
            break;
        }
        case 'c': {
            Node* node = findNode(tree, key);
            if (node != NULL)
                fout << "color(" << key << "): " << ((node->color == BLACK) ? "BLACK" : "RED") << "\n";
            break;
        }
        default:
            break;
        }
        if (key < 0) break;
    }

    fin.close();
    fout.close();

    deleteTree(tree);

    return 0;
}
