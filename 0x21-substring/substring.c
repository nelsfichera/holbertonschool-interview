#include "substring.h"

/**
 * find_substring -  finds substrings in given string
 * @s: string to scan
 * @words:  array of words
 * @nb_words: number of elements in array
 * @n: address at which to store the number
 * of elements in the returned array
 * Return:  an array w each substring index on success
 NULL on failure 
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{

	int x, i, o, current_idx, count, lenstr, wordlen, strcheck;
	int *idx_array, *match;

	if (!s || !words || !n || nb_words == 0)
		return (NULL);

	lenstr = strlen(s);
	wordlen = strlen(words[0]);
	idx_array = malloc(lenstr * sizeof(int));
	if (!idx_array)
		return (NULL);
	match = malloc(nb_words * sizeof(int));
	if (!match)
		return (NULL);

	for (x = count = 0; x <= lenstr - nb_words * wordlen; x++)
	{
		memset(match, 0, nb_words * sizeof(int));
		for (i = 0; i < nb_words; i++)
		{
			for (o = 0; o < nb_words; o++)
			{
				current_idx = x + i * wordlen;
				strcheck = strncmp(s + current_idx, *(words + o), wordlen);
				if (!*(match + o) && !strcheck)
				{
					*(match + o) = 1;
					break;
				}
			}
			if (o == nb_words)
				break;
		}
		if (i == nb_words)
			*(idx_array + count) = x, count += 1;
	}
	free(match);
	*n = count;
	return (idx_array);
}
