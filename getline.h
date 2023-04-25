#ifndef GET_LINE_H
# define GET_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 32

char	*func(char **line, char **tmp, int nl);
char	*_getline(int fd);
int		check_newline(char *buff);
size_t	_strlen(const char *s);
char	*get_reminder(char **str, int nl);
char	*_substr(char const *s, unsigned int start, size_t len);
void	*_calloc(size_t count, size_t size);
void	_bzero(void *s, size_t n);
char	*_strjoin(char const *s1, char const *s2);
char	*_strdup(const char *s1);

#endif
