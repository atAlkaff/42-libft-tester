#include <criterion/criterion.h>
#include <string.h>	// memset()
#include "libft.h"

Test(ft_memcpy, returns_dest)
{
	char dest[10];
	char src[10] = {0};

	cr_assert_eq(ft_memcpy(dest, src, 0), dest,
		"ft_memcpy() did not return dest");
}

Test(ft_memcpy, zero_length)
{
	char dest[10] = {0};
	char src[10];

	memset(src, 'A', sizeof src);
	cr_assert_neq(dest[0], src[0],
		"ft_memcpy() attempted to copy bytes"
		"when a zero byte change was requested");
}

Test(ft_memcpy, full_copy)
{
	char src[] = "Hello world";
	char dest[12];

	ft_memcpy(dest, src, sizeof src);
	cr_assert_str_eq(dest, src,
		"ft_memcpy() did copy all of src to dest");
}

Test(ft_memcpy, partial_copy)
{
	char src[] = "Hello world";
	char dest[12] = {0};

	ft_memcpy(dest, src, 6);
	cr_assert_arr_neq(&dest[6], &src[6], 6,
		"ft_memcpy() copied more bytes than required");
}

Test(ft_memcpy, copy_binary_data)
{
	int src[] = {3, 5, 1, 2, 6};
	int dest[5];

	ft_memcpy(dest, src, sizeof src);
	cr_assert_arr_eq(dest, src, sizeof src,
		"ft_memcpy() did not correctly copy an integer array");
}
