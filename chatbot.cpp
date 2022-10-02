#include <iostream>
#include <conio.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <chrono>
#include <ctime>

using namespace std;
void color(int num);
class Voice{
public:
    void say(string phrase);
};

void Voice::say(string phrase){
    string command = "espeak \"" + phrase + "\"";
    const char* charCommand = command.c_str();
    color(7), cout <<phrase <<endl;
    system(charCommand);
}

class Learner{
public:
    void respond(string phrase);
    void learn(string phrase);
    void say(string phrase);
    //void freeTalk(string phrase);
    Voice voice;
};

void Learner::respond(string phrase){
    fstream memory;
    memory.open("memory/memory.txt", ios::in);

    while(!memory.eof()){
        string identifier;
        getline(memory, identifier);
        if(identifier == phrase){
            string respose;
            getline(memory, respose);
            const char* resCommand = respose.c_str();
            system(resCommand);
            return;
        }
    }

    memory.close();
    color(6), cout <<"GenMCS: ";
    voice.say("Sorry, I still don't know what to do with that phrase.");
}

void Learner::learn(string phrase){
    fstream memory;
    memory.open("memory/memory.txt", ios::in);

    while(!memory.eof()){
        string identifier;
        getline(memory, identifier);
        if(identifier == phrase){
            color(6), cout <<"GenMCS: ";
            voice.say("I've already learned this phrase.");
            return;
        }
    }

    memory.close();
    memory.open("memory/memory.txt", ios::in | ios::app);
    memory <<phrase <<endl;

    string userResponse;
    color(6), cout <<"GenMCS: ";
    voice.say("It seems this phrase has not been taken.");
    color(6), cout <<"GenMCS: ";
    voice.say("What command would you like me to associate with this phrase?");
    color(11), cout <<"YOU: ";
    color(7), getline(cin, userResponse);
    for(int i=0; i<userResponse.length(); i++){
        userResponse[i] = tolower(userResponse[i]);
    }
    memory <<"start " + userResponse <<endl;
    memory.close();
    color(6), cout <<"GenMCS: ";
    voice.say("Okay, I've taken a note of that.");
    return;
}

/*void Learner::freeTalk(string phrase){
    fstream memory;
    memory.open("memory/free_talk.txt", ios::in);

    while(!memory.eof()){
        string identifier;
        getline(memory, identifier);
        if(identifier == phrase){
            string response;
            cout <<"GenMCS: ";
            getline(memory, response);
            voice.say(response);
            return;
        }
    }

    memory.close();
    memory.open("memory/free_talk.txt", ios::in | ios::app);
    memory <<phrase <<endl;

    string userResponse;
    cout <<"GenMCS: ";
    voice.say("I don't know how to reply to that yet.");
    cout <<"GenMCS: ";
    voice.say("How do you want me to address to that query?");
    cout <<"YOU: ";
    getline(cin, userResponse);
    for(int i=0; i<userResponse.length(); i++){
        userResponse[i] = tolower(userResponse[i]);
    }
    memory <<userResponse <<endl;
    memory.close();
    cout <<"GenMCS: ";
    voice.say("Okay, I've taken a note of that.");
    return;
}*/

void Learner::say(string phrase){
    this->voice.say(phrase);
}

string lowerCase(string input);
void textChat(Learner textAI);
void techAssistant(Learner techAI);
void chatbotTrain(Learner trainAI);
void listCommand(Learner commandAI);
void reportSave(string title, string department, string content, string date);
void reset(Learner resetAI);
//void freeTalk(Learner chatAI);

int main(){
    Learner AI;
    color(6), cout <<"GenMCS: ";
    AI.say("Hi! I am GenMCS short for General Messaging Company Support, is here to assist you for today.");
    color(6), cout <<"GenMCS: ";
    AI.say("This is my user interface where you can navigate around my functionalities.");
    cout <<endl <<endl;
    while(true){
        int userInput;
        color(7), cout<<"-------------", color(4), cout <<"Main Menu", color(7), cout <<"-------------" <<endl;
        cout <<"[0] Exit" <<endl;
        cout <<"[1] Company Report Creator" <<endl;
        cout <<"[2] GenMCS Computer Assistant" <<endl;
        cout <<"[3] GenMCS Trainer" <<endl;
        cout <<"[4] GenMCS Command List" <<endl;
        cout <<"[5] GenMCS Reset" <<endl;
        //cout <<"[6] Free Talk Chat" <<endl;
        cout <<"-----------------------------------";
        color(11), cout <<endl <<endl <<"YOU: ";
        color(7), cin >>userInput;
        switch(userInput){
        case 0:
            color(6), cout <<"GenMCS: ";
            AI.say("Program is closing");
            system("cls");
            _Exit(0);
            break;
        case 1:
            textChat(AI);
            break;
        case 2:
            techAssistant(AI);
            break;
        case 3:
            chatbotTrain(AI);
            break;
        case 4:
            listCommand(AI);
            break;
        case 5:
            reset(AI);
            break;
        //case 5:
            //freeTalk(AI);
        default:
            color(6), cout <<"GenMCS: ";
            AI.say("Invalid input! Please try again.");
            break;
        }
    }
    return 0;
}

void color(int num){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), num);
}

string lowerCase(string input){
    for(int i=0; i<input.length(); i++){
        input[i] = tolower(input[i]);
    }
    return input;
}

void textChat(Learner textAI){
    int tick;
    string title;
    string department;
    string content;
    string userInput;
    string confirm;
    string eDate;
    system("cls");
    color(6), cout <<"GenMCS: ";
    textAI.say("Company report creator is initializing...");
    system("cls");

    //Department
    color(6), cout <<"GenMCS: ";
    textAI.say("Please enter the department what you want to create a report to.");
    color(3), cout <<"Departments:", color(7), cout <<" HR Department, Marketing Department, OA Department, IT Department" <<endl <<endl;
    cin.ignore();
    while(true){
        color(11), cout <<"YOU: ";
        color(7), getline(cin, userInput);
        userInput = lowerCase(userInput);
        if(userInput == "exit"){
            color(6), cout <<"GenMCS: ";
            textAI.say("Returning to main menu.");
            system("cls");
            return;
        }
        department = userInput;
        if(department == "hr department" || department == "it department" || department == "oa department" || department == "marketing department"){
            break;
        }
        else{
            color(6), cout <<"GenMCS: ";
            textAI.say("Department is not found! Please check you input.");
        }
    }

    //Title
    color(6), cout <<"GenMCS: ";
    textAI.say("Please provide a title for your report.");
    color(11), cout <<"YOU: ";
    color(7), getline(cin, userInput);
    userInput = lowerCase(userInput);
    if(userInput == "exit"){
        color(6), cout <<"GenMCS: ";
        textAI.say("Returning to main menu.");
        system("cls");
        return;
    }
    title = userInput;

    //Content
    color(6), cout <<"GenMCS: ";
    textAI.say("Please provide the message of your report.");
    color(11), cout <<"YOU: ";
    color(7), getline(cin, userInput);
    userInput = lowerCase(userInput);
    if(userInput == "exit"){
        color(6), cout <<"GenMCS: ";
        textAI.say("Returning to main menu.");
        system("cls");
        return;
    }
    content = userInput;

    //Time
    auto start = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(start);
    eDate = ctime(&end_time);
    tick = eDate.size();
    for(int i=0; i<tick; i++){
        if(i<=10){
            eDate[i]=eDate[i];
        }
        else if(i>=19){
            eDate[i-9] = eDate[i];
            eDate[i] = '\0';
        }
        else{
            eDate[i] = '\0';
        }
    }

    //Output
    system("cls");
    color(6), cout <<"GenMCS: ";
    textAI.say("Generating the content of your report.");
    system("cls");

    color(14), cout <<"Department Report: ", color(7), cout <<department <<endl;
    color(14), cout <<"Report Title: ", color(7), cout <<title <<endl;
    color(14), cout <<"Report Date: ", color(7), cout <<eDate <<endl;
    color(14), cout <<"Report message: ", color(7), cout <<endl;
    color(7), cout <<content <<endl <<endl <<endl;

    color(6), cout <<"GenMCS: ";
    textAI.say("Are you satisfied with the output of this report document?");
    color(6), cout <<"GenMCS: ";
    textAI.say("Enter Y if yes, otherwise enter any keys.");
    color(11), cout <<"YOU: ";
    color(7), getline(cin, confirm);
    confirm = lowerCase(confirm);
    if(confirm == "exit"){
        color(6), cout <<"GenMCS: ";
        textAI.say("Returning to main menu.");
        system("cls");
        return;
    }
    else if(confirm == "y"){
        system("cls");
        color(6), cout <<"GenMCS: ";
        textAI.say("Creating a report file...");
        reportSave(title, department, content, eDate);
        color(6), cout <<"GenMCS: ";
        textAI.say("Report file has been saved!");
        title = "\0";
        department = "\0";
        content = "\0";
        eDate = "\0";
        userInput = "\0";
        system("cls");
    }
    else{
        system("cls");
        color(6), cout <<"GenMCS: ";
        textAI.say("Deleting the report file...");
        title = "\0";
        department = "\0";
        content = "\0";
        eDate = "\0";
        userInput = "\0";
        color(6), cout <<"GenMCS: ";
        textAI.say("Report file has been discarded!");
        system("cls");
    }
    return;
}

void reportSave(string title, string department, string content, string date){
    fstream memory;
    if(department == "hr department"){
        ofstream("memory/hr_report/" + title + ".txt");
        memory.open("memory/hr_report/" + title + ".txt", ios::out | ios::app);
        memory <<"Title: " <<title <<endl;
        memory <<"Date submitted: " <<date <<endl <<endl;
        memory <<content;
    }
    else if(department == "it department"){
        ofstream("memory/it_report/" + title + ".txt");
        memory.open("memory/it_report/" + title + ".txt", ios::out | ios::app);
        memory <<"Title: " <<title <<endl;
        memory <<"Date submitted: " <<date <<endl <<endl;
        memory <<content;
    }
    else if(department == "marketing department"){
        ofstream("memory/market_report/" + title + ".txt");
        memory.open("memory/market_report/" + title + ".txt", ios::out | ios::app);
        memory <<"Title: " <<title <<endl;
        memory <<"Date submitted: " <<date <<endl <<endl;
        memory <<content;
    }
    else if(department == "oa department"){
        ofstream("memory/oa_report/" + title + ".txt");
        memory.open("memory/oa_report/" + title + ".txt", ios::out | ios::app);
        memory <<"Title: " <<title <<endl;
        memory <<"Date submitted: " <<date <<endl <<endl;
        memory <<content;
    }
    memory.close();
    return;
}

void techAssistant(Learner techAI){
    string userInput;
    system("cls");
    color(6), cout <<"GenMCS: ";
    techAI.say("Hi, how can I help you today?");
    cin.ignore();
    while(true){
        color(11), cout <<"YOU: ";
        color(7), getline(cin, userInput);
        userInput = lowerCase(userInput);
        if(userInput == "exit"){
            color(6), cout <<"GenMCS: ";
            techAI.say("Returning to main menu.");
            system("cls");
            return;
        }
        color(6), cout <<"GenMCS: ";
        techAI.say("Executing the command: " + userInput);
        techAI.respond(userInput);
        color(6), cout <<"GenMCS: ";
        techAI.say("Is there anything else?");
    }
}

void chatbotTrain(Learner trainAI){
    string userInput;
    system("cls");
    cin.ignore();
    while(true){
        color(6), cout <<"GenMCS: ";
        trainAI.say("What do you want me to learn?");
        color(11), cout <<"YOU: ";
        color(7), getline(cin, userInput);
        userInput = lowerCase(userInput);
        if(userInput == "exit"){
            color(6), cout <<"GenMCS: ";
            trainAI.say("Returning to main menu.");
            system("cls");
            return;
        }
        color(6), cout <<"GenMCS: ";
        trainAI.say("Alright, I'm trying to search if " + userInput +" phrase is already in my memory");
        trainAI.learn(userInput);
    }
}
void listCommand(Learner commandAI){
    system("cls");
    color(6), cout <<"GenMCS: ";
    commandAI.say("These are the list of the phrase that I can execute with the corresponding command.");
    fstream memory;
    memory.open("memory/memory.txt", ios::in);
    string phrase;
    string command;
    while(!memory.eof()){
        getline(memory, phrase);
        if(phrase != "\0"){
        cout <<"Phrase: " <<phrase <<endl;
        getline(memory, command);
        cout <<"Command: " <<command <<endl <<endl;
        }
        else{
            break;
        }
    }
    memory.close();
    return;
}

void reset(Learner resetAI){
    system("cls");
    fstream memory;
    string userInput;
    color(6), cout <<"GenMCS: ";
    resetAI.say("Would you like to reset my memory? Enter Y if yes, otherwise enter any keys.");
    cin.ignore();
    color(11), cout <<"YOU: ";
    color(7), getline(cin, userInput);
    userInput = lowerCase(userInput);
    if(userInput == "y"){
        color(6), cout <<"GenMCS: ";
        resetAI.say("Deleting my memory...");
        int status = remove("memory/memory.txt");
        if(status !=0){
            color(6), cout <<"GenMCS: ";
            resetAI.say("ERROR!, Couldn't delete my memory. Please check if my memory is still running.");
            system("cls");
            return;
        }
        ofstream("memory/memory.txt");
        memory.open("memory/memory.txt", ios::out | ios::app);
        memory <<"exit" <<endl;
        memory <<"return to main menu" <<endl;
        memory <<"open hr report" <<endl;
        memory <<"start C:/Users/phant/Desktop/Codes/CPP/Chatterbot-main/memory/hr_report" <<endl;
        memory <<"open marketing report" <<endl;
        memory <<"start C:/Users/phant/Desktop/Codes/CPP/Chatterbot-main/memory/market_report" <<endl;
        memory <<"open oa report" <<endl;
        memory <<"start C:/Users/phant/Desktop/Codes/CPP/Chatterbot-main/memory/oa_report" <<endl;
        memory <<"open it report" <<endl;
        memory <<"start C:/Users/phant/Desktop/Codes/CPP/Chatterbot-main/memory/it_report" <<endl;
        memory.close();
        color(6), cout <<"GenMCS: ";
        resetAI.say("Succesfully deleted my memory!");
    }
    color(6), cout <<"GenMCS: ";
    resetAI.say("Returning to main menu.");
    system("cls");
    return;
}

/*void freeTalk(Learner chatAI){
    string userInput;
    system("cls");
    cout <<"GenMCS: ";
    chatAI.say("Hi what would you like to talk about?");
    cin.ignore();
    while(true){
        cout <<"YOU: ";
        getline(cin, userInput);
        userInput = lowerCase(userInput);
        if(userInput == "exit"){
            cout <<"GenMCS: ";
            chatAI.say("Returning to main menu.");
            system("cls");
            return;
        }
        chatAI.freeTalk(userInput);
    }
}*/
