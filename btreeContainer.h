//
// Created by scani on 28/06/2022.
//

#ifndef BTREE_BTREECONTAINER_H
#define BTREE_BTREECONTAINER_H

#include <iostream>
#include "Models.h"

#define NODE_MAX_DEGREE 4

namespace BTree {

    /**
     * B-Tree container
     */
    class btreeContainer {
    public:
        btreeContainer() {
            auto node = new Node;
            node->children = new Node *[m_maxDegree];
            node->keys = new int[m_maxDegree - 1];
            node->parent = nullptr;
            node->isLeaf = true;
            for (int i = 0; i < m_maxDegree; i++) {
                node->children[i] = nullptr;
            }

            m_root = node;
        }

        /**
         * Insert an index in the B-Tree.
         * @param pIndex Index to insert.
         */
        void insert(const int pIndex) {

        }

        /**
         * Remove an index from the B-Tree.
         * @param pIndex Index to remove.
         */
        void remove(const int pIndex) {
        }

        /**
         * Traverse the whole container.
         * @param pNode Node to traverse.
         */
        void traverse(Node *pNode) {
            std::cout << std::endl;

            int i;
            for (i = 0; i < m_maxDegree; ++i) {
                if (!pNode->isLeaf) {
                    traverse(pNode->children[i]);
                }
                std::cout << " " << pNode->keys[i];
            }

            if (!pNode->isLeaf) {
                traverse(pNode->children[i]);
            }

            std::cout << std::endl;
        }

        /**
         * Search for a node from its index in the container.
         * @param key Index to find.
         * @return The node with the specified index, or nullptr if not found.
         */
        Node *search(Node *pNode, const int key) {
            // if it's the first key, then the node is returned
            if (pNode->keys[0] == key) {
                return pNode;
            }

            if (key < pNode->keys[0]) {
                return search(pNode->children[0], key);
            }

            for (int i = 0; i < m_maxDegree; ++i) {
                // if the node contains the key, return it
                if (pNode->keys[i] == key)
                    return pNode;

                // if the key is between current and next key, search between them
                if (pNode->keys[i] < key && pNode->keys[i + 1] > key)
                    return search(pNode->children[i], key);

                if (pNode->keys[i] < key && i == m_maxDegree)
                    return search(pNode->children[i + 1], key);
            }

            // nothing has been found
            return nullptr;
        }

    private:
        Node *m_root;
        int m_maxDegree = NODE_MAX_DEGREE;
    };
}


#endif //BTREE_BTREECONTAINER_H
