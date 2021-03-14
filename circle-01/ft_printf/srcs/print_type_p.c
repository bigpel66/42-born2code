#include "ft_printf.h"
#include <stdio.h>

int allocate_with_dot(t_form *f, char **pref, char **suff, size_t len)
{
	long long val;
	long long p_len;
	long long s_len;

	if (len < f->precision)
	{
		s_len = f->precision - len;
		val = f->precision + 2;
	}
	else
	{
		s_len = 0;
		val = len + 2;
	}
	if (val < f->width)
		p_len = f->width - val;
	else
		p_len = 0;
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}

int allocate_without_dot(t_form *f, char **pref, char **suff, size_t len)
{
	char *tmp;
	long long p_len;
	long long s_len;

	tmp = NULL;
	s_len = 0;
	if (len + 2 < f->width)
		p_len = f->width - (len + 2);
	else
		p_len = 0;
	*suff = (char *)ft_calloc(s_len + 1, sizeof(char));
	*pref = (char *)ft_calloc(p_len + 1, sizeof(char));
	if (!(*pref && *suff))
		return (0);
	if (f->flag & ((char)1 << 4))
	{
		tmp = *pref;
		*pref = *suff;
		*suff = tmp;
	}
	ft_memset(*pref, 32, p_len);
	ft_memset(*suff, 48, s_len);
	return (1);
}

int padd_p(t_form *f, char **pref, char **suff, size_t len)
{
	int ret;

	if (f->flag & ((char)1 << 2))
		ret = allocate_with_dot(f, pref, suff, len);
	else
		ret = allocate_without_dot(f, pref, suff, len);
	if (!ret)
		return (0);

	return (1);
}

char *get_address(va_list ap, size_t *len)
{
	unsigned long long adr;
	int shift;
	int offset;
	int i;
	char *buf;

	adr = (unsigned long long)(va_arg(ap, void *));
	*len = 0;
	shift = sizeof(adr) * 2 - 1;
	offset = shift;
	if (!(buf = (char *)ft_calloc(offset + 2, sizeof(char))))
		return (NULL);
	while (shift >= 0)
	{
		i = (adr & (unsigned long long)15 << (shift * 4)) >> (shift * 4);
		buf[offset - shift--] = "0123456789abcdef"[i];
		if (i)
			++(*len);
	}
	return (buf);
}

int print_type_p(t_form *f, va_list ap)
{
	char *adr;
	size_t len;
	char *pref;
	char *suff;

	if (!((adr = get_address(ap, &len)) && padd_p(f, &pref, &suff, len)))
		return (0);
	if (!(f->flag & ((char)1 << 7)))
		f->size += write(f->fd, pref, ft_strlen(pref));
	f->size += write(f->fd, "0x", 2);
	f->size += write(f->fd, suff, ft_strlen(suff));
	f->size += write(f->fd, adr + ft_strlen(adr) - len, len);
	if (f->flag & ((char)1 << 7))
		f->size += write(f->fd, pref, ft_strlen(pref));
	free_ptr((void *)(&adr));
	free_ptr((void *)(&pref));
	free_ptr((void *)(&suff));
	return (1);
}
