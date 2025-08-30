#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_isalnum, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_isalnum(i) != 0,
			isalnum(i) != 0,
			"ft_isalnum(%d) != isalnum(%d)",
			i, i);
	}
}

Test(ft_isalnum, eof)
{
	cr_assert_eq(ft_isalnum(EOF) != 0,
		isalnum(EOF) != 0,
		"ft_isalnum(EOF) != isalnum(EOF)");
}
