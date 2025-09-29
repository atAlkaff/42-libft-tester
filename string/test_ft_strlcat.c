#include <criterion/criterion.h>
#include <string.h>	// strlen()
#include "libft.h"

Test(ft_strlcat, zero_length)
{
	char dest[] = "Hi";
	char src[] = "There";
	size_t length = ft_strlcat(dest, src, 0);

	cr_assert_str_neq(dest + 2, src,
		"ft_strlcat() appended when a 0 byte change was requested");
	cr_assert_eq(length, strlen(src),
		"ft_strlcat() did not return the length of src"
		"when a 0 byte change was requested");
}

Test(ft_strlcat, full_append)
{
	char dest[10] = "Hi";
	char src[] = "There";
	size_t expected = strlen(src) + strlen(dest);
	size_t length = ft_strlcat(dest, src, sizeof dest);

	cr_assert_str_eq(dest + 2, src,
		"ft_strlcat() did not append src to dest");
	cr_assert_eq(length, expected,
		"ft_strlcat() did not return the length of the total string");
}

Test(ft_strlcat, partial_append)
{
	char dest[6] = "Hi";
	char src[] = "There";
	size_t expected = strlen(src) + strlen(dest);
	size_t length = ft_strlcat(dest, src, sizeof dest);

	cr_assert_str_eq(dest, "HiThe",
		"ft_strlcat() overflowed dest");
	cr_assert_eq(length, expected,
		"ft_strlcat() did not return the length of the total string");
}

Test(ft_strlcat, empty_dest)
{
	char dest[10] = "";
	char src[] = "Hello";
	size_t expected = strlen(src) + strlen(dest);
	size_t length = ft_strlcat(dest, src, sizeof dest);

	cr_assert_str_eq(dest, src,
		"ft_strlcat() did not append to an empty string");
	cr_assert_eq(length, expected,
		"ft_strlcat() did not return the length of the total string");
}

Test(ft_strlcat, empty_src)
{
	char dest[10] = "Hello";
	char src[] = "";
	size_t expected = strlen(src) + strlen(dest);
	size_t length = ft_strlcat(dest, src, sizeof dest);

	cr_assert_str_eq(dest, "Hello",
		"ft_strlcat() appended characters when src was empty");
	cr_assert_eq(length, expected,
		"ft_strlcat() did not return the length of the total string");
}

Test(ft_strlcat, dest_bigger_than_dstsize)
{
	char dest[10] = "Hello";
	char src[] = " World";
	size_t n = 4;
	size_t expected = strlen(src) + n;
	size_t length = ft_strlcat(dest, src, n);

	cr_assert_str_eq(dest, "Hello",
		"ft_strlcat() appended characters past dstsize");
	cr_assert_eq(length, expected,
		"ft_strlcat() did not return the length of the total string");
}
