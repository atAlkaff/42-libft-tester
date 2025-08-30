#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_toupper, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_toupper(i) != 0,
			toupper(i) != 0,
			"ft_toupper(%d) != toupper(%d)",
			i, i);
	}
}

Test(ft_toupper, eof)
{
	cr_assert_eq(ft_toupper(EOF) != 0,
		toupper(EOF) != 0,
		"ft_toupper(EOF) != toupper(EOF)");
}
