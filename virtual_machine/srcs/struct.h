#ifndef STRUCT_H
# define STRUCT_H

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define FIRST_CHAIN 0
#define OTHER_CHAIN 0
/*
typedef struct		s_list
{
	int				nombre;
	struct s_list	*next;
	struct s_list	*begin;
}					t_list;*/

typedef struct		s_tab_chain
{
	t_list			*proccess;
}					t_tab_chain;

#endif