#include <iostream>
#include <vector>
#include "rsa_library.h"
#include <boost/multiprecision/cpp_int.hpp>

int main() {
    cpp_int p = 3940691;
    cpp_int q = 3936307;
    cpp_int e = 7;
    cpp_int n = p * q;
    cpp_int phi = (p - 1) * (q - 1);
    cpp_int k = 1;

    // Вычисляем d
    while (((k * phi + 1) % e) != 0) {
        k++;
    }
    cpp_int d = (k * phi + 1) / e;

    std::string message = "What I've done I'll face myself To cross out what I've become Erase myself And let go of what I've done";
    std::cout << "Исходное сообщение: " << message << std::endl;

    std::vector<cpp_int> encryptedMessage = encryptMessage(message, e, n);

    std::cout << "Зашифрованное сообщение: ";
    for (const auto& block : encryptedMessage) {
        std::cout << block << " ";
    }
    std::cout << std::endl;

    std::string decryptedMessage = decryptMessage(encryptedMessage, d, n);
    std::cout << "Расшифрованное сообщение: " << decryptedMessage << std::endl;

    return 0;
}
