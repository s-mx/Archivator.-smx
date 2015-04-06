#include <bits/stdc++.h>
#include "Code.h"

#ifndef _SMX_WRITER
#define _SMX_WRITER
class Writer {
private:
public:

    Writer(const std::string& name);
    void write4(size_t);
    void write2(size_t);
    void write1(size_t);
    void write_code(const Code& code);
    void flush();

};
#endif
