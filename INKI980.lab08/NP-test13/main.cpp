#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

bool checkAnswer(int questionNumber, string answer) { // proverka za dali e odgovorot tocen na prasanjata
    if (questionNumber == 1 && answer == "b") {
        return true;
    } else if (questionNumber == 2 && answer == "c") {
        return true;
    } else if (questionNumber == 3 && answer == "c") {
        return true;
    } else if (questionNumber == 4 && answer == "c") {
        return true;
    } else if (questionNumber == 5 && answer == "a") {
        return true;
    } else if (questionNumber == 6 && answer == "a") {
        return true;
    } else if (questionNumber == 7 && answer == "b") {
        return true;
    } else if (questionNumber == 8 && answer == "c") {
        return true;
    } else if (questionNumber == 9 && answer == "c") {
        return true;
    } else if (questionNumber == 10 && answer == "a") {
        return true;
    } else {
        return false;
    }
}

int calculateGrade(int points) { // presmetuvanje na ocenka
    if (points < 50) {
        return 5;
    } else if (points < 61) {
        return 6;
    } else if (points < 71) {
        return 7;
    } else if (points < 81) {
        return 8;
    } else if (points < 91) {
        return 9;
    } else {
        return 10;
    }
}

void printResultsToFile(string firstName, string lastName, string index, string startTime, string endTime) {
    ofstream results("results.txt", ios::app);
    if (results.is_open()) {
        results <<"Starting time: "<<startTime<<endl;
        results <<"First Name: "<< firstName<<endl;
        results <<"Last Name: "<<lastName<<endl;
        results <<"Index: " <<index<<endl;
        results <<"Ending time: "<<endTime<<endl;
        results <<endl;
        results.close();
    } else {
        cout << "Neuspesno otvoranje na fajlot" <<endl;
    }
}

int main() {
    string firstName, lastName, index;
    bool exists = false;
    int points = 0;
    cout <<"Vnesi ime na studentot: "<<endl;
    getline(cin, firstName);
    cout <<"Vnesi prezime na studentot: "<<endl;
    getline(cin, lastName);
    cout <<"Vnesi go indeksot na studentot: ";
    getline(cin, index);
    string fileName = firstName + "_" + lastName + "_" + index + ".txt";

    ifstream infile(fileName.c_str());
    if (infile.good()) {
        exists = true;
        cout <<" veke igravte ednas!"<<endl;
        return 0;
    }


    auto now = chrono::system_clock::now();
    time_t startTime = chrono::system_clock::to_time_t(now);

    ifstream questions("prasanja.txt");
    if (questions.is_open()) {
        string question, answer;
        int questionNumber = 1;
        ofstream outfile(fileName.c_str(), ios_base::app);
        while (getline(questions, question)) {
            cout <<question<<endl;
            getline(cin, answer);
            if (checkAnswer(questionNumber, answer)) { // se dodavaat poeni za tocen odgovor
                points+= 10;
            }
            outfile <<"Odgovor: "<<answer<<endl; //  Zapisuvanje na odgovor
            questionNumber++; // prefrluvanje na sledno prasanje
        }
        questions.close();
        outfile.close();
    } else {
        cout <<"Ne moze da se otvori fajlot"<<endl;
        return 1;
    }


    now = chrono::system_clock::now();
    time_t endTime = chrono::system_clock::to_time_t(now); // Tuka go dobivam krajnoto vreme na kvizot

    cout <<"Osvoivte " <<points<<" poeni"<<endl;
    cout <<"Vasata ocenka e "<<calculateGrade(points)<<endl;
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&startTime)); // konverzija na pocetno vreme vo string
    string startTimeStr = buffer;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&endTime)); // konverzija na krajno vreme vo string
    string endTimeStr = buffer;


    ofstream outfile(fileName.c_str(), ios_base::app);
    outfile <<"Vreme na pocetok: "<<startTimeStr<<endl;
    outfile <<"Ime na studentot: " <<firstName<<" Prezime: "<<lastName<<endl;
    outfile <<"Indeks: "<<index<<endl;
    outfile <<"Poeni: "<<points<<endl;
    outfile <<"Ocena: "<<calculateGrade(points)<<endl;
    outfile <<"Kraj na kviz: "<<endTimeStr<<endl;
    outfile.close();

    printResultsToFile(firstName, lastName, index, startTimeStr, endTimeStr); // pecatenje na rezultati za korisnikot

    return 0;
}
