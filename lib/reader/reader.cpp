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

template <typename Type>
int Reader::read1(Type &ch) {
    return read_k(ch, 1);
}

template <typename Type>
int Reader::read2(Type &ch) {
    return read_k(ch, 2);
}

template <typename Type>
int Reader::read4(Type &ch) {
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

template <typename Type>
int Reader::read_k(Type &ch, size_t k) {
    assert(k <= LIMIT);

    while (bucket.size() < 8 * k) {
        if (!read_to_bucket())
            return 0;
    }

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

    for (size_t i = 0; i < 8; i++) {
        bucket.push_back(bool(int(ch) & (1 << i)));
    }

    return 1;
}

Code Reader::read_code(size_t size_bytes, size_t size_bits) {
    return Code(); // Implement later
}

bool Reader::read_bit() {
    if (!bucket.size())
        read_to_bucket();
    bool res = bucket.front();
    bucket.pop_front();
    return res;
}

Reader::Reader():
    opened(false) {
}

void Reader::open(const std::string &name) {
    opened = true;
    name_file = name;
    stream.open(name, std::ios::binary);
}
