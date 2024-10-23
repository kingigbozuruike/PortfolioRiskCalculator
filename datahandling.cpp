#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<double> readData(const string& filename) {
    vector<double> data;
    ifstream file(filename);
    
    // The condition should check if the file is open
    if (file.is_open()) {
        string line;
        // Read the file line by line and convert to double
        while (getline(file, line)) {
            data.push_back(stod(line));
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
    return data;
}

double average(const vector<double>& data) {
    double sum = 0.0;
    for (double value : data) {
        sum += value;
    }
    return data.empty() ? 0 : sum / data.size();
}

double volatility(const vector<double>& data, double average) {
    double sum = 0.0;
    for (double value : data) {
        sum += (value - average) * (value - average);
    }
    return data.empty() ? 0 : sqrt(sum / data.size());
}

int main() {
    string filename = "data.csv";
    vector<double> stockPrices = readData(filename);

    cout << "Read " << stockPrices.size() << " data points." << endl;

    double averagePrice = average(stockPrices);
    cout << "Average Stock price: " << averagePrice << endl;

    double vol = volatility(stockPrices, averagePrice);
    cout << "Volatility (Standard Deviation): " << vol << endl;

    return 0;
}
