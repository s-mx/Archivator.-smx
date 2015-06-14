#include "reader.h"
#include <bits/stdc++.h>
#include "OS_lib.h"

Reader::Reader(const std::string& name) :
    opened(true), name_file(name) {
    assert(check_read_access(name));
    stream.open(name, std::ios::binary);
}

void Reader::set_begin() {
    stream.clear();
    stream.seekg(0, stream.beg);
}

bool Reader::eof() {
    return stream.eof();
}

int Reader::getchar(char &ch) {
    if (eof()) {
        return 0;
    }

    stream.read((char *) &ch, sizeof ch);
    return eof() ? 0 : 1;
}

Reader::~Reader() {
    stream.close();
}

int Reader::read1(unsigned int &ch) {
    return read_k(ch, 1);
}

int Reader::read2(unsigned int &ch) {
    return read_k(ch, 2);
}

int Reader::read4(unsigned int &ch) {
    return read_k(ch, 4);
}

int Reader::pop(unsigned &ch) {
    assert(bucket.size() < 8);

    ch = 0;
    for (int i = 0; i < 8; i++) {
        ch = (ch << 1) + bucket.front();
        bucket.pop_front();
    }

    return 1;
}

template <typename container>
void print(const container& arr) {
#ifdef _DEBUG

    for (auto it : arr)
        std::cerr << it << " ";
    std::cerr << "\n";

    #endif
}


int Reader::read_k(unsigned int &ch, size_t k) {
    assert(k <= LIMIT);

    while (bucket.size() < 8 * k) {
        if (!read_to_bucket())
            return 0;
    }

    print(bucket);

    ch = 0;
    for (size_t i = 0; i < 8 * k; i++) {
        ch = (ch << 1) + bucket.front();
        bucket.pop_front();
    }

    return 1;
}

int Reader::read_to_bucket() {
    assert(!eof());

    char ch;

    if (stream.read((char*) &ch, 1) == 0)
        return 0;

    for (int i = 7; i >= 0; i--) {
        bucket.push_back(bool(int(ch) & (1 << i)));
    }

    print(bucket);

    return 1;
}

Code Reader::read_code(size_t size_bytes, size_t size_bits) {
    Code res = Code();

    while (bucket.size() < 8 * size_bytes) {
        if (!read_to_bucket())
            break;
    }

    for (int i = 0; i < size_bits; i++) {
        res += bucket.front();
        bucket.pop_front();
    }

    return res;
}

int Reader::read_bit(bool& bit) {
    if (!bucket.size()) {
        if (!read_to_bucket())
            return 0;
    }

    bit = bucket.front();
    bucket.pop_front();
    return 1;
}

Reader::Reader():
    opened(false) {
}

void Reader::open(const std::string &name) {
    opened = true;
    name_file = name;
    stream.open(name, std::ios::binary);
}

void Reader::close() {
    opened = false;
    name_file = "";
    stream.close();
    bucket.clear();
}
