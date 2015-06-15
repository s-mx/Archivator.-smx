//
// Created by sabyaninmax on 25.03.15.
//

#include "BinaryTree.h"

int get_max_value(const std::map<int, int>& cont) {
    if (cont.empty()) {
        return -1;
    }

    int res = cont.begin()->second;
    for (const auto& it : cont) {
        res = std::max(res, it.second);
    }

    return res;
}

BinaryTree::BinaryTree(const std::map<int, int>& frequency) :
        root(0)
{
    struct vertex {
        int freq, symbol;
        Node* ptr_root;

        vertex() : ptr_root(0) {}
        vertex(int _freq, int _symbol, Node *_ptr_root) :
                freq(_freq), symbol(_symbol), ptr_root(_ptr_root) {}

        bool operator< (const vertex& right) const {
            return freq < right.freq ||
                    (freq == right.freq && ptr_root < right.ptr_root);
        }
    };

    std::set<vertex> set_vertex;
    for (const auto& elem : frequency) {
        set_vertex.insert(vertex(elem.first, elem.second, new Node(elem.first, true)));
    }

    if (set_vertex.size() == 1) {
        Node *ptr = new Node(0, 0, set_vertex.begin()->symbol, true);
        root = new Node(ptr, 0, -1, false);
        return;
    }

    int symbol = get_max_value(frequency) + 1;
    while (set_vertex.size() > 1) {
        std::pair<vertex, vertex> pair_vertex;
        pair_vertex.first = *set_vertex.begin();
        set_vertex.erase(set_vertex.begin());
        pair_vertex.second = *set_vertex.begin();
        set_vertex.erase(set_vertex.begin());

        int sum_freq = pair_vertex.first.freq + pair_vertex.second.freq;
        Node *new_node = new Node(pair_vertex.first.ptr_root, pair_vertex.second.ptr_root, symbol);
        vertex new_vertex(sum_freq, symbol, new_node);
        set_vertex.insert(new_vertex);
        symbol++;
    }

    root = set_vertex.begin()->ptr_root;
}

Node* const BinaryTree::get_root() const {
    return root;
}

BinaryTree::BinaryTree(const PrefixCodes &codes) {
    root = new Node(0, 0,-1, false);
    auto ptr = root;
    for (auto it = codes.cbegin(); it != codes.cend(); it++) {
        for (auto elem : it->second.get_seq()) {
            auto ptr_to = ptr->get_elem(elem);
            if (ptr_to == 0) {
                ptr_to = new Node(0, 0, -1, false);
                (elem ? ptr->right : ptr->left) = ptr_to;
            }

            ptr = ptr_to;
        }

        ptr->is_term = true;
        ptr->code = it->second.get_seq();
        ptr->symbol = it->first;
        ptr = root;
    }
}
