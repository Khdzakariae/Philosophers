#include "../so_long.h"

static int	ft_intlen(long n)
{
	int	tmp;

	tmp = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		tmp++;
		n = n * -1;
	}
	while (n)
	{
		n = n / 10;
		tmp++;
	}
	return (tmp);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (nb == 0)
		ptr[0] = 48;
	else if (nb < 0)
	{
		ptr[0] = '-';
		nb = nb * -1;
	}
	while (nb != 0)
	{
		ptr[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (ptr);
}

void	ft_strlcpy1(char **dst, char **src, size_t colon, size_t line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < line && src[i])
	{
		j = 0;
		while (j < colon && src[i][j])
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
	}
}
