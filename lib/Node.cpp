//
// Created by sabyaninmax on 25.03.15.
//

#include "Node.h"

Node *Node::get_elem(size_t number) {
    assert(number <= 1);
    return number == 0 ? left : right;
}

const Node *Node::get_elem(size_t number) const {
    assert(number <= 1);
    return number == 0 ? left : right;
}
