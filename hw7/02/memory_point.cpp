#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

void print_point(Point p){
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}

Point* create_point_lists(const double* xlist, int xsize, const double* ylist, int ysize){
    int size = max(xsize, ysize);
    Point* points = new Point[size];
    
    for (int i = 0; i < size; ++i){
        double x = i < xsize ? xlist[i] : nan(" ");
        double y = i < ysize ? ylist[i] : nan(" ");
        points[i] = {x, y};
    }
    return points;
}

void delete_point_lists(Point* points){
    delete[] points;
}

double** split_point_fields(const Point* points, int size){
    double* xlist = new double[size];
    double* ylist = new double[size];
    int xcount = 0, ycount = 0;
    
    for (int i = 0; i < size; ++i){
        if (!isnan(points[i].x)) {
            xlist[xcount++] = points[i].x;
        }
        if (!isnan(points[i].y)) {
            ylist[ycount++] = points[i].y;
        }
    }

    double** result = new double*[2];
    result[0] = new double[xcount];
    result[1] = new double[ycount];
    copy_n(xlist, xcount, result[0]);
    copy_n(ylist, ycount, result[1]);

    delete[] xlist;
    delete[] ylist;

    return result;
}

void delete_point_fields(double** fields){
    delete[] fields[0];
    delete[] fields[1];
    delete[] fields;
}

int main(){
    double xlist[] = {1, 2, 3, 5, 67, 8, 12};
    double ylist[] = {23, 45, 3, 61, 29.4};
    int xsize = sizeof(xlist) / sizeof(double);
    int ysize = sizeof(ylist) / sizeof(double);

    Point* points = create_point_lists(xlist, xsize, ylist, ysize);
    cout << "Created Point Lists: " << endl;
    for (int i = 0; i < max(xsize, ysize); ++i){
        print_point(points[i]);
    }
    cout << endl;

    double** split = split_point_fields(points, max(xsize, ysize));
    for (int i = 0; i < 2; ++i){
        if (i == 0){
            cout << "X: ";
        }
        else{
            cout << "Y: ";
        }
        for (int j = 0; j < (i == 0 ? xsize : ysize); ++j){
            cout << split[i][j] << " ";
        }
        cout << endl;
    }

    delete_point_lists(points);
    delete_point_fields(split);
    return 0;
}
