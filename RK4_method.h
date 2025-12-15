#pragma once
#include<vector>
#include <cmath> 

struct RK4_stepdata
{
    int i;
    double xi;
    //first var
    double v1i;
    double v1_2i;
    double v1i_v1_2i;
    //second var
    double v2i;
    double v2_2i;
    double v2i_v2_2i;
    //errors 
    double error; 
    double s1; 
    double s2;

    double hi;
    int c1; //double h
    int c2; //half h
};

auto f1 = [](double v2) {
    return v2;
    };

auto f2 = [&](double x, double v2, double L, double P, double EI) {
    double factor = (1.0 / L - x / (L * L)) * (P * L * L / EI);
    return pow(1.0 + v2 * v2, 1.5) * factor;
    };

void RK4_step(const double& x, double& v1, double& v2, const double& h, const double& L, const double& P, const double& EI) {
    double k1u1 = h * f1(v2);
    double k1u2 = h * f2(x, v2, L, P, EI);

    double k2u1 = h * f1(v2 + k1u2 / 2.0);
    double k2u2 = h * f2(x + h / 2.0, v2 + k1u2 / 2.0, L, P, EI);

    double k3u1 = h * f1(v2 + k2u2 / 2.0);
    double k3u2 = h * f2(x + h / 2.0, v2 + k2u2 / 2.0, L, P, EI);

    double k4u1 = h * f1(v2 + k3u2);
    double k4u2 = h * f2(x + h, v2 + k3u2, L, P, EI);

    v1 += (k1u1 + 2 * k2u1 + 2 * k3u1 + k4u1) / 6.0;
    v2 += (k1u2 + 2 * k2u2 + 2 * k3u2 + k4u2) / 6.0;
}

std::vector<RK4_stepdata> RK4_solve(double L = 1.0, double P = 2.0, double EI = 1.0, double eps = 1e-7, double delta = 1e-7 , double x0 = 0.0, double u10 = 0.0, double u20 = 0.0, double h = 1e-2, double xmax = 1.0, int maxSteps = 1000000) {
    double x = x0;
    double v1 = u10; double v2 = u20;
    double x_tmp = x, v1_tmp = v1, v2_tmp = v2;

    double s1 = 0.0, s2 = 0.0, error = 0.0;

    int step = 0;
    int p = 4; //method order
    int iter = 0;

    std::vector<RK4_stepdata> table;

    {
        RK4_stepdata row;
        row.i = step;
        row.xi = x;
        row.v1i = v1;
        row.v1_2i = v1;
        row.v2i = v2;
        row.v2_2i = v2;
        row.v1i_v1_2i = 0.0;
        row.v2i_v2_2i = 0.0;
        row.error = 0.0;
        row.s1 = 0.0;
        row.s2 = 0.0;
        row.hi = h;
        row.c1 = 0;
        row.c2 = 0;

        table.push_back(row);
    } //first row

    while ((x + h <= xmax) && (iter < maxSteps)) {
        RK4_stepdata row;
        bool step_accepted = false;
        row.i = step;
        row.c1 = 0; //double
        row.c2 = 0; //half
        int flag = 0;
        
        while (!step_accepted && iter <= maxSteps) {
            iter++;
            x_tmp = x;
            v1_tmp = v1;
            v2_tmp = v2;
            RK4_step(x, v1, v2, h, L, P, EI);


            RK4_step(x_tmp, v1_tmp, v2_tmp, h / 2.0, L, P, EI);
            x_tmp += h / 2.0;
            RK4_step(x_tmp, v1_tmp, v2_tmp, h / 2.0, L, P, EI);

            s1 = std::abs(v1 - v1_tmp) / (pow(2, p) - 1);
            s2 = std::abs(v2 - v2_tmp) / (pow(2, p) - 1);

            error = sqrt(s1 * s1 + s2 * s2); //Euclidus norm

            row.v1i = v1;
            row.v2i = v2;
            row.v1_2i = v1_tmp;
            row.v2_2i = v2_tmp;
            row.v1i_v1_2i = v1 - v1_tmp;
            row.v2i_v2_2i = v2 - v2_tmp;
            row.error = error;

            if (error > eps) {
                h /= 2.0;
                row.c2 = 1;
               
            }
            else if (error <= eps) {
                step_accepted = true;
                x = x + h;
                if ((error < eps / pow(2, p + 1) )&& (flag == 0)) {
                    h *= 2.0;
                    row.c1 = 1;
                    
                }
            }

        }
        if (!step_accepted) break;
        step++;
        row.hi = h;
        row.xi = x;
        table.push_back(row);
        if (x + h >= xmax - delta) {
            h = xmax - x;
            row.c2 = 1;
            flag = 1;
        }
        if (std::fabs(xmax - x) < delta) break;
        if (step + iter - 1 > maxSteps) break;

    }
    return table;
}