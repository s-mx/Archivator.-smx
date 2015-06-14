//
// Created by sabyaninmax on 25.03.15.
//

#ifndef _ARCHIVATOR_SMX_NODE_H_
#define _ARCHIVATOR_SMX_NODE_H_


#include <glob.h>
#include <bits/stdc++.h>
#include "Code.h"

class Node {
public:
    Node *left, *right;
    int symbol;
    bool is_term;
    Code code;
    Node (Node *_left = 0, Node *_right = 0, int _symbol = -1, bool state = false) :
            left(_left), right(_right), symbol(_symbol), is_term(state) {}

    Node (int _symbol, bool state) : left(0), right(0), symbol(_symbol), is_term(state) {}
    Node * get_elem(size_t number);
    const Node *  get_elem(size_t number) const;
};


#endif //_ARCHIVATOR_SMX_NODE_H_