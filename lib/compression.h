#include <bits/stdc++.h>
#include "reader.h"
#include "writer.h"

#ifndef _SMX_COMPRESSION
#define _SMX_SOMPRESSION

class Compression {
    private:

        Reader *reader;
        Writer *writer;

        std::map<int, int> calculate_frequency(Reader& reader);             

    public:

        Compression (Reader*, Writer*);
        void compress_huffman();
};
#endif
