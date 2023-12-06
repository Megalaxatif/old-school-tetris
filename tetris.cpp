#include "tetris.hpp"
/*
* 
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
1 pièce posée = 10 points
1 ligne cassée = 100 points
2 ligne = 300
3 lignes = 500
4 lignes (tetris) = 1000
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
    L"\033[37;1m██\033[0m"  // bordure
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
    game_mode = 1; // normal mode par défaut
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
    board_posx = tetris_logo_length/2 - board_length + tetris_logo_posx; // on centre le tableau sur le logo tetris
    board_posy = tetris_logo_heigth + tetris_logo_posy + 1;
    next_tetra_posx = board_posx + board_length + 15;
    next_tetra_posy = board_posy + 1;
    score_text_length = 24;
    score_text_posx = 15 + board_posx + board_length;
    score_text_posy = board_posy + 10;
    level_text_length = 23;
    level_text_posx = score_text_posx; // alligné avec le score
    level_text_posy = score_text_posy + 5;
    game_state_text_length = 28;
    game_state_text_posx = score_text_posx; // alligné avec le score
    game_state_text_posy = score_text_posy + 10;
    pagga_font_heigth = 3;
    numbers_length = 4;
    score = 0;
    broke_line = 0;
    broke_line_counter_posx = board_posx;
    broke_line_counter_posy = board_posy - 1;
    timer = 0;
    r_index = 0;
    random_index_list[9] = rand() % 7; // on initialise la derniere valeur
    is_key_up_pressed = false;
    is_key_enter_pressed = true;
    game_running = false;
    is_key_space_bar_pressed = false;
    srand(std::time(nullptr)); // graine aléatoire
    //___Game_starting___
    draw_tetris_logo();
    create_board(); // créer le tableau de jeu
    display_board();
    display_next_tetramino_board();
    get_random_index_list();
    set_tetramino();
    draw_tetramino();
    display_next_tetramino(1);
    draw_pagga_text(0, score_text_posx, score_text_posy, score_text_length); // affichage du score
    draw_pagga_text(3, level_text_posx, level_text_posy, level_text_length); // affichage du level
    draw_pagga_text(1, game_state_text_posx, game_state_text_posy, game_state_text_length); // affichage de l'état du jeu
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
    random_index_list[0] = random_index_list[9]; // on initialise la première valeur à la dernière de l'ancienne liste qui n'a pas pu être affichée
    while (i < 10){
        index = rand() % 7;
        if (random_index_list[i - 1] != index) {
            random_index_list[i] = index;
            i++;
        }
    }
}
void Tetris::set_tetramino() {
    if ((r_index + 1) == 10) { // check si on peut réinitialiser à 0
        r_index = 0;
        get_random_index_list(); // regénérer la liste d'index
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            current_tetramino[j][i] = tetraminos[random_index_list[r_index]][i][j]; // assigne le tetramino
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
            std::cin.clear(); // on efface l'entrée invalide
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // on ignore les caractères source de l'erreur
            std::cout << "Please type a valid number: ";
        }
    }
    std::cout << "\033[2J\033[1;1H"; // séquence d'échappement ANSI pour effacer la console
}
void Tetris::create_board() {
    for (int y = 0; y < board_heigth; y++) {
        for (int x = 0; x < board_length; x++) {
            board[x][y] = 0; // on initialise toutes les valeurs à 0
            board[0][y] = board[board_length - 1][y] = board[x][0] = board[x][board_heigth - 1] = 8; // on initialise tout les cotés à 8 (nombre représentatif des cotés de la grille)
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
    goto_(tetris_logo_posx, tetris_logo_posy + tetris_logo_heigth + board_heigth + 2);
    WriteConsole(console, L"Move with ← ↓ →    Rotate with ↑    Switch pause/playing with entry    Set the piece down with the space bar", 108, NULL, NULL);
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
                return true; // collision détectée
            }
        }
    }
    return false; // pas de colision à la fin de la boucle
}
const void Tetris::erase_tetramino() {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (current_tetramino[x][y] != 0) {
                // on efface la projection
                goto_(board_posx + (posx + x) * 2, board_posy + highest_posy + y);
                WriteConsole(console, L"  ", 2, NULL, NULL);
                // on efface le tetramino
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
                // on affiche la projection
                goto_(board_posx + (posx + x) * 2, board_posy + highest_posy + y);
                WriteConsole(console, L"##", 2, NULL, NULL);
                // on affiche le tetramino
                goto_(board_posx + (posx + x)*2, board_posy + posy + y);
                WriteConsole(console, ANSI_code[random_index_list[r_index] + 1], 14, NULL, NULL);
            }
        }
    }
}
const void Tetris::display_next_tetramino(int n) {
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (tetraminos[random_index_list[r_index + 1]][y][x] != 0) { // pourquoi est ce qu'on doit mettre y x et pas x y ?
                goto_(next_tetra_posx + 3 + x * 2, next_tetra_posy + 2 + y);
                if (n == 1) {
                    WriteConsole(console, ANSI_code[random_index_list[r_index + 1] + 1], 14, NULL, NULL); // on ecrit
                }
                else WriteConsole(console, ANSI_code[0], 14, NULL, NULL); // sinon on efface
            }
        }
    }
}
int Tetris::move_tetramino(int dirx, int diry) {
    if (!check_collision(current_tetramino, dirx, diry, posx, posy)) { //si il n'y a pas de collision
        erase_tetramino(); //on efface le tetramino
        // on déplace le tetramino
        posx += dirx;
        posy += diry;
        draw_tetramino(); // on dessine le tetramino
        return 0; // succés, pas de collision
    }
    return 1; // echec, collision
}
void Tetris::try_force_down() {
    timer += 50;
    timer = timer % (550 - level*50); 
    if (timer == 0 && move_tetramino(0, 1) != 0) { // si il y a une colision move_tetramino return 1
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
    try_break_line();// est ce qu'on peu casser la ligne
    // on change la position du tetramino pour que le prochain apparaisse en haut au millieu
    posy = 0;
    posx = 4;
    display_next_tetramino(0); // on efface l'ancien next tetramino
    r_index++; // on incrémente le random_index
    set_tetramino(); // on choisit le nouveau tetramino
    if (check_collision(current_tetramino, 0, 0, posx, posy)) { // si il y a une colision on réinitialise le tableau, on réinitialise le score et le niveau
        game_over();
    }
    display_board();  // on actualise le tableau
    draw_tetramino(); // on affiche le tetramino
    display_next_tetramino(1); // on dessine le prochain tetramino
}
void Tetris::game_over() {
    create_board();
    display_counter(1, &score, score_text_posx + score_text_length, score_text_posy); // on efface
    display_counter(1, &level, level_text_posx + level_text_length, level_text_posy);
    score = 0;
    broke_line = 0;
    if (game_mode == 1) level = 1;
    display_broken_line_counter();
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy); // on ecrit
    display_counter(0, &level, level_text_posx + level_text_length, level_text_posy);
    game_running = false;
    draw_pagga_text(1, game_state_text_posx, game_state_text_posy, game_state_text_length); // on actualise le l'état du jeu sur pause
}
void Tetris::check_input() {
    if (game_running) { // si le jeu tourne on check les inputs
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
            move_tetramino(-1, 0);
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
            move_tetramino(1, 0);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
            move_tetramino(0, 1);
        }
        if (!(GetAsyncKeyState(VK_UP) & 0x8000)) { // si la touche est relachée avec le "!"
            is_key_up_pressed = false;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000) {
            if (!is_key_up_pressed) {
                rotate_tetramino();
                is_key_up_pressed = true;
            }
        }
        if (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { // touche entrée
            is_key_enter_pressed = false;
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // touche entrée
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
    else { // sinon on check juste si le joueur reprend le jeu
        if (!(GetAsyncKeyState(VK_RETURN) & 0x8000)) { // touche entrée
            is_key_enter_pressed = false;
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000) { // touche entrée
            if (!is_key_enter_pressed) {
                game_running = true;
                draw_pagga_text(2, game_state_text_posx, game_state_text_posy, game_state_text_length); // playing
                is_key_enter_pressed = true;
            }
        }
    }
}
void Tetris::rotate_tetramino() {
    // on check si le tetramino peut faire la rotation (si il n'y a pas de collision au futur emplacement)
    int new_tetramino[4][4] = { 0 };
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            new_tetramino[x][y] = current_tetramino[y][3 - x];
        }
    }
    if (!check_collision(new_tetramino, 0, 0, posx, posy)) { // si il n'y a pas de collision on fusionne current_tetramino et new_tetramino
        erase_tetramino();
        for (int y = 0; y < 4; y++) {
            for (int x = 0; x < 4; x++) {
                current_tetramino[x][y] = new_tetramino[x][y];
            }
        }
        draw_tetramino();
    }
}
//  veritable oeuvre d'art
void Tetris::try_break_line() {
    bool at_least_one_line_broken = false;
    int line_to_broke_list[4] = { 0 };
    int broke_line_ = 0;
    for (int y = 0; y < 4; y++) {
        if (posy + y < board_heigth - 1) { // execute si on ne touche pas la bordure inférieure
            for (int x = 1; x < board_length - 1; x++) {
                if (board[x][posy + y] == 0) {
                    break; // il y a un espace vide donc impossible de casser la ligne on teste la ligne suivante
                }
                else if (x == board_length - 2) { // si x est le dernier de la ligne
                    at_least_one_line_broken = true;
                    line_to_broke_list[y] = posy + y;
                    broke_line_ ++;
                    broke_line ++; // on incrémente le compteur
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
        // on fait clignoter la ligne 3 fois
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
        // on réinitialise la ligne
        for (int i = 0; i < 4; i++) {
            if (line_to_broke_list[i] != 0) {
                for (int x = 1; x < board_length - 1; x++) {
                    board[x][line_to_broke_list[i]] = 0;
                }
                display_board();
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                move_board_down(line_to_broke_list[i]); // on fait descendre le tableau
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }
    add_score(broke_line_); // on ajoute le score
}
void Tetris::move_board_down(int line) {
    for (int y = 0; y < line - 1; y++) {
        for (int x = 1; x < board_length - 1; x++) {
            board[x][line - y] = board[x][line - y - 1]; // la ligne du dessous est égale à la ligne du dessus
        }
    }
    // on réinitialise la premiere ligne car dans tout les cas elle est égale à 0 quand on fait descendre le tableau
    for (int x = 1; x < board_length - 1; x++) {
        board[x][1] = 0;
    }
}
void Tetris::get_tetramino_highest_posy() {
    highest_posy = posy + 0;
    while (1) {
        if (!check_collision(current_tetramino, 0, 1, posx, highest_posy)) highest_posy++;
        else break;
    }
}
void Tetris::set_tetramino_highest_posy(){
    //get_tetramino_highest_posy();
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
        score += 10; // aucune ligne
        break;
    case 1:
        score += 100; // 1 ligne
        break;
    case 2:
        score += 300; // 2 lignes
        break;
    case 3:
        score += 500; // 3 lignes
        break;
    case 4: 
        score += 1000; // 4 lignes (tetris)
        break;
    }
    display_counter(0, &score, score_text_posx + score_text_length, score_text_posy); // on actualise l'affichage
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
                pos = text[i] - '0'; // on converti le caractère en entier
                WriteConsole(console, score_numbers_font[j][pos], numbers_length, NULL, NULL); // on ecrit
            }
            else std::cout << "    "; // on efface
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