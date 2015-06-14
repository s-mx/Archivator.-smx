#include <bits/stdc++.h>
#include "reader.h"
#include "writer.h"
#include "compression.h"
#include "huffman.h"

Compression::Compression(Reader* _reader, Writer* _writer) :
    reader(_reader), writer(_writer) {}

void print_tree(Node *tree) {
    #ifdef _DEBUG

    if (tree == 0)
        return;

    auto ptr = tree;
    std::cerr << ptr << ":\n";
    std::cerr << " left: " << ptr->left << "\n";
    std::cerr << " right: " << ptr->right << "\n";
    std::cerr << " symb: " << ptr->symbol << "\n";
    print_tree(ptr->left);
    print_tree(ptr->right);

    #endif
}

void print_tree(const BinaryTree& tree) {
    if (tree.get_root() == 0)
        return;
    print_tree(tree.get_root());
}

void Compression::compress_huffman() {
    std::map<int, int> frequency = calculate_frequency(*reader);
    BinaryTree tree(frequency);
    print_tree(tree);
    PrefixCodes prefix_codes(tree);
    prefix_codes.print_stdout();
    write_coded_file(reader, writer, prefix_codes);
}

template <typename T, typename P>
void print(const std::map<T, P>& container) {
    #ifdef _DEBUG

    for (auto it = container.cbegin(); it != container.cend();) {
        std::cerr << it->first << ": " << it->second;
        it++;
        if (it != container.cend())
            std::cerr << ", ";
    }

    #endif
}

#define _DEBUG
void print(const PrefixCodes& codes) {
    #ifdef _DEBUG
    for (auto it = codes.cbegin(); it != codes.cend(); it++) {
        std::cerr << it->first << " " << it->second << "\n";
    }

    #endif
}

std::map<int, int> Compression::calculate_frequency(Reader& reader) {
    reader.set_begin();
    std::map<int, int> frequency;

    char ch;
    while (reader.getchar(ch)) {
        frequency[ch]++;
    }

    print(frequency);
    return frequency;
}

void Compression::decompress_huffman() {
    PrefixCodes codes;

    read_prefix_codes(reader, codes);
    print(codes);
    BinaryTree tree(codes);

    write_decompressed_file(reader, writer, tree);
}