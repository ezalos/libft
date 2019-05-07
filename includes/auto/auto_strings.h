/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_strings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:45:05 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 18:45:05 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUTO_STRINGS_H
# define AUTO_STRINGS_H

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_multi(size_t nb, ...);
char		**ft_strsplit(char const *s, char c);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_islower(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
size_t		ft_strfastlen(const char *str);
size_t		ft_strlen(const char *s);
size_t		ft_strnlen(const char *s, size_t size);
int			ft_char_srch(const char src, const char *dlt);
int			ft_match(char *s1, char *s2);
int			ft_nmatch(char *s1, char *s2);
char		*ft_pstrnstr(const char *m, const char *a, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *meule_de_foin, const char *aiguille);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

#endif
