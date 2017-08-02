/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevine <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 19:57:27 by rlevine           #+#    #+#             */
/*   Updated: 2017/08/01 14:10:58 by wwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdio.h>

# define AL "#.\n#.\n##\n .#\n.#\n##\n ##\n.#\n.#\n ##\n#.\n#.\n ###\n..#\n"
# define ALL "..#\n###\n ###\n#..\n #..\n###\n #\n#\n#\n#\n ####\n ##.\n.##\n"
# define ALLL "#.\n##\n.#\n .#\n##\n#.\n ##\n##\n .#.\n###\n ###\n.#.\n"
# define ALLLL ".#\n##\n.#\n .##\n##.\n #.\n##\n#.\n "

char	***ft_mkmap(char *file);
char	**ft_twod(char *str, char	**twod);
char	**ft_makeasquare(int len);
void	testyershit(char **lul);
void	ft_gtfo(void);
void	ft_mapfail(void);
int		ft_maplen(char *file);
char	***ft_makearectangularprism(void);
int		sidelen(int tetnum);
char	**dotary(int tetnum, int size);
int		main(int ac, char **av);
int		ft_min(char *str, int start);
int		ft_max(char *str, int start);
char	**ft_chk_chars(char **matrix, int dot, int hash, int i);
int		ft_prelim_dot_hash(char *file, int dot, int len);
char	***ft_letterize(char ***map, int i, int j, int k);
int		ft_prelim_line_placement(char *str, int len);
char	**ft_solvit(char **board, char ***map, int tetnum);
void	ft_test(char ***threed);
int		ft_tetnum(char ***map);
int		tetra_in_map(char **map, int size, int i);
char	**clean_map(char **map, int size);
char	**map_new(int s);
char	**solve(char **map, char ***tetra, int num);
char	**remove_tetra(char **map, int i, int size);
int		getdim(char **tetra, int flag);
int		try_place(char **tetra, char **map, int x, int y);
int		tryfit_tetra(char **map, char **tetra, int size);
char	**enlarge_map(char **map, int size);
char	**place(char **tetra, char **map, int x, int y);
char	**put_tetra(char **map, char **tetra, int size);
char	**shift_tetra(char **map, char **tetra, int size);
int		tryshift_tetra(char **map, char **tetra, int size);
void	ft_printit(char **twod);
#endif
