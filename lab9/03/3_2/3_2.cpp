#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include <variant>
#include "nse/html.hpp"
using namespace std;
using namespace nse::html;

const string width = "500";
const string height = "500";
const string url = "http://www.w3.org/2000/svg";
const string stroke_color = "black";
const string stroke_width = "2";
const string fill_color = "none";

class Circle {
    private:
        double x;
        double y;
        double radius;
    public:
        Circle(double xx=50, double yy=50, double r=10) {
            x = xx;
            y = yy;
            radius = r;
        }

        Circle(istream& is) {
            is >> x >> y >> radius;
        }

        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        double getRadius() const {
            return radius;
        }

        double area() const {
            double area = 3.14 * radius * radius;
            return area;
        }

        void print(ostream& out) const {
            out << "[" << "Circle: (" << x << ", " << y << ", " << radius << ")]";
        }

        Element get_svg() const {
            auto attrs = Attribute_map{
                {"cx", to_string(x)},
                {"cy", to_string(y)},
                {"r", to_string(radius)},
                {"stroke", stroke_color},
                {"stroke-width", stroke_width},
                {"fill", fill_color}
            };
            
            return Element("circle", attrs, {});
        }
};

class Rectangle {
    private:
        double x;
        double y;
        double width;
        double height;
    public:
        Rectangle(double xx=45, double yy=45, double w=10, double h=10) {
            x = xx;
            y = yy;
            width = w;
            height = h;
        }

        Rectangle(istream& is) {
            is >> x >> y >> width >> height;
        }

        double getX() const {
            return x;
        }
        double getY() const {
            return y;
        }
        double getWidth() const {
            return width;
        }
        double getHeight() const {
            return height;
        }

        double area() const {
            double area = width * height;
            return area;
        }

        void print(ostream& out) const {
            out << "[" << "Rectangle: (" << x << ", " << y << ", " << width << ", " << height << ")]";
        }

        Element get_svg() const {
            auto attrs = Attribute_map{
                {"x", to_string(x)},
                {"y", to_string(y)},
                {"width", to_string(width)},
                {"height", to_string(height)},
            };
            
            return Element("rect", attrs, {});
        }
};

using Shape = std::variant<Circle, Rectangle>;

class Stream_writer: public nse::html::Writer {
    public:
        void write(std::string_view msg) const override;
        void write(const Element& e, int lv = 0) const override;

        Stream_writer(std::ostream& o): os(o) {}
    private:
        std::ostream& os;
};

void Stream_writer::write(std::string_view msg) const
{
    os << msg;
}

void Stream_writer::write(const Element& e, int lv) const
{
    e.write_to(*this, lv);
}


int main() {
    istringstream iss("C 50 50 15 R 40 40 20 20");
    
    vector<std::variant<Circle, Rectangle>> shapes;
    string shapeType;
    while (iss >> shapeType) {
        if (shapeType == "C") {
            shapes.emplace_back(Circle(iss));
        } else if (shapeType == "R") {
            shapes.emplace_back(Rectangle(iss));
        } else {
            cerr << "Unknown shape type: " << shapeType << endl;
        }
    }
    
    std::ofstream myfile;
    myfile.open ("test.svg");

    Stream_writer out(myfile);

    auto attrs1 = Attribute_map{
        {"width", width},
        {"height", height},
        {"xmlns", url}
    };
    vector<Element> svgShapes;
    for (auto& shape : shapes) {
        std::visit([&](auto& s) {
            svgShapes.push_back(s.get_svg());
        }, shape);
    }
    auto svg = Element("svg", attrs1, svgShapes);
    out.write(svg);
}
