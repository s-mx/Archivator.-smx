#include <glob.h>
#include "writer.h"
#include "OS_lib.h"

Writer::Writer(std::string const & name){
    assert(check_write_access(name));
    stream.open(name, std::ios::binary);
}

void Writer::write4(size_t t) {
    char out[4] = {};
    for (int i = 3; i >= 0; i--) {
        out[i] = char(t % (1<<8));
        t /= (1<<8);
    }

    for (int i = 0; i < 4; i++)
        stream.write(static_cast<char*>(&out[i]), 1);
}

void Writer::flush() {
    stream.flush();
}

void Writer::write_code(const Code &code) {
    for (auto it = code.cbegin(); it != code.cend(); it++) {
        bucket.push_back(*it);
    }

    while (bucket.size() >= 8) {
        int out = 0;
        for (int i = 0; i < 8; i++) {
            out = (out<<1) + bucket.front();
            bucket.pop_front();
        }

        stream.write((char*) &out, 1);
    }
}

void Writer::write2(size_t t) {
    char out[2] = {};
    out[0] = char(t / (1<<8));
    out[1] = char(t % (1<<8));
    stream.write(static_cast<char*>(&out[0]), 1);
    stream.write(static_cast<char*> (&out[1]), 1);
}

void Writer::write1(size_t t) {
    stream.write((char*) &t, 1);
}

Writer::~Writer() {
    close();

    stream.close();
}

void Writer::write(char ch) {
    write1(ch);
}

void Writer::close() {
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
}
