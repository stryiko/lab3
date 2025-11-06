#include <iostream>
#include <cmath>
using namespace std;

// ======= ДЕКЛАРАЦІЯ ФУНКЦІЙ =======
void task_if5();     // Завдання 1 (If5)
void task_if36();    // Завдання 1 (If36)
void task_geom();    // Завдання 2 (геометрія)
void show_menu();    // Меню

// ==================== MAIN ====================
int main() {
    int choice;

    while (true) {
        show_menu();
        cin >> choice;

        if (!cin) {
            cout << "Некоректне введення!" << endl;
            return 0;
        }

        switch (choice) {
        case 1: task_if5(); break;
        case 2: task_if36(); break;
        case 3: task_geom(); break;
        case 0: 
            cout << "Вихід із програми..." << endl;
            return 0;
        default:
            cout << "Невірний вибір! (Лише 0–3)" << endl;
        }

        cout << "\n-----------------------------------\n";
    }

    return 0;
}

// ==================== МЕНЮ ====================
void show_menu() {
    cout << "\n===== Лабораторна робота №3 =====\n";
    cout << "1 — If5 (рахунок додатних і відʼємних)\n";
    cout << "2 — If36 (обчислення t(x))\n";
    cout << "3 — Геометричне завдання\n";
    cout << "0 — Вихід\n";
    cout << "Ваш вибір: ";
}

// ==================== If5 ====================
// Дано три цілих числа. Знайти кількість додатних і кількість від’ємних чисел.
void task_if5() {
    cout << "\n******* Завдання If5 ********\n";

    int a, b, c;
    cout << "Введіть три цілих числа: ";
    cin >> a >> b >> c;

    if (!cin) {
        cout << "Помилка! Потрібно ввести цілі числа.\n";
        return;
    }

    int positive = 0, negative = 0;

    if (a > 0) positive++;
    if (b > 0) positive++;
    if (c > 0) positive++;

    if (a < 0) negative++;
    if (b < 0) negative++;
    if (c < 0) negative++;

    cout << "Кількість додатних: " << positive << endl;
    cout << "Кількість від’ємних: " << negative << endl;
}

// ==================== If36 ====================
// t(x) =
// x − 2, якщо x ≤ −1
// x² + x, якщо −1 < x < 2
// 6, якщо x ≥ 2
void task_if36() {
    cout << "\n******* Завдання If36 ********\n";

    double x;
    cout << "Введіть x: ";
    cin >> x;

    if (!cin) {
        cout << "Помилка! Потрібно ввести число.\n";
        return;
    }

    double t;

    if (x <= -1)
        t = x - 2;
    else if (x < 2)
        t = x*x + x;
    else
        t = 6;

    cout << "t(x) = " << t << endl;
}

// ==================== Геометрія (з прикладу) ====================
void task_geom() {
    cout << "\n******* Геометричне завдання ********\n";

    double a, b, x, y;

    cout << "Введіть a, b: ";
    cin >> a >> b;

    if (cin.fail() || b/2 < a || a <= 0 || b <= 0) {
        cout << "Некоректні дані!" << endl;
        return;
    }

    cout << "Введіть координати (x, y): ";
    cin >> x >> y;

    if (!cin) {
        cout << "Помилка! Введіть числа." << endl;
        return;
    }

    double R2 = a*a/4.0;
    double xc = b/2.0, yc = a/2.0;
    double circle = pow(x - xc, 2) + pow(y - yc, 2);

    bool inRectExCirc = x > b/2 && x < b && y > 0 && y < a && circle > R2;
    bool inHalfCirc = circle < R2 && x < b/2;

    if (inRectExCirc || inHalfCirc)
        cout << "Точка належить області." << endl;
    else
        cout << "Точка НЕ належить області." << endl;
}
