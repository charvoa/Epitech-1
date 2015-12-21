#ifndef _MINISHELL_H_
#define _MINISHELL_H_

typedef	struct	s_mini
{
  char	**env;
  char	**tab;
  char	**cmd;
}		t_mini;

char	**str_to_wordtab(t_mini *mini, char *str);
int	main(int ac, char **av, char **envp);
int	aff_prompt(char **av, t_mini *mini);
void	getpath(t_mini *mini, char **envp);
void	strtotab(t_mini *mini, char *str);
int	do_cmd(char **av, t_mini *mini);
void	get_sigint(int sig);
int	check_path(char **envp);
void	my_env(char **envp, t_mini *mini);
int	my_cd(char*, char**);
void	*xmalloc(size_t size);
int	xread(int fd, char *buffer, int size);
char	*epur_str(char *str);
int	builtin(char *cmd, t_mini *mini);
int	check_space(char *str);

#endif
