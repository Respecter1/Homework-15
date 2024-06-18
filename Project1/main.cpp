/*
1. ������� ���� JetPlane (���������� ����), ������������ ���� �� ���� ������� ����� � Rocket (������) �� Airplane (˳���).
*/

#include <iostream>

class Rocket {
public:
    Rocket(int traction) : traction_(traction) {}
    virtual ~Rocket() {}

    virtual void Show_Traction() const { std::cout << "Thrust of the rocket: " << traction_ << " kH.\n"; }

protected://�������� ��� �������� ������ �� ���� �� ���������� ���������, �� ���������� �������� ��������������� �� ������ .
    int GetTraction() const { return traction_; }

private:
    int traction_; // ���� ������
};

class Airplane {
public:
    Airplane(int wing) : wing_(wing) {}
    virtual ~Airplane() {}

    virtual void Show_Wing() const { std::cout << "Airplane wing size: " << wing_ << " m.\n"; }

protected:
    int GetWingSize() const { return wing_; }

private:
    int wing_; // ����� �����
};

class JetPlane : public Rocket, public Airplane {
public:

    JetPlane(int speed, int wing, int traction)
        : Rocket(traction), Airplane(wing), speed_(speed) {}

    //��� ���������� �� ������� �� ��� �����

    virtual void Show_Traction() const override //override ��� �������, �� ����� ����� - � �������� ����������� ���������� ����� �������� �����.
    {
        std::cout << "A jet plane has a thrust: " << GetTraction() << " kN.\n";
    }

    virtual void Show_Wing() const override 
    {
        std::cout << "A jet plane has a wing size: " << GetWingSize() << " m.\n";
    }

    void Show_Speed() const { std::cout << "The speed of the plane: " << speed_ << " km/h.\n"; }

private:
    int speed_; // �������� �����
};

int main() {
    JetPlane jet(2400, 20, 80);
    jet.Show_Traction();
    jet.Show_Wing();
    jet.Show_Speed();

    return 0;
}
