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
void handle_flag(t_flags_values *flags_values, char *flag)
{
	if (ft_strcmp(flag, "--simple") == 0)
		flags_values->simple += 1;
	else if (ft_strcmp(flag, "--medium") == 0)
		flags_values->medium += 1;
	else if (ft_strcmp(flag, "--complex") == 0)
		flags_values->complex += 1;
	else if (ft_strcmp(flag, "--adaptive") == 0)
		flags_values->adaptive += 1;
	else if (ft_strcmp(flag, "--bench") == 0)
		flags_values->bench += 1;
	else
	{
		free(flags_values);
		exit(1);
	}
}

t_flags_values	*check_flags(char **argv)
{
	t_flags_values	*flags_values;

	flags_values = malloc(sizeof(t_flags_values));
	init_flags_values(flags_values);
	if (!flags_values)
		return NULL;
	while (*argv && ((*argv)[0] == '-' && (*argv)[1] == '-'))
		handle_flag(flags_values, *argv++);
	return (flags_values);
}
