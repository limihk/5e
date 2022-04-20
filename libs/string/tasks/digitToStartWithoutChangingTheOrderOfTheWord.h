

#ifndef LABA_5E_DIGITTOSTARTWITHOUTCHANGINGTHEORDEROFTHEWORD_H
#define LABA_5E_DIGITTOSTARTWITHOUTCHANGINGTHEORDEROFTHEWORD_H


void digitToStartWithoutChangingTheOrderOfTheWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIf(_stringBuffer,
                               endStringBuffer,
                               word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithoutChangingTheOrderOfTheWordForString(char *beginString) {
    char *beginSearch = beginString;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithoutChangingTheOrderOfTheWord(word);

        beginSearch = word.end;
    }
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_digitsInEnd() {
    char s[] = "qwerty12345  ytrewq54321";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("12345qwerty  54321ytrewq", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_digitsInWord() {
    char s[] = "a5f7l8w2         re4341fr35fi";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("5782aflw         434135refrfi", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_digitsInStart() {
    char s[] = "1234asdfd       982314asdfasw";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("1234asdfd       982314asdfasw", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_noDigits() {
    char s[] = "dfgh asdu dsa";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("dfgh asdu dsa", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_noLetters() {
    char s[] = "123 4 56 42";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("123 4 56 42", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_allWhitespaceCharacters() {
    char s[] = "\n   \t \n   \t";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("\n   \t \n   \t", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWordForString_emptyString() {
    char s[] = "";
    digitToStartWithoutChangingTheOrderOfTheWordForString(s);
    ASSERT_STRING("", s);
}

void test_digitToStartWithoutChangingTheOrderOfTheWord() {
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_digitsInEnd();
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_digitsInWord();
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_digitsInStart();
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_noDigits();
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_noLetters();
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_allWhitespaceCharacters();
    test_digitToStartWithoutChangingTheOrderOfTheWordForString_emptyString();
}


#endif //LABA_5E_DIGITTOSTARTWITHOUTCHANGINGTHEORDEROFTHEWORD_H
