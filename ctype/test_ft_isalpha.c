#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_isalpha, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_isalpha(i) != 0,
			isalpha(i) != 0,
			"ft_isalpha(%d) != isalpha(%d)",
			i, i);
	}
}

Test(ft_isalpha, eof)
{
	cr_assert_eq(ft_isalpha(EOF) != 0,
		isalpha(EOF) != 0,
		"ft_isalpha(EOF) != isalpha(EOF)");
}
