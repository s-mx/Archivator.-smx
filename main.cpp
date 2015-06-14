#include <bits/stdc++.h>
#include "writer.h"
#include "reader.h"
#include "compression.h"

int main(int argc, char* argv[]) {

    std::string input_file(argv[1]), output_file(argv[2]);

    Reader reader(input_file);
    Writer writer(output_file);

    Compression compression(&reader, &writer);

    compression.compress_huffman();

    reader.close();
    writer.close();

    Reader reader2("output.txt");
    Writer writer2("input2.txt");

    Compression compression2(&reader2, &writer2);
    compression2.decompress_huffman();

}