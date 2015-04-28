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
    std::vector<bool>::iterator begin();
    std::vector<bool>::iterator end();
    std::vector<bool>::const_iterator cbegin() const;
    std::vector<bool>::const_iterator cend() const;

    bool operator == (const Code& other) const;
    bool operator != (const Code& other) const;
};


#endif //_ARCHIVATOR_SMX_CODE_H_
