/*
1. Опишіть клас JetPlane (Реактивний літак), успадковуючи його від двох базових класів – Rocket (Ракета) та Airplane (Літак).
*/

#include <iostream>

class Rocket {
public:
    Rocket(int traction) : traction_(traction) {}
    virtual ~Rocket() {}

    virtual void Show_Traction() const { std::cout << "Thrust of the rocket: " << traction_ << " kH.\n"; }

protected://дозволяє мені захищати методи та поля від зовнішнього втручання, та дозволяючи нащадкам використовувати ці методи .
    int GetTraction() const { return traction_; }

private:
    int traction_; // Тяга ракети
};

class Airplane {
public:
    Airplane(int wing) : wing_(wing) {}
    virtual ~Airplane() {}

    virtual void Show_Wing() const { std::cout << "Airplane wing size: " << wing_ << " m.\n"; }

protected:
    int GetWingSize() const { return wing_; }

private:
    int wing_; // розмір крила
};

class JetPlane : public Rocket, public Airplane {
public:

    JetPlane(int speed, int wing, int traction)
        : Rocket(traction), Airplane(wing), speed_(speed) {}

    //тут деструктор не потрібен на мою думку

    virtual void Show_Traction() const override //override для вказівки, що метод класу - є нащадком перевизначає віртуальний метод базового класу.
    {
        std::cout << "A jet plane has a thrust: " << GetTraction() << " kN.\n";
    }

    virtual void Show_Wing() const override 
    {
        std::cout << "A jet plane has a wing size: " << GetWingSize() << " m.\n";
    }

    void Show_Speed() const { std::cout << "The speed of the plane: " << speed_ << " km/h.\n"; }

private:
    int speed_; // швидкість літака
};

int main() {
    JetPlane jet(2400, 20, 80);
    jet.Show_Traction();
    jet.Show_Wing();
    jet.Show_Speed();

    return 0;
}
