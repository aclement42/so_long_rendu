/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclement <aclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:12:24 by aclement          #+#    #+#             */
/*   Updated: 2023/01/25 18:43:15 by aclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# define CONVERTS "diucspxX%"
# define BG "0123456789ABCDEF"
# define BP "0123456789abcdef"

typedef struct s_env_printf
{
	va_list	ap;
	char	*str;
	int		ret;
	int		i;
}				t_env_printf;

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// prototypes ft_printf

int		ft_printf(const char *str, ...);
void	ft_firstparse(t_env_printf *var);
void	ft_parsemodulo(t_env_printf *var);
void	ft_choose_conv(t_env_printf *var);
void	ft_mod_c(t_env_printf *var);
void	ft_mod_id(t_env_printf *var, int param);
void	ft_mod_s(t_env_printf *var);
void	ft_mod_xx(t_env_printf *var, unsigned int param);
void	ft_mod_u(t_env_printf *var, unsigned int param);
void	ft_mod_p(t_env_printf *var, unsigned long long int param);
void	ft_putnbr(int nb);
int		ft_convert_ui_in_hex(unsigned int nb, char *base);
int		ft_unsigned_nblen(unsigned int nb);
void	ft_unsigned_putnbr(unsigned int nb);
void	ft_convert_ulli_in_hex(t_env_printf *var, unsigned long long int nb,
			char *base);
void	ft_putchar(char c);
int		ft_c_in_str(char *str, char c);
void	ft_putstr(char *str);
int		ft_nblen(long int nb);
int		ft_strlen_printf(char *str);

#endif
