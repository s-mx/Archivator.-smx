//
// Created by smx on 25.04.15.
//

#include "OS_lib.h"
#include <unistd.h>

bool check_read_access(const std::string& path) {
    int res = access(path.c_str(), R_OK);
    #ifdef _DEBUG
        std::cerr << path << " " << res << "\n";
    #endif

    return res != -1;
}

bool check_write_access(const std::string& path) {
    int res = access(path.c_str(), W_OK);
#ifdef _DEBUG
    std::cerr << path << " " << res << "\n";
#endif

    return res != -1;
}