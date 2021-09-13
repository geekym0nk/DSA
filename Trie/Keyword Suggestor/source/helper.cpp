#include "helper.h"

void displayMenu() {
    cout << endl;
    cout << "============================" << endl;
    cout << "Select what you wish to do -" << endl;
    cout << "----------------------------" << endl;
    cout << "1 - Create a new Dictionary (deletes existing)" << endl;
    cout << "2 - Add a new word to the dictionary" << endl;
    cout << "3 - Check if a word exists" << endl;
    cout << "4 - Delete a word" << endl;
    cout << "5 - Delete entire dictionary" << endl;
    cout << "0 - QUIT MENU" << endl;
    cout << "============================" << endl;
    cout << endl;
}

bool processResp(char c) {
    if ((c == 'y') ||
        (c == 'Y'))
        return true;

    return false;
}



