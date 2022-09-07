#include "head.h"
vector<electorate> electorates;
vector<party> parties;
vector<issue> issues;

void abort()
{
	cerr << "System gonna abort" << endl;
	exit(1);
}

void checkParameter(int argc, int argv1, int argv2)
{
	if(argc != 3)
	{
		cerr << "Invalid Parameter Input Number!" << endl;
		abort();
	}
	if(argv1<0||argv1>10)
	{
		cerr << "Invalid Electorate Input Number!" << endl;
		abort();
	}
	if(argv2<0||argv2>30)
	{
		cerr << "Invalid Day Input Number!" << endl;
		abort();
	}
}

electorate::electorate()
{
	
}

electorate::~electorate()
{
	
}

void electorate::initData()
{
	for(int i = 0; i < 3; i++)
	{
		supportations[i] = RandomNumber(0,10);
	}		
}

int electorate::get_ID()
{
	return ID;
}

int electorate::get_supportations(int party_index)
{
	return supportations[party_index];
}

void electorate::set_supportations(int party_index,int change_value)
{
	supportations[party_index] = supportations[party_index] + change_value;
}

void electorate::choose_candidate()
{
	int largest = 0;
	if(supportations[0]<supportations[1])
	{
		largest = 1;
	}
	if(supportations[largest]<supportations[2])
	{
		largest = 2;
	}
	candidate = largest;
}

void electorate::set_ID(int number)
{
	ID = number;
}

int electorate::get_candidate()
{
	return candidate;
}

issue::issue()
{
	
}

issue::~issue()
{
	
}

void issue::initData()
{
	for(int i = 0; i < 3; i++)
	{
		significance[i] = RandomNumber(-2,2);
	}
}

string issue::get_name()
{
	return name;
}

void issue::set_name(string issue_name)
{
	name = issue_name;
}

int issue::get_significance(int party_index)
{
	return significance[party_index];
}

int issue::get_approach()
{
	return approach;
}

void issue::set_approach()
{
	approach = RandomNumber(-2,2);
}

party::party()
{
	
}

party::~party()
{
	
}

void party::initData()
{
	leader_ability = RandomNumber(1,5);
	candidate_ability = RandomNumber(1,5);
	Cmanager_ability = RandomNumber(1,5);
	NCmanager_ability = RandomNumber(1,5);
	NFmanager_ability = RandomNumber(3,7);
	fund = RandomNumber(50,100);
	income = 0;
	LEexpenditure = 0;
	NEexpenditure = 0;
	supportation = 0;
}

string party::get_party_name()
{
	return party_name;
}

string party::get_leader_name()
{
	return leader_name;
}

string party::get_candidate_name()
{
	return candidate_name;
}
		
int party::get_leader_ability()
{
	return leader_ability;
}

int party::get_candidate_ability()
{
	return candidate_ability;
}

int party::get_Cmanager_ability()
{
	return Cmanager_ability;
}

int party::get_NCmanager_ability()
{
	return NCmanager_ability;
}

int party::get_NFmanager_ability()
{
	return NFmanager_ability;
}

int party::get_fund()
{
	return fund;
}

int party::get_LEexpenditure()
{
	return LEexpenditure;
}

int party::get_NEexpenditure()
{
	return NEexpenditure;
}

int party::get_income()
{
	return income;
}

int party::get_supportation()
{
	return supportation;
}

void party::set_party_name(string name)
{
	party_name = name;
}

void party::set_leader_name(string name)
{
	leader_name = name;
}

void party::set_candidate_name(string name)
{
	candidate_name = name;
}

void party::set_fund(int change_value)
{
	fund = fund - change_value;
}

void party::set_supportation()
{
	supportation++;
}

void party::set_LEexpenditure()
{
	LEexpenditure =  RandomNumber(10,20) - NFmanager_ability;
}

void party::set_NEexpenditure(int expenditure)
{
	NEexpenditure = expenditure;
}

void party::set_income()
{
	income = NFmanager_ability + RandomNumber(20,30);
}

void party::manage_fund()
{
	fund = fund - LEexpenditure - NEexpenditure + income;
}

event::event()
{
	
}

event::~event()
{
	
}

string event::get_name()
{
	return name;
}

int event::get_partyNO()
{
	return partyNO;
}

int event::get_effect()
{
	return effect;
}

string event::get_effect_type()
{
	return effect_type;
}

bool event::get_happend()
{
	return happend;
}

void event::set_name()
{

}

void event::set_partyNO()
{
	partyNO = RandomNumber(0,2);
} 

void event::set_effect(int ability1, int ability2, int issue_index)
{
	if(issue_index > 4)
	{
		effect = RandomNumber(-5,5) + ability1 + ability2;
	}
	else
	{
		issue ii = issues.at(issue_index);
		ii.set_approach();
		effect = ii.get_significance(partyNO) + ii.get_approach();
	}
}

void event::set_effect_type()
{
	if(effect == 0)
	{
		effect_type = "normal";
	}
	else if(effect > 0)
	{
		effect_type = "positive";
	}
	else
	{
		effect_type = "negative";
	}
}

void event::set_happend()
{
	
}

void event::effect_electorate()
{
	
}

void event::show()
{
	
}

int event::select_issue()
{
	
}

local_event::local_event()
{
	
}

local_event::~local_event()
{
	
}

string local_event::get_type()
{
	return type;
}

int local_event::select_issue()
{
	return RandomNumber(0,4);
}

void local_event::set_type()
{
	if(happend == true)
	{
		int type_number = RandomNumber(1,3);
		if(type_number == 1) type = "Local debate";
		if(type_number == 2) type = "Candidate related event";
		if(type_number == 3) type = "Local issue";
	}
}

void local_event::set_name(int issue_index)
{
	if(type == "local issue")
	{
		issue ii = issues.at(issue_index);
		name = ii.get_name();
	}
	else
	{
		name = type;
	}
}

void local_event::effect_electorate(int electorate_index)
{
	electorate &e = electorates.at(electorate_index);
	e.set_supportations(partyNO,effect);
}

void local_event::set_happend()
{
	int integer = RandomNumber(1,5);
	if(integer == 1) happend = true;
	else happend = false;
}

void local_event::show(int electorate_ID, string issue)
{
	party p = parties.at(partyNO);
	if(type == "Local debate")
	{
		cout<<"Electorate "<<electorate_ID<<" watch local debate in which all party candidates participate. Because "<<p.get_candidate_name()<<" has "<<effect_type<<" performance. "<<endl;
		cout<<"His supportation for the "<<p.get_party_name()<<" change by "<<effect<<" point."<<endl;
	}
	else if(type == "Local issue")
	{
		cout<<"Electorate "<<electorate_ID<<" has a "<<effect_type<<" effect by "<<p.get_candidate_name()<<"'s approach for "<<issue<<" issue."<<endl;
		cout<<"His supportation for the "<<p.get_party_name()<<" change by "<<effect<<" point."<<endl;
	}
	else if(type == "Candidate related event")
	{
		cout<<"Electorate "<<electorate_ID<<" has a "<<effect_type<<" effect by "<<p.get_candidate_name()<<"'s event. "<<endl;
		cout<<"His supportation for the "<<p.get_party_name()<<" change by "<<effect<<" point."<<endl;
	}
	cout<<endl;
}

national_event::national_event()
{
	
}

national_event::~national_event()
{
	
}

int national_event::get_expenditure()
{
	return expenditure;
}

void national_event::set_type()
{
	if(happend == true)
	{
		int type_number = RandomNumber(1,3);
		if(type_number == 1) type = "Leaders debate";
		if(type_number == 2) type = "Leader related event";
		if(type_number == 3) type = "National issue";
	}
}

string national_event::get_type()
{
	return type;
}

void national_event::set_name(int issue_index)
{
	if(type == "national issue")
	{
		issue ii = issues.at(issue_index);
		name = ii.get_name();
	}
	else
	{
		name = type;
	}
}

void national_event::set_happend()
{
	int integer = RandomNumber(1,10);
	if(integer < 4 ) happend = true;
	else happend = false;
}

void national_event::effect_electorate(int electorate_number)
{
	for(int i = 0; i < electorate_number; i++)
	{
		electorate &e = electorates.at(i);
		e.set_supportations(partyNO,effect);
	}
}

int national_event::select_issue()
{
	return RandomNumber(0,4);
}

void national_event::set_expenditure()
{
	if(type == "Leaders debate")
	{
		for(int i = 0; i < 3; i++)
		{
			party &p = parties.at(i);
			expenditure = RandomNumber(20,30) - p.get_NFmanager_ability();
			p.set_NEexpenditure(expenditure);
		}
	}
	else
	{
		party &p = parties.at(partyNO);
		expenditure = RandomNumber(20,30) - p.get_NFmanager_ability();
		p.set_NEexpenditure(expenditure);
	}
			
}

void national_event::last_day(int current_day, int days_number)
{
	if(current_day == days_number)
	{
		for(int i = 0; i < 3; i++)
		{
			party &p = parties.at(i);
			expenditure = p.get_fund();
			p.set_NEexpenditure(expenditure);
		}
	}
}

void national_event::show(string issue)
{
	party p = parties.at(partyNO);
	if(type == "Leaders debate")
	{
		cout<<"All electorate "<<" watch local debate in which all party candidates participate. Because "<<p.get_leader_name()<<" has "<<effect_type<<" performance. "<<endl;
		cout<<"Their supportation for the "<<p.get_party_name()<<" change by "<<effect<<" point."<<endl;
	}
	else if(type == "National issue")
	{
		cout<<"All electorate has a "<<effect_type<<" effect by "<<p.get_leader_name()<<" 's approach for "<<issue<<" issue."<<endl;
		cout<<"Their supportation for the "<<p.get_party_name()<<" change by "<<effect<<" point."<<endl;
	}
	else if(type == "Leader related event")
	{
		cout<<"All electorate has a "<<effect_type<<" effect by "<<p.get_leader_name()<<"'s event. "<<endl;
		cout<<"Their supportation for the "<<p.get_party_name()<<" change by "<<effect<<" point."<<endl;
	}
	cout<<endl;
}

void create_information(int electorate_number)
{
	create_electorate(electorate_number);
	create_party();
	create_issue();
	print_initialization(electorate_number);
}

void create_electorate(int electorate_number)
{
	for(int i = 0; i < electorate_number; i++)
	{
		electorate e1;
		e1.initData();
		e1.set_ID(1001 + i);
		electorates.push_back(e1);
	}
}

void create_issue()
{
	string new_name[5] = {"Financial Crisis", "Terrorist Attacks", "Unemployment Rate Rises","Resident Evil", "The Third World War"};
	for(int i = 0; i < 5; i++)
	{
		issue Issue;
		Issue.initData();
		Issue.set_name(new_name[i]);
		issues.push_back(Issue);
	}
}

void create_party()
{
	string new_pname[3] = {"Democratic Party", "Republican Party", "Communist Party"};
	string new_lname[3] = {"George Washington", "John Adams", "Thomas Jefferson"};
	string new_cname[3] = {"Donald John", "James Monroe", "Andrew Jackson"};
	for(int i = 0; i < 3; i++)
	{
		party p;
		p.initData();
		p.set_party_name(new_pname[i]);
		p.set_leader_name(new_lname[i]);
		p.set_candidate_name(new_cname[i]);
		parties.push_back(p);		
	}
}

void manage_fund()
{
	cout<<left<<setw(20)<<"Party name";
	cout<<left<<setw(25)<<"local event cost($)";
	cout<<left<<setw(25)<<"national event cost($)";
	cout<<left<<setw(10)<<"income($)";
	cout<<left<<setw(10)<<"New fund($)"<<endl;;
	for(int i = 0; i < 3; i++)
	{
		party &p = parties.at(i);
		p.set_LEexpenditure();
		p.set_income();
		p.manage_fund();
		cout<<left<<setw(20)<<p.get_party_name();
		cout<<left<<setw(25)<<p.get_LEexpenditure();
		cout<<left<<setw(25)<<p.get_NEexpenditure();
		cout<<left<<setw(10)<<p.get_income();
		cout<<left<<setw(10)<<p.get_fund()<<endl;
		p.set_NEexpenditure(0);
	}
}

void last_day(int electorate_number)
{
	cout<<"----------------------------------------------The last day processing"<<"-----------------------------------"<<endl;
	cout<<"This is the last day, all parties decided to hold a national debate with all their funds."<<endl;	
	int partyNO = RandomNumber(0,2);
	party p1 = parties.at(partyNO);
	string leader_name = p1.get_leader_name();
	string party_name = p1.get_party_name();
	for(int i = 0; i < electorate_number; i++)
	{
		electorate &e = electorates.at(i);
		e.set_supportations(partyNO,10);
		e.get_candidate();
	}
	for(int i = 0; i < 3; i++)
	{
		party &p = parties.at(i);
		int current_fund = p.get_fund();
		p.set_fund(current_fund);
		cout<<"Party "<<p.get_party_name()<<" cost $"<<current_fund<<" on this debate. Now they has no fund."<<endl;
	}
	cout<<leader_name<<" has an excellent performance. All electorates' supportation for "<<party_name<<" increase 10 point."<<endl;
}

void print_initialization(int electorate_number)
{
	cout<<"-----------------------Party initialization---------------------------------------"<<endl;
	for(int i = 0; i < 3; i++)
	{
		party p = parties.at(i);
		cout<<"---------------------------The "<<i+1<<"th party-----------------------------------"<<endl;
		cout<<"Party name: "<<p.get_party_name()<<endl;
		cout<<"Leader name: "<<p.get_leader_name()<<endl;
		cout<<"Candidate name: "<<p.get_candidate_name()<<endl;
		cout<<"Leader ability: "<<p.get_leader_ability()<<endl;
		cout<<"Candidate ability: "<<p.get_candidate_ability()<<endl;
		cout<<"Campaign manager_ability: "<<p.get_Cmanager_ability()<<endl;
		cout<<"National campaign manager_ability: "<<p.get_NCmanager_ability()<<endl;
		cout<<"National financial manager_ability: "<<p.get_NFmanager_ability()<<endl;
		cout<<"Fund($): "<<p.get_fund()<<endl;
		cout<<endl;
	}
	cout<<"-----------------------Issue initialization---------------------------------------"<<endl;
	cout<<left<<setw(30)<<"Issue name";
	cout<<left<<setw(30)<<"significance of each party"<<endl;
	for(int i = 0; i < 5; i++)
	{
		issue ii = issues.at(i);
		ii.set_approach();
		cout<<left<<setw(30)<<ii.get_name();
		cout<<left<<setw(5)<<ii.get_significance(0)<<" : ";
		cout<<left<<setw(5)<<ii.get_significance(1)<<" : ";
		cout<<left<<setw(5)<<ii.get_significance(2)<<endl; 
	}
	cout<<endl;
	cout<<"-----------------------Electorate initialization---------------------------------------"<<endl;
	cout<<left<<setw(30)<<"Electorate ID";
	cout<<left<<setw(30)<<"Supportation of each party"<<endl;
	for(int i = 0; i < electorate_number; i++)
	{
		electorate e = electorates.at(i);
		cout<<left<<setw(30)<<e.get_ID();
		cout<<left<<setw(5)<<e.get_supportations(0)<<" : ";
		cout<<left<<setw(5)<<e.get_supportations(1)<<" : ";
		cout<<left<<setw(5)<<e.get_supportations(2)<<endl; 
	}
	cout<<endl;
}

void make_events(int electorate_number, int days)
{
	int current_day = 1;
	while(current_day < days)
	{
		cout<<"------------------------------------------The "<<current_day<<"th day processing"<<"-----------------------------------"<<endl;
		int current_electorate = 0;
		while(current_electorate < electorate_number)//process local event for each electorate
		{
			electorate &e = electorates.at(current_electorate);
			local_event l;//create a local event
			l.set_happend();//determination for event happend
			if(l.get_happend() == true)
			{
				l.set_partyNO();
				int partyNO = l.get_partyNO();
				l.set_type();
				string type = l.get_type();
				int issue_index;
				string issue_name;
				if(type == "Local issue") 
				{
					issue_index = l.select_issue();
					issue ii = issues.at(issue_index);
					issue_name = ii.get_name();
				}
				else issue_index = 5;//means not issue type of local event
				party p1 = parties.at(partyNO);
				l.set_effect(p1.get_candidate_ability(),p1.get_Cmanager_ability(),issue_index);
				l.set_effect_type();
				l.set_name(issue_index);
				l.effect_electorate(current_electorate);
				l.show(e.get_ID(),issue_name);				
			}
			current_electorate++;
		}
		national_event n;//create a national event effect for all electorates everyday
		n.set_happend();
		if(n.get_happend() == true)
		{
			n.set_type();
			n.set_partyNO();
			string type = n.get_type();
			int issue_index;
			string issue_name;
			if(type == "National issue") 
			{
				issue_index = n.select_issue();
				issue iii = issues.at(issue_index);
				issue_name = iii.get_name();
			}
			else issue_index = 5;//means not issue type of national event
			party &p2 = parties.at(n.get_partyNO());
			n.set_effect(p2.get_leader_ability(),p2.get_NCmanager_ability(),issue_index);
			n.set_effect_type();
			n.set_name(issue_index);
			n.set_expenditure();
			p2.set_NEexpenditure(n.get_expenditure());
			n.effect_electorate(electorate_number);
			n.show(issue_name);
		}
		else cout<<"Today has no national event."<<endl;
		manage_fund();		
		current_day++;
		cout<<endl;
	}
	last_day(electorate_number);
	election(electorate_number);
}

void election(int electorate_number)
{
	cout<<"----------------------------------------------Election----------------------------------------------"<<endl;
	int win_party = 3;
	int popularity = electorate_number/2;
	cout<<"---------------------------------------Electorate Supportation Result---------------------------------------"<<endl;
	cout<<left<<setw(30)<<"Electorate ID";
	cout<<left<<setw(30)<<"Supportation of each party";
	cout<<left<<setw(30)<<"Candidate supported"<<endl;
	for(int i = 0; i < electorate_number; i++)
	{
		electorate &e = electorates.at(i);
		e.choose_candidate();		
		cout<<left<<setw(30)<<e.get_ID();
		cout<<left<<setw(5)<<e.get_supportations(0)<<" : ";
		cout<<left<<setw(5)<<e.get_supportations(1)<<" : ";
		cout<<left<<setw(15)<<e.get_supportations(2); 
		party &p = parties.at(e.get_candidate());
		p.set_supportation();
		cout<<left<<setw(30)<<p.get_candidate_name()<<endl; 
		if(p.get_supportation() > popularity) 
		{
			win_party = e.get_candidate();
		}
	}
	cout<<"-------------------------------------------Election Result-------------------------------------------------------------------------------"<<endl;
	cout<<left<<setw(20)<<"Party name";
	cout<<left<<setw(20)<<"Leader name";
	cout<<left<<setw(20)<<"Candidate name";
	cout<<left<<setw(30)<<"Supportation(electorate number)"<<endl;
	for(int i = 0; i < 3; i++)
	{
		party p = parties.at(i);
		cout<<left<<setw(20)<<p.get_party_name();
		cout<<left<<setw(20)<<p.get_leader_name();
		cout<<left<<setw(20)<<p.get_candidate_name();
		cout<<left<<setw(30)<<p.get_supportation()<<endl;
	}		
	cout<<endl;
	if(win_party == 3)
	{
		cout<<"There is no party has won more than 50% of the electorates. So the current government is composed of Hung Parliament without a president. "<<endl;
	}
	else
	{
		party &p = parties.at(win_party);
		cout<<"Congratulations!!! "<<p.get_party_name()<<" has won more than 50% of the electorates."<<endl;
		cout<<"They will form a government and "<<p.get_leader_name()<<" will be president."<<endl;
	}
	cout<<"-----------------------------------------All over---------------------------------------------"<<endl;
}

int RandomNumber(int lowerbound, int upperbound){
	return (rand()%(upperbound - lowerbound + 1) + lowerbound);
}



