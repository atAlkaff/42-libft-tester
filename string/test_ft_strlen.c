#include <criterion/criterion.h>
#include <string.h>	// strlen(), strcpy()
#include <stdlib.h>	// malloc()
#include "libft.h"

#define _assert_ft_strlen_libc_strlen(s)		\
	cr_assert_eq(ft_strlen(s), strlen(s),		\
		"ft_strlen(\"%s\") != strlen(\"%s\")",	\
		s, s)

Test(ft_strlen, empty_string)
{
	_assert_ft_strlen_libc_strlen("");
}

Test(ft_strlen, length1)
{
	_assert_ft_strlen_libc_strlen("H");
}

Test(ft_strlen, length4)
{
	_assert_ft_strlen_libc_strlen("Hell");
}

Test(ft_strlen, length7)
{
	_assert_ft_strlen_libc_strlen("Hello w");
}

Test(ft_strlen, length24)
{
	_assert_ft_strlen_libc_strlen("Hello world! "
		"I am a user");
}

Test(ft_strlen, length10k)
{
	char buf[10000];
	memset(buf, 'A', sizeof(buf) - 1);
	buf[sizeof(buf) - 1] = '\0';
	_assert_ft_strlen_libc_strlen(buf);
}

Test(ft_strlen, null_terminator_in_array)
{
	_assert_ft_strlen_libc_strlen("Hello\0world");
}

Test(ft_strlen, null_terminator_start)
{
	_assert_ft_strlen_libc_strlen("\0Hello\0world");
}

Test(ft_strlen, stack_allocated_string)
{
	char buf[100];
	strcpy(buf, "Hello world");
	_assert_ft_strlen_libc_strlen(buf);
}

Test(ft_strlen, heap_allocated_string)
{
	char *buf = malloc(100);
	strcpy(buf, "Hello world");
	_assert_ft_strlen_libc_strlen(buf);
}

Test(ft_strlen, utf8_support)
{
	_assert_ft_strlen_libc_strlen("✓ café");
}
