#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <set>
#include <climits>
#include <cmath>
#include <stdexcept>
#include <map>
using namespace std;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

class Player
{
private:
	int id;
    string name;
	int credits;
public:
	void SetDetails(int id, string name, int credits)
	{
		this->id = id;
		this->name = name;
		this->credits = credits;
	}
	int GetId()
	{
		return id;
	}
	string GetName()
	{
		return this->name;
	}
	int GetCredits()
	{
		return this->credits;
	}
};
class Dream11
{
	private:
		int total_credits;
		int batsman;
		int bowlers;
		int wicketkeeper;
		int allrounders;
		vector<Player> batsman_credits;
		vector<Player> bowler_credits;
		vector<Player> wicketkeeper_credits;
		vector<Player> allrounder_credits;
		int players_selected;
		int total_players;
		int lower_bound_of_batsman;
		int lower_bound_of_bowlers;
		int lower_bound_of_wicketkeepers;
		int lower_bound_of_allrounders;
		int upper_bound_of_batsman;
		int upper_bound_of_bowlers;
		int upper_bound_of_wicketkeepers;
		int upper_bound_of_allrounders;
	public:
		Dream11(vector<Player> batsman_credits, vector<Player> bowler_credits, vector<Player> wicketkeeper_credits, vector<Player> allrounder_credits )
		{
			this->total_credits = 100;
			this->batsman = 0;
			this->bowlers = 0;
			this->allrounders = 0;
			this->wicketkeeper = 0;
			this->total_players = 11;
			this->players_selected = 0;
			this->lower_bound_of_batsman = 3;
			this->lower_bound_of_bowlers = 3;
			this->lower_bound_of_wicketkeepers = 1;
			this->lower_bound_of_allrounders = 1;
			this->upper_bound_of_batsman = 6;
			this->upper_bound_of_bowlers = 6;
			this->upper_bound_of_wicketkeepers = 4;
			this->upper_bound_of_allrounders = 4;
			this->batsman_credits = batsman_credits;
			this->bowler_credits = bowler_credits;
			this->wicketkeeper_credits = wicketkeeper_credits;
			this->allrounder_credits = allrounder_credits;
		}
		void PrintDetails()
		{
			cout << "Batsman      : " << this->batsman << endl;
			cout << "Bowler       : " << this->bowlers << endl;
			cout << "WicketKeeper : " << this->wicketkeeper << endl;
			cout << "Allrounder   : " << this->allrounders << endl;
			cout << "Available Credits : " << this->total_credits << endl;
		}
		pair<int, int> ShowBatsman()
		{
			int id = 1;
			for(Player p : this->batsman_credits)
			{
				cout << id++ << "-> " <<  p.GetId() << ". " << p.GetName() << " - " << p.GetCredits() << endl;
			}
			int choice;
			cin >> choice;
			return {this->batsman_credits[choice-1].GetId() ,this->batsman_credits[choice-1].GetCredits()};
		}
		pair<int, int> ShowBowlers()
		{
			int id = 1;
			for(Player p : this->bowler_credits)
			{
				cout << id++ << "-> " <<  p.GetId() << ". " << p.GetName() << " - " << p.GetCredits() << endl;
			}
			int choice;
			cin >> choice;
			return {this->bowler_credits[choice-1].GetId() ,this->bowler_credits[choice-1].GetCredits()};
		}
		pair<int, int> ShowWicketKeeper()
		{
			int id = 1;
			for(Player p : this->wicketkeeper_credits)
			{
				cout << id++ << "-> " <<  p.GetId() << ". " << p.GetName() << " - " << p.GetCredits() << endl;
			}
			int choice;
			cin >> choice;
			return {this->wicketkeeper_credits[choice-1].GetId() ,this->wicketkeeper_credits[choice-1].GetCredits()};
		}
		pair<int, int> ShowAllRounder()
		{
			int id = 1;
			for(Player p : this->allrounder_credits)
			{
				cout << id++ << "-> " <<  p.GetId() << ". " << p.GetName() << " - " << p.GetCredits() << endl;
			}
			int choice;
			cin >> choice;
			return {this->allrounder_credits[choice-1].GetId() ,this->allrounder_credits[choice-1].GetCredits()};
		}
		void AddBatsman(int id, int credits)
		{
			this->batsman++;
			this->players_selected++;
			total_credits -= credits;
			int total_players_needed = this->total_players - this->players_selected;
			int batsman_needed = lower_bound_of_batsman - batsman;
			if(batsman_needed < 0) batsman_needed = 0;
			int wicketkeeper_needed = lower_bound_of_wicketkeepers - this->wicketkeeper;
			if(wicketkeeper_needed < 0) wicketkeeper_needed = 0;
			int bowlers_needed = this->lower_bound_of_bowlers - this->bowlers;
			if(bowlers_needed < 0) bowlers_needed = 0;
			int allrounders_needed = this->lower_bound_of_allrounders - this->allrounders;
			if(allrounders_needed < 0) allrounders_needed = 0;
			if(total_credits < 0)
			{
				this->batsman--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add this batsman because, your credits is not enough" << endl;
			}
			else if(this->batsman  > upper_bound_of_batsman) 
			{
				this->batsman--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add batsman because, total no of batsman should  be less than 6" << endl;
			}
			else if(total_players_needed < (batsman_needed + bowlers_needed + wicketkeeper_needed + allrounders_needed))
			{
				this->batsman--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add batman because" << endl;
				if(batsman_needed > 0)
				{
					cout << "You should choose atleast 4 batsman" << endl;
				}
				if(bowlers_needed > 0)
				{
					cout << "You should choose atleast 4 bowlers" << endl;
				}
				if(wicketkeeper_needed > 0)
				{
					cout << "You should choose atleast 1 wicketkeeper" << endl;
				}
				if(allrounders_needed > 0)
				{
					cout << "You should choose atleast 1 allrounders" << endl;
				}
			}
			else
			{
				for(vector<Player>::iterator it  = batsman_credits.begin(); it != batsman_credits.end(); it++)
				{
					if(it->GetId() == id)
					{
						cout << it->GetName() << " added" << endl;
						this->batsman_credits.erase(it);
						break;
					}
				}
				if(players_selected == total_players)
				{
					cout << "Congratulations Team Selection Completed" << endl;
				}
			}
			this->PrintDetails();
		}
		void AddBowlers(int id, int credits)
		{
			this->bowlers++;
			this->players_selected++;
			total_credits -= credits;
			int total_players_needed = this->total_players - this->players_selected;
			int batsman_needed = lower_bound_of_batsman - batsman;
			if(batsman_needed < 0) batsman_needed = 0;
			int wicketkeeper_needed = lower_bound_of_wicketkeepers - this->wicketkeeper;
			if(wicketkeeper_needed < 0) wicketkeeper_needed = 0;
			int bowlers_needed = this->lower_bound_of_bowlers - this->bowlers;
			if(bowlers_needed < 0) bowlers_needed = 0;
			int allrounders_needed = this->lower_bound_of_allrounders - this->allrounders;
			if(allrounders_needed < 0) allrounders_needed = 0;
			if(total_credits < 0)
			{
				this->bowlers--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add this bowler because, your credits is not enough" << endl;
			}
			else if(this->batsman  > upper_bound_of_bowlers) 
			{
				this->bowlers--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add bowler because, total no of bowler should  be less than 6" << endl;
			}
			else if(total_players_needed < (batsman_needed + bowlers_needed + wicketkeeper_needed + allrounders_needed))
			{
				this->bowlers--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add bowler because" << endl;
				if(batsman_needed > 0)
				{
					cout << "You should choose atleast 4 batsman" << endl;
				}
				if(bowlers_needed > 0)
				{
					cout << "You should choose atleast 4 bowlers" << endl;
				}
				if(wicketkeeper_needed > 0)
				{
					cout << "You should choose atleast 1 wicketkeeper" << endl;
				}
				if(allrounders_needed > 0)
				{
					cout << "You should choose atleast 1 allrounders" << endl;
				}
			}
			else
			{

				for(vector<Player>::iterator it  = bowler_credits.begin(); it != bowler_credits.end(); it++)
				{
					if(it->GetId() == id)
					{
						cout << it->GetName() << " added" << endl;
						this->bowler_credits.erase(it);
						break;
					}
				}
				if(players_selected == total_players)
				{
					cout << "Congratulations Team Selection Completed" << endl;
				}
			}
			this->PrintDetails();
		}
		void AddWicketKeeper(int id, int credits)
		{
			this->wicketkeeper++;
			this->players_selected++;
			total_credits -= credits;
			int total_players_needed = this->total_players - this->players_selected;
			int batsman_needed = lower_bound_of_batsman - batsman;
			if(batsman_needed < 0) batsman_needed = 0;
			int wicketkeeper_needed = lower_bound_of_wicketkeepers - this->wicketkeeper;
			if(wicketkeeper_needed < 0) wicketkeeper_needed = 0;
			int bowlers_needed = this->lower_bound_of_bowlers - this->bowlers;
			if(bowlers_needed < 0) bowlers_needed = 0;
			int allrounders_needed = this->lower_bound_of_allrounders - this->allrounders;
			if(allrounders_needed < 0) allrounders_needed = 0;
			if(total_credits < 0)
			{
				this->wicketkeeper--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add this wicketkeeper because, your credits is not enough" << endl;
			}
			else if(this->wicketkeeper  > upper_bound_of_wicketkeepers) 
			{
				this->wicketkeeper--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add wicketkeeper because, total no of wicketkeeper should  be less than 6" << endl;
			}
			else if(total_players_needed < (batsman_needed + bowlers_needed + wicketkeeper_needed + allrounders_needed))
			{
				this->wicketkeeper--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add wicketkeeper because" << endl;
				if(batsman_needed > 0)
				{
					cout << "You should choose atleast 4 batsman" << endl;
				}
				if(bowlers_needed > 0)
				{
					cout << "You should choose atleast 4 bowlers" << endl;
				}
				if(wicketkeeper_needed > 0)
				{
					cout << "You should choose atleast 1 wicketkeeper" << endl;
				}
				if(allrounders_needed > 0)
				{
					cout << "You should choose atleast 1 allrounders" << endl;
				}
			}
			else
			{
				for(vector<Player>::iterator it  = wicketkeeper_credits.begin(); it != wicketkeeper_credits.end(); it++)
				{
					if(it->GetId() == id)
					{
						cout << it->GetName() << " added" << endl;
						this->wicketkeeper_credits.erase(it);
						break;
					}
				}
				if(players_selected == total_players)
				{
					cout << "Congratulations Team Selection Completed" << endl;
				}

			}
			this->PrintDetails();
		}
		void AddAllRounder(int id, int credits)
		{
			this->allrounders++;
			this->players_selected++;
			total_credits -= credits;
			int total_players_needed = this->total_players - this->players_selected;
			int batsman_needed = lower_bound_of_batsman - batsman;
			if(batsman_needed < 0) batsman_needed = 0;
			int wicketkeeper_needed = lower_bound_of_wicketkeepers - this->wicketkeeper;
			if(wicketkeeper_needed < 0) wicketkeeper_needed = 0;
			int bowlers_needed = this->lower_bound_of_bowlers - this->bowlers;
			if(bowlers_needed < 0) bowlers_needed = 0;
			int allrounders_needed = this->lower_bound_of_allrounders - this->allrounders;
			if(allrounders_needed < 0) allrounders_needed = 0;
			if(total_credits < 0)
			{
				this->allrounders--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add this allrounder because, your credits is not enough" << endl;
			}
			else if(this->allrounders  > upper_bound_of_allrounders) 
			{
				this->allrounders--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add allrounder because, total no of wicketkeeper should  be less than 6" << endl;
			}
			else if(total_players_needed < (batsman_needed + bowlers_needed + wicketkeeper_needed + allrounders_needed))
			{
				this->allrounders--;
				this->players_selected--;
				total_credits += credits;
				cout << "You can't add allrounder because" << endl;
				if(batsman_needed > 0)
				{
					cout << "You should choose atleast 4 batsman" << endl;
				}
				if(bowlers_needed > 0)
				{
					cout << "You should choose atleast 4 bowlers" << endl;
				}
				if(wicketkeeper_needed > 0)
				{
					cout << "You should choose atleast 1 wicketkeeper" << endl;
				}
				if(allrounders_needed > 0)
				{
					cout << "You should choose atleast 1 allrounders" << endl;
				}
			}
			else
			{
				for(vector<Player>::iterator it  = allrounder_credits.begin(); it != allrounder_credits.end(); it++)
				{
					if(it->GetId() == id)
					{
						cout << it->GetName() << " added" << endl;
						this->allrounder_credits.erase(it);
						break;
					}
				}
				if(players_selected == total_players)
				{
					cout << "Congratulations Team Selection Completed" << endl;
				}


			}
			this->PrintDetails();
		}

};

int main()
{
	speed;
	vector<Player> batsman_credits(6);
	batsman_credits[0].SetDetails(101, "Dhoni", 8);
	batsman_credits[1].SetDetails(102, "Raina", 8);
	batsman_credits[2].SetDetails(103, "Yuvaraj", 8);
	batsman_credits[3].SetDetails(104, "Shewag", 8);
	batsman_credits[4].SetDetails(105, "Ganguly", 8);
	batsman_credits[5].SetDetails(106, "Sachin", 8);
	vector<Player> wicketkeeper_credits(5);
	wicketkeeper_credits[0].SetDetails(201, "Johnson", 10);
	wicketkeeper_credits[1].SetDetails(202, "Ram", 8);
	wicketkeeper_credits[2].SetDetails(203, "Gokul", 8);
	wicketkeeper_credits[3].SetDetails(204, "Marley", 8);
	wicketkeeper_credits[4].SetDetails(204, "Choplin", 8);
	vector<Player> bowler_credits(6);
	bowler_credits[0].SetDetails(301, "Bravo", 100);
	bowler_credits[1].SetDetails(302, "Aththar", 8);
	bowler_credits[2].SetDetails(303, "Rahul", 8);
	bowler_credits[3].SetDetails(304, "Ashwin", 8);
	bowler_credits[4].SetDetails(305, "Harbhajan", 8);
	bowler_credits[5].SetDetails(306, "Badrinath", 8);
	vector<Player> allrounder_credits(4);
	allrounder_credits[0].SetDetails(401, "Jadega", 8);
	allrounder_credits[1].SetDetails(402, "Lokesh", 8);
	allrounder_credits[2].SetDetails(403, "Charley", 8);
	allrounder_credits[3].SetDetails(404, "Martin", 8);
	Dream11 team = Dream11(batsman_credits, bowler_credits, wicketkeeper_credits, allrounder_credits);
	cout << "Player Selection" << endl;
	int choice;
	bool stop = false;
	do
	{
		cout << "1.Add Batsman\n";
		cout << "2.Add Bowler\n";
		cout << "3.Add WicketKeeper\n";
		cout << "4.Add Allrounder\n"; 
		cout << "Press 5 or other to quit\n";
		cout << flush;
		cin >> choice;
		pair<int, int> player;
		switch(choice)
		{
			case 1:
				player = team.ShowBatsman();
				team.AddBatsman(player.first, player.second);
				break;
			case 2:
				player = team.ShowBowlers();
				team.AddBowlers(player.first, player.second);
				break;
			case 3:
				player = team.ShowWicketKeeper();
				team.AddWicketKeeper(player.first, player.second);
				break;
			case 4:
				player = team.ShowAllRounder();
				team.AddAllRounder(player.first, player.second);
				break;
			default:
				stop = true;
				break;
		}

	}while(!stop);
	

	return 0;
}
