#include <criterion/criterion.h>
#include <string.h>	// memset()
#include <stdlib.h>	// free()
#include "libft.h"

#define _test_ft_strdup_match(output, input)		\
	cr_assert_str_eq(output, input,					\
		"ft_strdup(%s) returned %s",				\
		input, output)

Test(ft_strdup, empty_string)
{
	char *s = ft_strdup("");

	cr_assert_neq(s, NULL,
		"ft_strdup() failed to allocate memory for an empty string");
	_test_ft_strdup_match(s, "");
	free(s);
}

Test(ft_strdup, returns_unique_pointer)
{
	const char *original = "Hello";
	char *result = ft_strdup(original);

	cr_assert_neq(result, original,
		"ft_strdup() did not return a unique pointer");
	_test_ft_strdup_match(result, original);
	free(result);
}

Test(ft_strdup, preserves_spacing)
{
	const char *original = "         Hello        ";
	char *result = ft_strdup(original);

	_test_ft_strdup_match(original, result);
	free(result);
}

Test(ft_strdup, preserves_special_characters)
{
	const char *original = "text\nmore text\tsome more";
	char *result = ft_strdup(original);

	_test_ft_strdup_match(original, result);
	free(result);
}

Test(ft_strdup, string_10kb)
{
	char big[10000];
	memset(big, 'A', 9999);
	big[9999] = '\0';
	char *result = ft_strdup(big);

	_test_ft_strdup_match(big, result);
	free(result);
}

Test(ft_strdup, modifiable_memory)
{
	const char *original = "Hello";
	char *result = ft_strdup(original);
	memset(result, 'A', 3);

	cr_assert_str_eq(result, "AAAlo",
		"Failed to modify buffer returned by ft_strdup()");
	free(result);
}
