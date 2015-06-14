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

Code Code::operator+=(int add) {
    seq.push_back(add);
    return Code(seq);
}

size_t Code::size_byte() const {
    return size_t(ceil((seq.size() + .0) / 8));
}

size_t Code::size_bits() const {
    return seq.size();
}

Code::Code(std::vector<bool> vector) {
    seq = vector;
}

std::vector<bool>::iterator Code::begin() {
    return seq.begin();
}

std::vector<bool>::iterator Code::end() {
    return seq.end();
}

std::vector<bool>::const_iterator Code::cbegin() const {
    return seq.cbegin();
}

std::vector<bool>::const_iterator Code::cend() const {
    return seq.cend();
}

bool Code::operator==(const Code &other) const {
    return seq == other.seq;
}

bool Code::operator!=(const Code &other) const {
    return ! this->operator==(other);
}

std::ostream &operator<<(std::ostream &stream, const Code &code) {
    for (const auto it : code.seq) {
        stream << it;
    }

    return stream;
}

const std::vector<bool> &Code::get_seq() const {
    return seq;
}
