#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

class Sword {
	string name;
	int att;
public:
	Sword(string n, int a)
	{
		name = n;
		att = a;
	}
	string get_name()
	{
		return name;
	}
	int get_att()
	{
		return att;
	}
};
class Shield {
	string name;
	int def;
public:
	Shield(string n, int d)
	{
		name = n;
		def = d;
	}
	string get_name()
	{
		return name;
	}
	int get_def()
	{
		return def;
	}
};
class Armor {
	string name;
	int hp;
public:
	Armor(string n, int h)
	{
		name = n;
		hp = h;
	}
	string get_name()
	{
		return name;
	}
	int get_hp()
	{
		return hp;
	}
};
class Hero {
	string name;
	int lvl;
	Sword sword = Sword("empty", 0);
	Shield shield = Shield("empty", 0);
	Armor armor = Armor("empty", 0);
public:
	Hero(string n, int i)
	{
		name = n;
		lvl = i;
	}
	string get_name()
	{
		return name;
	}
	int get_lvl()
	{
		return lvl;
	}
	void lvl_up()
	{
		lvl++;
		system("CLS");
		cout << name << " leveled up!\n"
			<< name << " is now level " << lvl << "!\n\n";
		system("pause");
	}
	void set_sword(Sword s)
	{
		string s1 = "", s2 = "";
		while (s1 != "y" && s1 != "n")
		{
			system("CLS");
			cout << "new:\n"
				<< right << setw(25) << s.get_name() << setw(5) << s.get_att() << " att\n\n"
				<< left << "equipped:\n"
				<< right << setw(25) << sword.get_name() << setw(5) << sword.get_att() << " att\n\n"
				<< left << "Would you like to exchange weapons? (y/n)\n";
			getline(cin, s1, '\n');
			if (s1 == "y" || s1 == "n")
			{
				while (s2 != "y" && s2 != "n")
				{
					system("CLS");
					cout << "Are you sure? (y/n)\n\n"
						<< "Discarded items cannot be recovered.\n";
					getline(cin, s2, '\n');
				}
				if (s2 == "n")
				{
					s1 = "";
					s2 = "";
				}
			}
		}
		if (s1 == "y")
		{
			sword = s;
		}
	}
	Sword get_sword()
	{
		return sword;
	}
	void set_shield(Shield s)
	{
		string s1 = "", s2 = "";
		while (s1 != "y" && s1 != "n")
		{
			system("CLS");
			cout << "new:\n"
				<< right << setw(25) << s.get_name() << setw(5) << s.get_def() << " def\n\n"
				<< left << "equipped:\n"
				<< right << setw(25) << shield.get_name() << setw(5) << shield.get_def() << " def\n\n"
				<< left << "Would you like to exchange shields? (y/n)\n";
			getline(cin, s1, '\n');
			if (s1 == "y" || s1 == "n")
			{
				while (s2 != "y" && s2 != "n")
				{
					system("CLS");
					cout << "Are you sure? (y/n)\n\n"
						<< "Discarded items cannot be recovered.\n";
					getline(cin, s2, '\n');
				}
				if (s2 == "n")
				{
					s1 = "";
					s2 = "";
				}
			}
		}
		if (s1 == "y")
		{
			shield = s;
		}
	}
	Shield get_shield()
	{
		return shield;
	}
	void set_armor(Armor a)
	{
		string s1 = "", s2 = "";
		while (s1 != "y" && s1 != "n")
		{
			system("CLS");
			cout << "new:\n"
				<< right << setw(25) << a.get_name() << setw(5) << a.get_hp() << " hp\n\n"
				<< left << "equipped:\n"
				<< right << setw(25) << armor.get_name() << setw(5) << armor.get_hp() << " hp\n\n"
				<< left << "Would you like to exchange armor? (y/n)\n";
			getline(cin, s1, '\n');
			if (s1 == "y" || s1 == "n")
			{
				while (s2 != "y" && s2 != "n")
				{
					system("CLS");
					cout << "Are you sure? (y/n)\n\n"
						<< "Discarded items cannot be recovered.\n";
					getline(cin, s2, '\n');
				}
				if (s2 == "n")
				{
					s1 = "";
					s2 = "";
				}
			}
		}
		if (s1 == "y")
		{
			armor = a;
		}
	}
	Armor get_armor()
	{
		return armor;
	}
	int get_att()
	{
		int att = lvl + sword.get_att();
		return att;
	}
	int get_def()
	{
		int def = lvl + shield.get_def();
		return def;
	}
	int get_hp()
	{
		int hp = lvl + armor.get_hp();
		return hp;
	}
};
bool home()
{
	string s = "";
	while (s != "y" && s != "n")
	{
		system("CLS");
		cout << setfill('*') << setw(60) << "" << endl
			<< setw(20) << "" << " Dungeon Adventures " << setw(20) << "" << endl
			<< setw(60) << "" << endl
			<< setfill(' ') << endl
			<< "Enter? (y=yes/n=no)\n";
		getline(cin, s, '\n');
	}
	if (s == "y")
	{
		srand(time(0));
		return true;
	}
	else
	{
		return false;
	}
}
Hero createHero()
{
	bool correct = false;
	string name = "", s = "";
	while (!correct)
	{
		system("CLS");
		cout << "Please enter your name: ";
		getline(cin, name, '\n');
		while (s != "y" && s != "n")
		{
			system("CLS");
			cout << "Is " << name << " correct? (y/n)\n";
			getline(cin, s, '\n');
		}
		if (s == "y")
		{
			correct = true;
		}
		else
		{
			s = "";
		}
	}
	Hero hero = Hero(name, 1);
	system("CLS");
	cout << "Welcome " << hero.get_name() << "!\n\n"
		<< "You are about to enter a dangerous dungeon full of monsters and riches.\n"
		<< "Navigate through the labyrinth by selecting which path to travel down.\n"
		<< "Along the way you will face many foes and find useful equipment.\n"
		<< "Legend has it that a powerful dragon lives in the deepest recess of the dungeon.\n"
		<< "It is also said that the dragon's den holds a plethora of gold and jewels.\n"
		<< "Many adventurers have tried to slay the dragon but none have been successful.\n\n"
		<< "Good luck!\n\n";
	system("pause");
	return hero;
}
Sword drawSword(Hero hero, int i)
{
	Sword s[] =
	{
		Sword("Stick", 1),
		Sword("Knife", 5),
		Sword("Hatchet", 10),
		Sword("Dagger", 50),
		Sword("Bronze Sword", 100),
		Sword("Iron Sword", 200),
		Sword("Steel Sword", 300),
		Sword("Battle Axe", 400),
		Sword("Hero Sword", 500),
		Sword("Demon Sword", 666),
		Sword("God Sword", 1000)
	};
	system("CLS");
	cout << hero.get_name() << " found a " << s[i].get_name() << "!\n\n";
	system("pause");
	return s[i];
}
Shield drawShield(Hero hero, int i)
{
	Shield s[] =
	{
		Shield("Leather Shield", 1),
		Shield("Wooden Shield", 5),
		Shield("Buckler", 10),
		Shield("Aspis", 50),
		Shield("Bronze Shield", 100),
		Shield("Iron Shield", 200),
		Shield("Steel Shield", 300),
		Shield("Spiked Shield", 400),
		Shield("Hero Shield", 500),
		Shield("Demon Shield", 666),
		Shield("God Shield", 1000)
	};
	system("CLS");
	cout << hero.get_name() << " found a " << s[i].get_name() << "!\n\n";
	system("pause");
	return s[i];
}
Armor drawArmor(Hero hero, int i)
{
	Armor a[] =
	{
		Armor("Leather Armor", 1),
		Armor("Brigandine", 5),
		Armor("Chain Mail", 10),
		Armor("Cuirass", 50),
		Armor("Bronze Armor", 100),
		Armor("Iron Armor", 200),
		Armor("Steel Armor", 300),
		Armor("Studded Armor", 400),
		Armor("Hero Armor", 500),
		Armor("Demon Armor", 666),
		Armor("God Armor", 1000)
	};
	system("CLS");
	cout << hero.get_name() << " found a " << a[i].get_name() << "!\n\n";
	system("pause");
	return a[i];
}
int path()
{
	string s = "";
	while (s != "q" && s != "w" && s != "a" && s != "s" && s != "d" && s != "lvlup" && s != "boss" && s != "godmode")
	{
		system("CLS");
		cout << "Three paths diverge in front of you.\n"
			<< "Which direction would you like to go?\n\n"
			<< "Enter a/w/d to select your route. (a=left, w=middle, d=right)\n\n"
			<< "You may also enter 'q' to view your hero's stats and equipment or 's' to return to the home screen.\n";
		getline(cin, s, '\n');
	}
	if (s == "w" || s == "a" || s == "d")
	{
		return rand() % 3;
	}
	else if (s == "q")
	{
		return 3;
	}
	else if (s == "s")
	{
		return 4;
	}
	else if (s == "lvlup")
	{
		return 5;
	}
	else if (s == "godmode")
	{
		return 6;
	}
	else if (s == "boss")
	{
		return 7;
	}
}
bool fight(Hero hero, Hero enemy)
{
	int damage, hhp = hero.get_hp(), ehp = enemy.get_hp();
	while (hhp > 0 && ehp > 0)
	{
		damage = hero.get_att() - enemy.get_def() / 2;
		if (damage < 1)
		{
			damage = 1;
		}
		ehp -= damage;
		if (ehp < 0)
		{
			ehp = 0;
		}
		system("CLS");
		cout << hero.get_name() << " attacked the " << enemy.get_name() << "!\n"
			<< hero.get_name() << " did " << damage << " damage!\n"
			<< "The " << enemy.get_name() << " has " << ehp << " hp remaining!\n\n";
		system("pause");
		if (ehp > 0)
		{
			damage = enemy.get_att() - hero.get_def() / 2;
			if (damage < 1)
			{
				damage = 1;
			}
			hhp -= damage;
			if (hhp < 0)
			{
				hhp = 0;
			}
			system("CLS");
			cout << "The " << enemy.get_name() << " attacked " << hero.get_name() << "!\n"
				<< "The " << enemy.get_name() << " did " << damage << " damage!\n"
				<< hero.get_name() << " has " << hhp << " hp remaining!\n\n";
			system("pause");
		}
	}
	if (ehp == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void combat(Hero& hero)
{
	if (hero.get_lvl() < 5)
	{
		system("CLS");
		cout << hero.get_name() << " stumbled upon a rat!\n\n";
		system("pause");
		if (fight(hero, Hero("rat", 1)))
		{
			hero.lvl_up();
		}
		if (rand() % 5 == 0)
		{
			system("CLS");
			cout << "The rat dropped an item!\n\n";
			system("pause");
			switch (rand() % 3)
			{
			case 0:
				hero.set_sword(drawSword(hero, 0));
				break;
			case 1:
				hero.set_shield(drawShield(hero, 0));
				break;
			case 2:
				hero.set_armor(drawArmor(hero, 0));
				break;
			}
		}
	}
	else if (hero.get_lvl() < 10)
	{
		system("CLS");
		cout << "A spider dropped down in front of " << hero.get_name() << "!\n\n";
		system("pause");
		if (fight(hero, Hero("spider", 5)))
		{
			hero.lvl_up();
		}
		if (rand() % 5 == 0)
		{
			system("CLS");
			cout << "The spider dropped an item!\n\n";
			system("pause");
			switch (rand() % 3)
			{
			case 0:
				hero.set_sword(drawSword(hero, 1));
				break;
			case 1:
				hero.set_shield(drawShield(hero, 1));
				break;
			case 2:
				hero.set_armor(drawArmor(hero, 1));
				break;
			}
		}
	}
	else if (hero.get_lvl() < 25)
	{
		system("CLS");
		cout << "A goblin charged at " << hero.get_name() << "!\n\n";
		system("pause");
		if (fight(hero, Hero("goblin", 10)))
		{
			hero.lvl_up();
		}
		if (rand() % 5 == 0)
		{
			system("CLS");
			cout << "The goblin dropped an item!\n\n";
			system("pause");
			switch (rand() % 3)
			{
			case 0:
				hero.set_sword(drawSword(hero, 3));
				break;
			case 1:
				hero.set_shield(drawShield(hero, 3));
				break;
			case 2:
				hero.set_armor(drawArmor(hero, 3));
				break;
			}
		}
	}
	else if (hero.get_lvl() < 50)
	{
		system("CLS");
		cout << "A skeleton charged at " << hero.get_name() << "!\n\n";
		system("pause");
		if (fight(hero, Hero("skeleton", 25)))
		{
			hero.lvl_up();
		}
		if (rand() % 5 == 0)
		{
			system("CLS");
			cout << "The skeleton dropped an item!\n\n";
			system("pause");
			switch (rand() % 3)
			{
			case 0:
				hero.set_sword(drawSword(hero, 5));
				break;
			case 1:
				hero.set_shield(drawShield(hero, 5));
				break;
			case 2:
				hero.set_armor(drawArmor(hero, 5));
				break;
			}
		}
	}
	else if (hero.get_lvl() < 85)
	{
		system("CLS");
		cout << "A wraith lunged at " << hero.get_name() << " from the dark!\n\n";
		system("pause");
		if (fight(hero, Hero("wraith", 50)))
		{
			hero.lvl_up();
		}
		if (rand() % 5 == 0)
		{
			system("CLS");
			cout << "The wraith dropped an item!\n\n";
			system("pause");
			switch (rand() % 3)
			{
			case 0:
				hero.set_sword(drawSword(hero, 7));
				break;
			case 1:
				hero.set_shield(drawShield(hero, 7));
				break;
			case 2:
				hero.set_armor(drawArmor(hero, 7));
				break;
			}
		}
	}
	else
	{
		system("CLS");
		cout << "A demon lunged at " << hero.get_name() << " from the dark!\n\n";
		system("pause");
		if (fight(hero, Hero("demon", 85)))
		{
			hero.lvl_up();
		}
		if (rand() % 5 == 0)
		{
			system("CLS");
			cout << "The demon dropped an item!\n\n";
			system("pause");
			switch (rand() % 3)
			{
			case 0:
				hero.set_sword(drawSword(hero, 9));
				break;
			case 1:
				hero.set_shield(drawShield(hero, 9));
				break;
			case 2:
				hero.set_armor(drawArmor(hero, 9));
				break;
			}
		}
	}
}
void equipment(Hero& hero)
{
	if (hero.get_lvl() < 5)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 3));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 3));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 3));
			break;
		}
	}
	else if (hero.get_lvl() < 10)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 4));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 4));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 4));
			break;
		}
	}
	else if (hero.get_lvl() < 20)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 5));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 5));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 5));
			break;
		}
	}
	else if (hero.get_lvl() < 30)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 5 + 1));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 5 + 1));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 5 + 1));
			break;
		}
	}
	else if (hero.get_lvl() < 40)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 5 + 2));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 5 + 2));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 5 + 2));
			break;
		}
	}
	else if (hero.get_lvl() < 50)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 5 + 3));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 5 + 3));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 5 + 3));
			break;
		}
	}
	else if (hero.get_lvl() < 60)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 5 + 4));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 5 + 4));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 5 + 4));
			break;
		}
	}
	else if (hero.get_lvl() < 70)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 5 + 5));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 5 + 5));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 5 + 5));
			break;
		}
	}
	else if (hero.get_lvl() < 80)
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 4 + 6));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 4 + 6));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 4 + 6));
			break;
		}
	}
	else
	{
		switch (rand() % 3)
		{
		case 0:
			hero.set_sword(drawSword(hero, rand() % 3 + 7));
			break;
		case 1:
			hero.set_shield(drawShield(hero, rand() % 3 + 7));
			break;
		case 2:
			hero.set_armor(drawArmor(hero, rand() % 3 + 7));
			break;
		}
	}
}
int boss(Hero hero)
{
	string s = "";
	while (s != "y" && s != "n")
	{
		system("CLS");
		cout << "You see a faint glow up ahead.\n"
			<< "As you approach you notice a putrid odor.\n"
			<< "When you get closer you realize the light is dragon fire and the stench is charred flesh.\n"
			<< "It must be the dragon's den.\n\n"
			<< "Do you dare enter? (y/n)\n";
		getline(cin, s, '\n');
	}
	if (s == "n")
	{
		return 3;
	}
	else
	{
		system("CLS");
		cout << "A lvl 500 Dragon guards a bountiful treasure.\n\n";
		system("pause");
		if (fight(hero, Hero("dragon", 500)))
		{
			system("CLS");
			cout << "Congratulations! " << hero.get_name() << " defeated the Dragon and won the treasure!\n\n";
			system("pause");
			return 1;
		}
		else
		{
			system("CLS");
			cout << "Oh no! " << hero.get_name() << " was defeated by the the Dragon!\n\n";
			system("pause");
			return 2;
		}
	}
}
void inventory(Hero hero)
{
	Sword s = hero.get_sword();
	Shield sh = hero.get_shield();
	Armor a = hero.get_armor();
	system("CLS");
	cout << setfill('*') << setw(60) << "" << endl
		<< setw(24) << "" << " Inventory " << setw(25) << "" << endl
		<< setw(60) << "" << endl
		<< endl
		<< setfill('.') << left << setw(30) << "name:" << right << setw(30) << hero.get_name() << endl
		<< left << setw(30) << "level:" << right << setw(30) << hero.get_lvl() << endl
		<< left << setw(30) << "attack:" << right << setw(30) << hero.get_att() << endl
		<< left << setw(30) << "defence:" << right << setw(30) << hero.get_def() << endl
		<< left << setw(30) << "health:" << right << setw(30) << hero.get_hp() << endl
		<< left << setw(30) << "sword:" << setw(25) << s.get_name() << right << setw(5) << s.get_att() << endl
		<< left << setw(30) << "shield:" << setw(25) << sh.get_name() << right << setw(5) << sh.get_def() << endl
		<< left << setw(30) << "armor:" << setw(25) << a.get_name() << right << setw(5) << a.get_hp() << endl
		<< left << setfill(' ') << endl;
	system("pause");
}
bool cont(Hero hero)
{
	string s = "";
	while (s != "y" && s != "n")
	{
		system("CLS");
		cout << hero.get_name() << " came to right outside the dragon's den.\n"
			<< "You can either go back and explore the dungeon to get stronger or look for a way out.\n\n"
			<< "Continue exploring? (y/n)\n";
		getline(cin, s, '\n');
	}
	if (s == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool exit()
{
	string s = "";
	while (s != "y" && s != "n")
	{
		system("CLS");
		cout << "Are you sure you want to exit the dungeon?\n"
			<< "All progress will be lost.\n"
			<< "Exit? (y/n)\n";
		getline(cin, s, '\n');
	}
	if (s == "y")
	{
		return true;
	}
	else
	{
		return false;
	}
}
void credits(Hero hero)
{
	Sword s = hero.get_sword();
	Shield sh = hero.get_shield();
	Armor a = hero.get_armor();
	system("CLS");
	cout << setfill('*') << setw(60) << "" << endl
		<< setw(25) << "" << " Victory " << setw(26) << "" << endl
		<< setw(60) << "" << endl
		<< endl
		<< setfill('.') << left << setw(30) << "name:" << right << setw(30) << hero.get_name() << endl
		<< left << setw(30) << "level:" << right << setw(30) << hero.get_lvl() << endl
		<< left << setw(30) << "attack:" << right << setw(30) << hero.get_att() << endl
		<< left << setw(30) << "defence:" << right << setw(30) << hero.get_def() << endl
		<< left << setw(30) << "health:" << right << setw(30) << hero.get_hp() << endl
		<< left << setw(30) << "sword:" << setw(25) << s.get_name() << right << setw(5) << s.get_att() << endl
		<< left << setw(30) << "shield:" << setw(25) << sh.get_name() << right << setw(5) << sh.get_def() << endl
		<< left << setw(30) << "armor:" << setw(25) << a.get_name() << right << setw(5) << a.get_hp() << endl
		<< left << setfill(' ') << endl;
	system("pause");
	ofstream f;
	f.open("Completion_Certificate.txt");
	f << setfill('*') << setw(60) << "" << endl
		<< setw(25) << "" << " Victory " << setw(26) << "" << endl
		<< setw(60) << "" << endl
		<< endl
		<< setfill('.') << left << setw(30) << "name:" << right << setw(30) << hero.get_name() << endl
		<< left << setw(30) << "level:" << right << setw(30) << hero.get_lvl() << endl
		<< left << setw(30) << "attack:" << right << setw(30) << hero.get_att() << endl
		<< left << setw(30) << "defence:" << right << setw(30) << hero.get_def() << endl
		<< left << setw(30) << "health:" << right << setw(30) << hero.get_hp() << endl
		<< left << setw(30) << "sword:" << setw(25) << s.get_name() << right << setw(5) << s.get_att() << endl
		<< left << setw(30) << "shield:" << setw(25) << sh.get_name() << right << setw(5) << sh.get_def() << endl
		<< left << setw(30) << "armor:" << setw(25) << a.get_name() << right << setw(5) << a.get_hp() << endl
		<< left << setfill(' ') << endl;
	f.close();
	system("CLS");
	cout << setfill('*') << setw(60) << "" << endl
		<< setw(25) << "" << " Credits " << setw(26) << "" << endl
		<< setw(60) << "" << endl
		<< endl
		<< setfill('.') << left << setw(30) << "Hero Class" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Sword Class" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Shield Class" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Armor Class" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Home Screen" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Hero Creation" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Route Selection" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Combat Room" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Combat" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Equipment Room" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Sword Draw" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Shield Draw" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Armor Draw" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Boss Fight" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Inventory" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Continue Function" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Exit Function" << right << setw(30) << "BB" << endl
		<< setfill('.') << left << setw(30) << "Credits" << right << setw(30) << "BB" << endl
		<< setfill(' ') << endl
		<< setw(41) << "Thank You For Playing!" << endl
		<< left << endl;
	system("pause");
}
int main()
{
	bool quit = false;
	while (!quit)
	{
		if (home())
		{
			Hero hero = createHero();
			for (int i = 0; i < 100; i)
			{
				switch (path())
				{
				case 0:
				case 1:
					combat(hero);
					i++;
					break;
				case 2:
					equipment(hero);
					i++;
					break;
				case 3:
					inventory(hero);
					break;
				case 4:
					if (exit())
					{
						i = 101;
					}
					break;
				case 5:
					hero.lvl_up();
					break;
				case 6:
					hero.set_sword(drawSword(hero, 10));
					hero.set_shield(drawShield(hero, 10));
					hero.set_armor(drawArmor(hero, 10));
					break;
				case 7:
					i = 100;
					break;
				}
				if (i == 100)
				{
					switch (boss(hero))
					{
					case 1:
						credits(hero);
						break;
					case 2:
						if (cont(hero))
						{
							i = 90;
						}
						else
						{
							if (!exit())
							{
								i = 90;
							}
						}
						break;
					case 3:
						i = 90;
						break;
					}
				}
			}
		}
		else
		{
			quit = true;
		}
	}
}