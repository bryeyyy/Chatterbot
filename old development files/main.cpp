#include <iostream>
#include "learner.h"

#include <conio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

void talk(Learner AI, string phrase){
    /*
    	The following is the main loop. It will continue until the application is closed.
    	The user enters their input, and then the learner will respond.
    */
    system("cls");
    cout<<"Feel free to ask me anything!"<<endl;
    for(;;){
        cout << "\nYOU: ";    // User prompt
        getline(cin, phrase);    // Using getline for multi word input, then store in phrase.

        cout << "GenMACS: ";
        AI.respond(phrase);    // Pass the user input to the learner and see if he can respond
    }
}
main(){
    Learner AI;    // Create a learner object
   //int check;
    int toggle;
    string phrase;
    // add a function that can search the directory for the "memory" folder, if not found, create one.
   /*
    DIR *dr;
    struct dirent *en;
    dr  opendir(".");
    if (dir) {
        while ((en = readdir(dr)) ! NULL){
            string folders[];
        }
    }

    // add a function that can search the memory dir for "memory.txt", if not found, create one.
    char* dirname = "memory";
    check = mkdir(dirname);
    ofstream file("memory/memory.txt");
*/
    phrase = "Hi I'm GenMCS! Short for General Messaging Customer Service.";
    cout << "GenMACS: ";
    AI.say(phrase);
    phrase = " ";

    a:
    cout<<"\nHow can I help?"<<endl;
    cout<<"\n\n     Quick Toggles"<<endl;
    cout<<"     [1] Contact Customer Service\n     [2] Learn more about me!\n     [3] Talk to me! :>\n";
    cout << "YOU: ";    // User prompt
    cin>>toggle;

    switch(toggle) {
    case 1:
        cout<<"Function 1"<<endl;
        goto a;
        break;
    case 2:
        cout<<"Function 2"<<endl;
        goto a;
        break;
    case 3:
        talk(AI, phrase);
        break;
    default:
        cout<<"Not Valid."<<endl;
        goto a;
        break;
    }
}
