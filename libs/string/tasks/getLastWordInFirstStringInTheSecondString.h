
#ifndef LABA_5E_GETLASTWORDINFIRSTSTRINGINTHESECONDSTRING_H
#define LABA_5E_GETLASTWORDINFIRSTSTRINGINTHESECONDSTRING_H

WordDescriptor getLastWordInFirstStringInTheSecondString(char *str1, char *str2) {
    getBagOfWords(&_bag, str1);
    getBagOfWords(&_bag2, str2);

    WordDescriptor word = {NULL, NULL};
    int isFound = 0;
    for (int i = _bag.size - 1; i >= 0 && !isFound; i--) {
        for (int j = 0; j < _bag2.size; j++) {
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                word = _bag.words[i];
                isFound = 1;
            }
        }
    }
    return word;
}

void test_getLastWordInFirstStringInTheSecondString_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringInTheSecondString_oneWord() {
    char s1[] = "Hello";
    char s2[] = "Hello";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("Hello", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasNotUnion() {
    char s1[] = "one two three four";
    char s2[] = "five six seven";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasWordInStrings() {
    char s1[] = "one two three four";
    char s2[] = "three five six seven";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("three", res);
}

void test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings() {
    char s1[] = "one two three four";
    char s2[] = "five four six";
    WordDescriptor word = getLastWordInFirstStringInTheSecondString(s1, s2);

    char res[MAX_STRING_SIZE];
    wordDescriptorToString(word, res);
    ASSERT_STRING ("four", res);
}


void test_getLastWordInFirstStringInTheSecondString() {
    //test_getLastWordInFirstStringInTheSecondString_emptyStrings();
    test_getLastWordInFirstStringInTheSecondString_oneWord();
    test_getLastWordInFirstStringInTheSecondString_hasNotUnion();
    test_getLastWordInFirstStringInTheSecondString_hasWordInStrings();
    test_getLastWordInFirstStringInTheSecondString_hasOneWordInStrings();
}

#endif
