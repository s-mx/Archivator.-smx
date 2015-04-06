//
// Created by sabyaninmax on 25.03.15.
//

#ifndef _ARCHIVATOR_SMX_BINARYTREE_H_
#define _ARCHIVATOR_SMX_BINARYTREE_H_

#include "Node.h"
#include <map>

class BinaryTree {
private:

    Node *root;

public:

    const Node * const get_root() const;
    BinaryTree(const std::map<int, int>& frequency);
};


#endif //_ARCHIVATOR_SMX_BINARYTREE_H_
