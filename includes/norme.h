/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 16:46:36 by rda-cost          #+#    #+#             */
/*   Updated: 2015/03/01 20:01:11 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORME_H
# define NORME_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <ncurses.h>
# include "../libft/includes/libft.h"
# define LOOSE_MAP -2
# define FULL_MAP -1
# define NORME_MAP 0
# define WIN_MAP 1
# define DEFAULT_UNDO 5
# define DEFAULT_X 4
# define DEFAULT_Y 4
# define CONTINUE_GAME 1
# define END_GAME -1
# define CONTINUE_APP 1
# define END_APP 0
# define HEADER_X 54
# define HEADER_Y 15
# define GAME_STEPS 3
# define SCORES_FILE "scores.txt"
# define ERROR_NBR 1
# define UNDEFINED_ERROR 0
# define FATAL_ERROR 0

enum				e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_error
{
	int				ret;
	int				code;
	char			*str;
}					t_error;

enum				e_types
{
	STRING,
	INT,
	GAME
};

enum				e_ncurses_mode
{
	INIT_NCURSES,
	END_NCURSES,
	RESET_NCURSES
};

enum				e_vectors
{
	TOP,
	LEFT,
	DOWN,
	RIGHT
};

typedef struct		s_term
{
	int				row;
	int				col;
	int				cur_x;
	int				cur_y;
}					t_term;

typedef struct		s_map
{
	int				merges;
	int				**map;
	int				score;
	int				stroke;
	struct s_map	*next;
	struct s_map	*prev;
}					t_map;

typedef struct		s_game
{
	int				id;
	int				width;
	int				height;
	int				undo;
	int				end;
	int				win;
	int				count_tmp;
	int				merge_tmp;
	t_term			term;
	t_map			*maps;
	struct s_game	*prev;
}					t_game;

typedef struct		s_env
{
	int				game_nbr;
	t_game			game_values;
	t_game			*games;
}					t_env;

typedef struct		s_hash
{
	int				val;
	int				x;
	int				y;
}					t_hash;

typedef struct		s_pt
{
	int				x;
	int				y;
}					t_pt;

typedef struct		s_menu
{
	int				select;
	char			*str;
	int				(*menu_cmd)(t_env *);
	int				ret;
}					t_menu;

int					handle_error(int error, t_env *env);
int					init_game(t_env *env);
int					play_game(t_env *env);
int					end_game(t_env *env);
int					display(void *data, int y, int x, int t);
int					set_ncurses(int mode);
int					handle_keyboard_game_event(t_game *game);
int					handle_keyboard_menu_event(t_env *env, t_menu *mnu, int e);
int					game_value_picker(t_env *env);
int					list_add_game(t_env *env);
int					list_add_map(t_game *game, int cmd);
int					write_score(int score);
int					create_table(t_map *map, int height, int widht);
void				print_map(t_map *map, int height, int widht);
int					call_random_map(t_game *game, int nb);
int					treat_cmd(t_game *game, int input);
void				reset_pt(t_pt *pt, t_pt vec, t_game *g);
int					call_rec(t_game *g, t_pt vec, t_pt pt, t_pt *off_set);
int					list_undo_map(t_game *game, int cmd);
int					poweroftwo (unsigned int x);
int					get_next_line(int const fd, char **line);
int					display_hall_of_fame(t_env *env);
void				display_game(t_game *game, int y, int x);
void				choose_color(int value);
void				overwrite_ascii(t_game *game);

#endif
