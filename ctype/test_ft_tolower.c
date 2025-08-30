#include <criterion/criterion.h>
#include <ctype.h>
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "../../libft/libft.h"

Test(ft_tolower, unsigned_char)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		cr_assert_eq(ft_tolower(i) != 0,
			tolower(i) != 0,
			"ft_tolower(%d) != tolower(%d)",
			i, i);
	}
}

Test(ft_tolower, eof)
{
	cr_assert_eq(ft_tolower(EOF) != 0,
		tolower(EOF) != 0,
		"ft_tolower(EOF) != tolower(EOF)");
}
