#include <criterion/criterion.h>
#include <string.h>	// memset()
#include "libft.h"

Test(ft_memset, returns_dest)
{
	char buf[10];

	cr_assert_eq(ft_memset(buf, 'A', sizeof buf), buf,
		"ft_memset() did not return dest");
}

Test(ft_memset, zero_length)
{
	char buf[10] = {0};

	ft_memset(buf, 'A', 0);
	cr_assert_neq(buf[0], 'A',
		"ft_memset() attempted to modify the buffer"
		"when a 0 byte change was requested");
}

Test(ft_memset, fill_with_nonzero_byte)
{
	char buf[10];
	char libc_buf[10];

	memset(libc_buf, 'A', sizeof libc_buf);
	ft_memset(buf, 'A', sizeof buf);
	cr_assert_arr_eq(buf, libc_buf, sizeof buf,
		"ft_memset() did not properly fill a buffer"
		"with 10 nonzero bytes");
}

Test(ft_memset, fill_with_zero_byte)
{
	char buf[10];
	char libc_buf[10] = {0};

	ft_memset(buf, 0, sizeof buf);
	cr_assert_arr_eq(buf, libc_buf, sizeof buf,
		"ft_memset() did not properly fill a buffer"
		"with 10 zero bytes");
}

Test(ft_memset, partial_fill_with_nonzero_byte)
{
	char buf[10] = {0};
	char libc_buf[10] = {0};

	memset(libc_buf, 'A', sizeof libc_buf);
	ft_memset(buf, 'A', 5);
	cr_assert_arr_neq(&buf[5], &libc_buf[5], 5,
		"ft_memset() filled more bytes than required");
}

Test(ft_memset, byte_over_255)
{
	char buf[2];
	char safebuf[2];

	ft_memset(buf, 300, 2);
	ft_memset(safebuf, (unsigned char)300, 2);
	cr_assert_arr_eq(buf, safebuf, 2,
		"ft_memset() failed to cast the byte input"
		"to unsigned char");
}
