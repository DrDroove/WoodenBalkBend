#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    // Параметры консоли
    double L = 1.0;      // длина балки
    double P = 100.0;    // сила
    double EI = 1e4;     // жесткость

    // Начальные условия
    double x = 0.0;
    double u1 = 0.0;      // u(0)
    double u2 = 0.0;      // u'(0)

    // Численные параметры
    double h = 0.001;
    double x_max = L;

    ofstream out("beam_RK4.txt");

    while (x <= x_max) {
        auto f1 = [](double u2) {
            return u2;
        };

        auto f2 = [&](double x, double u2) {
            double factor = (1.0 / L - x / (L * L)) * (P * L * L / EI);
            return pow(1.0 + u2 * u2, 1.5) * factor;
        };

        // RK4
        double k1u1 = h * f1(u2);
        double k1u2 = h * f2(x, u2);

        double k2u1 = h * f1(u2 + k1u2 / 2.0);
        double k2u2 = h * f2(x + h / 2.0, u2 + k1u2 / 2.0);

        double k3u1 = h * f1(u2 + k2u2 / 2.0);
        double k3u2 = h * f2(x + h / 2.0, u2 + k2u2 / 2.0);

        double k4u1 = h * f1(u2 + k3u2);
        double k4u2 = h * f2(x + h, u2 + k3u2);

        u1 += (k1u1 + 2 * k2u1 + 2 * k3u1 + k4u1) / 6.0;
        u2 += (k1u2 + 2 * k2u2 + 2 * k3u2 + k4u2) / 6.0;

        out << x << " " << u1 << " " << u2 << endl;

        x += h;
    }

    out.close();
    int a;
    cout << "Расчет завершен. Результаты в beam_RK4.txt\n";
    cin >> a;
    return 0;
}
