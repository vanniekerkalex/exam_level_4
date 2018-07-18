
#include <stdlib.h>
#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;
    while (*(str + i))
    {
        write(1, &str[i++], 1);
    }
}

int ft_strlen(char *str)
{
    int len = 0;

    while (*(str + len))
        len++;
    return (len);
}

char **ft_split(char *str)
{
    int len = ft_strlen(str);
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab;

    tab = (char **)malloc(sizeof(char *) * (len + 1));
    while (*(str + i) == ' ' || *(str + i) == '\t')
        i++;
    while (*(str + i))
    {
        if (*(str + i) != ' ' && *(str + i) != '\t')
        {
            k = 0;
            tab[j] = (char *)malloc(sizeof(char) * (len + 1));
            while (*(str + i) && *(str + i) != ' ' && *(str + i) != '\t')
                tab[j][k++] = *(str + i++);
            tab[j][k] = '\0';
            j++;
        }
        else
            i++;
    }
    tab[j] = NULL;
    return (tab);
}

int main (int argc, char **argv)
{
    int i = 0;
    char **tab;
    if (argc >= 2)
    {
            i = 1;
            if (argv[1][0] != '\0')
            {
                tab = ft_split(argv[1]);
                while (tab[i])
                {
                    ft_putstr(tab[i++]);
                    write(1, " ", 1);
                }
                ft_putstr(tab[0]);
                write(1, "\n", 1);
            }
    }
    else
        write(1,"\n", 1);
    return (0);
}
