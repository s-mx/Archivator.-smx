#include <bits/stdc++.h>
#include "Code.h"

#ifndef _SMX_READER
#define _SMX_READER
class Reader {
    private:

        static const int LIMIT = 4;

        bool opened;

        std::string name_file;
        std::ifstream stream;
        std::deque<bool> bucket;

        int pop(unsigned &ch);

        int read_k(unsigned int &ch, size_t k);
        int read_to_bucket();

    public:

        Reader();
        Reader(const std::string& name);

        void open(const std::string& name);

        void set_begin();
        bool eof();
        int getchar(char &ch);

        int read1(unsigned int &ch);
        int read2(unsigned int &ch);
        int read4(unsigned int &ch);
        Code read_code(size_t size_bytes, size_t size_bits);
        int read_bit(bool& bit);

        void close();
        ~Reader();
};
#endif
