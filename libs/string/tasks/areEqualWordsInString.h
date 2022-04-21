
#ifndef LABA_5E_AREEQUALWORDSINSTRING_H
#define LABA_5E_AREEQUALWORDSINSTRING_H

bool areEqualWordsInString(char *str) {
    getBagOfWords(&_bag, str);

    for (int i = 0; i < _bag.size; i++) {
        for (int j = i + 1; j < _bag.size; j++) {
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;
        }
    }
    return false;
}

void test_areEqualWordsInString_emptyString() {
    char s[] = "";
    assert(!areEqualWordsInString(s));
}

void test_areEqualWordsInString_oneWord() {
    char s[] = "Hello";
    assert(!areEqualWordsInString(s));
}

void test_areEqualWordsInString_LettersHasEqualWords() {
    char s[] = "a b a d e";
    assert(areEqualWordsInString(s));
}

void test_areEqualWordsInString_hasEqualWords() {
    char s[] = "Hello World Hello";
    assert(areEqualWordsInString(s));
}

void test_areEqualWordsInString_hasNotEqualWords() {
    char s[] = "Hello World Bye";
    assert(!areEqualWordsInString(s));
}

void test_areEqualWordsInString() {
    test_areEqualWordsInString_emptyString();
    test_areEqualWordsInString_oneWord();
    test_areEqualWordsInString_hasEqualWords();
    test_areEqualWordsInString_LettersHasEqualWords();
    test_areEqualWordsInString_hasNotEqualWords();
}

#endif
