#include "tetris.hpp"

int main() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    Tetris tetris(console);  // instance de Tetris
    while (1){
        if (tetris.is_game_running()) { // si le jeu n'est pas sur pause
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            tetris.check_input();
            tetris.try_force_down();
        }
        else tetris.check_input(); // sinon on check input jusqu'à ce que le jeu reprenne
    }
    CloseHandle(console);
    return 0;
}