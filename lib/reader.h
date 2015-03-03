#include <bits/stdc++.h>

#ifndef _SMX_READER
#define _SMX_READER
class Reader {
    private:
    public:

        Reader(const std::string& name);

        void set_begin();
        bool eof();
        char get_next();
};
#endif
