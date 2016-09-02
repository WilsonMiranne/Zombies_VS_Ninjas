#include <iostream>
struct Zambie
{
	int health;
	bool alive;
	int hunger;
};
struct Ninja
{
	int health;
	bool alive;
	int chi;
};
struct Abilities
{
	//both zombies and ninjas will have some ability cost
	int Feast;				//deals slightly lower damage but heals the zombie for half the damage dealt
	int Stalk;				//does no damage but replinishes hunger
	int Frenzy;				//deals high damage at the cost of health
	int UltUndead;			//at a massive hunger cost, deals high damage to all remaining ninja
			//the abilities above are for zombies, those below are for ninja
	int Ambush;				//deals high damage with a huge chi cost
	int Meditation;			//deals no damage but replinishes a moderate amount of chi and a small amount of health
	int Recover;			//deals no damage but replinishes a moderate amount of health
	int UltWarriorsHeart;	//Drains the remainder of your chi (minimum of 50) to fully restore all other ninla's health and chi
};
int Feast(Zambie &attacker, Ninja &defender)
{
	std::cout << "zambie uses feast against the ninja!" << std::endl;
	defender.health -= 8;
	std::cout << "the ninja took 8 damage his health is now ->" << defender.health << std::endl;
	attacker.health += 4;
	std::cout << "After using feast, zambie gains 4 health and is now at >-" << attacker.health << std::endl;
	attacker.hunger -= 10;
	std::cout << "the zambie used feast so his hunger is now" << attacker.hunger << std::endl;
	return defender.health, attacker.health, attacker.hunger;
}
int Stalk(Zambie &attacker, Ninja &defender)
{
	std::cout << "zambie uses stalk against the ninja!" << std::endl;
	defender.health -= 0;
	std::cout << "the ninja took 0 damage his health is now ->" << defender.health << std::endl;
	attacker.hunger += 15;
	std::cout << "After using feast, zambie gains 15 hunger and is now at >-" << attacker.hunger << std::endl;
	attacker.hunger -= 0;
	return attacker.hunger;
}
int Frenzy(Zambie &attacker, Ninja &defender)
{
	std::cout << "zambie uses frenzy against the ninja!" << std::endl;
	defender.health -= 30;
	std::cout << "the ninja took 30 damage his health is now ->" << defender.health << std::endl;
	attacker.health -= 10;
	std::cout << "After using frenzy, zambie loses 10 health and is now at >-" << attacker.health << std::endl;
	attacker.hunger -= 10;
	std::cout << "the zambie used frenzy so his hunger is now" << attacker.hunger << std::endl;
	return defender.health, attacker.health, attacker.hunger;
}
int UltUndead(Zambie &attacker, Ninja &defender)
{
	std::cout << "zambie uses Undead against the ninja!" << std::endl;
	defender.health -= 40;
	std::cout << "all ninja took 40 damage his health is now ->" << defender.health << std::endl;
	attacker.hunger -= 30;
	std::cout << "the zambie used feast so his hunger is now" << attacker.hunger << std::endl;
	return defender.health, attacker.hunger;
}
int Fight(Zambie &attacker, Ninja &defender)
{
	std::cout << "zambie is attacking ninja" << std::endl;
	defender.health -= 10;
	std::cout << "the ninja took 10 damage his health is now ->" << defender.health << std::endl;
	attacker.hunger -= 1;
	std::cout << "the zambie attacked so his hunger is now" << attacker.hunger << std::endl;
	//fighting is when a zambie "does damage" to a ninja
	//fighting is when a ninja "does damage" to a zambie
	//"damage" is when we decrement the health variable of a ninja or zambie
	//in order to do "damage" you must "attack"
	//"attack" is able to be performed if you have positive chi if you are a ninja or positive spirit if you a zambie
	return defender.health;
}

int Fight(Ninja &defender, Zambie &attacker)
{
	std::cout << "ninja is attacking zambie" << std::endl;
	attacker.health -= 15;
	std::cout << "the zambie took 15 damage his health is now ->" << attacker.health << std::endl;
	defender.chi -= 1;
	std::cout << "the ninja attacked so his chi is now" << defender.chi << std::endl;
	return attacker.health;
}

int Ambush(Ninja &defender, Zambie &attacker)
{
	std::cout << "ninja uses ambush against zambie" << std::endl;
	attacker.health -= 30;
	std::cout << "the zambie took 30 damage his health is now ->" << attacker.health << std::endl;
	defender.chi -= 40;
	std::cout << "the ninja atttacked with ambush so his chi is now" << defender.chi << std::endl;
	return attacker.health, defender.chi;
}
int Meditation(Ninja &defender, Zambie &attacker)
{
	std::cout << "ninja uses meditation" << std::endl;
	defender.health += 10;
	std::cout << "the ninja gains 10 health is now ->" << attacker.health << std::endl;
	defender.chi += 15;
	std::cout << "the ninja gains 15 chi is now" << defender.chi << std::endl;
	return defender.health, defender.chi;
}
int Recover(Ninja &defender, Zambie &attacker)
{
	std::cout << "ninja momentarily retreats to recover zambie" << std::endl;
	defender.health += 20;
	std::cout << "the ninja gains 20 health is now ->" << attacker.health << std::endl;
	defender.chi -= 20;
	std::cout << "the ninja uses recover so his chi is now" << defender.chi << std::endl;
	return defender.health, defender.chi;
}
int UltWarriorsHeart(Ninja &defender, Zambie &attacker)
{
	std::cout << "ninja uses Warrior's Heart" << std::endl;
	defender.health += 100;
	std::cout << "All allied Ninja gain 100 health. Their health is now ->" << attacker.health << std::endl;
	defender.chi -= 100;
	std::cout << "the ninja attacked so his chi is now" << defender.chi << std::endl;
	return attacker.health, defender.chi;
}

int main()
{
	Zambie chris = { 90, true, 5 };
	Zambie matthew = { 100, true, 15 };
	Ninja regi = { 150, true, 25 };
	Ninja wilson = { 100, true, 20 };
	char input = '0';

	std::cout << "Hello players and welcome to" << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%   The Ultimate Defense   %%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
	std::cout << "                               Survive the Undead" << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "In a world plagued by terrors known as zambies, undead beings with an" << std::endl;
	std::cout << "insatatable hunger roam the land." << std::endl;
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Only the Ninja, our brave defenders rose up in the name of peace to restore the" << std::endl;
	std::cout << "balance of the world, and protect the living." << std::endl;
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "For a balance must exist in all things. The living must remain in the realm" << std::endl;
	std::cout << "of the living, and the dead must reside with their own." << std::endl;
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "And the Ninja are here to enforce the balance strictly, onto their final breath." << std::endl;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "How to play:" << std::endl;
	std::cout << "There are two teams of two Zambies and two Ninja" << std::endl;
	std::cout << "It is simple, claim victory by destroying your enemies." << std::endl;
	std::cout << "Each team will take turns utilizing their unique abilities!" << std::endl;
	std::cout << "The Zambie teams abilities come as followed." << std::endl;
	std::cout << "(a) this is your basic attack. It will deal damage to a target Ninja" << std::endl;
	std::cout << "with a low cost" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(q) Feast: this will deal lower damage than your basic attack, but will heal you" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(w) Stalk: You deal no damage this turn but you heal and increase your hunger" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(e) Frenzy: at the cost of both your hunger and health." << std::endl;
	std::cout << "your attack will deal more damage" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(r) Undead: You utilize your ultimate power, dealing massive damaje to all Ninja" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "The Ninja team's abilities come as followed." << std::endl;
	std::cout << "(A) this is your basic attack. It will deal damage" << std::endl;
	std::cout << "to a target Zambie with a low cost" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(Q) Ambush: Your Ninja will attack with suprise on his side." << std::endl;
	std::cout << "This comes at a great chi cost" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(W) Meditation: Your training allows you to maintain a calm mind" << std::endl;
	std::cout << "replinishing chi and health" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(E) Recover: You decide not to fight, but to instead" << std::endl;
	std::cout << "use chi to heal your wounds" << std::endl;
	std::cout << "~~~" << std::endl;
	std::cout << "(R) Warriors Heart: In a heroic display you inspire all other ninja" << std::endl;
	std::cout << "revitalizing your allies while sacrificing all of your chi" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "You use your team's abilities by pressing the cooresponding button in the () during your team's turn." << std::endl;
	std::cout << "The game ends " << std::endl;

	while (input != '`')
	{
		std::cin >> input;
		if (input == 'a')
		{
			std::cout << "CHRIS FIGHT REGI" << std::endl;
			Fight(chris, regi);
			
		}
		std::cin >> input;
		if (input == 'q')
		{
			std::cout << "Chris uses the ability ambush!" << std::endl;

			if (Feast(chris, regi))
			{
				regi.health -= 8;
				chris.health += 4;
				chris.hunger -= 10;
				
			}
		}
		std::cin >> input;
		if (input == 'w')
		{
			std::cout << "Chris retreats and stalks his prey!" << std::endl;

			if (Stalk(chris, regi))
			{
				chris.health += 15;
				chris.hunger += 10;
				
			}
		}
		std::cin >> input;
		if (input == 'e')
		{
			std::cout << "Chris goes into a Frenzy!" << std::endl;

			if (Frenzy(chris, regi))
			{
				chris.hunger -= 10;
				chris.health -= 10;
				regi.health -= 30;
				
			}
		}
		std::cin >> input;
		if (input == 'r')
		{
			std::cout << "Chris calls for the undead!" << std::endl;

			if (UltUndead(chris, regi))
			{
				chris.hunger -= 30;
				regi.health -= 40;
				
			}
		}
		std::cin >> input;

		if (Fight(chris, regi) <= 0)
		{
			std::cout << "Chris has defeated the regi... GAME OVER\n" << std::endl;
			std::cout << "get gud lol. \n \a" << std::endl;
		
		}

		std::cin >> input;
		if (input == 'A')
		{
			std::cout << "REGI FIGHT CHRIS" << std::endl;

			Fight(regi, chris);

		}
		std::cin >> input;
		if (input == 'Q')
		{
			std::cout << "Regi ambushes chris!";

			if (Ambush(regi, chris))
			{
				regi.chi -= 30;
				chris.health -= -40;
			
			}
		}
		std::cin >> input;
		if (input == 'W')
		{
			std::cout << "Regi begins to meditate!" << std::endl;

			if (Meditation(regi, chris))
			{
				regi.health += 10;
				regi.chi += 15;
			
			}
		}
		std::cin >> input;
		if (input == 'E')
		{
			std::cout << "Regi retreats to recover!" << std::endl;

			if (Recover(regi, chris))
			{
				regi.chi -= 20;
				regi.health = +20;
			
			}
		}
		std::cin >> input;
		if (input == 'R')
		{
			std::cout << "Regi shows the heart of a warrior! Wilson gains determination!" << std::endl;

			if (UltWarriorsHeart(regi, chris))
			{
				regi.health += 100;
				regi.chi == 0;
				wilson.health += 100;
				wilson.chi += 100;
			
			}
		}
		std::cin >> input;
		if (Fight(regi, chris) <= 0)
		{
			printf("The Ninja has Defeated the Zambie... GAME OVER\n");
			printf("get guhd lol. \n \a");
			break;
		}
		std::cin >> input;
		if (Fight(chris, regi) <= 0)
		{
			printf("The Zambie has defeated the Ninja... GAME OVER\n");
			printf("get guhd lol. \n \a");
			break;
		}
		printf("new frame \n");
	}

	system("pause");
	//how i fight??
	return 0;
}