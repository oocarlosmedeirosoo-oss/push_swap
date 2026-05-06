#include "push_swap.h"


static int(ft_strcmp(const char *s1, const char *s2))
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static void init_flags_values(t_flags_values *flags_values)
{
	flags_values->simple = 0;
	flags_values->medium = 0;
	flags_values->complex = 0;
	flags_values->adaptive = 0;
	flags_values->bench = 0;
}

t_flags_values	*check_flags(char **argv)
{
	t_flags_values	*flags_values;

	flags_values = malloc(sizeof(t_flags_values));
	init_flags_values(flags_values);
	if (!flags_values)
		return NULL;

	while (*argv && ((*argv)[0] == '-' && (*argv)[1] == '-'))
	{
		if (ft_strcmp(*argv, "--simple") == 0)
			flags_values->simple += 1;
		else if (ft_strcmp(*argv, "--complex") == 0)
			flags_values->complex += 1;
		else if (ft_strcmp(*argv, "--medium") == 0)
			flags_values->medium += 1;
		else if (ft_strcmp(*argv, "--adaptive") == 0)
			flags_values->adaptive += 1;
		else if (ft_strcmp(*argv, "--bench") == 0)
			flags_values->bench += 1;
		else
		{
			free(flags_values);
			return NULL;
		}
		argv++;
	}
	return (flags_values);
}
