#include <bits/stdc++.h>
#include <OS_lib.h>
#include "writer.h"
#include "reader.h"
#include "compression.h"

void print_help() {
    const std::string help_message =
            "Archivator\n"
            "There are 2 commands:\n"
            "1) compress\n"
            "2) decompress\n"
            "Each of them need \"input_name_file\", \"output_name_file\"\n"
            "If \"output_name_file\" is missing there will be created output file with \"input_name_file\".out name";
    std::cout << help_message << "\n";
}

int main(int argc, char* argv[]) {

    if (argc == 1) {
        std::cout << "Missing command\nTry help\n";
        return 0;
    }

    std::string command = argv[1];

    if (command == "compress") {
        if (argc == 2) {
            std::cout << "Wrong argument\nTry help\n";
            return 0;
        }

        std::string input, output;

        input = argv[2];
        if (argc == 3) {
            output = input + ".out";
            create_file(output);
        } else {
            output = argv[3];
        }

        Reader reader(input);
        Writer writer(output);
        Compression compression(&reader, &writer);
        compression.compress_huffman();
        reader.close();
        writer.close();
        return 0;
    } else if (command == "decompress") {
        if (argc == 2) {
            std::cout << "Wrong argument\nTry help\n";
            return 0;
        }

        std::string input, output;

        input = argv[2];
        if (argc == 3) {
            output = input + ".out";
            create_file(output);
        } else {
            output = argv[3];
        }

        Reader reader(input);
        Writer writer(output);
        Compression compression(&reader, &writer);
        compression.decompress_huffman();
        reader.close();
        writer.close();
        return 0;
    } else if (command == "help") {
        print_help();
    } else {
        std::cout << "Wrong command\nTry help";
        return 0;
    }

    return 0;
}