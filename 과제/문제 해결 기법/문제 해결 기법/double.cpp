#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == string::npos || last == string::npos)
        return "";
    return str.substr(first, (last - first + 1));
}

int calculatePrecision(const string& number) {
    auto decimalPos = number.find('.');
    if (decimalPos == string::npos) return 0;
    int count = 0;
    for (size_t i = decimalPos + 1; i < number.length(); i++) {
        if (isdigit(number[i])) count++;
    }
    return count;
}

long double computeResult(const string& lhs, const string& rhs, char op) {
    long double left = stold(lhs);
    long double right = stold(rhs);

    switch (op) {
    case '+': return left + right;
    case '-': return left - right;
    case '*': return left * right;
    case '/': return left / right;
    default:
        cerr << "Invalid operator: " << op << endl;
        exit(1);
    }
}

int main() {
    ifstream fin("double.inp");
    ofstream fout("double.out");

    if (!fin.is_open()) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    int numExpressions;
    fin >> numExpressions;
    fin.ignore();

    string expression;
    for (int i = 0; i < numExpressions; ++i) {
        getline(fin, expression);
        expression = trim(expression);

        size_t space1 = expression.find(' ');
        size_t space2 = expression.rfind(' ');

        string lhs = expression.substr(0, space1);
        char op = expression[space1 + 1];
        string rhs = expression.substr(space2 + 1);

        long double result = computeResult(lhs, rhs, op);
        int precision = max(calculatePrecision(lhs), calculatePrecision(rhs));

        if (op == '/') {
            fout << static_cast<long long>(result) << endl;
        }
        else {
            if (result == floor(result)) {
                fout << static_cast<long long>(result) << '\n';
            }
            else {
                stringstream ss;
                ss << fixed << setprecision(precision) << result;
                string res = ss.str();
                res.erase(res.find_last_not_of('0') + 1, string::npos);
                if (res.back() == '.') res.pop_back();
                fout << res << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}
