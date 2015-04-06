#include "reader.h"
#include "writer.h"
#include "Node.h"
#include "PrefixCodes.h"

#ifndef _SMX_HUFFMAN
#define _SMX_HUFFMAN


void write_coded_file(Reader*, Writer*, const PrefixCodes&);
void write_prefix_codes(Writer *, PrefixCodes const &);
void write_data(Reader *, Writer *, PrefixCodes const&);

#endif 
