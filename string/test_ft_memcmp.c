#include <criterion/criterion.h>
#include "libft.h"

Test(ft_memcmp, equal_strings)
{
	char a[] = "Hello";
	char b[] = "Hello";
	cr_assert_eq(ft_memcmp(a, b, 5), 0,
		"ft_memcmp() returned a difference between equal strings");
}

Test(ft_memcmp, difference_in_middle)
{
	char a[] = "Hello";
	char b[] = "Hemlo";
	cr_assert_lt(ft_memcmp(a, b, 5), 0,
		"ft_memcmp() missed a difference in the middle");
}

Test(ft_memcmp, difference_at_last_byte)
{
	char a[] = "abc";
	char b[] = "abd";
	cr_assert_lt(ft_memcmp(a, b, 3), 0);
}

Test(ft_memcmp, zero_length)
{
	cr_assert_eq(ft_memcmp("abc", "xyz", 0), 0);
}

Test(ft_memcmp, embedded_null_bytes)
{
	char a[] = {'a', '\0', 'c'};
	char b[] = {'a', '\0', 'd'};
	cr_assert_lt(ft_memcmp(a, b, 3), 0);
}

Test(ft_memcmp, same_prefix_different_lengths)
{
	char a[] = "abc";
	char b[] = "abcd";
	cr_assert_eq(ft_memcmp(a, b, 3), 0);
}
