#include "reader.h"
#include "writer.h"
#include "Node.h"
#include "PrefixCodes.h"

#ifndef _SMX_HUFFMAN
#define _SMX_HUFFMAN


void write_coded_file(Reader*, Writer*, const PrefixCodes&);
void write_prefix_codes(Writer *, PrefixCodes const &); // понять позже зачем так...
void write_data(Reader *, Writer *, PrefixCodes const&);

void read_prefix_codes(Reader *reader, PrefixCodes &codes);
void write_decompressed_file(Reader *reader, Writer *writer, const BinaryTree &);

#endif 
