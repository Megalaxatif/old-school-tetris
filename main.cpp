#include "tetris.hpp"

int main() {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    Tetris tetris(console);
    while (1){
        if (tetris.is_game_running()) { // if the game isn't paused
            std::this_thread::sleep_for(std::chrono::milliseconds(75));
            tetris.try_force_down();
        }
        tetris.check_input();
        if ((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_BACK) & 0x8000)) {
            std::cout << "\033[2J\033[1;1H"; // ANSI sequence to delete the console
            break;
        }
    }
    CloseHandle(console);
    return 0;
}