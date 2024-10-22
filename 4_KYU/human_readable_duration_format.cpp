#include <iostream>
#include <string>

using namespace std;
const int YEAR = 31536000;
const int DAY = 86400;
const int HOUR = 3600;
const int MINUTE = 60;

std::string format_duration(int seconds) {
    int components[] = {0,0,0,0,0};
    int n_components = 0;
    string result = "";

    if(seconds >= YEAR) {
        components[0] = seconds/YEAR;
        seconds = seconds%YEAR;
        ++n_components;
    }
    if(seconds >= DAY) {
        components[1] = seconds/DAY;
        seconds = seconds%DAY;
        ++n_components;
    }
    if(seconds >= HOUR) {
        components[2] = seconds/HOUR;
        seconds = seconds%HOUR;
        ++n_components;
    }
    if(seconds >= MINUTE) {
        components[3] = seconds/MINUTE;
        seconds = seconds%MINUTE;
        ++n_components;
    }
    if(seconds > 0) {
        components[4] = seconds;
        ++n_components;
    }

    if(n_components == 0) {
        return "now";
    }

    for(int i = 0; i < 5; i++) {
        if(components[i] > 0) {
            result = result + to_string(components[i]) + " ";
            switch(i) {
                case 0: result = result + "year"; break;
                case 1: result = result + "day"; break;
                case 2: result = result + "hour"; break;
                case 3: result = result + "minute"; break;
                case 4: result = result + "second"; break;
            }
            if(components[i] > 1) {
                result = result + "s";
            }
            if(n_components == 2) {
                result = result + " and ";
            }
            if(n_components > 2) {
                result = result + ", ";
            }
            --n_components;
        }
    }
    
    return result;
}

int main () {
    cout << format_duration(8641);
    return 0;
}