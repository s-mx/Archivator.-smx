//
// Created by sabyaninmax on 25.03.15.
//

#include <glob.h>
#include <bits/stl_pair.h>
#include <stddef.h>
#include "PrefixCodes.h"
#include "Code.h"

PrefixCodes::PrefixCodes(const BinaryTree &tree) {
    built_codes_with_dfs(tree.get_root(), Code());
}

void PrefixCodes::built_codes_with_dfs(const Node* const ptr_node, Code way) {
    if (ptr_node->is_term) {
        codes[ptr_node->symbol] = way;
        return;
    }

    if (ptr_node->left) {
        built_codes_with_dfs(ptr_node->left, way + 0);
    }
    if (ptr_node->right) {
        built_codes_with_dfs(ptr_node->right, way + 1);
    }
}

size_t PrefixCodes::size() const {
    return codes.size();
}

Code &PrefixCodes::get_code(short val) {
    return codes[val];
}

const Code &PrefixCodes::get_code(short val) const {
    return codes.at(val);
}

std::map<short, Code>::iterator PrefixCodes::begin() {
    return codes.begin();
}

std::map<short, Code>::iterator PrefixCodes::end() {
    return codes.end();
}

std::map<short, Code>::const_iterator PrefixCodes::cbegin() const {
    return codes.cbegin();
}

std::map<short, Code>::const_iterator PrefixCodes::cend() const {
    return codes.cend();
}

PrefixCodes::PrefixCodes() {

}

void PrefixCodes::add(const std::pair<short, Code> &item) {
    assert(codes.count(item.first) == 0 || codes[item.first] != item.second);
    codes[item.first] = item.second;
}
