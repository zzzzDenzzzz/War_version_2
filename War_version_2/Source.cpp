#include<iostream>
#include<vector>

using namespace std;

class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {};
};

class Infantryman : public Warrior
{
public:
	void info() override
	{
		cout << "Infantryman ";
	}
};

class Archer : public Warrior
{
public:
	void info() override
	{
		cout << "Archer ";
	}
};

class Horseman : public Warrior
{
public:
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
	virtual void info() = 0;
	virtual ~Weapon() {};
};

class Sword : public Weapon
{
public:
	void info() override
	{
		cout << "Sword" << endl;
	}
};

class Bow : public Weapon
{
public:
	void info() override
	{
		cout << "Bow" << endl;
	}
};

class Pike : public Weapon
{
public:
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

int main()
{
	pair<InfantryFactory, SwordFactory> infantryman;
	vector<pair<InfantryFactory, SwordFactory>> v_i;

	v_i.push_back(infantryman);
	for (size_t i = 0; i < v_i.size(); i++)
	{
		v_i[i].first.createWarior()->info();
		v_i[i].second.createWeapon()->info();
	}

	return 0;
}