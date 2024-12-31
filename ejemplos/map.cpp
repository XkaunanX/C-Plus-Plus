#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    std::unordered_map<string, int> edad_map;

    edad_map["Juan"] = 25;
    edad_map["Maria"] = 30;
    edad_map["Pedro"] = 20;

    for (const auto& par : edad_map) {
        cout << par.first << " tiene " << par.second << " años." << endl;
    }

    return 0;
}
