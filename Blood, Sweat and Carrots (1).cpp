/************************************************************************************************************************************************************************************************************************************************
Jan 8th, 2018
Jack Huang
Dev C++ 5.11
purpose: take care of an anthro bunny
(SUMMATIVE - alone)

	Dictionary: 		MenuOp - variable to start the game											Cont/Cont2 - used to advance the info screens 
						AaronEvt - the switch that activates a special event						PlayCounter - used as a loop in the actions menu
						BunBun - used to choose what option the player wants in game				Currency - used to keep track of bag space 
						GameOp - used to choose what action the player wants to do to the pet		
*************************************************************************************************************************************************************************************************************************************************/

//bringing in files
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

//declairing functions
int ItemShop (int &Currency, int ITEMS[]);
int BunnyPlay (int &HungerStat, int &WaterStat, int &MentalStat, int &StressNumber, int &EnergyMeter);
int FeedingBun (int &FoodMeter, int &ThirstMeter, int &StressMeter, int &SanityMeter, int &EnergyMeter, int FoodArray[]);
void BunnyStats (int Sanitystat, int Foodstat, int Thirststat, int Stressstat);
void FoodMenu (int Items[]);
void IntroMessage (int Sanity, int Days);

//start of main program
main()
{
	//declairing variables
	string PlayerName;
	char End, GameRestart = 'y';
	bool Death = false, AaronEvt = false, Restart = true;
	int RandomEvent, MenuOp;
	int BunBun, Bagspace;
	srand((int) time(0));
	
	//prompts the player to start the game
	cout<<"______ _                 _     _____                    _                     _   _____                      _\n"; 
	cout<<"| ___ \\ |               | |   /  ___|                  | |                   | | /  __ \\                    | |\n";  
	cout<<"| |_/ / | ___   ___   __| |   \\ `--.__      _____  __ _| |_    __ _ _ __   __| | | /  \\/ __ _ _ __ _ __ ___ | |_ ___\n";
	cout<<"| ___ \\ |/ _ \\ / _ \\ / _` |    `--. \\ \\ /\\ / / _ \\/ _` | __|  / _` | '_ \\ / _` | | |    / _` | '__| '__/ _ \\| __/ __|\n";
	cout<<"| |_/ / | (_) | (_) | (_| |_  /\\__/ /\\ V  V /  __/ (_| | |_  | (_| | | | | (_| | | \\__/\\ (_| | |  | | | (_) | |_\\__ \\\n";
	cout<<"\\____/|_|\\___/ \\___/ \\__,_( ) \\____/  \\_/\\_/ \\___|\\__,_|\\__|  \\__,_|_| |_|\\__,_|  \\____/\\__,_|_|  |_|  \\___/ \\__|___/\n";
	cout<<"	                  |/                                                                                   V1.0\n";                                                                                        
	cout<<"\n-------------------------------------------------------------------------------------------------------------\n";
	cout<<"[1] - Play\n\nEnter here: ";
	cin>>MenuOp;

	//asks the player for their name
	system("CLS");
	cout<<"Hello! You have been chosen to take care of a new specimen named Ethan, before you start, can I get your name? We need\nit for credentials and things...";
	cout<<"\n-------------------------------------------------------------------------------------------------------------";
	cout<<"\nEnter your name: ";
	cin>>PlayerName;
	
	//capitalizes all the letters in name
	for(int i = 0; i < PlayerName.length(); i++)
	{
		PlayerName[i] = toupper(PlayerName[i]);
	}
	
	//tells the player what to do in the game
	system("CLS");
	cout<<"There we go, here's your ID tag, this will allow you in and out of here. Have fun but remember to care for the specimen.\nHe gets a little... well, good luck!";
	cout<<"\n-------------------------------------------------------------------------------------------------------------";
	Sleep(2000);
	
	while ((GameRestart == 'y')||(GameRestart == 'Y'))
	{	
		int Objects[4] = {0, 0, 0, 0};
		int DayCounter = 0;
		int FoodStat = 0;
		int ThirstStat = 0;
		int StressStat = 0;
		int SaneStat = 100;
		Death = false;
	
		//loops until the player loses
		while (Death == false)
		{
			//declairing and setting variables 
			bool DayEnd = false;
			int Energy = 200;
			
			Bagspace = 5;
			RandomEvent = (rand() % 30)+1;
			int EnergyEvent = (rand() % 40)+1; 
			DayCounter = DayCounter + 1;
			
			FoodStat = FoodStat + 15;
			ThirstStat = ThirstStat + 15;
			SaneStat = SaneStat - 15;
			StressStat = 0;
			
			//loops until the player ends the day
			while (DayEnd == false)
			{
				//activates a special event if random number is 30
				system("CLS");			
				if (RandomEvent == 30)
				{
					cout<<"You walk to Ethan's room and you see another rabbit! They seem to be getting along VERY well.";
					cout<<"\n-------------------------------------------------------------------------------------------------------------";
					cout<<"\n(Sanity +75)";
					SaneStat = SaneStat + 75;
					RandomEvent = 0;
					AaronEvt = true;
					Sleep(2500);
				}
				
				//actuvates a double energy event if random number is 40
				else if (EnergyEvent == 40)
				{
					system("CLS");
					cout<<"Today you feel pumped up for some reason!";
					cout<<"\n-------------------------------------------------------------------------------------------------------------";
					cout<<"\n(ENERGY DOUBLED!)";
					Energy = 400;
					Sleep(1300);
				}
				
				//outputs basic information
				system("CLS");
				cout<<"Day: "<<DayCounter<<"\t\tEnergy: "<<Energy<<"\t\tID: "<<PlayerName<<"\n\n";
				
				//outputs a special diologue if event is true 
				if(AaronEvt == true)
				{
					cout<<"Aaron: hoi. \n";
				}
				
				//calls for the character message function
				IntroMessage(SaneStat, DayCounter);
				cout<<"\n-----------------------------------------------------------------------------------";
				
				//outputs the options the player can choose if sanity is over 25
				if (SaneStat >25)
				{
					cout<<"\nWhat would you like to do?\n\n[1] - Use item on the bun bun\t\t[3] - Get some supplies\t\t[5] - Check Ethan's stats\n[2] - Play with the bun bun\t\t[4] - Supplies\t\t\t[6] - End the day\n\nEnter here: ";
					cin>>BunBun;
					
					//calls a function for every option
					switch (BunBun)
					{
						case 1:
							FeedingBun (FoodStat, ThirstStat, StressStat, SaneStat, Energy, Objects);
							break;
						case 2:
							BunnyPlay (FoodStat, ThirstStat, SaneStat, StressStat, Energy);
							break;
						case 3:
							ItemShop (Bagspace, Objects);
							break;
						case 4:
							FoodMenu (Objects);
							break;
						case 5:
							BunnyStats (SaneStat, FoodStat, ThirstStat, StressStat);
							break;
						case 6:
							//asks the player if they want to end the day
							system("CLS");
							cout<<"You are about to head off for the day, are you sure? (Y/N)\n\nEnter here: ";
							cin>>End;
							
							if ((End == 'Y')||(End == 'y'))
							{
								DayEnd = true;
							}
							break;
					}
				}
				
				//outputs options the player can choose if sanity is equal or less than 25
				else if (SaneStat <=20)
				{
					cout<<"\nOnly one thing...\n\n";
					cout<<"[1] - Escape\n\nEnter here: ";
					cin>>BunBun;
					SaneStat = 0;
					DayEnd = true;
				}
			}
					
			if (SaneStat == 0)
			{
				system("CLS");
				cout<<"You turn around and try to flee the room, you quickly feel something grasping on your leg. You try your best to\nkick Ethan off but you couldn't, the door closes in front of you as the once docile Ethan drags you deeper into\nthe room... ";
				cout<<"What ever happened to you, Ethan or the staff of the facility is unknown.";
				cout<<"\n-------------------------------------------------------------------------------------------------------------";
				Death = true;
				cout<<"\nFINALLY, THE FREEDOM I WANTED\n\nYour score: "<<DayCounter<<"\n\nRestart? (Y/N): ";
				cin>>GameRestart;
			}
			
			else if (SaneStat > 0)
			{
				//outputs a small little message between day change
				system("CLS");
				cout<<"Tomorrow's going to be an adventure...";
				Sleep(2000);
				
				//outputs game over message if the food, stress or thirst meter reaches 100 or above 
				if ((FoodStat >= 100)||(ThirstStat >= 100))
				{
					system("CLS");
					cout<<"You walk into Ethan's room. You see him on face down on the floor, you walk up to him and try to wake him up...\nit's no use. Ethan died due to your neglect.";
					cout<<"\n-------------------------------------------------------------------------------------------------------------";
					cout<<"\nGAME OVER\n\nYour score: "<<DayCounter<<"\n\nRestart? (Y/N): ";
					Death = true;
					cin>>GameRestart;
				}
				
				else if (Stress >=100)
				{
					cout<<"You walk into Ehtan's room. You see him laying down on the floor, you go up to him and realise he died from\nstress.";
					cout<<"\n-------------------------------------------------------------------------------------------------------------";
					cout<<"\nGAME OVER\n\nYour score: "<<DayCounter<<"\n\nRestart? (Y/N): ";
					Death = true;
					cin>>GameRestart;
				}
			}
		}
	}
}

//*********************************************************************************************************************************************************************************************************************************************

//get supplies function
int ItemShop (int &Currency, int ITEMS[])
{
	//declairing variables
	int purchase;
	bool Leave = false;
	string ShopList[4] = {"Blue Berries","Water","Stress Toy","Entertainment"};
	
	while(Leave == false)
	{
		system("CLS");
		//outputs the items available
		for(int ii = 0; ii <= 3; ii++)
		{
			cout<<"["<<ii + 1<<"] - "<<ShopList[ii]<<"\n";
		}
	
		//outputs the amount of items the player can take
		cout<<"\nAmount of space left: "<<Currency;
		cout<<"\n-------------------------------------------------------------------------------------------------------------";
		
		//asks player for what they want
		cout<<"\nWhat do you need?\n\nEnter here: ";
		cin>>purchase;
		
		//subtracts one from space available and adds the item to the array
		if (Currency >= 1)
		{
			Currency = Currency - 1;
			ITEMS[purchase - 1] = ITEMS[purchase - 1] + 1;
			cout<<"You grabbed the item and placed it in your bag... "<<Currency<<" spaces left";
			Sleep(1000);
		}
	
		//outputs that the player can't get anymore items and makes the player leave
		else if (Currency == 0)
		{
			system("CLS");
			cout<<"Sorry, it appears that you don't have any space left. I'm afraid you're going to have to leave";
			Sleep(2000);
			Leave = true;
		}
	}
}

//*********************************************************************************************************************************************************************************************************************************************

//check stats function
void BunnyStats (int Sanitystat, int Foodstat, int Thirststat, int Stressstat)
{
	//declairing variables
	string Cont;
	
	//outputs the general info 
	system("CLS");
	cout<<"GENERAL INFO\n\n";
	cout<<"Specimen name: Ethan Bunston\t\tSpecimen age: 17?\nSpecimen No: 0305\n\n";
	
	//outputs the game stats 
	cout<<"MENTAL AND PHYSICAL INFO\n\nHunger - "<<Foodstat<<"\t\tStress - "<<Stressstat<<"\nThirst - "<<Thirststat<<"\t\tSanity - "<<Sanitystat;
	cout<<"\n\nType anything to leave: ";
	cin>>Cont;
}

//*********************************************************************************************************************************************************************************************************************************************

//Play with Bun Bun function
int BunnyPlay (int &HungerStat, int &WaterStat, int &MentalStat, int &StressNumber, int &EnergyMeter)
{
	//declairing variables
	int GameOp;
	bool PlayCounter = false;
	
	while (PlayCounter == false)
	{
		//asks what the player wants to do
		system("CLS");
		cout<<"Energy: "<<EnergyMeter;
		cout<<"\n\nWhat will you do with the bunny?\n\n[1] - Play catch (15 Energy)\t\t[3] - Give head pats (90 energy)\n[2] - play chess (50 energy)\t\t[4] - Exit\n\nEnter here: ";
		cin>>GameOp;
		
		//tells the player what they did and the stats that changed
		if (GameOp == 1)
		{
			if (EnergyMeter >= 15)
			{
				system("CLS");
				cout<<"You head over to the toy box and pulled out a ball. You and Ethan play a game of catch!";
				cout<<"\n-------------------------------------------------------------------------------------------------------------";
				cout<<"\n(Sanity +10%) (Hunger +10%) (Thirst +15%) (Stress +5%)";

				MentalStat = MentalStat + 10;
				HungerStat = HungerStat + 10;
				WaterStat = WaterStat + 15;
				StressNumber = StressNumber + 5;
				EnergyMeter = EnergyMeter - 15;
					
				if (StressNumber < 0)
				{
					StressNumber = 0;
				}
			
				else if (HungerStat < 0)
				{
					StressNumber = 0;
				}
				
				else if (WaterStat < 0)
				{
					StressNumber = 0;
				}
					
				Sleep(4000);
			}
			
			else if (EnergyMeter < 15)
			{
				system("CLS");
				cout<<"You're too tired to do this...";
				Sleep(1000);
				PlayCounter = true;
			}
		}
		
		else if (GameOp == 2)
		{
			if (EnergyMeter >= 50)
			{
				system("CLS");
				cout<<"You head over to the toy box and pulled out a small chess set. You and Ethan play an intensive round of chess!";
				cout<<"\n-------------------------------------------------------------------------------------------------------------";
				cout<<"\n(Sanity +5%) (Hunger +5%) (Thirst +5%) (Stress +50%)";
				
				MentalStat = MentalStat + 5;
				HungerStat = HungerStat + 5;
				WaterStat = WaterStat + 5;
				StressNumber = StressNumber + 50;	
				EnergyMeter = EnergyMeter - 50;
						
				if (StressNumber < 0)
				{
					StressNumber = 0;
				}
			
				else if (HungerStat < 0)
				{
					StressNumber = 0;
				}
			
				else if (WaterStat < 0)
				{
					StressNumber = 0;
				}
				
				Sleep(4000);
			}
			
			else if (EnergyMeter < 50)
			{
				system("CLS");
				cout<<"You're too tired to do this...";
				Sleep(1000);
				PlayCounter = true;
			}
		}
		
		else if (GameOp == 3)
		{
			if (EnergyMeter >= 90)
			{
				system("CLS");
				cout<<"You walk up to Ethan and place your hand on his soft head as he starts to vibrate. You start giving the bunny boy a\nvigorous head pat!";
				cout<<"\n-------------------------------------------------------------------------------------------------------------";
				cout<<"\n(Sanity +10%) (Stress -20%)";
				
				MentalStat = MentalStat + 10;
				StressNumber = StressNumber - 20;
				EnergyMeter = EnergyMeter - 90;
				
				if (StressNumber < 0)
				{
					StressNumber = 0;
				}
				
				Sleep(4000);				
			}
			
			else if (EnergyMeter < 90)
			{
				system("CLS");
				cout<<"You lack the energy to do the sacred head pat...";
				Sleep(1000);
				PlayCounter = true;
			}
		}
		
		else if (GameOp == 4)
		{
			PlayCounter = true;
		}
	}
}

//*********************************************************************************************************************************************************************************************************************************************

//supplies function
void FoodMenu (int Items[])
{
	//declairing variables
	string Cont2;
	
	//outputs the option title
	system("CLS");
	cout<<"Supply Menu\n\n";
	
	//outputs the item and the amount the player has
	cout<<"Blue berries: "<<Items[0]<<"\t\tStress toy: "<<Items[2]<<"\n";
	cout<<"Water: "<<Items[1]<<"\t\tEntertainment: "<<Items[3]<<"\n\n";
	
	//tells the player to type anything to continue 
	cout<<"Type anything to continue: ";
	cin>>Cont2;
}

//*********************************************************************************************************************************************************************************************************************************************

//character message function
void IntroMessage(int Sanity, int Days)
{	
	//outputs a good message if sanity is above 50
	if (Sanity > 50)
	{
		//outptus a one time message for the first day
		if (Days == 1)
		{
			cout<<"Ethan: hello there! Nice to meet you, how are you doing?";
		}
		
		//outputs normal message for the rest of the days		
		else if (Days != 1)
		{
			cout<<"Ethan: Hey there, nice to meet you again!";
		}
	}
	
	//outputs an ok message if sanity is between 50 and 25		
	else if ((Sanity <= 50)&&(Sanity > 25))
	{
		cout<<"Ethan: I don't want to be here anymore...";
	}
	
	//outputs a bad message if sanity is lower or equals to 25		
	else if (Sanity <= 25)
	{
		cout<<"You walk towards Ethan's room, you notice the security guard outside is gone. As you walk into the\nroom Ethan sits there smiling at you not moving an inch, there appears to be blood on his hands";
	}
}

//*********************************************************************************************************************************************************************************************************************************************

//feed the BunBun function
int FeedingBun (int &FoodMeter, int &ThirstMeter, int &StressMeter, int &SanityMeter, int &EnergyMeter, int FoodArray[])
{
	//declairing variables
	int FoodItem;
	
	//asks what the player wants to give to the rabbit
	system("CLS");
	cout<<"What will you give to Ethan? (10 ENERGY)\n\n";
	cout<<"[1] - Blue berries\t\t[3] - Stress toy\n";
	cout<<"[2] - Water\t\t\t[4] - Entertainment\n\nEnter here: ";
	cin>>FoodItem;
	
	//outputs that the option the user picked doesn't exist
	if ((FoodItem > 4)||(FoodItem <= 0))
	{
		system("CLS");
		cout<<"That option doesn't exist";
		Sleep(900);
	}
	
	//outputs a message and changes stats if the player has that item and the player has enough energy
	else if ((FoodArray[FoodItem - 1] > 0)&&(EnergyMeter >= 10))
	{
		if (FoodItem == 1)
		{
			system("CLS");
			cout<<"You give Ethan a handfull of blue berries. He quickly snatches it and eats them... Yummy, he says as he starts to\nvibrate.";
			cout<<"\n-------------------------------------------------------------------------------------------------------------";
			cout<<"\n(Hunger -10%)";
			FoodArray[FoodItem - 1] = FoodArray[FoodItem - 1] - 1;
			EnergyMeter = EnergyMeter - 10;	
			FoodMeter = FoodMeter - 10;
			
			if (FoodMeter < 0)
			{
				FoodMeter = 0;
			}
			
			Sleep(1800);	
		}
		
		else if (FoodItem == 2)
		{
			system("CLS");
			cout<<"You give Ethan a bottle of water. He slowly nibbles at the liquid slowly drinking it...";
			cout<<"\n-------------------------------------------------------------------------------------------------------------";		
			cout<<"\n(Thirst -10%)";
			FoodArray[FoodItem - 1] = FoodArray[FoodItem - 1] - 1;	
			EnergyMeter = EnergyMeter - 10;	
			ThirstMeter = ThirstMeter - 10;
			
			if (ThirstMeter < 0)
			{
				ThirstMeter = 0;
			}
			
			Sleep(1800);	
		}		
		
		else if (FoodItem == 3)
		{
			system("CLS");
			cout<<"You give Ethan a stress ball. He struggles to squeeze it but in the end he had fun.";
			cout<<"\n-------------------------------------------------------------------------------------------------------------";		
			cout<<"\n(Stress -20%)";
			FoodArray[FoodItem - 1] = FoodArray[FoodItem - 1] - 1;	
			EnergyMeter = EnergyMeter - 10;
			StressMeter = StressMeter - 20;
			
			if (StressMeter < 0)
			{
				StressMeter = 0;
			}
			
			Sleep(1800);	
		}		
		
		else if (FoodItem == 4)
		{
			system("CLS");
			cout<<"You give Ethan some toys to play with. You play with him and he seems to be enjoying himself!";
			cout<<"\n-------------------------------------------------------------------------------------------------------------";		
			cout<<"\n(Sanity +15%)";
			FoodArray[FoodItem - 1] = FoodArray[FoodItem - 1] - 1;	
			SanityMeter = SanityMeter + 15;
			EnergyMeter = EnergyMeter - 10;
			Sleep(1800);	
		}
	}
	//outputs that the player is too tired or doesn't have that item
	else if ((FoodArray[FoodItem - 1] == 0)||(EnergyMeter < 10))
	{
		if (FoodArray[FoodItem - 1] == 0)
		{
			system("CLS");
			cout<<"You search for that item but you don't have any...";
			Sleep(1400);
		}
		
		else if (EnergyMeter < 10)
		{
			system("CLS");
			cout<<"Your arms are too weak to even lift up a blue berry. Get some rest";
			Sleep(1400);
		}
	}
}
