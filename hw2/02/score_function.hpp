#ifndef SCORE_HPP
#define SCORE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

struct Player {
    std::string name;
    std::vector<int> scores;
};

int max_score(const Player &player);
int min_score(const Player &player);
double avg_score(const Player &player);

#endif 