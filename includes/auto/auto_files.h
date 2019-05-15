#ifndef AUTO_FILES_H
# define AUTO_FILES_H

ssize_t		ft_get_size_file(char *str);
void		ft_add_to_file(char *name, char *data);
int			ft_create_new_file(char *str);
int			ft_get_tab_from_file(char *str, int **tab, int lines);

#endif
