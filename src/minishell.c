#include "minishell.h"

void	exit_shell(void)
{
	if (!"-n")
		write(1, "\n", 1);
	ft_free_malloc(g_envp);
	exit(0);
}

int	envp_len(char **envp)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	while (envp[++i])
		cnt++;
	return (cnt);
}

void	init_envp(int argc, char **argv, char **envp)
{
	int	i;

	(void)argc;
	(void)argv;
	g_envp = (char **)ft_calloc(sizeof(char *), (envp_len(envp) + 1));
	if (!g_envp)
		exit_shell();
	i = -1;
	while (envp[++i])
	{
		g_envp[i] = ft_strdup(envp[i]);
		if (!g_envp[i])
			exit_shell();
	}
}

void	ft_free_malloc(char **array)
{
<<<<<<< HEAD
	(void)envp;
	printf("minishell!\n");
	exec_cmd(parse_cmd(argv[argc - 1]));
=======
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	array = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	init_envp(argc, argv, envp);
	while (1)
	{

	}
	ft_free_malloc(g_envp);
>>>>>>> fe249061a7c6c27fd8cbfd71068508a129cf2724
	return (0);
}
