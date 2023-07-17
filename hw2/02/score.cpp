#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include "score_function.hpp"

using namespace std;

int main() {
    vector<Player> players;
    string input;

    while (true) {
        getline(cin, input);
        if (input.empty()) {
            break;
        }

        istringstream iss(input);
        string player_name;
        iss >> player_name;

        players.push_back({player_name, {}});

        int score;
        while (iss >> score) {
            players.back().scores.push_back(score);
        }
    }

    vector<pair<string, int>> max_scores;
    for (auto &player : players) {
        max_scores.push_back({player.name, max_score(player)});
    }

    sort(max_scores.begin(), max_scores.end(), [](auto &p1, auto &p2) {
        if (p1.second != p2.second) {
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    });

    int max = 0;
    for (int i = 0; i < players.size(); i++){
        if (players[i].name.size() >= max){
            max = players[i].name.size();
        }
    }
    
    vector<pair<string, int>> min_scores;
    for (auto &player : players) {
        min_scores.push_back({player.name, min_score(player)});
    }

    sort(min_scores.begin(), min_scores.end(), [](auto &p1, auto &p2) {
        if (p1.second != p2.second) {
            return p1.second > p2.second;
        }
        return p1.first > p2.first;
    });

    vector<pair<string, double>> avg_scores;
    
    for (auto &player : players) {
        avg_scores.push_back({player.name, avg_score(player)});
    }

    sort(avg_scores.begin(), avg_scores.end(), [](auto &p1, auto &p2) {
        if (p1.second != p2.second) {
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    });

    cout << "Max Score Rankings" << endl;
    int rank = 1;
    for (auto &p : max_scores) {
        cout << left << rank << ". " << setw(max)<< p.first << " " << p.second << endl;
        rank++;
    }

    cout << "Min Score Rankings" << endl;
    rank = 1;
    for (auto &p : min_scores) {
        cout << left << rank << ". " << setw(max)<< p.first << " " << p.second << endl;
        rank++;
    }

    cout << "Average Score Rankings" << endl;
    rank = 1;
    for (auto &p : avg_scores) {
        cout << left << rank << ". " << setw(max)<< p.first << " " << p.second << endl;
        rank++;
    }

    return 0;
}
