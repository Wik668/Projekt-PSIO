#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

struct Person {
    std::string Imie;
    std::string Nazwisko;
    std::string Miasto;
    std::string Stan;
    int kod_pocztowy;
    std::string nrtel;
    std::string email;
    std::string www;

    bool operator<(const Person& kolejny) const {
        return kod_pocztowy > kolejny.kod_pocztowy;
    }
};

int main() {
    std::ifstream inputFile("C:\\Users\\wikto\\OneDrive\\Dokumenty\\PSIO\\aa.csv");

    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<Person> people;
    std::string line;

    
    std::getline(inputFile, line);

    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string field;

        Person person;

        std::getline(ss, field, ','); 
        person.Imie = field;

        std::getline(ss, field, ',');
        person.Nazwisko = field;

        std::getline(ss, field, ',');
        person.Miasto = field;

        std::getline(ss, field, ',');
        person.Stan = field;

        std::getline(ss, field, ',');
        person.kod_pocztowy = std::stoi(field); 

        std::getline(ss, field, ',');
        person.nrtel = field;

        std::getline(ss, field, ',');
        person.email = field;

        std::getline(ss, field, ',');
        person.www = field;

        people.push_back(person);
    }

    // if (people.empty()) {
    //     std::cerr << "brak danych" << std::endl;
    //     return 1; 
    // }

    std::sort(people.begin(), people.end());

    for (const Person& person : people) {
        std::cout << person.Imie << "," << person.Nazwisko << "," << person.Miasto << ","
                  << person.Stan << "," << person.kod_pocztowy << "," << person.nrtel << ","
                  << person.email << "," << person.www << std::endl;
    }
    


    std::regex Regex("(http|https)://.[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,3}");


    for (const Person& person : people) {
        if (std::regex_match(person.www, Regex)) {
            std::cout << "Valid website: " << person.www << std::endl;
        } else {
            std::cout << "Invalid website: " << person.www << std::endl;
        }
    }
    return 0;
}
