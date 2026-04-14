#include "romano.hpp"
#include <vector>

int converteRomano(const std::string& numeroRomano) {
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
    if (confereErros(vetorConvertido)) {
        return operaVetor(vetorConvertido);
    }else {
        return -1;
    }

}

bool confereErros(const std::vector<int> &vetorConvertido) {
    for (size_t i = 0; i < vetorConvertido.size(); i++) {
        if (i + 3 < vetorConvertido.size()
            && vetorConvertido[i] == vetorConvertido[i + 1]
            && vetorConvertido[i] == vetorConvertido[i + 2]
            && vetorConvertido[i] == vetorConvertido[i + 3]) {
            return false;
            }
    }
    return true;
}

int operaVetor(const std::vector<int> &vetorConvertido) {
    int numeroDecimal = 0;
    for (size_t i = 0; i < vetorConvertido.size(); i++) {
        if (i + 1 < vetorConvertido.size() && vetorConvertido[i] < vetorConvertido[i + 1]) {
            numeroDecimal -= vetorConvertido[i];
        } else {
            numeroDecimal += vetorConvertido[i];
        }
    }
    return numeroDecimal;
}