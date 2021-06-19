#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen_second(const char *s1);
char	*ft_strjoin_second(char *memory, char *buffer);
char	*ft_clearmemory(char *memory);
char	*ft_new_line(char *s);
int		ft_strchr(const char *s, int c);

#endif
