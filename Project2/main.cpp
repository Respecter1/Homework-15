/*
	2. Виконайте від класу JetPlane, оголошеного в першій вправі, новий клас Boeing747.
*/

#include <iostream>
#include<cstring>

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

	virtual void Show_Speed() const { std::cout << "The speed of the plane: " << speed_ << " km/h.\n"; }
	
protected:
	int GetSpeed() const { return speed_; }
private:
	int speed_; // швидкість літака
};

class Boeing747
	:public JetPlane
{
public:
	Boeing747(int speed, int wing, int traction, const char* name)
		: JetPlane(traction, wing, speed), name_(nullptr), size_(0)
		//визначає довжину переданої стрічки за допомогою функції std::strlen(name) і виділяє достатньо пам’яті
		//  для її зберігання.Вам не потрібно вказувати довжину стрічки вручну; конструктор обробляє це за вас.
	{
		if (name != nullptr && std::strlen(name) != 0)
		{
			size_t lenght = std::strlen(name);
			size_ = lenght;
			name_ = new char[lenght + 1];
			strcpy_s(name_, lenght + 1, name);
		}
	}

	~Boeing747()
	{
		delete[] name_;
		name_ = nullptr;
		size_ = 0;
	}

	virtual void Show_Traction() const override //override для вказівки, що метод класу - є нащадком перевизначає віртуальний метод базового класу.
	{
		std::cout << "A jet plane has a thrust: " << GetTraction() << " kN.\n";
	}

	virtual void Show_Wing() const override
	{
		std::cout << "A jet plane has a wing size: " << GetWingSize() << " m.\n";
	}

	virtual void Show_Speed() const { std::cout << "The speed of the plane: " << GetSpeed() << " km/h.\n"; }
	
	void Show_Name() const { std::cout << "Name of the jet plane: " << GetName() << "\n"; }
	
	const char* GetName() const { return name_ ? name_ : ""; }
	

private:

	size_t size_;
	char* name_;
};

int main() {
	Boeing747 jet(2400, 20, 80, "Boeing747"); 
	jet.Show_Traction();
	jet.Show_Wing();
	jet.Show_Speed();
	jet.Show_Name();

	return 0;
}

