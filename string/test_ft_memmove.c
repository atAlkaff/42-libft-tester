#include <criterion/criterion.h>
#include <string.h>	// memset()
#include "libft.h"

Test(ft_memmove, returns_dest)
{
	char dest[10];
	char src[10] = {0};

	cr_assert_eq(ft_memmove(dest, src, 0), dest,
		"ft_memmove() did not return dest");
}

Test(ft_memmove, zero_length)
{
	char dest[10] = {0};
	char src[10];

	memset(src, 'A', sizeof src);
	cr_assert_neq(dest[0], src[0],
		"ft_memmove() attempted to copy bytes"
		"when a zero byte change was requested");
}

Test(ft_memmove, full_copy)
{
	char src[] = "Hello world";
	char dest[12];

	ft_memmove(dest, src, sizeof src);
	cr_assert_str_eq(dest, src,
		"ft_memmove() did copy all of src to dest");
}

Test(ft_memmove, partial_copy)
{
	char src[] = "Hello world";
	char dest[12] = {0};

	ft_memmove(dest, src, 6);
	cr_assert_arr_neq(&dest[6], &src[6], 6,
		"ft_memmove() copied more bytes than required");
}

Test(ft_memmove, copy_binary_data)
{
	int src[] = {3, 5, 1, 2, 6};
	int dest[5];

	ft_memmove(dest, src, sizeof src);
	cr_assert_arr_eq(dest, src, sizeof src,
		"ft_memmove() did not correctly copy an integer array");
}

Test(ft_memmove, overlap_fwd)
{
	char buf[20] = "1234567890";
	ft_memmove(buf + 2, buf, 5);
	cr_assert_str_eq(buf, "1212345670",
		"ft_memmove() did not properly handle a forward overlap");
}

Test(ft_memmove, overlap_bwd)
{
	char buf[20] = "1234567890";
	ft_memmove(buf, buf + 2, 5);
	cr_assert_str_eq(buf, "3456767890",
		"ft_memmove() did not properly handle a backward overlap");
}
