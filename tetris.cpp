#include "tetris.hpp"
/*
//\033[5;1,31m ______\033[0m   \033[5;1,31m______\033[0m     \033[5;1,31m______\033[0m   \033[5;1,31m______\033[0m     \033[5;1,31m__\033[0m     \033[5;1,31m______\033[0m
//\033[5;1,31m/\\__  _\\\033[0m \033[5;1,31m/\\  ___\\\033[0m   \033[5;1,31m/\\__  _\\\033[0m \033[5;1,31m/\\  == \\\033[0m   \033[5;1,31m/\\ \\\033[0m   \033[5;1,31m/\\  ___\\\033[0m
//\033[5;1,31m\\/_/\\ \\/\033[0m \033[5;1,31m\\ \\  __\\\033[0m   \033[5;1,31m\\/_/\\ \\/\\033[0m \033[5;1,31m\\ \\  __<\033[0m   \033[5;1,31m\\ \\ \\\033[0m  \033[5;1,31m\\ \\___  \\\033[0m
//\033[5;1,31m   \\ \\_\\\033[0m  \033[5;1,31m\\ \\_____\\\033[0m    \033[5;1,31m\\ \\_\\\033[0m  \033[5;1,31m\\ \\_\\ \\_\\\033[0m  \033[5;1,31m\\ \\_\\\033[0m  \033[5;1,31m\\/\\_____\\\033[0m
//\033[5;1,31m    \\/_/\033[0m   \033[5;1,31m\\/_____/\\033[0m     \033[5;1,31m\\/_/\\033[0m   \033[5;1,31m\\/_/ /_/\033[0m   \033[5;1,31m\\/_/\033[0m   \033[5;1,31m\\/_____/\033[0m

 ______   ______    ______   ______     __     ______
/\__  _\ /\  ___\  /\__  _\ /\  == \   /\ \   /\  ___\
\/_/\ \/ \ \  __\  \/_/\ \/ \ \  __<   \ \ \  \ \___  \
   \ \_\  \ \_____\   \ \_\  \ \_\ \_\  \ \_\  \/\_____\
    \/_/   \/_____/    \/_/   \/_/ /_/   \/_/   \/_____/ 57

* POLICE: Pagga
░▄▀▄░▀█░░▀▀▄░▀▀█░█░█░█▀▀░▄▀▀░▀▀█░▄▀▄░▄▀▄
░█ █░░█░░▄▀░░░▀▄░░▀█░▀▀▄░█▀▄░▄▀░░▄▀▄░░▀█
░░▀░░▀▀▀░▀▀▀░▀▀░░░░▀░▀▀░░░▀░░▀░░░░▀░░▀▀░
▓█▀▀▓█▀▀▓█▀█▓█▀▄▓█▀▀▓▓▓▓
▓▀▀█▓█▓▓▓█▓█▓█▀▄▓█▀▀▓▓▀▓
▓▀▀▀▓▀▀▀▓▀▀▀▓▀▓▀▓▀▀▀▓▓▀▓
▓█▀█▓█▀█▓█▓█▓█▀▀▓█▀▀
▓█▀▀▓█▀█▓█▓█▓▀▀█▓█▀▀
▓▀▓▓▓▀▓▀▓▀▀▀▓▀▀▀▓▀▀▀
▓█▀█▓█▓▓▓█▀█▓█▓█▓▀█▀▓█▀█▓█▀▀
▓█▀▀▓█▓▓▓█▀█▓▓█▓▓▓█▓▓█▓█▓█▓█
▓▀▓▓▓▀▀▀▓▀▓▀▓▓▀▓▓▀▀▀▓▀▓▀▓▀▀▀
▓█▓▓▓█▀▀▓█▓█▓█▀▀▓█▓▓▓▓▓
▓█▓▓▓█▀▀▓▀▄▀▓█▀▀▓█▓▓▓▀▓
▓▀▀▀▓▀▀▀▓▓▀▓▓▀▀▀▓▀▀▀▓▀▓
1 fitted piece = 10 points
1 broken line = 100 points
2 lines = 300
3 lines = 500
4 lines (tetris) = 1000
*/
const char* tetris_text[5]{
    "\033[5;31m ______\033[0m   \033[5;1;37m______\033[0m    \033[5;33m______\033[0m   \033[5;1;32m______\033[0m     \033[5;1;36m__\033[0m     \033[5;35m______\033[0m",
    "\033[5;31m/\\__  _\\\033[0m \033[5;1;37m/\\  ___\\\033[0m  \033[5;33m/\\__  _\\\033[0m \033[5;1;32m/\\  == \\\033[0m   \033[5;1;36m/\\ \\\033[0m   \033[5;35m/\\  ___\\\033[0m",
    "\033[5;31m\\/_/\\ \\/\033[0m \033[5;1;37m\\ \\  __\\\033[0m  \033[5;33m\\/_/\\ \\/\033[0m \033[5;1;32m\\ \\  __<\033[0m   \033[5;1;36m\\ \\ \\\033[0m  \033[5;35m\\ \\___  \\\033[0m",
    "\033[5;31m   \\ \\_\\\033[0m  \033[5;1;37m\\ \\_____\\\033[0m   \033[5;33m\\ \\_\\\033[0m  \033[5;1;32m\\ \\_\\ \\_\\\033[0m  \033[5;1;36m\\ \\_\\\033[0m  \033[5;35m\\/\\_____\\\033[0m",
    "\033[5;31m    \\/_/\033[0m   \033[5;1;37m\\/_____/\033[0m    \033[5;33m\\/_/\033[0m   \033[5;1;32m\\/_/ /_/\033[0m   \033[5;1;36m\\/_/\033[0m   \033[5;35m\\/_____/\033[0m"
};

const wchar_t* pagga_text[3][4] = {
    L" █▀▀ █▀▀ █▀█ █▀▄ █▀▀    ",L" █▀█ █▀█ █ █ █▀▀ █▀▀        ",L" █▀█ █   █▀█ █ █ ▀█▀ █▀█ █▀▀",L"█   █▀▀ █ █ █▀▀ █     ",
    L" ▀▀█ █   █ █ █▀▄ █▀▀  ▀ ",L" █▀▀ █▀█ █ █ ▀▀█ █▀▀        ",L" █▀▀ █   █▀█  █   █  █ █ █ █",L"█   █▀▀ ▀▄▀ █▀▀ █   ▀ ",
    L" ▀▀▀ ▀▀▀ ▀▀▀ ▀ ▀ ▀▀▀  ▀ ",L" ▀   ▀ ▀ ▀▀▀ ▀▀▀ ▀▀▀        ",L" ▀   ▀▀▀ ▀ ▀  ▀  ▀▀▀ ▀ ▀ ▀▀▀",L"▀▀▀ ▀▀▀  ▀  ▀▀▀ ▀▀▀ ▀ "
};
const wchar_t* score_numbers_font[3][10] = {
    L" ▄▀▄", L" ▀█ ", L" ▀▀▄", L" ▀▀█",L" █ █", L" █▀▀", L" ▄▀▀", L" ▀▀█", L" ▄▀▄", L" ▄▀▄",
    L" █ █", L"  █ ", L" ▄▀ ", L"  ▀▄",L"  ▀█", L" ▀▀▄", L" █▀▄", L" ▄▀ ", L" ▄▀▄", L"  ▀█",
    L"  ▀ ", L" ▀▀▀", L" ▀▀▀", L" ▀▀ ",L"   ▀", L" ▀▀ ", L"  ▀ ", L" ▀  ", L"  ▀ ", L" ▀▀ "
};      
const wchar_t* ANSI_code[9] = {
    L"\033[37m  \033[0m",
    L"\033[36;1m▓▓\033[0m", // tetramino I
    L"\033[34;1m▓▓\033[0m", // tetramino J
    L"\033[37;1m▓▓\033[0m", // tetramino L
    L"\033[33m▓▓\033[0m", // tetramino O
    L"\033[32;1m▓▓\033[0m", // tetramino S
    L"\033[35m▓▓\033[0m", // tetramino T
    L"\033[31m▓▓\033[0m", // tetramino Z
    L"\033[37;1m██\033[0m"  // border
};

int tetraminos[7][4][4] = {
    {
        0, 0, 0, 0,
        0, 0, 0, 0,
        1, 1, 1, 1,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        2, 0, 0, 0,
        2, 2, 2, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 0, 3, 0,
        3, 3, 3, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 4, 4, 0,
        0, 4, 4, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 5, 5, 0,
        5, 5, 0, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        0, 6, 0, 0,
        6, 6, 6, 0,
        0, 0, 0, 0
    },
    {
        0, 0, 0, 0,
        7, 7, 0, 0,
        0, 7, 7, 0,
        0, 0, 0, 0
    }
};

Tetris::Tetris(HANDLE console_) : board{ 0 }, current_tetramino{ 0 }, random_index_list{ 0 } {
    console = console_;
    level = 1;
    game_mode = 1; // normal mode by default
    set_game_settings("Enter your starting level\n>>> ", 1, 10, &level);
    set_game_settings("Enter your gamemode:\n.1 = normal mode\n.2 = peaceful mode (no level increase)\n>>> ", 1, 2, &game_mode);
    posx = 4;
    posy = 0;
    highest_posy = 1;
    board_heigth = 22;
    board_length = 12;
    tetris_logo_posx = 5;
    tetris_logo_posy = 0;
    tetris_logo_length = 56;
    tetris_logo_heigth = 5;
    board_posx = tetris_logo_length/2 - board_length + tetris_logo_posx; // we center the board on the tetris logo
    board_posy = tetris_logo_heigth + tetris_logo_posy + 1;
    next_tetra_posx = board_posx + board_length + 15;
    next_tetra_posy = board_posy + 1;
    score_text_length = 24;
    score_text_posx = 15 + board_posx + board_length;
    score_text_posy = board_posy + 10;
    level_text_length = 23;
    level_text_posx = score_text_posx; // aligned with the score
    level_text_posy = score_text_posy + 5;
    game_state_text_length = 28;
    game_state_text_posx = score_text_posx; // aligned with the score
    game_state_text_posy = score_text_posy + 10;
    pagga_font_heigth = 3;
    numbers_length = 4;
    score = 0;
    broke_line = 0;
    broke_line_counter_posx = board_posx;
    broke_line_counter_posy = board_posy - 1;
    timer = 0;
    r_index = 0;
    random_index_list[9] = rand() % 7; // we initialize the last value
    is_key_up_pressed = false;
    is_key_enter_pressed = true;
    game_running = false;
    is_key_space_bar_pressed = false;
    srand(static_cast<unsigned>(time(NULL))); // random seed

    //___Game_starting___
    draw_tetris_logo();
    create_board();
    display_board();
    display_next_tetramino_board();
    get_random_index_list();
    set_tetramino();
    draw_tetramino();
    display_next_tetramino(1);
    draw_pagga_text(0, score_text_posx, score_text_posy, score_text_length); // score text display
    draw_pagga_text(3, level_text_posx, level_text_posy, level_text_length); // level text display
    draw_pagga_text(1, game_state_text_posx, game_state_text_posy, game_state_text_length); // game state display
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy);
    display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
    display_broken_line_counter();
    display_command_info();
}
const void Tetris::goto_(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}
void Tetris::get_random_index_list() {
    int index = 0;
    int i = 1;
    random_index_list[0] = random_index_list[9]; // we initialize the first value to the last value of the old list we haven't displayed
    while (i < 10){
        index = rand() % 7;
        if (random_index_list[i - 1] != index) {
            random_index_list[i] = index;
            i++;
        }
    }
}
void Tetris::set_tetramino() {
    if ((r_index + 1) == 10) { // check if we can reset to 0
        r_index = 0;
        get_random_index_list(); // regenerate the index list
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            current_tetramino[j][i] = tetraminos[random_index_list[r_index]][i][j]; // assign tetramino
        }
    }
}
void Tetris::set_game_settings(std::string message, int n1, int n2, int *var) {
    int entry;
    std::cout << message;
    while (1) {
        if (std::cin >> entry) {
            if (entry >= n1 && entry <= n2) {
                *var = entry;
                break;
            }
            else {
                std::cout << "Please type a number between " << n1 << " and " << n2 << ": ";
            }
        }
        else {
            std::cin.clear(); // we delete the invalid entry
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please type a valid number: ";
        }
    }
    std::cout << "\033[2J\033[1;1H"; // ANSI sequence to delete the console
}
void Tetris::create_board() {
    for (int y = 0; y < board_heigth; y++) {
        for (int x = 0; x < board_length; x++) {
            board[x][y] = 0; // we initialize all value to 0
            board[0][y] = board[board_length - 1][y] = board[x][0] = board[x][board_heigth - 1] = 8; // we initialise all edges to 8 (integer for the edge of the board)
        }
    }
}
const void Tetris::display_next_tetramino_board() {
    goto_(next_tetra_posx + 1, next_tetra_posy - 1);
    std::cout << "\033[31mNEXT PIECE :\033[0m";
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 6; x++) {
            goto_(next_tetra_posx, next_tetra_posy + y);
            WriteConsole(console, ANSI_code[8], 14, NULL, NULL);
            goto_(next_tetra_posx + 12, next_tetra_posy + y + 1);
            WriteConsole(console, ANSI_code[8], 14, NULL, NULL);
            goto_(next_tetra_posx + 2+ x*2, next_tetra_posy);
            WriteConsole(console, ANSI_code[8], 14, NULL, NULL);
            goto_(next_tetra_posx + x*2, next_tetra_posy + 6);
            WriteConsole(console, ANSI_code[8], 14, NULL, NULL);
        }
    }
}
const void Tetris::display_command_info() {
    goto_(0, tetris_logo_posy + tetris_logo_heigth + board_heigth + 2);
    WriteConsole(console, L"Move with ← ↓ →   Rotate with ↑   Switch pause/playing with entry   force down with space bar   Quit with ctrl + Back", 117, NULL, NULL);
    goto_(tetris_logo_posx + 96, tetris_logo_posy);
    std::cout << "made by Megalaxatif";
}
const void Tetris::display_board(){
    for (int y = 0; y < board_heigth; y++) {
        for (int x = 0; x < board_length; x++) {
            goto_(board_posx + x*2, board_posy + y);
            WriteConsole(console, ANSI_code[board[x][y]], 14, NULL, NULL);
        }
    }
}
const bool Tetris::check_collision(int tetramino[4][4], int dirx, int diry, int posx_, int posy_) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (board[posx_ + dirx + x][posy_ + diry + y] != 0 && tetramino[x][y] != 0) {
                return true; // collision
            }
        }
    }
    return false; // no collision at the end of the loop
}
const void Tetris::erase_tetramino() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                // we delete the projection
                goto_(board_posx + (posx + x) * 2, board_posy + highest_posy + y);
                WriteConsole(console, L"  ", 2, NULL, NULL);
                // we delete the tetramino
                goto_(board_posx + (posx + x)*2,board_posy + posy + y);
                WriteConsole(console, ANSI_code[0], 14, NULL, NULL);
            }
        }
    }
}
const void Tetris::draw_tetramino() {
    get_tetramino_highest_posy();
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                // we draw the projection
                goto_(board_posx + (posx + x) * 2, board_posy + highest_posy + y);
                WriteConsole(console, L"##", 2, NULL, NULL);
                // we draw the tetramino
                goto_(board_posx + (posx + x)*2, board_posy + posy + y);
                WriteConsole(console, ANSI_code[random_index_list[r_index] + 1], 14, NULL, NULL);
            }
        }
    }
}
const void Tetris::display_next_tetramino(int n) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetraminos[random_index_list[r_index + 1]][y][x] != 0) {
                goto_(next_tetra_posx + 3 + x * 2, next_tetra_posy + 2 + y);
                if (n == 1) {
                    WriteConsole(console, ANSI_code[random_index_list[r_index + 1] + 1], 14, NULL, NULL); // we write
                }
                else WriteConsole(console, ANSI_code[0], 14, NULL, NULL); // else we delete
            }
        }
    }
}
int Tetris::move_tetramino(int dirx, int diry) {
    if (!check_collision(current_tetramino, dirx, diry, posx, posy)) { // there is no collisions
        erase_tetramino(); //we delete the tetramino
        // we move it
        posx += dirx;
        posy += diry;
        draw_tetramino(); // we draw it
        return 0; // success there is no collision
    }
    return 1; // failure, collision detected
}
void Tetris::try_force_down() {
    timer += 50;
    timer = timer % (550 - level*50); 
    if (timer == 0 && move_tetramino(0, 1) != 0) { // reminder : if there is a collision move_tetramino return 1
        lock_tetramino();
    }
}
void Tetris::lock_tetramino() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                board[posx + x][posy + y] = current_tetramino[x][y];
            }
        }
    }
    try_break_line();// can we broke the line
    // we change the position of the tetramino because we want the next tetramino to appear at the top, in the middle. 
    posy = 0;
    posx = 4;
    display_next_tetramino(0); // we delete the tetramino projection
    r_index++; // we increment the random index
    set_tetramino(); // we choose the next tetramino
    if (check_collision(current_tetramino, 0, 0, posx, posy)) { // if there is a collision, we reset the board, the score and the level
        game_over();
    }
    display_board();  // we update the board
    draw_tetramino(); // we draw the tetramino
    display_next_tetramino(1); // we draw the tetramino projection
}
void Tetris::game_over() {
    create_board();
    display_counter(1, &score, score_text_posx + score_text_length, score_text_posy); // we delete
    display_counter(1, &level, level_text_posx + level_text_length, level_text_posy);
    score = 0;
    broke_line = 0;
    if (game_mode == 1) level = 1;
    display_broken_line_counter();
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy); // we write
    display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
    game_running = false;
    draw_pagga_text(1, game_state_text_posx, game_state_text_posy, game_state_text_length); // we set the game state on pause
}
void Tetris::check_input() {
    if (game_running) { // if the game is running we check the input
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            move_tetramino(-1, 0);
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            move_tetramino(1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            move_tetramino(0, 1);
        }
        if (!(GetAsyncKeyState(VK_UP) & 0x8000)) {
            is_key_up_pressed = false;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (!is_key_up_pressed) {
                rotate_tetramino();
                is_key_up_pressed = true;
            }
        }
        if (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { // entry key
            is_key_enter_pressed = false;
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // entry key
            if (!is_key_enter_pressed) {
                game_running = false;
                draw_pagga_text(1, game_state_text_posx, game_state_text_posy, game_state_text_length); // pause
                is_key_enter_pressed = true;
            }
        }
        if (!(GetAsyncKeyState(VK_SPACE) & 0x8000)) {
            is_key_space_bar_pressed = false;
        }

        if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
            if (!is_key_space_bar_pressed) {
                set_tetramino_highest_posy();
                is_key_space_bar_pressed = true;
            }
        }
    }
    else { // else we just check if the game restarts
        if (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { // entry key
            is_key_enter_pressed = false;
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // enter key
            if (!is_key_enter_pressed) {
                game_running = true;
                draw_pagga_text(2, game_state_text_posx, game_state_text_posy, game_state_text_length); // playing
                is_key_enter_pressed = true;
            }
        }
    }
}
void Tetris::rotate_tetramino() {
    // we check if there is no collisions at the future location
    int new_tetramino[4][4] = { 0 };
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            new_tetramino[x][y] = current_tetramino[y][3 - x];
        }
    }
    if (!check_collision(new_tetramino, 0, 0, posx, posy)) { // if there is no collisions we merge current_tetramino and new_tetramino
        erase_tetramino();
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                current_tetramino[x][y] = new_tetramino[x][y];
            }
        }
        draw_tetramino();
    }
}
void Tetris::try_break_line() {
    bool at_least_one_line_broken = false;
    int line_to_broke_list[4] = { 0 };
    int broke_line_ = 0;
    for (int y = 0; y < 4; y++) {
        if (posy + y < board_heigth - 1) { // execute that if we don't touch the bottom edge
            for (int x = 1; x < board_length - 1; x++) {
                if (board[x][posy + y] == 0) {
                    break; // there is an empty space, impossible to break the line, we check the next one
                }
                else if (x == board_length - 2) { // if x is the last of the line
                    at_least_one_line_broken = true;
                    line_to_broke_list[y] = posy + y;
                    broke_line_ ++;
                    broke_line ++; // we increment the counter
                    display_broken_line_counter();
                    if (broke_line % 10 == 0 && level < 10 && game_mode == 1) {
                        level ++;
                        display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
                    }
                }
            }
        }
        else break;
    }
    if (at_least_one_line_broken) {
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
        // we flash the line 3 times
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                if (line_to_broke_list[j] != 0) {
                    goto_(board_posx + 2, board_posy + line_to_broke_list[j]);
                    std::cout << std::string(board_length * 2 - 4, ' ');
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(25));
            display_board();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        // we reset the line
        for (int i = 0; i < 4; i++) {
            if (line_to_broke_list[i] != 0) {
                for (int x = 1; x < board_length - 1; x++) {
                    board[x][line_to_broke_list[i]] = 0;
                }
                display_board();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                move_board_down(line_to_broke_list[i]); // we move the board down
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
    add_score(broke_line_); // we add score
}
void Tetris::move_board_down(int line) {
    for (int y = 0; y < line - 1; y++) {
        for (int x = 1; x < board_length - 1; x++) {
            board[x][line - y] = board[x][line - y - 1]; // the top line is equal to the bottom line
        }
    }
    // we reset the first line because in all case it is equal to 0 when we move the board downwards
    for (int x = 1; x < board_length - 1; x++) {
        board[x][1] = 0;
    }
}
void Tetris::get_tetramino_highest_posy() {
    highest_posy = posy;
    while (1) {
        if (!check_collision(current_tetramino, 0, 1, posx, highest_posy)) highest_posy++;
        else break;
    }
}
void Tetris::set_tetramino_highest_posy(){
    erase_tetramino();
    posy = highest_posy;
    draw_tetramino();
    lock_tetramino();
}
const bool Tetris::is_game_running() {
    return game_running;
}
const void Tetris::draw_pagga_text(int n, int posx, int posy, int length) {
    for (int i = 0; i < pagga_font_heigth; i++) {
        goto_(posx, posy + i);
        WriteConsole(console, pagga_text[i][n], length, NULL, NULL);
    }
}
void Tetris::add_score(int score_) {
    switch (score_) {
    case 0:
        score += 10; // no line
        break;
    case 1:
        score += 100; // 1 line
        break;
    case 2:
        score += 300; // 2 lines
        break;
    case 3:
        score += 500; // 3 lines
        break;
    case 4: 
        score += 1000; // 4 lines (tetris)
        break;
    }
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy); // update the score
}
const void Tetris::display_counter(int n, int *var, int counter_posx, int counter_posy) {
    std::string text = std::to_string(*var);
    int num_posx = 0;
    int num_posy = 0;
    int pos = 0;
    for (int i = 0; i < text.length(); i++) {
        for (int j = 0; j < pagga_font_heigth; j++) {
            num_posx = counter_posx + i * numbers_length;
            num_posy = counter_posy + j;
            goto_(num_posx, num_posy);
            if (n == 0) {
                pos = text[i] - '0'; // convert character in integer
                WriteConsole(console, score_numbers_font[j][pos], numbers_length, NULL, NULL); // we write
            }
            else std::cout << "    "; // we delete
        }
    }
}
const void Tetris::display_broken_line_counter() {
    std::string counter = std::to_string(broke_line);
    goto_(broke_line_counter_posx, broke_line_counter_posy);
    std::cout << "\033[31m" << "BROKEN LINE: " << counter << "\033[0m";
}
const void Tetris::draw_tetris_logo() {
    for (int i = 0; i < tetris_logo_heigth; i++) {
        goto_(tetris_logo_posx, tetris_logo_posy + i);
        std::cout << tetris_text[i];
    }
}