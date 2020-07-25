
#include "SniperCommander.hpp"
#include <vector>
#include <math.h>
#include "Sniper.hpp"


void SniperCommander::Fight(vector<vector<Soldier *>> &board, pair<int, int> dest) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            Soldier *s = board[i][j];
            if (s != nullptr) {
                if (Sniper *fs = dynamic_cast<Sniper *> (s)) {

                    SniperCommander *fc = dynamic_cast<SniperCommander *> (s);
                    if ((fc == nullptr) || (i == dest.first && j == dest.second)) {
                        if (fs->getnum() == board[dest.first][dest.second]->getnum()) {
                            fs->Sniper::Fight(board, make_pair(i, j));

                        }
                    }


                }
            }
        }
    }}
