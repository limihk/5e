
#ifndef LABA_5E_REMOVEEXTRASPACES_H
#define LABA_5E_REMOVEEXTRASPACES_H

#include "../string_.h"

void removeExtraSpaces(char *s) {
    char *destination = s;
    char symbolBeforeS = *s;

    while (*s != '\0') {
        if (*s != symbolBeforeS || symbolBeforeS != ' ') {
            *destination = *s;
            destination++;
        }

        symbolBeforeS = *s;
        s++;
    }
    if (symbolBeforeS == ' ')
        destination--;

    *destination = '\0';
}

void test_removeExtraSpaces_spacesBetweenBeforeAfterWords() {
    char s[] = "    Hi     Ivan   Sergeevich     ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi Ivan Sergeevich", s);
}

void test_removeExtraSpaces_oneWord() {
    char s[] = "   Hi  ";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi", s);
}

void test_removeExtraSpaces_noSpaces() {
    char s[] = "HiIvanSergeevich";
    removeExtraSpaces(s);
    ASSERT_STRING("HiIvanSergeevich", s);
}

void test_removeExtraSpaces_emptyString() {
    char s[] = "";
    removeExtraSpaces(s);
    ASSERT_STRING("", s);
}

void test_removeExtraSpaces_oneSpacesBetweenWords() {
    char s[] = "Hi Ivan Sergeevich";
    removeExtraSpaces(s);
    ASSERT_STRING("Hi Ivan Sergeevich", s);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_spacesBetweenBeforeAfterWords();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_emptyString();
    test_removeExtraSpaces_oneWord();
    test_removeExtraSpaces_oneSpacesBetweenWords();
}

#endif

