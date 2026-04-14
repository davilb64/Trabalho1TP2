#include "romano.hpp"

int converteRomano(std::string numeroRomano) {
    for (const char c: numeroRomano) {
        if (c == 'I') {
            return 1;
        }
    }
    return -1;
}

