#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

struct Player {
    string name;
    vector<int> scores;
};

int max_score(const Player &player) {
    return *max_element(player.scores.begin(), player.scores.end());
}

int min_score(const Player &player) {
    return *min_element(player.scores.begin(), player.scores.end());
}

double avg_score(const Player &player) {
    return accumulate(player.scores.begin(), player.scores.end(), 0.0) / player.scores.size();
}