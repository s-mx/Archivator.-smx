//
// Created by sabyaninmax on 25.03.15.
//

#ifndef _ARCHIVATOR_SMX_PREFIXCODES_H_
#define _ARCHIVATOR_SMX_PREFIXCODES_H_

#include "Code.h"
#include "BinaryTree.h"
#include <map>

class PrefixCodes {
private:

    std::map<short, Code> codes;

public:

    PrefixCodes(const BinaryTree& tree);
    PrefixCodes();
    void built_codes_with_dfs(const Node* const ptr_node, Code way);
    size_t size() const;

    std::map<short, Code>::iterator begin();
    std::map<short, Code>::iterator end();
    std::map<short, Code>::const_iterator cbegin() const;
    std::map<short, Code>::const_iterator cend() const;
    Code& get_code(short val);
    const Code& get_code(short val) const;
    void add(const std::pair<short, Code>& item);
};


#endif //_ARCHIVATOR_SMX_PREFIXCODES_H_
