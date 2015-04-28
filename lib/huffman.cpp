#include <bits/stdc++.h>
#include "huffman.h"
#include "Node.h"

void write_prefix_codes(Writer *writer, PrefixCodes const &codes) {
    writer->write4(codes.size());

    for (auto it = codes.cbegin(); it != codes.cend(); ++it) {
        writer->write1(it->first);

        size_t size_byte = it->second.size_byte(),
               size_bits = it->second.size_bits();
        writer->write1(size_byte);
        writer->write1(size_bits);
        writer->write_code(it->second);
        writer->flush();
    }
}

void read_prefix_codes(Reader *reader, PrefixCodes & codes) {
    size_t size_prefix_codes = reader->read4();

    for (size_t i = 0; i < size_prefix_codes; i++) {
        std::pair<short, Code> current_pair;

        current_pair.first = reader->read1();

        size_t size_bytes = reader->read1(),
               size_bits = reader->read1();

        current_pair.second = reader->read_code(size_bytes, size_bits);

        codes.add(current_pair);
    }
}

void write_decompressed_file(Reader *reader, Writer *writer, const BinaryTree & tree) {
    Node * ptr_root = tree.get_root();
    while (!reader->eof()) {
        bool bit = reader->read_bit();
        ptr_root = ptr_root->get_elem(bit);
        if (ptr_root->is_term) {
            writer->write_code(ptr_root->code);
            ptr_root = tree.get_root();
        }
    }
}

void write_data(Reader *reader, Writer *writer, PrefixCodes const &codes) {
    size_t size_bits = 0;
    reader->set_begin();
    while (!reader->eof()) {
        size_bits += codes.get_code(reader->get_next()).size_bits();
    }

    writer->write4(size_bits/8);
    writer->write4(size_bits);

    reader->set_begin();
    while (!reader->eof()) {
        writer->write_code(codes.get_code(reader->get_next()));
    }

    writer->flush();
}

void write_coded_file(Reader* reader, Writer* writer, const PrefixCodes& codes) {
    write_prefix_codes(writer, codes);
    write_data(reader, writer, codes);
}