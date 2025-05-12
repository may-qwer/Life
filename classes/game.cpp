#include "game.h"
#include <iostream>
#include <unistd.h>
using namespace std;

Game::Game() {
    mtx_now = new char*[HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        mtx_now[i] = new char[WIDTH];
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            mtx_now[i][j] = '.';
        }
    }
    mtx_next = new char*[HEIGHT];
    for (int i = 0; i < HEIGHT; i++) {
        mtx_next[i] = new char[WIDTH];
    }
}

Game::~Game() {
    cout << "end" << endl;
}

void Game::show() {
    // y = 20 x = 40
    for (int t = 0; t < COUNT_OF_GENS; t++) {
        usleep(500000);
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                cout << mtx_now[y][x];
                if ((y > 0) && (y < HEIGHT - 1) && (x > 0) && (x < WIDTH - 1)) {
                    set_next_gen(x, y);
                }
                clean_frame(x, y);
            }
            cout << endl;
        }
    from_next_to_now();
    }
}

void Game::set_first_gen(int arr_of_cells[][2], int len_of_arr) {
    for (int i = 0; i < len_of_arr; i++) {
        mtx_now[arr_of_cells[i][0]][arr_of_cells[i][1]] = '#';
    }
}

void Game::clean_frame(int x, int y) {
    if ((x == 0) || (y == 0) || (x == WIDTH - 1) || (y = HEIGHT - 1)) {
        mtx_next[y][x] = '.';
    }
}

void Game::set_next_gen(int x, int y) {
    int k = 0;
    for (int i = -1; i <= 1; i ++ ) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0)) {
                if (mtx_now[y+j][x+i] == '#') {
                    k++;
                }
            }
        }
    }
    if (k == 3 && mtx_now[y][x] == '.') {
        mtx_next[y][x] = '#';
    } else if ((k == 2 || k == 3) && mtx_now[y][x] == '#') { 
        mtx_next[y][x] = '#';
    } else if ((k < 2 || k > 3) && mtx_now[y][x] == '#') {
        mtx_next[y][x] = '.';
    } else {
        mtx_next[y][x] = '.';
    }
}

void Game::from_next_to_now() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            mtx_now[y][x] = mtx_next[y][x];
        }
    }
}