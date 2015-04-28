#include <bits/stdc++.h>
#include "Code.h"

#ifndef _SMX_READER
#define _SMX_READER
class Reader {
    private:

        static int LIMIT = 4;

        std::string name_file;
        std::ifstream stream;
        std::deque<bool> bucket;

        unsigned pop();
        unsigned read_k(size_t k);
        void read_to_bucket();

    public:

        Reader(const std::string& name);

        void set_begin();
        bool eof();
        char get_next();
        unsigned short read1();
        unsigned short read2();
        unsigned read4();
        Code read_code(size_t size_bytes, size_t size_bits);
        bool read_bit();
        ~Reader();
};
#endif
