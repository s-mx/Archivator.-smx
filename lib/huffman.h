#include "reader.h"
#include "writer.h"

#ifndef _SMX_HUFFMAN
#define _SMX_HUFFMAN
struct Node {
    Node *left, *right;
    int symbol;
    bool is_term;
    Node (Node *_left = 0, Node *_right = 0, int _symbol = -1, bool state = false) :
        left(_left), right(_right), symbol(_symbol), is_term(state) {}

    Node (int _symbol, bool state) : symbol(_symbol), is_term(state) {}
};

class BinaryTree {
    private:

        Node *root;

    public:

        const Node * const get_root() const;
        BinaryTree(const std::map<int, int>& frequency);
};

class PrefixCodes {
    private:

        std::map<int, int> codes;

    public:

        PrefixCodes(const BinaryTree& tree);
        void built_codes_with_dfs(const Node* const ptr_node, int way);
};

void write_coded_file(Reader*, Writer*, const PrefixCodes&);
#endif 
