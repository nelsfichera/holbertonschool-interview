# 0x21 Substring with concatenated words
## 0. Substring with concatenated words
### Write a function that finds all the possible substrings containing a list of words, within a given string.
- Prototype: int *find_substring(char const *s, char const **words, int nb_words, int *n);, where
    - s is the string to scan
    - words is the array of words all substrings must be a concatenation arrangement of
    - nb_words is the number of elements in the array words
    - n holds the address at which to store the number of elements in the returned array.
- Your function must return an allocated array, storing each index in s, at which a substring was found. If no solution is found, NULL can be returned
- All words in the array words are the same length
- A valid substring of s is the concatenation of each word in words exactly once and without any intervening characters
```
alex@~/holbertonschool-interview_prep/0x21-substring$ ./a.out barfoothefoobarman foo bar
Indices -> [0, 9]
alex@~/holbertonschool-interview_prep/0x21-substring$ ./a.out wordgoodgoodgoodbestword word good best word
Indices -> []
alex@~/holbertonschool-interview_prep/0x21-substring$ ./a.out wordgoodgoodgoodbestword word good best good
Indices -> [8]
alex@~/holbertonschool-interview_prep/0x21-substring$
```