//
// Created by sabyaninmax on 25.03.15.
//

#include "BinaryTree.h"
#include <set>

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

        vertex() {}
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

const Node* const BinaryTree::get_root() const {
    return root;
}