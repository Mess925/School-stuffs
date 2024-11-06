#include <stdlib.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int swap;
    t_list *cur = lst;
    
    while (lst && lst->next)
    {
        if((*cmp)(lst->data,lst->next->data)== 0)
        {
            swap =lst->next->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = cur;
        }
        else{
            lst = lst->next;
        }
    }
    return(cur);
}