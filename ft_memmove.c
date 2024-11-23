#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	*end_dest;
	char	*end_src;

	d = (char *)dst;
	s = (char *)src;
	end_dest = d + len - 1;
	end_src = s + len - 1;
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*end_dest-- = *end_src--;
	}
	return (dst);
}
