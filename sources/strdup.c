#include "../rover.h"

char	*strdup(const char *str)
{
	char	*a;
	char	*str1;
	int		i;

	str1 = (char *)str;
	i = 0;
	a = (char *)malloc(strlen(str1) + 1);
	if (a == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		a[i] = str1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}