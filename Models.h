//
// Created by scani on 28/06/2022.
//

#ifndef BTREE_MODELS_H
#define BTREE_MODELS_H

struct Node {
    // Keys in the node
    int *keys;

    // Nodes in this node
    Node **children;

    // Is this node a leaf ?
    bool isLeaf;

    // Parent of this node
    Node *parent;
};

#endif //BTREE_MODELS_H
