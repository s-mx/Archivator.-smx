#include <bits/stdc++.h>
#include "reader.h"
#include "writer.h"
#include "compression.h"
#include "huffman.h"

Compression::Compression(Reader* _reader, Writer* _writer) :
    reader(_reader), writer(_writer) {}

void Compression::compress_huffman() {
    std::map<int, int> frequency = calculate_frequency(*reader);
    BinaryTree tree(frequency);
    PrefixCodes prefix_codes(tree);
    write_coded_file(reader, writer, prefix_codes); 
}

std::map<int, int> Compression::calculate_frequency(Reader& reader) {
    reader.set_begin();
    std::map<int, int> frequency;

    while (!reader.eof()) {
        frequency[reader.get_next()]++;
    }

    return frequency;
}

void Compression::decompress_huffman() {
    PrefixCodes codes;

    read_prefix_codes(reader, codes);
    BinaryTree tree(codes);

    write_decompressed_file(reader, writer, tree);
}