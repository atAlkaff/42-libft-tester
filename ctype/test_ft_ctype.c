#include <criterion/criterion.h>
#include <ctype.h>	// libc ctype functions
#include <limits.h>	// UCHAR_MAX (usually 255)
#include <stdio.h>	// EOF (usually -1)
#include "libft.h"

#define _test_ft_ctype_unsigned_char(x)			\
	Test(ft_##x, unsigned_char)					\
	{											\
		for (int i = 0; i <= UCHAR_MAX; i++)	\
		{										\
			cr_assert_eq(ft_##x(i) != 0,		\
				x(i) != 0,						\
				"ft_"#x"(%d) != "#x"(%d)",		\
				i, i);							\
		}										\
												\
	}

#define _test_ft_ctype_eof(x)					\
	Test(ft_##x, eof)							\
	{											\
		cr_assert_eq(ft_##x(EOF) != 0,			\
			x(EOF) != 0,						\
			"ft_"#x"(EOF) != "#x"(EOF)");		\
	}

#define _test_ft_ctype(x)						\
	_test_ft_ctype_unsigned_char(x)				\
	_test_ft_ctype_eof(x)						\

_test_ft_ctype(isalpha)
_test_ft_ctype(isdigit)
_test_ft_ctype(isalnum)
_test_ft_ctype(isprint)
_test_ft_ctype(isascii)
_test_ft_ctype(toupper)
_test_ft_ctype(tolower)
