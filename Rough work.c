Tree insertIntoAVLTree(Tree tree, int key) {
    if (tree == NULL) {
        return newTree(key);
    } else if (key < tree->key) { // go left
        printf("AVL~insert>> Going left at %d to insert %d\n", tree->key, key);
        tree->left = insertIntoAVLTree(tree->left, key);
    } else if (key > tree->key) { // go right
        printf("AVL~insert>> Going right at %d to insert %d\n", tree->key, key);
        tree->right = insertIntoAVLTree(tree->right, key);
    } else { // tree-> == key
        printf("AVL~insert>> Duplicate key %d\n");
        return tree;
    }
    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    int balanceFactor = getHeight(tree->left) - getHeight(tree->right);
    // Left left
    if (balanceFactor > 1 && key < tree->left->key) {
        printf("AVL~insert>> LL at %d while inserting %d\n", tree->key, key);
        return rotateRight(tree);
    }
    // Left Right
    if (balanceFactor > 1 && key > tree->left->key) {
        printf("AVL~insert>> LR at %d while inserting %d\n", tree->key, key);
        tree->left = rotateLeft(tree->left);
        return rotateRight(tree);
    }
    // Right Right
    if (balanceFactor < -1 && key > tree->right->key) {
        printf("AVL~insert>> RR at %d while inserting %d\n", tree->key, key);
        return rotateLeft(tree);
    }
    // Right Left
    if (balanceFactor < -1 && key < tree->right->key) {
        printf("AVL~insert>> RL at %d while inserting %d\n", tree->key, key);
        tree->right = rotateRight(tree->right);
        return rotateLeft(tree);
    }
    return tree;
}
