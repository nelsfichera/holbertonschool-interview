#include "regex.h"

/**
 * recur_match - recursively checks for match
 * @str: string
 * @pattern: pattern
 * @idx_str: index into str
 * @idx_pat: index into pattern
 * Return: 1 on match. 0 on no match
 */
int recur_match(char const *str, char const *pattern, size_t idx_str, size_t idx_pat)
{
	if (pattern[idx_pat] == '\0' && str[idx_str] == '\0')
		return (1);
	if (pattern[idx_pat] == '\0' && str[idx_str] != '\0')
		return (0);
	if (pattern[idx_pat + 1] != '*')
	{
		if (
			pattern[idx_pat] == str[idx_str] ||
			(pattern[idx_pat] == '.' && str[idx_str] != '\0')
		)
			return (recur_match(str, pattern, idx_str + 1, idx_pat + 1));
		else
			return (0);
	}
	else
	{
		if (
			pattern[idx_pat] == str[idx_str] ||
			(pattern[idx_pat] == '.' && str[idx_str] != '\0')
		)
		{
			if (recur_match(str, pattern, idx_str + 1, idx_pat))
				return (1);
			else
				return (recur_match(str, pattern, idx_str, idx_pat + 2));
		}
		else
			return (recur_match(str, pattern, idx_str, idx_pat + 2));
	}
}
/**
 * regex_match - checks if str matches regex pattern
 * @str: string
 * @pattern: regular expression
 * Return: 1 on success 0 on failure
 */
int regex_match(char const *str, char const *pattern)
{
	return (recur_match(str, pattern, 0, 0));
}
