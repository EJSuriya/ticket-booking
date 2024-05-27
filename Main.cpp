#include"Main.hpp"

void signUp(Tree*& root)
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
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    passenger* p = new passenger(name, age, gender, username, password);
    root = insert(root, p); // Update the root pointer with the new passenger
    cout << "Passenger added successfully" << endl;
}



void display()
{
    cout << "1.sign up" << endl;
    cout << "2.log in" << endl;
    cout << "3.ticket booking" << endl;
    cout << "4.exit"<< endl;
}

void logIn(Tree* root)
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

    while (!loggedIn && attempts < maxAttempts)
    {
        for (auto i = 0; i < 8; i++)
        {
            for(const auto& passenger : root->passengerList[i])
            {
                if (passenger.getUsername() == username && passenger.getPassword() == password)
                {
                    loggedIn = true;
                    cout << "LOG IN successful"<< endl;
                    return; // Exit the function after successful login
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
            if (p.getUsername() == username && p.getPassword() == password)
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



int main() 
{

    Tree* root = nullptr;
    bool loop = true;

    // Create some dummy passengers to insert into the tree
    passenger dummy("dummy",1,'m',"dummy","dummy");
    passenger p1("nithish", 24, 'm', "nithish@123", "yazhini0411@");
    // Assuming you have a root node declared somewhere

    
    // Insert passengers into the tree
    // cout << "into the insert function" << endl;
    root = insert(root, &dummy);
    root = insert(root, &p1);


    // create train
    ClassType acClass("AC", 100, 2.2);
    ClassType sleeperClass("sleeper", 100, 1.2);
    ClassType ladies("ladies", 50, 1.3);
    ClassType secondSitting("sitting", 150, 1);
    ClassType unreserved("ur", 100, 0.8);

    Schedule schedule("5.45pm", "2.30am");

    // Creating vector of ClassType for train classes
    vector<ClassType> classTypes;
    classTypes.push_back(acClass);
    classTypes.push_back(sleeperClass);
    classTypes.push_back(ladies);
    classTypes.push_back(secondSitting);
    classTypes.push_back(unreserved);
    

    // create stations
    vector<stations> route1 = {
        stations("Chennai-Egmore", 0.0),
        stations("vilupuram", 165.0),
        stations("trichy", 164.0),
        stations("pudukottai", 56.0),
        stations("Mandabam-Ramnad", 129.0)
    };

    // creating train 

    
    Train rameshwaramExpress1("Rameswaram Express1", classTypes, schedule, "Chennai-Egmore", "Mandabam-Ramnad", "2024-05-07", route1);


    trainList.push_back(rameshwaramExpress1);
    // trainList.push_back(rameshwaramExpress2);

    // print the trains 

    // for(auto i : trainList)
    // {
    //     cout << i.getTrainId() << endl;
    //     cout << i.getTrainName() << endl;
    //     cout << i.getSource() << endl;
    //     cout << i.getDestination() << endl;
    //     cout << i.getSchedule().getDepartureTime() << endl;
    //     cout << i.getSchedule().getArrivedTime() << endl;
    // }
    printUserDetails(root);

    while (loop)
    {
        display();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            signUp(root);
            break;
        case 2:
            logIn(root);
            break;
        case 3:
            loop = false;
            break;
        case 4:
            // ticketBooking(root);
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    // cout << "into the print function"<< endl;

    // print details
    // cout << "end of functions "<< endl;
    
    return 0;
}

