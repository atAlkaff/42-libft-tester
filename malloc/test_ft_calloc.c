#include <criterion/criterion.h>
#include <stdlib.h>	// calloc(), free(), NULL
#include <stdint.h>
#include "libft.h"

Test(ft_calloc, correct_size_zeroed_memory_freeable)
{
	int count = 25;
	int *arr = ft_calloc(count, sizeof(int));
	int *libc_arr = calloc(count, sizeof(int));

	cr_assert_arr_eq(arr, libc_arr, count,
		"ft_calloc() returned an array that was "
		"either too small or not zeroed");

	free(arr);
	free(libc_arr);
}

Test(ft_calloc, writable_memory)
{
	int count = 10;
	long *arr = ft_calloc(count, sizeof(long));

	for (int i = 0; i < count; i++)
		arr[i] = i * 7;
	for (int i = 0; i < count; i++)
		cr_assert_eq(arr[i], i * 7, "ft_calloc() "
			"returned non-writable memory. arr[%d] "
			"is %d, but should be %d",
			i, arr[i], i * 7);
}

Test(ft_calloc, unique_pointer_when_nmemb_zero)
{
	cr_assert_neq(ft_calloc(0, 20), NULL,
		"ft_calloc() returned NULL when nmemb was zero");
}

Test(ft_calloc, unique_pointer_when_size_zero)
{
	cr_assert_neq(ft_calloc(50, 0), NULL,
		"ft_calloc() returned NULL when size was zero");
}

Test(ft_calloc, unique_pointer_when_nmemb_and_size_zero)
{
	cr_assert_neq(ft_calloc(0, 0), NULL,
		"ft_calloc() returned NULL when nmemb and size"
		" were both zero");
}

Test(ft_calloc, null_when_over_ptrdiff_max_requested)
{
	char *buf = ft_calloc((size_t)PTRDIFF_MAX + 1U, sizeof(char));

	cr_assert_eq(buf, NULL,
		"ft_calloc() allocated more than PTRDIFF_MAX");
}

Test(ft_calloc, null_when_overflow)
{
	short *wbuf = ft_calloc(SIZE_MAX, sizeof(short));

	cr_assert_eq(wbuf, NULL,
		"ft_calloc() did not handle size overflow");
}
