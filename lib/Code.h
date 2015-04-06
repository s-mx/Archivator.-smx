//
// Created by sabyaninmax on 25.03.15.
//

#ifndef _ARCHIVATOR_SMX_CODE_H_
#define _ARCHIVATOR_SMX_CODE_H_


#include <stddef.h>
#include <bits/stdc++.h>

class Code {
private:

    std::vector<bool> seq;

public:

    Code (std::vector<bool>);
    Code();
    Code operator+ (int add);
    size_t size_byte() const;
    size_t size_bits() const;
};


#endif //_ARCHIVATOR_SMX_CODE_H_
