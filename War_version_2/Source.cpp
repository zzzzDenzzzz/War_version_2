#include<iostream>
#include<vector>
#include<random>

using namespace std;

class Warrior
{
public:
	int health;
	int damage;
	virtual void info() = 0;
	virtual ~Warrior() {};

	void healthDecrease(int damage)
	{
		health -= damage;
	}

	void damageIncrease(int damage)
	{
		this->damage += damage;
	}
};

class Infantryman : public Warrior
{
public:
	Infantryman()
	{
		health = 100;
		damage = 100;
	}
	void info() override
	{
		cout << "Infantryman ";
	}
};

class Archer : public Warrior
{
public:
	Archer()
	{
		health = 50;
		damage = 150;
	}
	void info() override
	{
		cout << "Archer ";
	}
};

class Horseman : public Warrior
{
public:
	Horseman()
	{
		health = 150;
		damage = 200;
	}
	void info() override
	{
		cout << "Horseman ";
	}
};

class FactoryWarrior
{
public:
	virtual Warrior *createWarior() = 0;
	virtual ~FactoryWarrior() {};
};

class InfantryFactory : public FactoryWarrior
{
public:
	Warrior *createWarior()
	{
		return new Infantryman;
	}
};

class ArchersFactory : public FactoryWarrior
{
public:
	Warrior *createWarior()
	{
		return new Archer;
	}
};

class HorsemanFactory : public FactoryWarrior
{
public:
	Warrior *createWarior()
	{
		return new Horseman;
	}
};

class Weapon
{
public:
	int damage;
	virtual void info() = 0;
	virtual ~Weapon() {};
};

class Sword : public Weapon
{
public:
	Sword()
	{
		damage = 50;
	}
	void info() override
	{
		cout << "Sword" << endl;
	}
};

class Bow : public Weapon
{
public:
	Bow()
	{
		damage = 100;
	}
	void info() override
	{
		cout << "Bow" << endl;
	}
};

class Pike : public Weapon
{
public:
	Pike()
	{
		damage = 80;
	}
	void info() override
	{
		cout << "Pike" << endl;
	}
};

class FactoryWeapon
{
public:
	virtual Weapon *createWeapon() = 0;
	virtual ~FactoryWeapon() {};
};

class SwordFactory : public FactoryWeapon
{
public:
	Weapon *createWeapon()
	{
		return new Sword;
	}
};

class BowFactory : public FactoryWeapon
{
public:
	Weapon *createWeapon()
	{
		return new Bow;
	}
};

class PikeFactory : public FactoryWeapon
{
public:
	Weapon *createWeapon()
	{
		return new Pike;
	}
};

class Army
{
//public:
	int population_army;
	int power_army;

	pair<InfantryFactory, SwordFactory> infantryman;
	vector<pair<InfantryFactory, SwordFactory>> v_i;

	pair<ArchersFactory, BowFactory> archer;
	vector<pair<ArchersFactory, BowFactory>> v_a;

	pair<HorsemanFactory, PikeFactory> horseman;
	vector<pair<HorsemanFactory, PikeFactory>> v_h;
public:
	Army()
	{
		v_i.push_back(infantryman);
		v_a.push_back(archer);
		v_h.push_back(horseman);
		population_army = 0;
		power_army = 0;
	}

	void createInfantryman()
	{
		for (size_t i = 0; i < v_i.size(); i++)
		{
			v_i[i].first.createWarior();
			v_i[i].second.createWeapon();
		}
	}

	void createArcher()
	{
		for (size_t i = 0; i < v_a.size(); i++)
		{
			v_a[i].first.createWarior();
			v_a[i].second.createWeapon();
		}
	}

	void createHorseman()
	{
		for (size_t i = 0; i < v_h.size(); i++)
		{
			v_h[i].first.createWarior();
			v_h[i].second.createWeapon();
		}
	}

	void changePopulationInfantryman(int population)
	{
		v_i.resize(population);
		createInfantryman();
		population_army += population;
	}

	void changePopulationArcher(int population)
	{
		v_a.resize(population);
		createArcher();
		population_army += population;
	}

	void changePopulationHorseman(int population)
	{
		v_h.resize(population);
		createHorseman();
		population_army += population;
	}

	void showPopulationArmy()
	{
		cout << "population army = " << population_army << endl;
	}

	void showPowerArmy()
	{
		for (size_t i = 0; i < v_i.size(); i++)
		{
			power_army += (v_i[i].first.createWarior()->damage + v_i[i].second.createWeapon()->damage);
		}

		for (size_t i = 0; i < v_a.size(); i++)
		{
			power_army += (v_a[i].first.createWarior()->damage + v_a[i].second.createWeapon()->damage);
		}

		for (size_t i = 0; i < v_h.size(); i++)
		{
			power_army += (v_h[i].first.createWarior()->damage + v_h[i].second.createWeapon()->damage);
		}
		cout << "power army = " << power_army << endl;
	}
};

class Game
{
	Army army_1;
	Army army_2;
public:

};

int main()
{
	Army army_1;
	army_1.changePopulationInfantryman(1000);
	army_1.changePopulationArcher(300);
	army_1.changePopulationHorseman(300);
	army_1.showPopulationArmy();
	army_1.showPowerArmy();

	Army army_2;
	army_2.changePopulationInfantryman(2000);
	army_2.changePopulationArcher(200);
	army_2.changePopulationHorseman(100);
	army_2.showPopulationArmy();
	army_2.showPowerArmy();

	return 0;
}