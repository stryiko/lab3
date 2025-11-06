#include <iostream>
#include <cmath>
using namespace std;

// ─── ДЕКЛАРАЦІЇ ─────────────────────────────────────────────────────────
void task_if5();     // If5: рахуємо додатні/від’ємні серед трьох цілих
void task_if36();    // If36: t(x) за шматковою формулою
void task_geom();    // Геометрія (табл.2, група 11–19) — КАРКАС
void show_menu();    // Меню (switch)

// ─── MAIN ───────────────────────────────────────────────────────────────
int main() {
    while (true) {
        show_menu();
        int m; 
        cin >> m;
        if (!cin) { cout << "Помилка вводу.\n"; return 0; }

        switch (m) {
            case 1: task_if5(); break;
            case 2: task_if36(); break;
            case 3: task_geom(); break;
            case 0: cout << "Вихід...\n"; return 0;
            default: cout << "Лише 0–3.\n";
        }
        cout << "\n---------------------------------------\n";
    }
}

// ─── МЕНЮ ───────────────────────────────────────────────────────────────
void show_menu() {
    cout << "\n===== Лабораторна №3 (C++) =====\n"
         << "1 — If5: кількість додатніх та від’ємних (3 цілі)\n"
         << "2 — If36: t(x)\n"
         << "3 — Геометрія (табл.2: варіанти 11–19) — каркас\n"
         << "0 — Вихід\n"
         << "Ваш вибір: ";
}

// ─── If5 ────────────────────────────────────────────────────────────────
void task_if5() {
    cout << "\n*** If5 ***\n";
    long long a,b,c; 
    cout << "Введіть три ЦІЛІ: ";
    cin >> a >> b >> c;
    if (!cin) { cout << "Потрібні цілі значення.\n"; cin.clear(); return; }

    int pos=0, neg=0;
    if (a>0) ++pos; else if (a<0) ++neg;
    if (b>0) ++pos; else if (b<0) ++neg;
    if (c>0) ++pos; else if (c<0) ++neg;

    cout << "Додатніх: " << pos << "\n"
         << "Від’ємних: " << neg << "\n";
}

// ─── If36 ───────────────────────────────────────────────────────────────
// t(x) = { x−2, x ≤ −1 ; x^2 + x, −1 < x < 2 ; 6, x ≥ 2 }
void task_if36() {
    cout << "\n*** If36 ***\n";
    double x; 
    cout << "x = ";
    cin >> x;
    if (!cin) { cout << "Потрібне число.\n"; cin.clear(); return; }

    double t;
    if (x <= -1.0)      t = x - 2.0;
    else if (x < 2.0)   t = x*x + x;
    else                t = 6.0;

    cout << "t(x) = " << t << "\n";
}

// ─── Геометрія (табл.2, 11–19) — КАРКАС ─────────────────────────────────
// Увести: варіант (11–19), r (радіус кіл), точку (x,y).
// Далі — заготівля примітивів; у switch під варіанти потрібно
// вписати конкретні умови (по рисунку), які задають темну область.
static inline bool inCircle(double x,double y,double xc,double yc,double r){
    return (x-xc)*(x-xc) + (y-yc)*(y-yc) <= r*r + 1e-12;
}
static inline bool inHalfPlane(double x,double y,double A,double B,double C){
    // A*x + B*y + C >= 0 — закрита півплощина
    return A*x + B*y + C >= -1e-12;
}
static inline bool between(double v,double a,double b){ return v>=a-1e-12 && v<=b+1e-12; }

void task_geom() {
    cout << "\n*** Геометрія (табл.2: 11–19) — каркас ***\n";
    int variant;
    double r, x, y;
    cout << "Номер варіанта (11–19): ";
    cin >> variant;
    cout << "Радіус r: ";
    cin >> r;
    cout << "Точка x y: ";
    cin >> x >> y;

    if (!cin || r<=0) { cout << "Некоректні дані.\n"; cin.clear(); return; }

    // === Типові центри/лінії з рисунка групи 11–19 ======================
    // За цими картинками зазвичай беруть:
    //  • верхнє коло центром (0,0) або (0, r) чи (r,0) — залежно від підгрупи;
    //  • нижнє коло симетричне по OX або OY;
    //  • великі трикутники — за лініями x + y = r, x = 0, y = 0 тощо.
    // Нижче — заготовлені примітиви; під свій варіант заміни центр/умови.

    // Приклади базових примітивів (ПРИ ПОТРЕБІ ПІДЛАШТУЙ):
    bool circleTop    = inCircle(x,y, 0.0,  r, r);   // коло у верхній півплощині
    bool circleRight  = inCircle(x,y,  r,  0.0, r);  // коло праворуч
    bool circleLeft   = inCircle(x,y, -r,  0.0, r);  // коло ліворуч/низ
    bool circleBottom = inCircle(x,y, 0.0, -r, r);   // коло внизу

    // півплощини для побудови трикутників (границі — осі й діагоналі):
    bool up     = inHalfPlane(x,y, 0,  1, 0);        // y ≥ 0
    bool rightH = inHalfPlane(x,y, 1,  0, 0);        // x ≥ 0
    bool diag1  = inHalfPlane(x,y, 1,  1, -r);       // x + y ≥ r
    bool diag2  = inHalfPlane(x,y, 1, -1,  0);       // x − y ≥ 0 (над діагоналлю y=x)

    // прямокутники/смуги, якщо треба обмежити сектор:
    bool inSquareR = (between(x,0,r) && between(y,0,r));
    bool inSquareL = (between(x,-r,0) && between(y,-r,0));

    bool inRegion = false;

    switch (variant) {
        case 11:
            // TODO: заміни на точну формулу для темної області 11-го варіанта.
            // Приклад (вигаданий): «верхнє коло ∩ трикутник над x+y=r»
            inRegion = circleTop && diag1 && up;
            break;
        case 12:
            // TODO: впиши комбінацію примітивів для 12-го
            inRegion = circleRight && rightH && up;
            break;
        case 13:
            // TODO
            inRegion = circleRight && !inSquareR && up;
            break;
        case 14:
            // TODO
            inRegion = circleTop && !rightH && up;
            break;
        case 15:
            // TODO
            inRegion = circleBottom && rightH && !up;
            break;
        case 16:
            // TODO
            inRegion = circleLeft && !rightH && !up;
            break;
        case 17:
            // TODO
            inRegion = circleBottom && diag2 && !up;
            break;
        case 18:
            // TODO
            inRegion = circleRight && !diag2 && up;
            break;
        case 19:
            // TODO
            inRegion = circleLeft && diag1 && !up;
            break;
        default:
            cout << "Варіант має бути в межах 11–19.\n";
            return;
    }

    cout << (inRegion ? "Точка НАЛЕЖИТЬ області.\n"
                      : "Точка НЕ належить області.\n");

    if (variant<11 || variant>19) return;
    cout << "⚠ Тепер залишається підставити точні умови для вашого №"
         << variant << " згідно з картиною (границі: кола радіуса r та "
         << "прямі типу x=0, y=0, x±y=const). Я додав усі будівельні блоки.\n";
}
