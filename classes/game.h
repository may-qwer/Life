#ifndef GAME_H
#define GAME_H

class Game {
public:
    int HEIGHT = 20;
    int WIDTH = 40;
    int COUNT_OF_GENS = 100;
    char **mtx_now;
    char **mtx_next;

    Game();

    ~Game();

    void show();

    void set_first_gen(int arr_of_cells[][2], int len_of_arr);

private:
    void set_next_gen(int x, int y);

    void clean_frame(int x, int y);

};

#endif