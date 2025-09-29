#include <criterion/criterion.h>
#include <string.h>	// strlen()
#include "libft.h"

Test(ft_strlcpy, zero_length)
{
	char dest[] = "AAAA";
	char src[] = "Hello";
	size_t length = ft_strlcpy(dest, src, 0);

	cr_assert_str_neq(dest, src,
		"ft_strlcpy() copied when a 0 byte change was requested");
	cr_assert_eq(length, strlen(src),
		"ft_strlcpy() did not return the length of src");
}

Test(ft_strlcpy, full_copy)
{
	char dest[10];
	char src[] = "Hello";
	size_t length = ft_strlcpy(dest, src, sizeof dest);

	cr_assert_str_eq(dest, src,
		"ft_strlcpy() did not copy a string until '\\0'");
	cr_assert_eq(length, strlen(src),
		"ft_strlcpy() did not return the length of src");
}

Test(ft_strlcpy, partial_copy)
{
	char dest[4];
	char src[] = "Hello";
	size_t length = ft_strlcpy(dest, src, sizeof dest);

	cr_assert_str_eq(dest, "Hel",
		"ft_strlcpy() copied past the end of dest");
	cr_assert_eq(length, strlen(src),
		"ft_strlcpy() did not return the length of src");
}

Test(ft_strlcpy, empty_string)
{
	char dest[5] = "Hello";
	char src[] = "";
	size_t length = ft_strlcpy(dest, src, sizeof dest);

	cr_assert_str_empty(dest,
		"ft_strlcpy() did not copy an empty string");
	cr_assert_eq(length, strlen(src),
		"ft_strlcpy() did not return the length of src");
}
