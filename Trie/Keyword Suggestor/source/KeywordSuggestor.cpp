#include "Dictionary.h"
#include "helper.h"

int main(){

    Dictionary *newDict = new Dictionary();
    short inp = -1;
    string str;
    char resp = 'n';
    auto resetInp = [&inp] {inp = -1;};
    auto dictPresent = [&newDict] {return (newDict != NULL);};

    /* Display Menu and get Input */
    while  (inp != 0){
        if (inp == -1) 
        {
            displayMenu();
            cin >> inp;
        }
        else 
        {
            if (inp == 0) 
            {
                break;
            }
            else if (inp == 1)
            {
                /* Overwrite the dictionary */
                resp = 'n';

                cout << "Are you sure, you want to overwrite the dictionary?" << endl;
                cin >> resp;

                if (!processResp(resp)) {
                    resetInp();
                    continue;
                }
                
                newDict = NULL;

                newDict = new Dictionary();

                if (dictPresent()) {
                    cout << "Dictionary overwritten." << endl;
                }

                resetInp();
            }
            else if (inp == 2) 
            {
                 /* Add a word to dictionary */
                str.clear();

                if (!dictPresent()) {
                    cout << "Dictionary doesn't exists." << endl;
                    resetInp();
                    continue;
                }

                cout << "Enter the word you wish to add to dictionary (To Stop enter the number 0)" << endl;
                cin >> str; 

                while (str != "0")
                {
                    if (newDict->addWord(str))
                    {
                        cout << "Word \"" << str << "\" added successfully" << endl;
                    }
                    else
                    {
                        cout << "There was some problem adding that word, please retry.." << endl;
                    }

                    cout << "Enter the word you wish to add to dictionary (To Stop enter the number 0)" << endl;                    
                    cin >> str;
                }

                resetInp();
            }
            else if (inp == 3)
            {
                /* Check if word exists in dictionary */
                str.clear();

                if (!dictPresent()) {
                    cout << "Dictionary doesn't exists." << endl;
                    resetInp();
                    continue;
                }

                cout << "Enter the word to check " << endl;
                cin >> str;

                if (newDict->checkWord(str)) {
                    cout << "Yes, thats a valid word" << endl;
                }
                else {
                    char resp;

                    cout << "The word \"" << str << "\" doesn't exists in the dictionary." << endl;
                    
                    cout << "Do you wish to add this as a word to the dictionary?(y/n)" << endl;
                    cin >> resp;

                    if (!processResp(resp)) {
                        resetInp();
                        continue;
                    }

                    if (newDict->addWord(str)) {
                        cout << "Word \"" << str << "\" added successfully" << endl;
                    }
                    else {
                        cout << "There was some problem adding that word, please retry.." << endl;
                    }

                }

                resetInp();
            }
            else if (inp == 4)
            {
                /* Delete a word from dictionary */
                resp = 'n';
                str.clear();

                if (!dictPresent()) {
                    cout << "Dictionary doesn't exists." << endl;
                    resetInp();
                    continue;
                }

                cout << "Enter the word to delete " << endl;
                cin >> str;

                cout << "Are you sure, you want to delete the word?" << endl;
                cin >> resp;

                if (!processResp(resp)) {
                    resetInp();
                    continue;
                }                    

                if (newDict->deleteWord(str)) {
                    cout << "Word \"" << str << "\" deleted successfully" << endl;
                }
                else {
                    cout << "There was some problem deleting that word, please retry.." << endl;
                }

                resetInp();
                continue;
            }
            else if (inp == 5)
            {
                /* Delete the dictionary */
                if (!dictPresent()) {
                    cout << "Dictionary doesn't exists." << endl;
                    resetInp();
                    continue;
                }

                resp = 'n';

                cout << "Are you sure, you want to delete the dictionary?" << endl;
                cin >> resp;

                if (!processResp(resp)) {
                    resetInp();
                    continue;
                }

                newDict = NULL;

                resetInp();
            }
            else 
            {
                cout << "Invalid choice. Pease select again..." << endl;
                resetInp();
            }
        }
    }

    return 0;
}