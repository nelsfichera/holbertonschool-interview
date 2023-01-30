# 0x20. RegEx
## 0. Simple RegEx
### Write a function that checks whether a given pattern matches a given string.
- Prototype: int regex_match(char const *str, char const *pattern);, where:
    - str is the string to scan
    - pattern is the regular expression
    - Your function must return 1 if the pattern matches the string, or 0 if it doesn’t
    - str can be empty, and can contain any ASCII character in the exception of . and *
    - pattern can be empty, and can contain any ASCII character, including . and *
    - The regular expression matching must support the characters . and *
    - . matches any single character
    - * matches zero or more of the preceding character
```
alex@~/holbertonschool-interview_prep/0x20-regex$ ./a.out
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
alex@~/holbertonschool-interview_prep/0x20-regex$
```