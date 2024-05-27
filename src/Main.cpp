//#include "Train.hpp"
#include "Main.hpp"


class Train;
extern Train * train;
Tree * signUp(Tree* root)
{
    string name;
    int age;
    char gender;
    string username;
    string password;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter gender: ";
    cin >> gender;
    label:
    cout << "Enter username: ";
    cin >> username;
    for (int i = 0; i < 8; i++)
    {
        for(auto p : root->passengerList[i])
        {
            if (p->getUsername() == username )
            {
            	cout<<"USER NAME ALREADY EXISTS!!!"<<endl;
                goto label;
            }
        }
    }
    cout << "Enter password: ";
    cin >> password;
    passenger* p = new passenger(name, age, gender, username, password);
    root = insert(root, p); // Update the root pointer with the new passenger
    cout << "Passenger added successfully" << endl;
    cout<<root<<endl;
    return root;
}



void display()
{
    cout << "1.sign up" << endl;
    cout << "2.log in" << endl;
    cout << "3.log out" << endl;
    cout << "4.exit"<< endl;
}

void dispalyForBooking()
{
    cout << "1.search train timings" << endl;
    cout << "2.book ticket" << endl;
    cout << "3.cancel ticket" << endl;
    cout << "4.fare enquiry" << endl;
    cout << "5.TICKET DETAILS" <<endl;
    cout << "6.CHECK SEAT STATUS" <<endl;
    cout << "7.USER HISTORY" <<endl;
    cout << "8.ADD TRAIN" <<endl;
    cout << "9.DETAILS OF SPECIFIC SEAT " <<endl;
    cout << "10.exit" << endl;
}


void logOut(Tree* root)
{
    string username;
    string password;
    cout << "enter the username" << endl;
    cin >> username;
    cout << "enter the password " << endl;
    cin >> password;
    for (int i = 0; i < 8; i++)
    {
        for(auto p : root->passengerList[i])
        {
            if (p->getUsername() == username && p->getPassword() == password)
            {
                auto it = find(root->passengerList[i].begin(),root->passengerList[i].end(),p);
                if (it != root->passengerList[i].end())

                {
                    root->passengerList[i].erase(it);
                    cout << "log out successful" << endl;
                    return;
                }
                
                cout << "LOG OUT successful" << endl;
                return;
            }
        }
    }
    
}

passenger* logIn(Tree* root)
{
    string username;
    string password;
    cout << "Enter username: ";

    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    bool loggedIn = false;
    const int maxAttempts = 3;
    int attempts = 0;
          
	//cout<<root->passengerList<<endl;
	//cout<<root->passengerList[5].getUsername()<<endl;
    while (!loggedIn && attempts < maxAttempts)
    {
        for (int i = 0; i < 8; i++)
        {
            for(auto passenger : root->passengerList[i])
            {
                if (passenger->getUsername() == username && passenger->getPassword() == password)
                {
                    loggedIn = true;
                    current_user=passenger;
                    cout << "LOG IN successful"<< endl;
                    log_in_result=true;
                    return current_user; 
                }
            }
        }
        
        attempts++;
        if (attempts < maxAttempts)
        {
            cout << "Login failed. Please try again." << endl;
            cout << "Attempts left: " << maxAttempts - attempts << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
        }
    }

    if (!loggedIn)
    {
        cout << "Login failed after " << maxAttempts << " attempts." << endl;
        cout << "Would you like to sign up? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            signUp(root); // Prompt the user to sign up if desired
        }
    }
    return current_user;
}




int main() 
{
	//fill_array();
    //Tree* root = nullptr;
    bool loop = true;
    // Create some dummy passengers to insert into the tree
    passenger *dummy=new passenger("dummy",1,'m',"dummy","dummy");
    passenger *p1=new passenger("nithish", 24, 'm', "1", "1");
    // Assuming you have a root node declared somewhere

    
    // Insert passengers into the tree

    root = insert(root, dummy);
    root = insert(root, p1);

    create_train();
    printUserDetails(root);

    while (loop)
    {
        display();
        int choice;
        cin >> choice;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid input" << endl;
			continue;
		}
        switch (choice)
        {
        case 1:
            root=signUp(root);
            break;
        case 2:
            current_user=logIn(root);
            if(log_in_result)
            {
            	bool loop1 = true;
            	while (loop1)
            	{
            		dispalyForBooking();
            		cout<<"ENTER YOUR CHOICE: "<<endl;
            		int ch;
            		cin >> ch;
					if(cin.fail())
		    	    {
        			    cin.clear();
        			    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        			    cout << "Please enter a valid input" << endl;
       	 			    continue;
       				}
            	    switch (ch)
            	    {
            	    case 1:
            	        trainTimings();
            	        break;
            	    case 2:
            	        ticketBooking(root);
            	        break;
            	    case 3:
            	        cancelTicket(root);
            	        break;
            	    case 4:
            	        calculateTicketFare();
            	        break;
            	    case 5:
            	    	printTicketDetails(0,root);
            	    	break;
            	    case 6:
            	    	seat_status();
            	    	break;
            	    case 7:
            	    	user_history(current_user);
            	    	break;
            	    case 8:
            	    	addTrain();
            	    	break;
            	    case 9:	
            	    	specific_seat_details();
            	    	break;
            	    case 10:
            	        loop1 = false;
            	        break;
            	    default:
            	        cout << "Invalid choice" << endl;
            	        break;
            	    }   
            	}
        	}
       		break;
        case 3:
            logOut(root);
            break;
        case 4:
            loop = false;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    
    return 0;
}

