#include "romano.hpp"
#include <vector>

int converteRomano(std::string numeroRomano) {
    int numeroDecimal = 0;
    std::vector<int> vetorConvertido;
    for (const char c: numeroRomano) {
        switch (c) {
            case 'I':
                vetorConvertido.push_back(1);
                break;
            case 'V':
                vetorConvertido.push_back(5);
                break;
            case 'X':
                vetorConvertido.push_back(10);
                break;
            case 'L':
                vetorConvertido.push_back(50);
                break;
            case 'C':
                vetorConvertido.push_back(100);
                break;
            case 'D':
                vetorConvertido.push_back(500);
                break;
            case 'M':
                vetorConvertido.push_back(1000);
                break;
            default:
                return -1;
        }
    }

    for (size_t i = 0; i < vetorConvertido.size(); i++) {
        if (i + 1 < vetorConvertido.size() && vetorConvertido[i] < vetorConvertido[i + 1]) {
            numeroDecimal -= vetorConvertido[i];
        } else {
            numeroDecimal += vetorConvertido[i];
        }
    }
    return numeroDecimal;
}