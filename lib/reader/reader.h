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

        template <typename Type>
        int read_k(Type &ch, size_t k);
        int read_to_bucket();

    public:

        Reader();
        Reader(const std::string& name);

        void open(const std::string& name);

        void set_begin();
        bool eof();
        int getchar(char &ch);

        template <typename Type>
        int read1(Type &ch);
        template <typename Type>
        int read2(Type &ch);
        template <typename Type>
        int read4(Type &ch);
        Code read_code(size_t size_bytes, size_t size_bits);
        bool read_bit();
        ~Reader();
};
#endif
