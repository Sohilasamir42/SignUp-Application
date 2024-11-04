
#include <iostream>
#include <string>
#include <array>


//record maximum limited
constexpr int MAX_USERS = 100;


//print message
void print(const std::string& message)
{
    std::cout << message;
}

//User Options
enum class Option 
{
    Add_Record=1 ,
    Fetch_Record=2 ,
    Quite=3
};


//operator overload
std::istream& operator>> (std::istream & input_stream, Option& result)
{
    int int_option;
    input_stream >> int_option;
    result = static_cast<Option>(int_option);
    return input_stream;
}
//user select
Option user_select()
{
    Option selected_option = Option::Quite;
    std::cin >> selected_option;
    return selected_option;
}


//User Selections
class Selections
{
    public:
    void show()
    {
        print("\nplease select an option:\n");
        print("1: Add Record \n");
        print("2: Fetch Record \n");
        print("3: Quite \n");
        print("\n Enter Option: ");
    }
};

//Record class to store user data
class Record
{
public:
    std::string User_name;
    int User_age;

    //saving user details
    void UserDetails(const std::string& name, const int age)
    {
        User_name = name;
        User_age = age;
    }
};


//container for user records
std::array<Record, MAX_USERS> records;
int user_record_count = 0 ;


//Add record function
void AddRecord()
{
    std::string name;
    int age;
    if (user_record_count < MAX_USERS)
    {

        print("Add User. Please enter user name and age:\n");
        print("Name: ");

        std::cin.ignore(); 
        std::getline(std::cin, name);

        print("Age: ");
        std::cin >> age;

        records[user_record_count].UserDetails(name, age);
        user_record_count++;
        print("\nUser record added successfully.\n");
    }
    else
    {
        print("Maximum limit reached\n");
    }
}


// Fetch record by ID
void FetchRecord()
{
    int User_ID;
    print("Please enter user ID: ");
    std::cin >> User_ID;

    if (User_ID >= 0 && User_ID < user_record_count)
    {
        print("User Name: " + records[User_ID].User_name + "\n");
        print("User Age: " + std::to_string(records[User_ID].User_age) + "\n");
    }
    else
    {
        print("Invalid ID. No user found.\n");
    }
}


int main ()
{
    Option option =  Option::Quite;
    Selections new_select;
    bool isRunning = true;

    print("User SignUp Application \n ");

    while (isRunning)
    {
        new_select.show();
        option=user_select();

        switch(option)
        {
            case Option::Add_Record:
            {
                AddRecord();
                break;
            }
            
            case Option::Fetch_Record:
            {
                FetchRecord();
                break;
            }

            case Option::Quite:
            {
                print("Exiting the application.\n");
                isRunning = false;
                break;
            }

            default:
                print("Invalid option, Please try again\n");
                break;
        }
         
    }
    

    return 0;
}