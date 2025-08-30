#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_isprint, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_isprint(i) != 0,
			isprint(i) != 0,
			"ft_isprint(%d) != isprint(%d)",
			i, i);
	}
}

Test(ft_isprint, eof)
{
	cr_assert_eq(ft_isprint(EOF) != 0,
		isprint(EOF) != 0,
		"ft_isprint(EOF) != isprint(EOF)");
}
