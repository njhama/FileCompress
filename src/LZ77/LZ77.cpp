#include "LZ77.h"

LZ77::LZ77(int windowSize, int lookAheadBufferSize)
    : windowSize(windowSize), lookAheadBufferSize(lookAheadBufferSize) {}

std::vector<LZ77::EncodedData> LZ77::compress(const std::string& data) {
    std::vector<EncodedData> compressedData;
    int dataLength = data.length();

    for (int i = 0; i < dataLength; ++i) {
        int matchLength = 0;
        int matchDistance = 0;
        int endLookAhead = i + lookAheadBufferSize < dataLength ? i + lookAheadBufferSize : dataLength;

        for (int j = std::max(0, i - windowSize); j < i; ++j) {
            int k = j;
            int currentMatchLength = 0;
            while (k < i && data[k] == data[i + currentMatchLength] && i + currentMatchLength < endLookAhead) {
                currentMatchLength++;
                k++;
            }

            if (currentMatchLength > matchLength) {
                matchLength = currentMatchLength;
                matchDistance = i - j;
            }
        }

        char nextChar = i + matchLength < dataLength ? data[i + matchLength] : '\0';
        compressedData.push_back({matchDistance, matchLength, nextChar});
        i += matchLength;
    }

    return compressedData;
}

std::string LZ77::decompress(const std::vector<EncodedData>& compressedData) {
    std::string decompressedData;

    for (const auto& data : compressedData) {
        int start = decompressedData.length() - data.offset;
        for (int i = 0; i < data.length; ++i) {
            decompressedData += decompressedData[start + i];
        }
        if (data.nextChar != '\0') {
            decompressedData += data.nextChar;
        }
    }

    return decompressedData;
}
