#include <iostream>
#include <cmath>

using namespace std;

    class Equation {
    public:
        virtual void solve() = 0;
    };

    class LinearEquation : public Equation {
    private:
        double a, b;

    public:
        LinearEquation(double a_val, double b_val) : a(a_val), b(b_val) {}

        void solve() override {
            if (a == 0) {
                if (b == 0)
                    cout << "The equation has infinitely many solutions" << endl;
                else
                    cout << "The equation has no solution" << endl;
            } else {
                double x = -b / a;
                cout << "Solution: x = " << x << endl;
            }
        }
    };

    class QuadraticEquation : public Equation {
    private:
        double a, b, c;

    public:
        QuadraticEquation(double a_val, double b_val, double c_val)
            : a(a_val), b(b_val), c(c_val) {}

        void solve() override {
            if (a == 0) {
                LinearEquation linear(b, c);
                linear.solve();
            } else {
                double discriminant = b * b - 4 * a * c;

                if (discriminant > 0) {
                    double x1 = (-b + sqrt(discriminant)) / (2 * a);
                    double x2 = (-b - sqrt(discriminant)) / (2 * a);
                    cout << "Solutions: x1 = " << x1 << ", x2 = " << x2 << endl;
                } else if (discriminant == 0) {
                    double x = -b / (2 * a);
                    cout << "The equation has one real solution x = " << x << endl;
                } else {
                    cout << "The equation has no real solutions" << endl;
                }
            }
        }
    };

int main() {


    QuadraticEquation equation1(1, -3, 2);
    equation1.solve();

    QuadraticEquation equation2(1, -2, 5);
    equation2.solve();

    LinearEquation equation3(0, 0);
    equation3.solve();

    LinearEquation equation4(0, 5);
    equation4.solve();


}
