#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

void print_point(Point p){
    cout << "(" << p.x << ", " << p.y << ")"<< endl;
}

vector<Point> create_point_lists(const vector<double>& xlist, const vector<double>& ylist){
    vector<Point> points;
    
    double x;
    double y;
    for (int i = 0; i < xlist.size(); ++i){
        if (i < ylist.size()){
           x = xlist[i];
        }
        else{
            x =  nan(" ");
        }

        if (i < xlist.size()){
           y = ylist[i];
        }
        else{
            y =  nan(" ");
        }
        
        points.push_back({x, y});
    }
    return points;
}

vector<vector<double>> split_point_fields(const vector<Point>& points){
    vector<double> xlist, ylist;
    for (auto i = 0u; i < points.size(); ++i){
        if (!isnan(points[i].x)) {
            xlist.push_back(points[i].x);
        }
        if (!isnan(points[i].y)) {
            ylist.push_back(points[i].y);
        }
    }

    vector<vector<double>> result{xlist, ylist};
    return result;
}

int main(){
    vector<double> xlist{1,2,3,5,67,8,12};
    vector<double> ylist{23,45,3,61,29.4};

    vector<Point> points = create_point_lists(xlist, ylist);
    cout << "Created Point Lists: " << endl;
    for (auto p: points){
        print_point(p);
    }
    cout << endl;

    vector<vector<double>> split = split_point_fields(points);
    for (auto s: split){
        if (s == split[0]){
            cout << "X: ";
        }
        else{
            cout << "Y: ";
        }
        for (auto n: s){
            cout << n << " ";
        }
        cout << endl;
    }
}