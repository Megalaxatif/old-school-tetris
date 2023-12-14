#ifndef MAIN_HPP
#define MAIN_HPP
#include <windows.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <ctime>
#include <string>
#include <limits>
#undef max // we undef the macro used by windows.h

class Tetris {
public:
	Tetris(HANDLE console);
	void try_force_down();
	void check_input();
	const bool is_game_running();
	void create_board();
	const void display_command_info();
	const void display_next_tetramino_board();
	const void display_board();
	const void goto_(int x, int y);
	void set_tetramino();
	void get_random_index_list();
	void set_game_settings(std::string message, int n1, int n2, int* var);
	int move_tetramino(int dirx, int diry);
	void get_tetramino_highest_posy();
	void set_tetramino_highest_posy();
	const bool check_collision(int tetramino[4][4], int dirx, int diry, int posx, int posy);
	void rotate_tetramino();
	const void erase_tetramino();
	const void draw_tetramino();
	const void display_next_tetramino(int number);
	void try_break_line();
	void lock_tetramino();
	void move_board_down(int line);
	const void draw_pagga_text(int position, int posx, int posy, int length);
	const void draw_tetris_logo();
	const void display_counter(int number, int* var, int posx_, int posy_);
	const void display_broken_line_counter();
	void add_score(int score);
	void game_over();

private:
	int board[12][22];
	int current_tetramino[4][4];
	int random_index_list[10];
	HANDLE console;
	int posx, posy;
	int highest_posy;
	int board_posx, board_posy, board_length, board_heigth;
	int next_tetra_posx, next_tetra_posy;
	int broke_line_counter_posx, broke_line_counter_posy;
	int score_text_length, score_text_posx, score_text_posy;
	int game_state_text_length, game_state_text_posx, game_state_text_posy;
	int level_text_length, level_text_posx, level_text_posy;
	int numbers_length;
	int pagga_font_heigth;
	int tetris_logo_posx, tetris_logo_posy;
	int tetris_logo_length;
	int tetris_logo_heigth;
	int game_mode;
	int score;
	int level;
	int broke_line;
	int timer;
	int r_index;
	bool is_key_up_pressed;
	bool is_key_enter_pressed;
	bool is_key_space_bar_pressed;
	bool game_running;
};

#endif