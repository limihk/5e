#ifndef LABA_5E_STRING__H
#define LABA_5E_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

#ifndef INC_5E_STRING_STRING__H
#define INC_5E_STRING_STRING__H

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

#define ASSERT_STRING(expected, got) assertString(expected, got, \
                    __FILE__, __FUNCTION__, __LINE__)

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

// возвращает количество символов в строке
size_t strlen_(char *begin);

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end не включая end
// Если символ не найден, возвращается значение end
char *find(char *begin, const char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с rbegin (последний символ строки, за которым следует ноль-символ) и заканчивая
// rend (адрес символа перед началом строки).
// Если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти, начиная с rbegin
// и заканчивая rend.
// Если символ не найден, возвращается адрес rend
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке (как в словаре), значение 0, если lhs и rhs равны,
// иначе – положительное значение.
int strcmp(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource до endSource
// Возвращает указатель на следующий свободный фрагмент памяти в destination
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource
// заканчивая endSource, удовлетворяющие функции-предикату f
// возвращает указатель на следующий свободный для записи фрагмент в памяти
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти начиная с rbeginSource
// заканчивая rendSource, удовлетворяющие функции-предикату f
// возвращает значение beginDestination по окончанию работы функции
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));


void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

// возвращает указатель на конец строки str
char *getEndOfString(char *str);

// возвращает 'истина' и записывает в word.begin адрес начала слова,
// а в word.end адрес конца слова, если слово найдено, иначе - 'ложь'
int getWord(char *beginSearch, WordDescriptor *word);

// возвращает 'истина' и записывает в rbegin адрес конца слова,
// а в rend адрес начала слова, если слово найдено, иначе - 'ложь'
bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

// возвращает отрицательное значение, если w1 располагается до w2
// в лексикографическом порядке (как в словаре), значение 0, если w1 и w2 равны,
// иначе – положительное значение.
int areWordsEqual(WordDescriptor w1, WordDescriptor w2);


// записывает в bag позиции начала и конца каждого слова строки s
void getBagOfWords(BagOfWords *bag, char *s);

// записывает по адресу beginDestination
// фрагмент памяти, начиная с адреса rbeginSource до rendSource
// Возвращает указатель на следующий слева свободный фрагмент памяти в destination
char *copyReverse(const char *rbeginSource, const char *rendSource, char *beginDestination);

// переводит слово word из типа данных WordDescriptor в char
void wordDescriptorToString(WordDescriptor word, char *destination);

// возвращает значение 'истина', если строка расположенная на ленте памяти, начиная с begin и заканчивая end
// является палиндромом, иначе - 'ложь'
int isPalindrome(char *begin, char *end);

#endif

#endif
