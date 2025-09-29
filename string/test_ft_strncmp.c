#include <criterion/criterion.h>
#include "libft.h"

Test(ft_strncmp, equal_strings)
{
	cr_assert_eq(ft_strncmp("hello", "hello", 5), 0,
		"ft_strncmp() compared two equal strings unequal");
}

Test(ft_strncmp, difference_before_limit)
{
	cr_assert_lt(ft_strncmp("hello", "hemlo", 5), 0,
		"ft_strncmp() failed to detect a difference");
}

Test(ft_strncmp, difference_after_limit)
{
	cr_assert_eq(ft_strncmp("hello", "hemlo", 2), 0,
		"ft_strncmp() compared past n bytes");
}

Test(ft_strncmp, first_string_shorter)
{
	cr_assert_lt(ft_strncmp("abc", "abcd", 4), 0,
		"ft_strncmp() did not null terminate the first string");
}

Test(ft_strncmp, second_string_shorter)
{
	cr_assert_gt(ft_strncmp("abcd", "abc", 4), 0,
		"ft_strncmp() did not null terminate the second string");
}

Test(ft_strncmp, empty_strings)
{
	cr_assert_eq(ft_strncmp("", "", 1), 0,
		"ft_strncmp() compared two empty strings unequal");
	cr_assert_lt(ft_strncmp("", "abc", 3), 0,
		"ft_strncmp() did not null terminate");
}

Test(ft_strncmp, zero_length)
{
	cr_assert_eq(ft_strncmp("abc", "xyz", 0), 0,
		"ft_strncmp() returned nonzero when asked to compare 0 bytes");
}
