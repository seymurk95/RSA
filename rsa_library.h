#ifndef RSA_LIBRARY_H
#define RSA_LIBRARY_H

#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

cpp_int BlockToInt(const std::string& block) {
    cpp_int result = 0;
    for (char ch : block) {
        result = result * 256 + static_cast<unsigned char>(ch);
    }
    return result;
}

std::string IntToBlock(cpp_int nums) {
    std::string result;
    while (nums > 0) {
        char ch = static_cast<char>(nums % 256);
        result += ch;
        nums /= 256;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int calculateBlockSize(const cpp_int& n) {
    int blockSize = 0;
    cpp_int maxBlockValue = 1;

    while (maxBlockValue < n) {
        maxBlockValue *= 256;
        ++blockSize;
    }
    return blockSize - 1;
}

std::vector<cpp_int> encryptMessage(const std::string& message, const cpp_int& e, const cpp_int& n) {
    std::vector<cpp_int> encryptedBlocks;
    int blockSize = calculateBlockSize(n);

    for (size_t i = 0; i < message.size(); i += blockSize) {
        std::string block = message.substr(i, blockSize);
        cpp_int blockNum = BlockToInt(block);
        encryptedBlocks.push_back(powm(blockNum, e, n));
    }

    return encryptedBlocks;
}

std::string decryptMessage(const std::vector<cpp_int>& encryptedBlocks, const cpp_int& d, const cpp_int& n) {
    std::string decryptedMessage;

    for (const auto& encryptedBlock : encryptedBlocks) {
        cpp_int decryptedBlock = powm(encryptedBlock, d, n);
        decryptedMessage += IntToBlock(decryptedBlock);
    }

    return decryptedMessage;
}

#endif // RSA_LIBRARY_H
