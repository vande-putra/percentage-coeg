#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <thread>

using namespace std;

void percent(ostream& os, int time ,string message, char symbol){
    static const auto barLength = 70;
    if (message.length() <= barLength){
        os << message << "\n";
        message.clear();
    }
    else {
        message = message + " ";
    }

    const auto progress = 100.0 /barLength - message.length();

    cout << message;
    for(double percentage = 0; percentage <= 101; percentage += progress){
        message += symbol;
        os << "\r (" <<  setw(3) << static_cast<int>(percentage) << "% ) " << message << flush;
        this_thread::sleep_for(chrono::milliseconds(time));

    }
    os << endl << endl;

}


int main(){
    char loop;
    do{
      percent(clog, 100 ,"Percent\n", '+');
      cout << "Wanna try again ? y/n ";
      cin >> loop;
    } while (loop == 'y');
    cout << "Out of the program";
    return 0;

}
