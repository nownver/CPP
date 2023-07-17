#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <tuple>
#include <algorithm>
#include <numeric>

std::vector<double> read_vector(std::string line) {
    std::vector<double> v;
    std::istringstream iss(line);
    double num;
    while (iss >> num) {
        v.push_back(num);
    }
    return v;
}

std::tuple<std::vector<double>, std::vector<double>, std::vector<double>> read_file(std::string file_name) {
    std::ifstream infile(file_name);
    std::string a, b, c;
    std::getline(infile, a, ';');
    std::getline(infile, b, ';');
    std::getline(infile, c);

    return std::make_tuple(read_vector(a), read_vector(b), read_vector(c));
}

void print_vector(const std::vector<double>& v) {
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

double calculate_average(const std::vector<double>& v) {
    return std::accumulate(v.begin(), v.end(), 0.0) / v.size();
}

std::vector<std::tuple<double, double, double>> generate_cartesian(const std::vector<double>& v1, const std::vector<double>& v2, const std::vector<double>& v3) {
    std::vector<std::tuple<double, double, double>> result;
    for (auto elem1 : v1) {
        for (auto elem2 : v2) {
            for (auto elem3 : v3) {
                result.emplace_back(elem1, elem2, elem3);
            }
        }
    }
    return result;
}

int main() {
    auto [v1, v2, v3] = read_file("data.txt");

    std::cout << std::fixed << std::setprecision(2) << calculate_average(v1) << ' ' << calculate_average(v2) << ' ' << calculate_average(v3) << std::endl;

    auto cartesian = generate_cartesian(v1, v2, v3);
    std::for_each(cartesian.begin(), cartesian.end(), [](const auto& t){
        std::cout << '(' << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << "), ";
    });
    std::cout << std::endl;

    return 0;
}
