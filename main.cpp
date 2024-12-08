#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

//Function to process the input according to threshold and limit
double processInput(const double& threshold, const double& limit, vector<double>& result) {
    string line;
    double sum = 0.0;
    bool flag = false;
    while (getline(cin, line)) {
        try {
            double value = stod(line);
            if(flag == true) {          //check if limit has reached then just insert 0.0 and continue
                result.push_back(0.0);
                continue;
            }
            double changedValue = max(0.0, value - threshold);

            if (sum + changedValue > limit) {
                changedValue = max(0.0, limit - sum);
            }

            result.push_back(changedValue);
            sum += changedValue;

            if (sum >= limit) flag = true;  // limit has reached
        }
        
        catch (const invalid_argument&) {
            cerr << "Invalid input encountered: " << line << endl;
            throw;
        }
    }

    return sum;
}

//Function to print the output
void printOutput(const vector<double>& result) {
    cout << fixed << setprecision(1);
    for (double val : result) {
        cout << val << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " <threshold> <limit>\n";
        return 1;
    }

    try {
        double threshold = stod(argv[1]);
        double limit = stod(argv[2]);
        vector<double> result;

        double sum = processInput(threshold, limit, result);
        result.push_back(sum);          // Add the sum as the last entry to vector
        printOutput(result);
    }
    catch (const exception&) {
        return 1;
    }

    return 0;
}
