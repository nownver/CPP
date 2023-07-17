#include <string>
class City {
public:
std::string name() { return n; }
double temperature() { return temp; }
City()
{
n = "Unknown";
temp = 0.0;
}
City(double t);
private:
std::string n;
double temp;
};

City::City(double t)
: n("Unknown"), temp{} {}

