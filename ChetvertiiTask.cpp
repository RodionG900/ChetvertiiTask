#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    getline(cin, str);
    cout << str << endl;
    if (str.find(".") != string::npos) str.erase(str.find("."), 1);
    while (str.find("  ") != string::npos) {
        str.erase(str.find("  "), 1);
    }
    if (str.at(0) == ' ') str.erase(0, 1);
    if (str.at(str.length() - 1) == ' ') str.erase(str.length() - 1, 1);
    cout << endl << endl << "ќбработанна€ строка:\n";
    cout << str << endl;

    string subend = " " + str.substr(str.rfind(" ") + 1) + " ";
    str = " " + str + " ";
    while (str.find(subend) != string::npos) str.erase(str.find(subend), subend.size() - 1);
    if (str.at(0) == ' ') str.erase(0, 1);
    if (str.at(str.length() - 1) == ' ') str.erase(str.length() - 1, 1);
    str += subend;
    if (str.at(str.length() - 1) == ' ') str.erase(str.length() - 1, 1);
    cout << endl << endl << "Cтрока без вхождений последнего слова:\n";
    cout << str;

    cout << endl << endl << "3) ≈сли перва€ буква слова входит в это слово еще раз.(Сabcad as aaaТ->Тabcad aaaТ) :\n";
    str += " ";
    while (str.find(" ") != string::npos) {
        string sub = str.substr(0, str.find(" "));
        if (sub.substr(1).find(sub[0])!= string::npos) cout << sub << " ";
        str = str.substr(str.find(" ") + 1);
    }
    cout << "\n\n\n";
}