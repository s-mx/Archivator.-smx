#include <glob.h>
#include "writer.h"
#include "OS_lib.h"

Writer::Writer(std::string const & name){
    assert(check_write_access(name));
    stream.open(name, std::ios::binary);
}

void Writer::flush() {
    while (bucket.size() >= 8) {
        int out = 0;
        for (int i = 0; i < 8; i++) {
            out = (out<<1) + bucket.front();
            bucket.pop_front();
        }

        stream.write((char*) &out, 1);
    }

    stream.flush();
}

void Writer::write_code(const Code &code) {
    for (auto it = code.cbegin(); it != code.cend(); it++) {
        bucket.push_back(*it);
    }

    flush();
}

template <typename C>
void print(const C& deq) {
    #ifdef _DEBUG

    for (const auto it : deq) {
        std::cerr << it << " ";
    }

    std::cerr << "\n";

    #endif
}

void Writer::write4(unsigned t) {
    for (int i = 31; i >= 0; i--) {
        bucket.push_back(bool(t & (1 << i)));
    }

    print(bucket);
    flush();
}

void Writer::write2(unsigned t) {
    for (int i = 15; i >= 0; i--) {
        bucket.push_back(bool(t & (1<<i)));
    }

    flush();
}

void Writer::write1(unsigned t) {
    for (int i = 7; i >= 0; i--) {
        bucket.push_back(bool(t & (1<<i)));
    }

    flush();
}

Writer::~Writer() {
    if (stream.is_open())
        close();
}

void Writer::write(char ch) {
    write1(unsigned(ch));
}

void Writer::close() {
    flush();
    if (bucket.size()) {
        char out = 0;
        for (int i = 0; i < 8; i++) {
            out <<= 1;
            if (bucket.size()) {
                out += bucket.front();
                bucket.pop_front();
            }
        }

        stream.write((char *) &out, 1);
    }

    stream.close();
}
