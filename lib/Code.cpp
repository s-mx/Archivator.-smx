//
// Created by sabyaninmax on 25.03.15.
//

#include <glob.h>
#include "Code.h"

Code::Code() {

}

Code Code::operator+(int add) {
    Code new_code(seq);
    new_code.seq.push_back(bool(add));
    return new_code;
}

size_t Code::size_byte() const {
    return seq.size() / 8;
}

size_t Code::size_bits() const {
    return seq.size();
}

Code::Code(std::vector<bool> vector) {
    seq = vector;
}
