#include "reader.h"
#include <bits/stdc++.h>
#include "OC_lib.h"

Reader::Reader(const std::string& name) :
    name_file(name) {
    assert(check_read_access(name));
    stream.open(name, std::ios::binary);
}

void Reader::set_begin() {
    stream.seekg(0, stream.beg);
}

bool Reader::eof() {
    return stream.eof();
}
char Reader::get_next() {
    char byte = 0;
    if (eof()) {
        return 0;
    }

    stream.read((char *) &byte, sizeof byte);
    return byte;
}

Reader::~Reader() {
    stream.close();
}

unsigned short Reader::read1() {
    return (short) read_k(1);
}

unsigned short Reader::read2() {
    return (short) read_k(2);
}

unsigned int Reader::read4() {
    return read_k(4);
}

unsigned Reader::pop() {
    assert(bucket.size() < 8);

    unsigned res = 0;
    for (int i = 0; i < 8; i++) {
        res = (res << 1) + bucket.front();
        bucket.pop_front();
    }

    return res;
}

unsigned Reader::read_k(size_t k) {
    assert(k <= LIMIT);

    while (bucket.size() < 8 * k) {
        read_to_bucket();
    }

    unsigned res = 0;
    for (size_t i = 0; i < 8 * k; i++) {
        res = (res << 1) + bucket.front();
        bucket.pop_front();
    }

    return res;
}

void Reader::read_to_bucket() {
    assert(!eof());

    char ch;
    stream.read((char*) &ch, 1);
    for (size_t i = 0; i < 8; i++) {
        bucket.push_back(bool(int(ch) & (1 << i)));
    }
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
