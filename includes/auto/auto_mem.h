#ifndef AUTO_AUTO_MEM_H
# define AUTO_AUTO_MEM_H

char		*ft_strnew(size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
t_list		**ft_garbage_collector(void);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
void		ft_burn_garbage(char *str);
void		ft_bzero(void *s, size_t n);
void		ft_clean_garbage(void);
void		ft_del(void *content, size_t size);
void		ft_memdel(void **ap);
void		ft_strdel(char **as);
void		ft_strdel_multi(size_t nb, ...);
void		ft_swap(void *one, void *two, size_t size);

#endif
