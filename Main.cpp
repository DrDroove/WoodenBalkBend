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
    double u = 0.0;      // u(0)
    double v = 0.0;      // u'(0)

    // Численные параметры
    double h = 0.001;
    double x_max = L;

    ofstream out("beam_RK4.txt");

    while (x <= x_max) {
        out << x << " " << u << " " << v << endl;

        auto f1 = [](double v) {
            return v;
            };

        auto f2 = [&](double x, double v) {
            double factor = (1.0 / L - x / (L * L)) * (P * L * L / EI);
            return pow(1.0 + v * v, 1.5) * factor;
            };

        // RK4
        double k1u = h * f1(v);
        double k1v = h * f2(x, v);

        double k2u = h * f1(v + k1v / 2.0);
        double k2v = h * f2(x + h / 2.0, v + k1v / 2.0);

        double k3u = h * f1(v + k2v / 2.0);
        double k3v = h * f2(x + h / 2.0, v + k2v / 2.0);

        double k4u = h * f1(v + k3v);
        double k4v = h * f2(x + h, v + k3v);

        u += (k1u + 2 * k2u + 2 * k3u + k4u) / 6.0;
        v += (k1v + 2 * k2v + 2 * k3v + k4v) / 6.0;

        x += h;
    }

    out.close();
    int a;
    cout << "Расчет завершен. Результаты в beam_RK4.txt\n";
    cin >> a;
    return 0;
}
