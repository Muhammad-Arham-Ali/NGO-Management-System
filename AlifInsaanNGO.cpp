#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int Size = 10;

// Global arrays and counters for storing data
string project[Size][2];
int projectCount = 0;

string volunteer[Size];
int volunteerCount = 0;

string beneficiary[Size];
int beneficiaryCount = 0;

string donation[Size][2];
int donationCount = 0;

string suggestions[Size];
int suggestionCount = 0;

string admin[Size][2];
int adminCount = 0;

string agent[Size][2];
int agentCount = 0;

// Function declarations
void MainMenu();
void SignUpMenu();
void signUp(string user);
void login(string username, string password, string user);
void AdminLogin();
void AgentLogin();
void AdminMenu();
void AgentMenu();
void AddInformation();
void Store(string arr[], int &count, const string &value);
void Store2d(string arr[][2], int &count, const string &value, const string &value2);
void Save(const string arr[], int &count, const string &filename);
void Save2d(const string arr[][2], int &count, const string &filename);
void AddProject();
void AddVolunteer();
void RecordSuggestion();
void RecordBeneficiary();
void RecordDonation();
void ViewInformation();
void View(string arr[], const int &count, string name);
void View2d(string arr[][2], const int &count, string name, string name2);
void Sort(string arr[], int count);
void Sort2d(string arr[][2], int count);
void SortData();
void SearchInformation();
int Search(string arr[], int count, string target);
int Search2d(string arr[][2], int count, string target);
void SearchDonor();
void SearchProject();
void SearchVolunteer();
void SearchBeneficiary();
void DeleteInformation();
void Delete(string arr[], int &count, string target);
void Delete2d(string arr[][2], int &count, string target);
void DeleteProject();
void DeleteDonor();
void DeleteVolunteer();
void DeleteBeneficiary();
void DeleteSuggestion();
void EditInformation();
void Edit(string arr[], int count, const string &oldValue, const string &newValue);
void Edit2d(string arr[][2], int count, const string &oldValue, const string &newValue, const string &newValue2);
void EditProject();
void EditVolunteer();
void EditBeneficiary();
void EditDonation();
void LogOut();
void ExitProgram();
void Load(string arr[], int count, const string filename);
void Load2d(string arr[][2], int count, const string filename);
void LoadData();
void Screen();

// Main Function
int main()
{
    LoadData();
    SortData();
    int option;
    do
    {
        MainMenu();
        cin >> option;

        switch (option)
        {
        case 1:
            AdminLogin();
            break;
        case 2:
            AgentLogin();
            break;
        case 3:
            SignUpMenu();
            break;
        case 4:
            ExitProgram();
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 4);

    return 0;
}

// File Sort Functions
void Sort(string arr[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void Sort2d(string arr[][2], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[i][0] > arr[j][0])
            {
                swap(arr[i][0], arr[j][0]);
                swap(arr[i][1], arr[j][1]);
            }
        }
    }
}

void SortData()
{
    Sort2d(project, projectCount);
    Sort2d(donation, donationCount);
    Sort2d(admin, adminCount);
    Sort2d(agent, agentCount);
    Sort(volunteer, volunteerCount);
    Sort(beneficiary, beneficiaryCount);
    Sort(suggestions, suggestionCount);
}

// File load function
void Load2d(string arr[][2], int count, const string filename)
{
    ifstream fin;
    fin.open(filename);
    if (fin)
    {
        fin >> count;
        fin.ignore();
        for (int i = 0; i < count; i++)
        {
            getline(fin, arr[i][0], ':');
            getline(fin, arr[i][1]);
        }
        fin.close();
    }
}

void Load(string arr[], int count, const string filename)
{
    ifstream fin;

    fin.open(filename);
    if (fin)
    {
        fin >> count;
        fin.ignore();
        for (int i = 0; i < count; i++)
        {
            getline(fin, arr[i]);
        }
        fin.close();
    }
}

void LoadData()
{

    Load2d(project, projectCount, "projects.txt");
    Load2d(donation, donationCount, "donations.txt");
    Load2d(admin, adminCount, "admin.txt");
    Load2d(agent, agentCount, "agent.txt");
    Load(volunteer, volunteerCount, "volunteers.txt");
    Load(beneficiary, beneficiaryCount, "beneficiaries.txt");
    Load(suggestions, suggestionCount, "suggestions.txt");
}

// Login and Signup Functions

void SignUpMenu()
{
    int choice;
    do
    {
        cout << "=====================================" << endl
             << "=           Sign Up Menu!           =" << endl
             << "=====================================" << endl
             << "1. Sign up as ADMIN" << endl
             << "2. Sign up as AGENT" << endl
             << "3. Back to Main Menu" << endl
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            signUp("admin");
            break;
        case 2:
            signUp("agent");
            break;
        case 3:
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);
}

void signUp(string user)
{
    if (user == "admin")
    {
        string username, password;
        cin.ignore();
        cout << "Enter Admin Username: ";
        getline(cin, username);
        cout << "Enter Admin Password: ";
        getline(cin, password);
        Store2d(admin, adminCount, username, password);
        Save2d(admin, adminCount, "admin.txt");
        cout << "Admin registered successfully!" << endl;
    }
    else if (user == "agent")
    {
        string username, password;
        cin.ignore();
        cout << "Enter Agent Username: ";
        getline(cin, username);
        cout << "Enter Agent Password: ";
        getline(cin, password);
        Store2d(agent, agentCount, username, password);
        Save2d(agent, agentCount, "agent.txt");
        cout << "Agent registered successfully!" << endl;
    }
}

void login(string username, string password, string user)
{

    if (user == "admin")
    {
        for (int i = 0; i < adminCount; i++)
        {
            if (username == admin[i][0] && password == admin[i][1])
            {
                cout << "Login successful!" << endl;
                AdminMenu();
                return;
            }
        }
        cout << "Invalid credentials. Please try again." << endl;
    }
    else if (user == "agent")
    {
        for (int i = 0; i < agentCount; i++)
        {
            if (username == agent[i][0] && password == agent[i][1])
            {
                cout << "Login successful!" << endl;
                AgentMenu();
                return;
            }
        }
        cout << "Invalid credentials. Please try again." << endl;
    }
}

void AdminLogin()
{
    string Username, Password;
    cin.ignore();
    cout << "Enter Admin Username: ";
    getline(cin, Username);
    cout << "Enter Admin Password: ";
    getline(cin, Password);
    login(Username, Password, "admin");
}

void AgentLogin()
{
    string Username, Password;
    cin.ignore();
    cout << "Enter Agent Username: ";
    getline(cin, Username);
    cout << "Enter Agent Password: ";
    getline(cin, Password);
    login(Username, Password, "agent");
}

// Menu Functions
void Screen()
{
    system("cls");
}
void MainMenu()
{
    Screen();
    cout << "####################################################################################\n"
         << "#                   Welcome to ALIF INSAAN NGO Management System                   #\n"
         << "####################################################################################\n"
         << "\n"
         << "1. Login as ADMIN\n"
         << "2. Login as AGENT\n"
         << "3. Sign Up\n"
         << "4. Exit\n"
         << "Choose option: ";
}

// Admin Menu Functions
void AdminMenu()
{
    Screen();
    int action;
    cout << "=====================================\n"
         << "=        Logged In As ADMIN!        =\n"
         << "=====================================\n";
    do
    {
        cout << "Choose an action!" << endl
             << "1. Add Information" << endl
             << "2. Edit Information" << endl
             << "3. Delete Information" << endl
             << "4. Search Information" << endl
             << "5. View Information" << endl
             << "6. Log Out" << endl
             << "Enter your choice (1-6): ";
        cin >> action;
        switch (action)
        {
        case 1:
            AddInformation();
            break;
        case 2:
            EditInformation();
            break;
        case 3:
            DeleteInformation();
            break;
        case 4:
            SearchInformation();
            break;
        case 5:
            ViewInformation();
            break;
        case 6:
            LogOut();
            break;
        default:
            cout << "Invalid action. Please try again." << endl;
        }
    } while (action != 6);
}

void AddInformation()
{
    Screen();
    int choice;
    do
    {
        cout << "=====================================\n"
             << "=          Add Information!         =\n"
             << "=====================================\n"
             << "1. Add Project\n"
             << "2. Add Volunteer\n"
             << "3. Record Beneficiary\n"
             << "4. Record Donation\n"
             << "5. Back to Admin Menu\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            AddProject();
            break;
        case 2:
            AddVolunteer();
            break;
        case 3:
            RecordBeneficiary();
            break;
        case 4:
            RecordDonation();
            break;
        case 5:
            AdminMenu();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}

void EditInformation()
{
    Screen();
    int choice;
    do
    {
        cout << "=====================================\n"
             << "=         Edit Information!         =\n"
             << "=====================================\n"
             << "1. Edit Project\n"
             << "2. Edit Donation\n"
             << "3. Edit Volunteer\n"
             << "4. Edit Beneficiary\n"
             << "5. Back to Admin Menu\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            EditProject();
            break;
        case 2:
            EditDonation();
            break;
        case 3:
            EditVolunteer();
            break;
        case 4:
            EditBeneficiary();
            break;
        case 5:
            AdminMenu();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}

void DeleteInformation()
{
    Screen();
    int choice;
    do
    {
        cout << "=====================================\n"
             << "=        Delete Information!        =\n"
             << "=====================================\n"
             << "1. Delete Project\n"
             << "2. Delete Donation\n"
             << "3. Delete Volunteer\n"
             << "4. Delete Beneficiary\n"
             << "5. Back to Admin Menu\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            DeleteProject();
            break;
        case 2:
            DeleteDonor();
            break;
        case 3:
            DeleteVolunteer();
            break;
        case 4:
            DeleteBeneficiary();
            break;
        case 5:
            AdminMenu();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}

void SearchInformation()
{
    Screen();
    int choice;
    do
    {
        cout << "=====================================\n"
             << "=        Search Information!        =\n"
             << "=====================================\n"
             << "1. Search Project\n"
             << "2. Search Donor\n"
             << "3. Search Volunteer\n"
             << "4. Search Beneficiary\n"
             << "5. Back to Admin Menu\n"
             << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            SearchProject();
            break;
        case 2:
            SearchDonor();
            break;
        case 3:
            SearchVolunteer();
            break;
        case 4:
            SearchBeneficiary();
            break;
        case 5:
            AdminMenu();
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);
}

void ViewInformation()
{
    Screen();
    int choice;
    do
    {
        cout << "=====================================\n"
             << "=         View Information!         =\n"
             << "=====================================\n"
             << "1. View Project Details\n"
             << "2. View Donation Details\n"
             << "3. View Volunteer Details\n"
             << "4. View Beneficiary Details\n"
             << "5. View Suggestions\n"
             << "6. Back to Admin Menu\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            View2d(project, projectCount, "Project", "Description");
            break;
        case 2:
            View2d(donation, donationCount, "Donor", "Amount");
            break;
        case 3:
            View(volunteer, volunteerCount, "Volunteer");
            break;
        case 4:
            View(beneficiary, beneficiaryCount, "Beneficiary");
            break;
        case 5:
            View(suggestions, suggestionCount, "Suggestion");
            break;
        case 6:
            AdminMenu();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 6);
}

void AgentMenu()
{
    Screen();
    int action;
    cout << "=====================================\n"
         << "=        Logged In As AGENT!       =\n"
         << "=====================================" << endl;

    do
    {
        cout << "Choose an action!\n"
             << "1.  View Project Details\n"
             << "2.  View Volunteer Details\n"
             << "3.  View Donation Details\n"
             << "4.  View Beneficiary Details\n"
             << "5.  Give Suggestions\n"
             << "6.  Log Out\n"
             << "\n"
             << "Enter your choice (1-7): ";
        cin >> action;

        switch (action)
        {
        case 1:
            View2d(project, projectCount, "Project", "Description");
            break;
        case 2:
            View(volunteer, volunteerCount, "Volunteer");
            break;
        case 3:
            View2d(donation, donationCount, "Donor", "Amount");
            break;
        case 4:
            View(beneficiary, beneficiaryCount, "Beneficiary");
            break;
        case 5:
            RecordSuggestion();
            break;
        case 6:
            LogOut();
            break;
        default:
            cout << "Invalid action. Please try again." << endl;
        }
    } while (action != 7);
}

// Adding/Record Functions

void Store(string arr[], int &count, const string &value)
{
    if (count < Size)
    {
        arr[count] = value;
        count++;
    }
    else
    {
        cout << "Array is full." << endl;
    }
}
void Store2d(string arr[][2], int &count, const string &value, const string &value2)
{
    if (count < Size)
    {
        arr[count][0] = value;
        arr[count][1] = value2;
        count++;
    }
    else
    {
        cout << "Array is full." << endl;
    }
}

void Save(const string arr[], int &count, const string &filename)
{
    ofstream fout(filename);
    if (fout)
    {
        fout << count << endl;
        for (int i = 0; i < count; i++)
        {
            fout << arr[i] << endl;
        }
        fout.close();
    }
    else
    {
        cout << "Failed to open file: " << filename << endl;
    }
}

void Save2d(const string arr[][2], int &count, const string &filename)
{
    ofstream fout(filename);
    if (fout)
    {
        fout << count << endl;
        for (int i = 0; i < count; i++)
        {
            fout << arr[i][0] << ":" << arr[i][1] << endl;
        }
        fout.close();
    }
    else
    {
        cout << "Failed to open file: " << filename << endl;
    }
}

void AddProject()
{
    string name, description;
    cout << "\nEnter Project Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter Project Description: ";
    getline(cin, description);
    cout << "Project added successfully!" << endl;
    Store2d(project, projectCount, name, description);
    Save2d(project, projectCount, "projects.txt");
}

void AddVolunteer()
{
    string name;
    cout << "Enter Volunteer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Volunteer added successfully!" << endl;
    Store(volunteer, volunteerCount, name);
    Save(volunteer, volunteerCount, "volunteers.txt");
}

void RecordBeneficiary()
{
    string name;
    cout << "Enter Beneficiary Name: ";
    cin.ignore();
    getline(cin, name);
    Store(beneficiary, beneficiaryCount, name);
    cout << "Beneficiary recorded successfully!" << endl;
    Save(beneficiary, beneficiaryCount, "beneficiaries.txt");
}

void RecordDonation()
{
    string amount, donorName;
    cout << "Enter Donation Amount: ";
    cin.ignore();
    getline(cin, amount);
    cout << "Enter Donor Name: ";
    getline(cin, donorName);
    Store2d(donation, donationCount, donorName, amount);
    cout << "Donation recorded successfully!" << endl;
    Save2d(donation, donationCount, "donations.txt");
}

void RecordSuggestion()
{
    string suggestion;
    cout << "Enter your suggestion: ";
    cin.ignore();
    getline(cin, suggestion);
    Store(suggestions, suggestionCount, suggestion);
    cout << "Suggestion recorded successfully!" << endl;
    Save(suggestions, suggestionCount, "suggestions.txt");
}

// View Functions

void View(string arr[], const int &count, string name)
{
    if (count == 0)
    {
        cout << "Nothing to display." << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << name << i + 1 << ": " << arr[i] << endl;
        }
    }
    cout << endl;
}

void View2d(string arr[][2], const int &count, string name, string name2)
{
    if (count == 0)
    {
        cout << "Nothing to display." << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            cout << name << " " << i + 1 << ": " << arr[i][0] << " - " << name2 << " " << arr[i][1] << "" << endl;
        }
    }
    cout << endl;
}

// Exiting Functions
void LogOut()
{
    cout << "=====================================" << endl
         << "=           Logging out             =" << endl
         << "=====================================" << endl;
}

void ExitProgram()
{
    cout << "=====================================" << endl
         << "=  Exiting the program. Thank you!  =" << endl
         << "=====================================" << endl;
}

// Search Functions

int Search(string arr[], int count, string target)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i] == target)
        {
            return i; // Return index if found
        }
    }
    return -1;
}

int Search2d(string arr[][2], int count, string target)
{
    for (int i = 0; i < count; i++)
    {
        if (arr[i][0] == target)
        {
            return i; // Return index if found
        }
    }
    return -1;
}

void SearchDonor()
{
    string name;
    cout << "Enter donor name to search: ";
    cin.ignore();
    getline(cin, name);

    int index = Search2d(donation, donationCount, name);
    if (index != -1)
    {
        cout << "Donor found at position " << index + 1 << ": " << donation[index][0] << " :" << donation[index][1] << endl;
    }
    else
    {
        cout << "Donor not found.\n";
    }
}

void SearchProject()
{
    string name;
    cout << "Enter project name to search: ";
    cin.ignore();
    getline(cin, name);

    int index = Search2d(project, projectCount, name);
    if (index != -1)
    {
        cout << "Project found at position " << index + 1 << ": " << project[index][0] << " - " << project[index][1] << endl;
    }
    else
    {
        cout << "Project not found.\n";
    }
}

void SearchVolunteer()
{
    string name;
    cout << "Enter volunteer name to search: ";
    cin.ignore();
    getline(cin, name);

    int index = Search(volunteer, volunteerCount, name);
    if (index != -1)
    {
        cout << "Volunteer found at position " << index + 1 << ": " << volunteer[index] << endl;
    }
    else
    {
        cout << "Volunteer not found.\n";
    }
}

void SearchBeneficiary()
{
    string name;
    cout << "Enter beneficiary name to search: ";
    cin.ignore();
    getline(cin, name);

    int index = Search(beneficiary, beneficiaryCount, name);
    if (index != -1)
    {
        cout << "Beneficiary found at position " << index + 1 << ": " << beneficiary[index] << endl;
    }
    else
    {
        cout << "Beneficiary not found.\n";
    }
}

// Delete Functions
void Delete(string arr[], int &count, string target)
{
    int index = Search(arr, count, target);
    if (index != -1)
    {
        for (int i = index; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        count--;
        cout << "Item deleted successfully.\n";
    }
    else
    {
        cout << "Item not found.\n";
    }
}

void Delete2d(string arr[][2], int &count, string target)
{
    int index = Search2d(arr, count, target);
    if (index != -1)
    {
        for (int i = index; i < count - 1; i++)
        {
            arr[i][0] = arr[i + 1][0];
            arr[i][1] = arr[i + 1][1];
        }
        count--;
        cout << "Item deleted successfully.\n";
    }
    else
    {
        cout << "Item not found.\n";
    }
}

void DeleteProject()
{
    string name;
    cout << "Enter project name to delete: ";
    cin.ignore();
    getline(cin, name);

    Delete2d(project, projectCount, name);
}

void DeleteDonor()
{
    string name, amount;
    cout << "Enter donor name to delete: ";
    cin.ignore();
    getline(cin, name);

    Delete2d(donation, donationCount, name);
}

void DeleteVolunteer()
{
    string name;
    cout << "Enter volunteer name to delete: ";
    cin.ignore();
    getline(cin, name);

    Delete(volunteer, volunteerCount, name);
}

void DeleteBeneficiary()
{
    string name;
    cout << "Enter beneficiary name to delete: ";
    cin.ignore();
    getline(cin, name);

    Delete(beneficiary, beneficiaryCount, name);
}

void DeleteSuggestion()
{
    string suggestion;
    cout << "Enter suggestion to delete: ";
    cin.ignore();
    getline(cin, suggestion);

    Delete(suggestions, suggestionCount, suggestion);
}

// Edit Functions
void Edit(string arr[], int count, const string &oldValue, const string &newValue)
{
    int index = Search(arr, count, oldValue);
    if (index != -1)
    {
        arr[index] = newValue;
        cout << "Item updated successfully.\n";
    }
    else
    {
        cout << "Item not found.\n";
    }
}

void Edit2d(string arr[][2], int count, const string &oldValue, const string &newValue, const string &newValue2)
{
    int index = Search2d(arr, count, oldValue);
    if (index != -1)
    {
        arr[index][0] = newValue;
        arr[index][1] = newValue2;
        cout << "Item updated successfully.\n";
    }
    else
    {
        cout << "Item not found.\n";
    }
}

void EditProject()
{
    string oldName, newName, newDescription;
    cout << "Enter project name to edit: ";
    cin.ignore();
    getline(cin, oldName);
    cout << "Enter New Project Name: ";
    getline(cin, newName);
    cout << "Enter New Description: ";
    getline(cin, newDescription);

    Edit2d(project, projectCount, oldName, newName, newDescription);
    Save2d(project, projectCount, "projects.txt");
}
void EditVolunteer()
{
    string oldName, newName;
    cout << "Enter volunteer name to edit: ";
    cin.ignore();
    getline(cin, oldName);
    cout << "Enter new volunteer name: ";
    getline(cin, newName);

    Edit(volunteer, volunteerCount, oldName, newName);
    Save(volunteer, volunteerCount, "volunteers.txt");
}
void EditBeneficiary()
{
    string oldName, newName;
    cout << "Enter beneficiary name to edit: ";
    cin.ignore();
    getline(cin, oldName);
    cout << "Enter new beneficiary name: ";
    getline(cin, newName);

    Edit(beneficiary, beneficiaryCount, oldName, newName);
    Save(beneficiary, beneficiaryCount, "beneficiaries.txt");
}
void EditDonation()
{
    string oldDonor, newDonor;
    string newAmount;
    cout << "Enter donor name to edit: ";
    cin.ignore();
    getline(cin, oldDonor);
    cout << "Enter New Name: ";
    getline(cin, newDonor);
    cout << "Enter Amount: ";
    getline(cin, newAmount);

    Edit2d(donation, donationCount, oldDonor, newDonor, newAmount);
    Save2d(donation, donationCount, "donations.txt");
}
