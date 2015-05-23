//
// Created by sabyaninmax on 25.03.15.
//

#ifndef _ARCHIVATOR_SMX_BINARYTREE_H_
#define _ARCHIVATOR_SMX_BINARYTREE_H_

#include "Node.h"
#include "PrefixCodes.h"
#include <map>

class PrefixCodes;

class BinaryTree {
private:

    Node *root;

public:

    Node * const get_root() const;
    BinaryTree(const std::map<int, int>& frequency);
    BinaryTree(const PrefixCodes& codes);
};


#endif //_ARCHIVATOR_SMX_BINARYTREE_H_
