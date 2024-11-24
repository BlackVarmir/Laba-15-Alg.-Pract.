#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// Функція для перевірки голосних
bool isVowel(char c) {
    string vowels = "aeiouyAEIOUY";
    return vowels.find(c) != string::npos;
}

// Завдання 1: Видалення зайвих пробілів та заміна перших 3 символів
void processStringTask1(string& S) {
    // Видалення зайвих пробілів
    string result;
    bool wasSpace = false;
    for (char c : S) {
        if (c == ' ') {
            if (!wasSpace) result += c;
            wasSpace = true;
        }
        else {
            result += c;
            wasSpace = false;
        }
    }
    // Заміна перших 3 символів
    if (result.size() >= 3) {
        result.replace(0, 3, "12345");
    }
    cout << "Результат: " << result << endl;
}

// Завдання 2: Об'єднання рядків та заміна цифр на '*'
void processStringTask2(string& S, string& S0) {
    string combined = S0 + S;
    cout << "Довжина утвореного рядка: " << combined.size() << endl;

    for (char& c : combined) {
        if (isdigit(c)) c = '*';
    }
    cout << "Результат: " << combined << endl;
}

// Завдання 3: Формування числового масиву з рядка
void processStringTask3(string& S) {
    vector<int> Ch;
    for (char c : S) {
        if (isdigit(c)) {
            Ch.push_back(c - '0');
        }
    }

    cout << "Числовий масив: ";
    for (int num : Ch) {
        cout << num << " ";
    }
    cout << endl;
}

// Завдання 4: Видалення всіх входжень рядка S0 в рядку S
void processStringTask4(string& S, string& S0) {
    size_t pos;
    while ((pos = S.find(S0)) != string::npos) {
        S.erase(pos, S0.size());
    }
    cout << "Результат: " << S << endl;
}

// Завдання 5: Слова з 3 літерами 'а'
void processStringTask5(string& S) {
    vector<string> words;
    size_t start = 0, end;
    while ((end = S.find(' ', start)) != string::npos) {
        words.push_back(S.substr(start, end - start));
        start = end + 1;
    }
    words.push_back(S.substr(start));

    cout << "Слова з рівно 3 літерами 'а': ";
    for (const string& word : words) {
        if (count(word.begin(), word.end(), 'a') == 3) {
            cout << word << " ";
        }
    }
    cout << endl;
}

// Завдання 6: Зміна регістру голосних та видалення приголосних
void processStringTask6(string& S) {
    string result;
    for (char c : S) {
        if (isVowel(c)) {
            result += islower(c) ? toupper(c) : tolower(c);
        }
    }
    cout << "Результат: " << result << endl;
}

// Основна функція
int main() {
    int option;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Видалити зайві пробіли та замінити перші 3 символи\n";
        cout << "2. Об'єднати рядки та замінити цифри\n";
        cout << "3. Формувати числовий масив\n";
        cout << "4. Видалити всі входження S0 у S\n";
        cout << "5. Знайти слова з 3 літерами 'а'\n";
        cout << "6. Змінити регістр голосних та видалити приголосні\n";
        cout << "0. Вихід\n";
        cout << "Оберіть опцію: ";
        cin >> option;

        if (option == 0) break;

        string S, S0;
        switch (option) {
        case 1:
            cout << "Введіть рядок S: ";
            cin.ignore();
            getline(cin, S);
            processStringTask1(S);
            break;
        case 2:
            cout << "Введіть рядок S: ";
            cin.ignore();
            getline(cin, S);
            cout << "Введіть рядок S0: ";
            getline(cin, S0);
            processStringTask2(S, S0);
            break;
        case 3:
            cout << "Введіть рядок S: ";
            cin.ignore();
            getline(cin, S);
            processStringTask3(S);
            break;
        case 4:
            cout << "Введіть рядок S: ";
            cin.ignore();
            getline(cin, S);
            cout << "Введіть рядок S0: ";
            getline(cin, S0);
            processStringTask4(S, S0);
            break;
        case 5:
            cout << "Введіть рядок S: ";
            cin.ignore();
            getline(cin, S);
            processStringTask5(S);
            break;
        case 6:
            cout << "Введіть рядок S: ";
            cin.ignore();
            getline(cin, S);
            processStringTask6(S);
            break;
        default:
            cout << "Невірний вибір!" << endl;
        }
    }

    return 0;
}
