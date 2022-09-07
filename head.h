#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <random>
#include <time.h>
#include <iomanip>

using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::stoi;
using std::vector;
using std::string;
using std::endl;
using std::ostream;
using std::normal_distribution;
using std::default_random_engine;
using std::ios;
using std::setw;
using std::left;
using std::setprecision;

class electorate{
	private:
		int ID;//every electorate has a ID to identify with each other
		int supportations[3];//the supportations for each party
		int candidate = 0;//the index of party which electorate support
	public:
		electorate();//construction
		void initData();//initialize Data
		int get_ID();//get ID value
		int get_supportations(int);//show the supportations by party index
		void set_ID(int);//set ID value
		void set_supportations(int,int);//change by index of party and supportations
		void choose_candidate();//according to the largest of supportations to choose the candidate
		int get_candidate();//get candidate value
		~electorate();//destruction
};

class issue{
	private:
		string name;
		int significance[3];//issue significance for each party(could be negative means disregard issue)
		int approach; //issue approach value show the approach is positive or nagetive(could be negative means bad approach)
	public:
		issue();//construction
		void initData();//initialize Data
		string get_name();//return the issue name
		void set_name(string);
		int get_significance(int);
		int get_approach();
		void set_approach();
		~issue();//destruction
};

class party{
	private:
		string party_name;
		string leader_name;
		string candidate_name;
		int leader_ability;//leader ability
		int candidate_ability;//candidate ability
		int Cmanager_ability;//campaign manager ability
		int NCmanager_ability;//national campaign manager ability
		int NFmanager_ability;//national financial manager ability
		int fund;//Campaign fund number
		int LEexpenditure;//local event expenditure
		int NEexpenditure;//national event expenditure
		int income;//party income for each day
		int supportation;//how many electorate support this party
	public:
		party();//construction
		void initData();//initialize Data
		string get_party_name();
		string get_leader_name();
		string get_candidate_name();
		int get_leader_ability();
		int get_candidate_ability();
		int get_Cmanager_ability();
		int get_NCmanager_ability();
		int get_NFmanager_ability();
		int get_fund();
		int get_LEexpenditure();
		int get_NEexpenditure();
		int get_income();
		int get_supportation();
		void set_party_name(string);
		void set_leader_name(string);
		void set_candidate_name(string);
		void set_fund(int);
		void set_supportation();//set the electorate supported number 
		void set_LEexpenditure();//each party make all kinds of local event everyday, even though some events has no electorate take part in.
		void set_NEexpenditure(int);//set national event expenditure
		void set_income();//set income value by each day
		void manage_fund();
		~party();//destruction
};

class event{
	protected:
		string name;
		int partyNO;//party index
		int effect;//the effect of this event will change elctorate supportation
		string effect_type;//this effect is positive or negative
		bool happend;//Determine if an event has occurred
	public:
		event();//construction
		string get_name();
		virtual void set_name();
		int get_partyNO();		
		int get_effect();
		string get_effect_type();
		bool get_happend();//determination for event happend
		virtual int select_issue();//select a issue from 5 five issues
		void set_partyNO();
		void set_effect(int,int,int);
		void set_effect_type();
		virtual void effect_electorate();
		virtual void set_happend();
		virtual void show();//display event value
		~event();//destruction
};

class local_event : public event{
	private:
		string type;//local event has three types which include debate,event and issue.
	public:
		local_event();//construction
		string get_type();
		int select_issue();
		void set_type();
		void set_name(int);
		void effect_electorate(int);//the effect of event will change a supportation of electorate for each party
		void set_happend();
		void show(int,string);
		~local_event();//destruction
};

class national_event : public event{
	private:
		string type;
		int expenditure = 0;
	public:
		national_event();//construction
		string get_type();
		int get_expenditure();
		int select_issue();
		void set_type();
		void set_name(int);
		void effect_electorate(int);//the effect of event will change all supportations of electorate for each party
		void set_happend();
		void set_expenditure();
		void last_day(int,int);//the last day will create a national leader debate for cost all money and finally effect supportation
		void show(string);
		~national_event();//destruction
};
void abort();
void checkParameter(int,int,int);//check the Parameter whether is legal
void create_information(int);//create initialization informations of each electorate,issue, party
void create_electorate(int);//initialize electorates
void create_issue();//initialize issue
void create_party();//initialize party
void print_initialization(int);//print all initializations
void last_day(int);//create a last day for cost all the remaining fund
void manage_fund();//manage and print partys' fund everyday 
int RandomNumber(int, int);//create a random number
void make_events(int, int);//create local events and national events everyday
void election(int);//process the election day

#endif
