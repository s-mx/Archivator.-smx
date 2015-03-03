#include <bits/stdc++.h>
#include "lib/reader.h"
#include "lib/writer.h"
#include "lib/compression.h"

int main(int argc, char* argv[]) {
    std::string input_file, output_file;
    if (argc == 1) {
        printf("No arguments\n");
        return 0;
    } else {
        input_file = argv[1];
        if (argc == 2) {
            output_file = argv[1];
            output_file += ".smx";
        } else {
            output_file = argv[2];
        }
    }

    /*
    Reader reader(input_file);
    Writer writer(output_file);
    Compression compression(&reader, &writer);
    compression.compress_huffman();
    */
}
