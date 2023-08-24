//
// Created by Momo on 2023/7/17.
//

#include "串.h"


int main() {
    using std::cout;
    using std::endl;

    const char *text = "ABCABCCDABCDABDE";
    const char *pattern = "aabaaae";

    int *ts = buildNextArray(pattern);

    int m = (int) strlen(pattern);

    for (int i = 0; i < m; ++i)
        cout << ts[i] << " ";
    cout << endl;
    delete[] ts;

    int matchIndex = Index_KMP(text, pattern);
    if (matchIndex == -1)
        std::cout << "No match found." << std::endl;
    else
        std::cout << "Match found at position: "
        << matchIndex << std::endl;

    return 0;
}