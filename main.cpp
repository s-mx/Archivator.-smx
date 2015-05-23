#include <bits/stdc++.h>
#include <writer/writer.h>
#include <reader/reader.h>
#include "compression.h"

void f() {
    std::vector<int> arr;
    for (int i = 0; i < 256; ++i) {
        arr.push_back(i);
    }

    Writer writer("input.txt");

    for (auto it : arr)
        writer.write2((size_t) it);

    writer.close();

    Reader reader("input.txt");

    std::vector<int> b;
    unsigned ch;
    while (reader.read2(ch)) {
        b.push_back(ch);
    }

    std::cerr << (arr == b) << std::endl;
}

int main(int argc, char* argv[]) {
    f();
    return 0;

    std::string input_file, output_file;
    int command = 0;
    if (argc == 1) {
        printf("No arguments\n");
        return 0;
    } else {
        input_file = argv[1];

        if (argc >= 4 && std::string(argv[3]) == "decompress") {
            command = 1;
        }

        if (argc == 2) {
            output_file = std::string(argv[1]) + ".smx";
        } else {
            output_file = argv[2];
        }
    }

    Reader reader(input_file);
    Writer writer(output_file);
    Compression compression(&reader, &writer);

    if (command == 0)
        compression.compress_huffman();
    else
        compression.decompress_huffman();
}