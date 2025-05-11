#include <iostream>
#include "./classes/game.h"

using namespace std;

int main() {
    int len_of_arr = 5;
    int arr[len_of_arr][2] = {{4, 6}, {4, 7}, {4, 8}, {3, 8}, {2, 7}};
    int len_of_arr2 = 3;
    int arr2[len_of_arr2][2] = {{3, 15}, {3, 16}, {3, 17}};
    Game game;
    game.set_first_gen(arr, len_of_arr);
    game.set_first_gen(arr2, len_of_arr2);
    game.show();

    return 0;
}