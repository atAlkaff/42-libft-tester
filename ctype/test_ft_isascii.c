#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_isascii, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_isascii(i) != 0,
			isascii(i) != 0,
			"ft_isascii(%d) != isascii(%d)",
			i, i);
	}
}

Test(ft_isascii, eof)
{
	cr_assert_eq(ft_isascii(EOF) != 0,
		isascii(EOF) != 0,
		"ft_isascii(EOF) != isascii(EOF)");
}
