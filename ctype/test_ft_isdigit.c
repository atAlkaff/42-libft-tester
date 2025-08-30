#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_isdigit, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_isdigit(i) != 0,
			isdigit(i) != 0,
			"ft_isdigit(%d) != isdigit(%d)",
			i, i);
	}
}

Test(ft_isdigit, eof)
{
	cr_assert_eq(ft_isdigit(EOF) != 0,
		isdigit(EOF) != 0,
		"ft_isdigit(EOF) != isdigit(EOF)");
}
