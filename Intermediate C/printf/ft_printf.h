#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <inttypes.h>

typedef struct	s_flag
{
	char	flag;
	int		width;
	int		dot;
	int		precision;
	char	key;
}				t_flag;

int				ft_dc(int n);

int				ft_dc_u(unsigned int n);

void			*ft_calloc(size_t count, size_t size);

int				ft_dc_hex(uintptr_t n);

char			*ft_itoa(int n);

char			*ft_itoa_u(unsigned int n);

unsigned long	ft_strlen(const char *s);

char			*ft_strjoin(char const *s1, char const *s2);

int				ft_check(char const *x, char y);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				getint(va_list ar, const char *format, int *i);

int				ft_printf(const char *format, ...);

char			*ft_strcpy(char *dest, char *src);

char			*ft_strcpy(char *dest, char *src);

void			*ft_memmove(void *dst, const void *src, size_t len);

char			*assignkeys(void);

int				ft_isdigit(int c);

char			*ft_strdup(const char *s1);

t_flag			giveflags(const char *format, int i, va_list ar);

char			*minus_zero(char *tmp, int precision, int len);

int				ft_atoi(const char *str);

void			*ft_memset(void *b, int c, size_t len);

char			*ft_itoa_hex(unsigned int n, char c);

char			*ft_itoa_ptr(void *p);

char			*ft_getchar(char c);

char			*usekey(t_flag flags, va_list ar);

char			*getprecision(char *rtn, int precision, char key);

int				useflags(t_flag flags, char *rtn, int len);

int				ft_propertext(const char *format, int j, va_list ar);

int				ft_print(const char *format, va_list ar, char *keys);

char			*getwidth(char *rtn, int width, char flag, int dot);

#endif
