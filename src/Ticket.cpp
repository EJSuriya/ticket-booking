#include "Ticket.hpp"
#include "Train.hpp"

using namespace std;
/*
bool isSeatAvailable(int seatNumber, bool array[], int maxSize) 
{
    if (array[seatNumber - 1==1]&&(seatNumber > 1 || seatNumber < maxSize)) 
    {
        //cout << "Invalid seat number" << endl;
        return true;
    }
    //return array[seatNumber - 1]
    return false;
}
*/

bool isSeatAvailable(Train* train,int seatNumber, string name) 
{
    if (name=="AC" && train->acArray[seatNumber]==true && seatNumber >=0 && seatNumber <100) 
    {
    	cout<<"SEAT IS AVAILABLE"<<endl;
        return true;
    }
    else if (name=="sleeper" && train->sleeperArray[seatNumber]==true && seatNumber >=0 && seatNumber <100) 
    {
    	cout<<"SEAT IS AVAILABLE"<<endl;
        return true;
    }
    else if (name=="ladies" && train->ladiesArray[seatNumber]==true && seatNumber >=0 && seatNumber <100) 
    {
    	cout<<"SEAT IS AVAILABLE"<<endl;
        return true;
    }
    else if (name=="sitting" && train->sittingArray[seatNumber]==true && seatNumber >=0 && seatNumber <100) 
    {
    	cout<<"SEAT IS AVAILABLE"<<endl;
        return true;
    }
    else
    {
    	return false;
    } 
    return false;
}
void printTicketDetails(int id,Tree* root)
{
	if(id==0)
	{
		cout<<"ENTER THE TICKET NUMBER :"<<endl;
		int id;
		cin>>id;
	}
	bool present=false;
	for (auto it: ticketMappings)
	{
		if(it.first->getTicketId()==id)
		{
			present=true;
			cout << "Ticket ID: " << it.first->getTicketId() << endl;
        	cout << "Train Name: " << it.second.first->getTrainName() << endl;
        	cout << "Source STATION ID: " << it.first->getSourceNo() << endl;
        	cout << "Destination STATION ID: " << it.first->getDestinationNo() << endl;
        	cout << "CLASS TYPE :"<< it.first->getClassName() << endl;
        	cout << "SEAT NUMBER :"<< it.first->getSeatNumber() << endl;
        	cout << "Passenger Name: " << it.second.second->getName() << endl;
		}
	}
    if (!present)
    {
    	//semicolon error
        cout << "ticket details not found"<< endl;
    }
}

void setArrayValue(void* array, int index, bool value, int capacity) {
    if (index < 0 || index >= capacity) 
    {
        cout << "Invalid index" << endl;
        return;
    }
    static_cast<bool*>(array)[index] = value;
}

/*
void fill_array()
{
	fill(acArray, acArray + 100, true);
	fill(sleeperArray, sleeperArray + 100, true);
	fill(ladiesArray, ladiesArray + 100, true);
	fill(sittingArray, sittingArray + 100, true);

}
*/
int acCapacity;
int ladiesCapacity;
int sleeperCapacity;
int sittingCapacity;


void change_seat_status(Train* train,string name,int seatNo)
{
	if(name=="AC")
	{
		cout<<"a"<<endl;
		train->acArray[seatNo - 1]=false;
	}
	else if(name=="sleeper")
	{cout<<"b"<<endl;
		train->sleeperArray[seatNo - 1]=false;
	}
	else if(name=="ladies")
	{cout<<"c"<<endl;
		train->ladiesArray[seatNo - 1]=false;
	}
	else 
	{cout<<"d"<<endl;
		train->sittingArray[seatNo - 1]=false;
	}
}


void ticketBooking(Tree* root)
{
    vector<vector<bool>> ticketArray;
    int s=0,d=0;
    string da;
    availableTrains = searchTRainAdvanced(&s,&d,&da);
    int trainNo = 1;
    label:
    for(auto t : availableTrains)
    {
        //cout <<"Train Number : "<< trainNo++ << endl;
        trainDetails(t);
    }
    cout << "ENTER THE TRAIN ID: " << endl;
    int tno;
    cin >>tno;
    //semicolon error
    int i = 0;
    bool present=false;
    for(auto t : availableTrains)
    {
        if(t->get_train_id()==tno)
        {
        	present=true;
            train = t;
        }
    }
    if(!present)
    {
    	cout<<"!!!INCORRECT TRAIN ID!!!"<<endl;
    	goto label;
    }
    double totalAmount = 0.0;
    for(auto c : train->getClasses())
    {
        if (c->getClassName() == "AC")
        {
            acCapacity = c->getCapacity();
        }
        if (c->getClassName() == "sleeper")
        {
        	//semicolon error
            sleeperCapacity = c->getCapacity();
        }
        if (c->getClassName() == "ladies")
        {
            ladiesCapacity = c->getCapacity();
        }
        if (c->getClassName()== "sitting")
        {
            sittingCapacity = c->getCapacity();
        }
    }

	
    
label1:
    string className;
    cout << "enter the class type (AC,sleeper,sitting,ladies)" << endl;
    cin >> className;
    ClassType* classType = nullptr;
    bool isClassAvailable = false;
    for(auto c : train->getClasses())
    {
        if (c->getClassName() == className)
        {
            classType = c;
            break;
        }
    }
    classDetails(classType);

    int seatNo;
    //semicolon error
    int selectedCapacity;
   //	void* selectedArray=nullptr;
   	int array=0;
    bool seatAvailable = false;
    cout << "Enter the seat number : " << endl;
    cin >> seatNo;
    seatAvailable=isSeatAvailable(train,seatNo-1, className);
    bool isConfirm=false;
    if (seatAvailable)
    {
        string confirmation;
        cout << "please confirm for booking this ticket ( yes || no ) "<< endl;
        cin >> confirmation;
        if(confirmation == "yes")
        {
            isConfirm = true;
        }
        else
        {
            cout << "please confirm for further purpose " << endl;
        }
    }
    else
    {
    	bool possible=false;
    	for(auto it :ticketMappings)
    	{
    		if(it.first->getSeatNumber()==seatNo && it.first->getClassName()==className)
    		{
    			if(it.first->getSourceNo()>=d || it.first->getDestinationNo()<=s)
    			{
    				isConfirm = true;
    				possible=true;
    			}
    		}
    	}
    	if(!possible)
    	{
        	cout << "seat is already booked, please select any other seat " << endl;
        	cout<<"PRESS 1 TO AGAIN START BOOKING TICKET OR 0 TO GO TO MAIN PAGE :"<<endl;
        	int opt;
        	cin>>opt;
        	if(opt==1)
        	{
        		goto label1;
        	}
        	else
        		return;
        }
    }

    double amountPayable;
    passenger* p = nullptr;
    if (isConfirm)
    {
    	//semicolon error
        totalAmount += calculateJourneyFare(train,s,d,className);
        //cout<<"THE TOTAL FARE AMOUNT IS : "<<totalAmount<<endl;
        int passengerId;
        cout << "enter your passenger id " << endl;
        cin >> passengerId;
        p = getPassenger(root, passengerId);
        Ticket* t = new Ticket(train->get_train_id(), p->getPassengerId(),s,d,seatNo,className,da);
        for(auto c : train->getClasses())
        {
            if (c->getClassName() == className)
            {
                //c->decrease_count();
                ticketMappings.insert({t, make_pair(train,p)});
                //setArrayValue(selectedArray, seatNo - 1, false, selectedCapacity);
                
                change_seat_status(train,className,seatNo);
                cout<<"TICKET BOOKED SUCCESSFULLY"<<endl;
                user_history(p);
            }
        }
    }
}

void reset_status(Train* train,int seatNo,string name)
{
	if(name=="AC")
	{
		train->acArray[seatNo - 1]=true;
	}
	else if(name=="sleeper")
	{
		train->sleeperArray[seatNo - 1]=true;
	}
	else if(name=="ladies")
	{
		train->ladiesArray[seatNo - 1]=true;
	}
	else 
	{
		train->sittingArray[seatNo - 1]=true;
	}
}


void cancelTicket(Tree* root)
{
    int id,start,end,count=0,seatNumber;
    string className;
    cout << "please enter your ticket id " << endl;
    cin >> id;
    /*cout <<"ENTER YOUR STARTING STATION NUMBER :" <<endl;
    cin >>start;
    cout <<"ENTER YOUR DESTINATION STATION NUMBER :" <<endl;
    cin >>end;*/
    printTicketDetails(id,root);
    string choice;
    cout << "do you want to cancel the ticket " << endl;
    cin >> choice;
    if(choice == "yes")
    {
    	for (auto iterator : ticketMappings)
    	{
    		if (iterator.first->getTicketId() == id )
    		{
    			className = iterator.first->getClassName();
    			seatNumber = iterator.first->getSeatNumber();
    		}
    	}
    	for (auto iterator1 : ticketMappings)
    	{
    		if(iterator1.first->getClassName() == className && iterator1.first->getSeatNumber() == seatNumber)
    		{
    			++count;
    		}
    	}
	 	auto it = ticketMappings.begin();
   		for (; it != ticketMappings.end(); ++it) 
    	{
       		if (it->first->getTicketId() == id) 
       		{
       			if(count == 1)
       			{
       				reset_status(train,seatNumber,className);
       			}
           		delete it->first; 
           		ticketMappings.erase(it);
           		cout << "Ticket with ID " << id << " has been removed." << endl;
           		return;
     		}
    	}
    }
}




void user_history(passenger * p)
{
	bool present=true;
	for (auto it: ticketMappings)
	{
		if(it.first->getPassengerId()==p->getPassengerId())
		{
			present=false;
			cout<<"---------------------------------------------------------"<<endl;
			cout << "Ticket ID: " << it.first->getTicketId() << endl;
        	cout << "Train Name: " << it.second.first->getTrainName() << endl;
        	cout << "DATE : " << it.second.first->getDate()<<endl;
        	cout << "Source STATION ID: " << it.first->getSourceNo() << endl;
        	cout << "Destination STATION ID: " << it.first->getDestinationNo() << endl;
        	cout << "CLASS TYPE :"<< it.first->getClassName() << endl;
        	cout << "SEAT NUMBER :"<< it.first->getSeatNumber() << endl;
        	cout << "Passenger Name: " << it.second.second->getName() << endl;
        	cout<<"---------------------------------------------------------"<<endl;
		}
	}
	if(present)
	{
		cout<<"USER HASN'T BOOKED ANY TICKET"<<endl;
		return;
	}
}

void specific_seat_details()
{
	int seatNo,tno;
	string name,date;
	bool available=true;
	cout << "ENTER THE TRAIN ID: " << endl;
    cin >>tno;
    cout << "ENTER THE DATE IN WHICH YOU WANT TO CHECK:"<<endl;
    cin>>date;
    cout<<"ENTER THE CLASS TYPE:"<<endl;
	cin>>name;
	cout<<"ENTER THE SEAT NUMBER YOU WANT TO CHECK:"<<endl;
	cin>>seatNo;
	for(auto it :ticketMappings)
	{
		if(it.first->getTrainId()==tno && it.first->getClassName()==name && it.first->getSeatNumber() && it.first->getDate()==date)
		{
			available=false;
			printTicketDetails(it.first->getTicketId(),root);
			cout<<"----------------------------------------------"<<endl;
		}
	}

	if(available)
	{
		cout<<"EITHER THE ENTERED DEATILS ARE WRONG OR THE SEAT IS NOT BOOKED AND IS AVAILABLE"<<endl;
	}

}

