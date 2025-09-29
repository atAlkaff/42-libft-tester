#include <criterion/criterion.h>
#include <string.h>	// memset()
#include "libft.h"

Test(ft_bzero, zero_length)
{
	char buf[10] = {0};

	memset(buf, 'A', sizeof buf);
	ft_bzero(buf, 0);
	cr_assert_eq(buf[0], 'A',
		"ft_bzero() attempted to modify the buffer"
		"when a 0 byte change was requested");
}

Test(ft_bzero, fill_with_zero_byte)
{
	char buf[10];
	char libc_buf[10] = {0};

	ft_bzero(buf, sizeof buf);
	cr_assert_arr_eq(buf, libc_buf, sizeof buf,
		"ft_bzero() did not properly fill a buffer"
		"with 10 zero bytes");
}
