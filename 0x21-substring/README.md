# Concept
find_substring is a function that finds all the possible substrings containing a list of words, within a given string.  
All words in the array words are the same length  
A valid substring of s is the concatenation of each word in words exactly once and without any intervening characters
# Prototype
Prototype: int *find_substring(char const *s, char const **words, int nb_words, int *n);
- s is the string to scan
- words is the array of words all substrings must be a concatenation arrangement of
- nb_words is the number of elements in the array words
- n holds the address at which to store the number of elements in the returned array.
# Return
Your function must return an allocated array, storing each index in s, at which a substring was found. If no solution is found, NULL can be returned
