#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class ChartGenerator {
    public:
        virtual void generate_chart(std::string filename, int num_values, int values[], std::string colors[]) = 0;
};

class BarChartGenerator : public ChartGenerator {
    public:
        void generate_chart(std::string filename, int num_values, int values[], std::string colors[]) {
            std::ofstream outfile(filename + ".html");

            // Title
            outfile << "<html>\n<head>\n<title>" << "Bar Chart" << "</title>\n</head>\n<body>\n";
            outfile << "<h2 style=\"text-align:center;\">" << "Bar Chart" << "</h2>\n";

            // Bar Chart
            outfile << "<div style=\"margin: 0 auto; width: " << 60 * num_values << "px;\">\n";
            for (int i = 0; i < num_values; i++) {
                outfile << "<div style=\"position: relative; background-color: " << colors[i] << "; height: " << values[i] << "px; width: 50px; display: inline-block; margin: 5px 0;\">\n";
                outfile << "<span style=\"position: absolute; top: 0; left: 0; right: 0; bottom: 0; text-align: center; line-height: " << values[i] << "px;\">" << values[i] << "</span>\n";
                outfile << "</div>\n";
            }
            outfile << "</div>\n";

            // Legends
            outfile << "<div style=\"margin: 0 auto; width: " << 60 * num_values << "px;\">\n";
            for (int i = 0; i < num_values; i++) {
                outfile << "<div style=\"width: 50px; display: inline-block; text-align: center;\">" << colors[i] << "</div>\n";
            }
            outfile << "</div>\n";

            outfile << "</body>\n</html>";

            outfile.close();
            std::cout << "Bar chart generated in " << filename << ".html" << std::endl;
        }
};

class PieChartGenerator : public ChartGenerator {
    public:
        void generate_chart(std::string filename, int num_values, int values[], std::string colors[]) {
            std::ofstream outfile(filename + ".html");

            // Title
            outfile << "<html>\n<head>\n<title>" << "Pie Chart" << "</title>\n</head>\n<body>\n";
            outfile << "<h2 style=\"text-align:center;\">" << "Pie Chart" << "</h2>\n";

            // Pie Chart
            outfile << "<div style=\"margin: 0 auto; display: flex; justify-content: center; px;\">\n";
            outfile << "<svg width=\"500\" height=\"500\">\n";
            double total_value = 0.0;
            for (int i = 0; i < num_values; i++) {
                total_value += values[i];
            }
            double angle = -90.0; // start at 12 o'clock
            for (int i = 0; i < num_values; i++) {
            outfile << "<div style=\"width: 50px; display: inline-block; text-align: center;\">" << colors[i] << "</div>\n";
            }
            outfile << "</div>\n";

            outfile << "</body>\n</html>";

            outfile.close();
            cout << "Bar chart generated in " << filename << ".html" << endl;
        }
};

class LineChartGenerator : public ChartGenerator {
    public:

        void generate_chart(string filename, int num_points, int y_values[], string line_color) override{
            ofstream outfile(filename + ".html");

            // Title
            outfile << "<html>\n<head>\n<title>" << "Line Graph" << "</title>\n</head>\n<body>\n";
            outfile << "<h2 style=\"text-align:center;\">" << "Line Graph" << "</h2>\n";

            double y_min = y_values[0], y_max = y_values[0];
            for (int i = 1; i < num_points; i++) {
                if (y_values[i] < y_min) y_min = y_values[i];
                if (y_values[i] > y_max) y_max = y_values[i];
            }

            int canvas_width = 600, canvas_height = 400;
            int margin_top = 50, margin_right = 50, margin_bottom = 50, margin_left = 80;

            double y_scale = (canvas_height - margin_top - margin_bottom) / (y_max - y_min);

            // Graph
            outfile << "<div style=\"margin: 0 auto; display: flex; justify-content: center; px;\">\n";
            outfile << "<svg width=\"" << canvas_width << "\" height=\"" << canvas_height << "\">\n";
            outfile << "<rect x=\"" << margin_left << "\" y=\"" << margin_top << "\" width=\"" 
                    << canvas_width - margin_left - margin_right << "\" height=\"" 
                    << canvas_height - margin_top - margin_bottom << "\" fill=\"none\" stroke=\"black\"/>\n"; // draw the axes box
            
            // Y-Axis
            for (int i = 0; i <= 10; i++) {
                double y_value = y_min + (i * (y_max - y_min) / 10);
                double y_pos = canvas_height - margin_bottom - (y_value - y_min) * y_scale;
                outfile << "<text x=\"" << (margin_left - 5) << "\" y=\"" << y_pos << "\" style=\"text-anchor: end; dominant-baseline: middle;\">" << y_value << "</text>\n";
                outfile << "<line x1=\"" << margin_left << "\" y1=\"" << y_pos << "\" x2=\"" << (canvas_width - margin_right) << "\" y2=\"" << y_pos << "\" stroke-dasharray=\"5,5\" stroke=\"#ccc\"/>\n";
            }

            // X-Axis
            for (int i = 0; i < num_points; i++) {
                double x = margin_left + i * ((canvas_width - margin_left - margin_right) / (num_points - 1));
                outfile << "<text x=\"" << x << "\" y=\"" << (canvas_height - margin_bottom + 20) << "\" style=\"text-anchor: middle; dominant-baseline: middle;\">" << i << "</text>\n";
            }
            
            // Line
            outfile << "<path fill=\"none\" stroke=\"" << line_color << "\" d=\""; // start the line path
            for (int i = 0; i < num_points; i++) {
                double x = margin_left + i * ((canvas_width - margin_left - margin_right) / (num_points - 1));
                double y = canvas_height - margin_bottom - (y_values[i] - y_min) * y_scale;
                if (i == 0) outfile << "M " << x << " " << y; // move to the first point
                else outfile << " L " << x << " " << y; // draw a line to the next point
            }
            outfile << "\"/>\n"; // end the line path
            outfile << "</svg>\n";

            outfile << "</body>\n</html>";

            outfile.close();
            cout << "Line graph generated in " << filename << ".html" << endl;
        }
};


int main() {
    string chart_type;
    cout << "Chart type: ";
    cin >> chart_type;

    int num_values;
    cout << "Number of values: ";
    cin >> num_values;

    int values[num_values];
    string names[num_values];
    string colors[num_values];
    string color;
    if(chart_type == "line"){
        cout << "Enter color: ";
        cin >> color;
    }
    for (int i = 0; i < num_values; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> values[i];
        
        if(chart_type != "line"){
            cout << "Enter color " << i + 1 << ": ";
            cin >> colors[i];
        }
    }

    string filename;
    cout << "Filename: ";
    cin >> filename;

    if(chart_type == "bar"){
        BarChartGenerator chart_1;
        chart_1.generate_chart(filename, num_values, values, colors);
    }
    else if(chart_type == "pie"){
        PieChartGenerator chart_2;
        chart_2.generate_chart(filename, num_values, values, colors);
    }
    // else if(chart_type == "line"){
    //     LineChartGenerator chart_3a;
    //     chart_3a.generate_chart(filename, num_values, values, color);
    // }

    return 0;
}