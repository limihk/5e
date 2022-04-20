#include <memory.h>
#include "string_.h"

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    char *end = begin;
    while (*end != '\0' && isspace(*end))
        end++;

    return end;
}

char *findSpace(char *begin) {
    char *end = begin;
    while (*end != '\0' && !isspace(*end))
        end++;

    return end;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs != '\0' && (*lhs == *rhs)) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

char *getEndOfString(char *str) {
    while (*str != '\0')
        str++;

    return str;
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

//TODO: также возможно пересмотреть
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin , rend) + 1;
    if (word->end == rend)
        return 0;

    word->begin = findSpaceReverse(word->end - 1, rend) + 1;

    return 1;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *begin1 = w1.begin;
    char *begin2 = w2.begin;
    while (begin1 != w1.end - 1 && (*begin1 == *begin2))
        begin1++, begin2++;

    return *begin1 - *begin2;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    char *beginSearch = s;
    bag->size = 0;

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        bag->words[bag->size] = word;

        bag->size++;
        beginSearch = word.end;
    }
}

char *copyReverse(const char *rbeginSource, const char *rendSource, char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination = *rbeginSource;
        beginDestination++;
        rbeginSource--;
    }

    return beginDestination;
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    *copy(word.begin, word.end, destination) = '\0';
}


int isPalindrome(char *begin, char *end) {
    end--;
    while (end - begin > 0) {
        if (*end != *begin)
            return 0;

        begin++;
        end--;
    }

    return 1;
}
