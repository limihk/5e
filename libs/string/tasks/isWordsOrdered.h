
#ifndef LABA_5E_ISWORDSORDERED_H
#define LABA_5E_ISWORDSORDERED_H

bool isWordsOrdered(char *str) {
    char *beginSearch = str;

    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;

    WordDescriptor previousWord = currentWord;
    beginSearch = previousWord.end;

    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(previousWord, currentWord) > 0)
            return false;

        previousWord = currentWord;
        beginSearch = previousWord.end;
    }

    return true;
}

void test_isWordsOrdered_emptyString() {
    char s[] = "";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_onlySpace() {
    char s[] = "     ";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_onlySpaceCharacters() {
    char s[] = " \t  \t  \n  \t  \n   ";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneWord() {
    char s[] = "hi";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneLetterOrdered() {
    char s[] = "a b c d e";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_oneLetterUnordered() {
    char s[] = "a b e d c";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_unorderedLastLetterAreDifferent() {
    char s[] = "abcdg abcdf";
    assert(!isWordsOrdered(s));
}

void test_isWordsOrdered_orderedLastLetterAreDifferent() {
    char s[] = "abcdf abcdg";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered_wordOrdered() {
    char s[] = "clion clions crazy lion mingw zara";
    assert(isWordsOrdered(s));
}

void test_isWordsOrdered() {
    test_isWordsOrdered_emptyString();
    test_isWordsOrdered_onlySpace();
    test_isWordsOrdered_onlySpaceCharacters();
    test_isWordsOrdered_oneWord();
    test_isWordsOrdered_oneLetterOrdered();
    test_isWordsOrdered_oneLetterUnordered();
    test_isWordsOrdered_unorderedLastLetterAreDifferent();
    test_isWordsOrdered_orderedLastLetterAreDifferent();
    test_isWordsOrdered_wordOrdered();
}

#endif
