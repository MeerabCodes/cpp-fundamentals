#include <iostream>
#include <fstream> // needed for file handling
#include <conio.h>
using namespace std;

const int Totalcars = 100;
int currentcar = 0;

// arrays required
string carNamesArr[Totalcars];
string carModelArr[Totalcars];
string carColourArr[Totalcars];
string carConditionArr[Totalcars];
string carTypeArr[Totalcars];
int carMillingArr[Totalcars];
string carPaintcondArr[Totalcars];
string carRegistryyrArr[Totalcars];
int carPriceArr[Totalcars];
int stockArr[Totalcars];
string carStatusArr[Totalcars];
string buyernameArr[Totalcars];
string customerName;

// file handling functions

// This function saves ALL car data into a text file
void saveToFile()
{
    ofstream file("cars.txt"); // opens (or creates) cars.txt for writing

    if (!file)
    {
        cout << "Error: Could not save data to file!" << endl;
        return;
    }

    file << currentcar << "\n"; // first line = how many cars we have

    for (int i = 0; i < currentcar; i++)
    {
        // Each car's data is written line by line

        file << carNamesArr[i] << "\n";
        file << carModelArr[i] << "\n";
        file << carColourArr[i] << "\n";
        file << carConditionArr[i] << "\n";
        file << carTypeArr[i] << "\n";
        file << carMillingArr[i] << "\n";
        file << carPaintcondArr[i] << "\n";
        file << carRegistryyrArr[i] << "\n";
        file << carPriceArr[i] << "\n";
        file << stockArr[i] << "\n";
        file << carStatusArr[i] << "\n";
        file << buyernameArr[i] << "\n";
    }

    file.close(); // always close the file after writing
    cout << "Data saved successfully!" << endl;
}

// This function loads ALL car data from the text file to the program's arrays
void loadFromFile()
{
    ifstream file("cars.txt"); // opens cars.txt for reading

    if (!file)
    {
        // File doesn't exist yet
        cout << "No saved data found. Starting fresh!" << endl;
        return;
    }

    file >> currentcar; // read how many cars are saved
    file.ignore();      // skip the newline after the number

    for (int i = 0; i < currentcar; i++)
    {
        getline(file, carNamesArr[i]); // to get full line including spaces
        getline(file, carModelArr[i]);
        getline(file, carColourArr[i]);
        getline(file, carConditionArr[i]);
        getline(file, carTypeArr[i]);
        file >> carMillingArr[i];
        file.ignore(); // to skip the newline after reading an int
        getline(file, carPaintcondArr[i]);
        getline(file, carRegistryyrArr[i]);
        file >> carPriceArr[i];
        file >> stockArr[i];
        file.ignore();
        getline(file, carStatusArr[i]);
        getline(file, buyernameArr[i]);
    }

    file.close();
    cout << "Data loaded successfully! (" << currentcar << " cars found)" << endl;
}

// all the functions for admin and customer operations

void displayHeader()
{
    system("cls");
    cout << "||*************************************************************************************||" << endl;
    cout << "                         - - -..................._     " << endl;
    cout << "                      _ _.. '_'.]]- .'-._              " << endl
         << endl;
    cout << "    _ _ _ _ _.-'       (_) |      ]]                 ' ]]'-. _  " << endl
         << endl;
    cout << "   /_          ------------'--------]]---...._ _ _ _ __ ]]_'.'  -..---" << endl;
    cout << "   | T         _.----._          Xxx|x...                |         _.._'--._    " << endl;
    cout << "   | |       .' ..--.. '.        XXX|XXXXXXXXXXXXXXxx==  |     .'.---..'.     -._  " << endl;
    cout << "   ]_j      /  /  _ _ )  )       XXX|XXXXXXXXXXXXXXxx==  |    /  / _ _ ) )        '-." << endl;
    cout << "    _|      |  | /   )|  |  |    XXX|'                 |    | |   / )  ||          |  " << endl;
    cout << "   |_ _)____|  |  (__/|  |_ _ _ _ _ |_ _ _ _ _ _ _ _ _ _ |_ _ | | (--/  | |_ _ _ _ _ _j " << endl;
    cout << "            '')(      / ./_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ( (      /  /_ _ _ _ _ _)   " << endl;
    cout << "               '.'_ _'.'   dp                                    '.'_'.'           " << endl;
    cout << "                ''                                                ''         " << endl;
    cout << "\n\n\n";
    cout << "                             CARS SHOWROOM MANAGEMENT SYSTEM                             " << endl;
    cout << "||***************************************************************************************||" << endl;
    cout << "\n";
}

int roleMenu()
{
    cout << "------------------Choose your role-----------------------" << endl;
    int role;
    cout << "1.ADMIN" << endl;
    cout << "2.CUSTOMER" << endl;
    cout << "3.Exit" << endl;
    cin >> role;
    cout << " u chose " << role << " role" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "\n";
    return role;
}

void adminMenu()
{
    cout << "||===============  ADMIN MENU  ======================" << endl;
    cout << "1.Add Car" << endl;
    cout << "2.View All Cars" << endl;
    cout << "3.Search Car" << endl;
    cout << "4.Update Car status" << endl;
    cout << "5.Delete Car" << endl;
    cout << "6.Sort Cars By Price" << endl;
    cout << "7.Sort Cars By Name" << endl;
    cout << "8.View low stock cars" << endl;
    cout << "9.View sales history" << endl;
    cout << "10.Total revenue" << endl;
    cout << "11.Logout" << endl;
    cout << "\n";
}

void customerMenu()
{
    cout << "||===============  CUSTOMER MENU  ================||" << endl;
    cout << "1.View Cars" << endl;
    cout << "2.Search Car" << endl;
    cout << "3.Sort Cars By Price" << endl;
    cout << "4.Sort Cars By Name" << endl;
    cout << "5.Buy Car" << endl;
    cout << "6.View My Purchases" << endl;
    cout << "7.Filter By Company" << endl;
    cout << "8.Check Car Availability" << endl;
    cout << "9.Generate Bill" << endl;
    cout << "10.Logout" << endl;
}

void addCar()
{
    cout << "--Add Car--!" << endl;
    cout << "Enter the NAME of car: " << endl;
    string name;
    cin.ignore(); // to clear the newline left by previous input
    getline(cin, name);

    cout << "Enter car model: " << endl;
    string model;
    getline(cin, model);
    cout << "Enter colour of the car: " << endl;
    string color;
    cin >> color;
    cout << "Enter Condition of the car: " << endl;
    string condition;
    cin.ignore();
    getline(cin, condition);
    cout << "Enter the type ( imported/exported) of the car: " << endl;
    string type;
    cin >> type;
    cout << "enter how many meters has car travelled: ";
    int miles;
    cin >> miles;
    cout << "Enter car paint condition(original/one paint/2nd paint etc): ";
    string paintcond;
    cin >> paintcond;
    cout << "Enter the time of registry of the car: ";
    string registrytime;
    cin.ignore();
    getline(cin, registrytime);
    cout << "Enter the price of car: ";
    int price;
    cin >> price;
    cout << " Enter the stock of car: ";
    int stock;
    cin >> stock;
    cout << "Enter car status" << endl;
    string status;
    cin.ignore();
    getline(cin, status);

    carNamesArr[currentcar] = name;
    carModelArr[currentcar] = model;
    carColourArr[currentcar] = color;
    carConditionArr[currentcar] = condition;
    carTypeArr[currentcar] = type;
    carMillingArr[currentcar] = miles;
    carPaintcondArr[currentcar] = paintcond;
    carRegistryyrArr[currentcar] = registrytime;
    carPriceArr[currentcar] = price;
    stockArr[currentcar] = stock;
    carStatusArr[currentcar] = status;
    buyernameArr[currentcar] = ""; // no buyer yet when adding a new car
    currentcar = currentcar + 1;

    saveToFile(); // save after adding a car
    cout << "Car added successfully!" << endl;
}

void viewCars()
{
    cout << "== View Cars ==\n";
    if (currentcar == 0)
    {
        cout << "No cars available!" << endl;
    }
    else
    {
        for (int i = 0; i < currentcar; i++)
        {
            cout << "Car #" << i + 1 << endl;
            cout << "Name: " << carNamesArr[i] << endl;
            cout << "Model: " << carModelArr[i] << endl;
            cout << "Color: " << carColourArr[i] << endl;
            cout << "Condition: " << carConditionArr[i] << endl;
            cout << "Type: " << carTypeArr[i] << endl;
            cout << "Mileage: " << carMillingArr[i] << endl;
            cout << "Paint: " << carPaintcondArr[i] << endl;
            cout << "Registry: " << carRegistryyrArr[i] << endl;
            cout << "Price: " << carPriceArr[i] << endl;
            cout << "Stock: " << stockArr[i] << endl;
            cout << "Status: " << carStatusArr[i] << endl;
            cout << "----------------------" << endl;
        }
    }
}

void updateCars()
{
    string searchtoname;
    cout << "enter car name to update: " << endl;
    cin.ignore();
    getline(cin, searchtoname);
    for (int i = 0; i < currentcar; i++)
    {
        if (carNamesArr[i] == searchtoname)
        {
            cout << "What do you want to update?\n";
            int updateoption;
            cout << "1.Name of car" << endl;
            cout << "2.color of car" << endl;
            cout << "3.Model of car" << endl;
            cout << "4.Condition" << endl;
            cout << "5.Type" << endl;
            cout << "6.miles covered" << endl;
            cout << "7.Paintcond" << endl;
            cout << "8.RegistryTime" << endl;
            cout << "9.Price" << endl;
            cout << "10.stock" << endl;
            cout << "Enter the number u want to update" << endl;
            cin >> updateoption;

            if (updateoption == 1)
            {
                cout << "enter new name" << endl;
                cin.ignore();
                getline(cin, carNamesArr[i]);
            }
            else if (updateoption == 2)
            {
                cout << "enter color of car" << endl;
                cin.ignore();
                getline(cin, carColourArr[i]);
            }
            else if (updateoption == 3)
            {
                cout << "Enter updated model of car" << endl;
                cin.ignore();
                getline(cin, carModelArr[i]);
            }
            else if (updateoption == 4)
            {
                cout << "Updated condition of the car" << endl;
                cin.ignore();
                getline(cin, carConditionArr[i]);
            }
            else if (updateoption == 5)
            {
                cout << "Updated Type of car" << endl;
                cin.ignore();
                getline(cin, carTypeArr[i]);
            }
            else if (updateoption == 6)
            {
                cout << "Updated miles covered" << endl;
                cin >> carMillingArr[i];
            }
            else if (updateoption == 7)
            {
                cout << "Updated paint condition" << endl;
                cin.ignore();
                getline(cin, carPaintcondArr[i]);
            }
            else if (updateoption == 8)
            {
                cout << "Updated registry time" << endl;
                cin.ignore();
                getline(cin, carRegistryyrArr[i]);
            }
            else if (updateoption == 9)
            {
                cout << "Updated price of car" << endl;
                cin >> carPriceArr[i];
            }
            else if (updateoption == 10)
            {
                cout << "Updated stock of car" << endl;
                cin >> stockArr[i];
            }
            else
            {
                cout << "invalid update option!" << endl;
            }

            saveToFile(); // save after updating
        }
    }
}

void deleteCar()
{
    string deletecar;
    cout << "Enter the name of the car u want to delete: " << endl;
    cin.ignore();
    getline(cin, deletecar);
    for (int i = 0; i < currentcar; i++)
    {
        if (carNamesArr[i] == deletecar)
        {
            for (int j = i; j < currentcar - 1; j++)
            {
                carNamesArr[j] = carNamesArr[j + 1];
                carModelArr[j] = carModelArr[j + 1];
                carColourArr[j] = carColourArr[j + 1];
                carConditionArr[j] = carConditionArr[j + 1];
                carTypeArr[j] = carTypeArr[j + 1];
                carMillingArr[j] = carMillingArr[j + 1];
                carPaintcondArr[j] = carPaintcondArr[j + 1];
                carRegistryyrArr[j] = carRegistryyrArr[j + 1];
                carPriceArr[j] = carPriceArr[j + 1];
                stockArr[j] = stockArr[j + 1];
                carStatusArr[j] = carStatusArr[j + 1];
                buyernameArr[j] = buyernameArr[j + 1];
            }
            currentcar--;
            saveToFile(); // save after deleting
            cout << "Car deleted successfully!" << endl;
            break;
        }
    }
}

void swapCars(int a, int b)
{
    swap(carNamesArr[a], carNamesArr[b]);
    swap(carModelArr[a], carModelArr[b]);
    swap(carColourArr[a], carColourArr[b]);
    swap(carConditionArr[a], carConditionArr[b]);
    swap(carTypeArr[a], carTypeArr[b]);
    swap(carMillingArr[a], carMillingArr[b]);
    swap(carPaintcondArr[a], carPaintcondArr[b]);
    swap(carRegistryyrArr[a], carRegistryyrArr[b]);
    swap(carPriceArr[a], carPriceArr[b]);
    swap(stockArr[a], stockArr[b]);
    swap(carStatusArr[a], carStatusArr[b]);
    swap(buyernameArr[a], buyernameArr[b]);
}

void sortCarsbyPrice()
{
    for (int i = 0; i < currentcar - 1; i++)
        for (int j = 0; j < currentcar - i - 1; j++)
            if (carPriceArr[j] > carPriceArr[j + 1])
                swapCars(j, j + 1);

    saveToFile(); // save the sorted order
    cout << "Cars sorted by price successfully!" << endl;
}

void sortcarsbyNames()
{
    for (int i = 0; i < currentcar - 1; i++)
        for (int j = 0; j < currentcar - i - 1; j++)
            if (carNamesArr[j] > carNamesArr[j + 1]) // actually sorts by name
                swapCars(j, j + 1);

    saveToFile(); // save the sorted order
    cout << "Cars sorted by name successfully!" << endl;
}

void viewlowStockcars()
{
    cout << "== Low Stock Cars ==\n";
    for (int i = 0; i < currentcar; i++)
    {
        if (stockArr[i] < 5)
        {
            cout << "Name: " << carNamesArr[i] << " | Stock: " << stockArr[i] << " | Price: " << carPriceArr[i] << endl;
            cout << "----------------------" << endl;
        }
    }
}

void viewSalesHistory()
{
    cout << "== Sales History ==\n";
    for (int i = 0; i < currentcar; i++)
    {
        if (carStatusArr[i] == "sold")
        {
            cout << "Name: " << carNamesArr[i] << " | Buyer: " << buyernameArr[i] << " | Price: " << carPriceArr[i] << endl;
            cout << "----------------------" << endl;
        }
    }
}

void totalRevenue()
{
    cout << "== Total Revenue ==\n";
    int revenue = 0;
    for (int i = 0; i < currentcar; i++)
        if (carStatusArr[i] == "sold")
            revenue += carPriceArr[i];
    cout << "Total Revenue: " << revenue << endl;
}

void buyCar()
{
    string buyCarName;
    cout << "Enter the name of the car u want to buy: " << endl;
    cin.ignore();
    getline(cin, buyCarName);
    bool found = false;
    for (int i = 0; i < currentcar; i++)
    {
        if (carNamesArr[i] == buyCarName)
        {
            found = true;
            if (stockArr[i] > 0)
            {
                stockArr[i]--;
                buyernameArr[i] = customerName;
                carStatusArr[i] = (stockArr[i] == 0) ? "sold" : "available";
                saveToFile(); // save after purchase
                cout << "Purchase successful! Thank you for buying " << carNamesArr[i] << "." << endl;
            }
            else
            {
                cout << "Sorry, this car is out of stock!" << endl;
            }
            break;
        }
    }
    if (!found)
        cout << "Car not found!" << endl;
}

void viewMyPurchases()
{
    cout << "== My Purchases ==\n";
    bool hasPurchases = false;
    for (int i = 0; i < currentcar; i++)
    {
        if (buyernameArr[i] == customerName)
        {
            hasPurchases = true;
            cout << "Name: " << carNamesArr[i] << " | Model: " << carModelArr[i] << " | Price: " << carPriceArr[i] << endl;
            cout << "----------------------" << endl;
        }
    }
    if (!hasPurchases)
        cout << "You have not purchased any cars yet!" << endl;
}

void checkAvailability()
{
    string checkCarName;
    cout << "Enter the name of the car to check availability: " << endl;
    cin.ignore();
    getline(cin, checkCarName);
    bool found = false;
    for (int i = 0; i < currentcar; i++)
    {
        if (carNamesArr[i] == checkCarName)
        {
            found = true;
            if (stockArr[i] > 0)
                cout << "Car is available! Stock: " << stockArr[i] << endl;
            else
                cout << "Sorry, this car is out of stock!" << endl;
            break;
        }
    }
    if (!found)
        cout << "Car not found!" << endl;
}

void generateBill()
{
    string billCarName;
    cout << "Enter the name of the car to generate bill: " << endl;
    cin.ignore();
    getline(cin, billCarName);
    bool found = false;
    for (int i = 0; i < currentcar; i++)
    {
        if (carNamesArr[i] == billCarName)
        {
            found = true;
            if (buyernameArr[i] == customerName)
            {
                cout << "=== Bill ===" << endl;
                cout << "Car Name: " << carNamesArr[i] << endl;
                cout << "Model: " << carModelArr[i] << endl;
                cout << "Price: " << carPriceArr[i] << endl;
                cout << "Buyer: " << customerName << endl;
                cout << "Thank you for your purchase!" << endl;
            }
            else
            {
                cout << "This car has not been purchased by you. No bill can be generated." << endl;
            }
            break;
        }
    }
    if (!found)
        cout << "Car not found!" << endl;
}

void affordableCars()
{
    cout << "== Affordable Cars (Under 2,500,000) ==\n";
    bool hasAffordableCars = false;
    for (int i = 0; i < currentcar; i++)
    {
        if (carPriceArr[i] < 2500000)
        {
            hasAffordableCars = true;
            cout << "Name: " << carNamesArr[i] << " | Price: " << carPriceArr[i] << " | Stock: " << stockArr[i] << endl;
            cout << "----------------------" << endl;
        }
    }
    if (!hasAffordableCars)
        cout << "No affordable cars available at the moment!" << endl;
}

void displaySingleCar(int i)
{
    cout << "Name: " << carNamesArr[i] << endl;
    cout << "Model: " << carModelArr[i] << endl;
    cout << "Color: " << carColourArr[i] << endl;
    cout << "Condition: " << carConditionArr[i] << endl;
    cout << "Price: " << carPriceArr[i] << endl;
    cout << "Stock: " << stockArr[i] << endl;
    cout << "----------------------" << endl;
}

// mainnnn
int main()
{
    loadFromFile(); // load saved data when program starts

    int role;

    while (true)
    {
        displayHeader();
        role = roleMenu();

        if (role == 1)
        {
            int adminOption;
            do
            {
                system("cls");
                adminMenu();
                cout << "Enter your option: ";
                cin >> adminOption;

                if (adminOption == 1)
                    addCar();
                else if (adminOption == 2)
                    viewCars();
                else if (adminOption == 3)
                {
                    string searchName;
                    bool found = false;
                    cout << "Enter car name to search: ";
                    cin.ignore();
                    getline(cin, searchName);
                    for (int i = 0; i < currentcar; i++)
                        if (carNamesArr[i] == searchName)
                        {
                            displaySingleCar(i);
                            found = true;
                            break;
                        }
                    if (!found)
                        cout << "Car not found!" << endl;
                }
                else if (adminOption == 4)
                    updateCars();
                else if (adminOption == 5)
                    deleteCar();
                else if (adminOption == 6)
                    sortCarsbyPrice();
                else if (adminOption == 7)
                    sortcarsbyNames();
                else if (adminOption == 8)
                    viewlowStockcars();
                else if (adminOption == 9)
                    viewSalesHistory();
                else if (adminOption == 10)
                    totalRevenue();
                else if (adminOption == 11)
                    cout << "Logging out..." << endl;
                else
                    cout << "Invalid option!" << endl;

                getch();
            } while (adminOption != 11);
        }
        else if (role == 2)
        {
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, customerName);

            int customerOption;
            do
            {
                customerMenu();
                cout << "Enter your option: ";
                cin >> customerOption;

                if (customerOption == 1)
                    viewCars();
                else if (customerOption == 2)
                {
                    string searchName;
                    bool found = false;
                    cout << "Enter car name to search: ";
                    cin.ignore();
                    getline(cin, searchName);
                    for (int i = 0; i < currentcar; i++)
                        if (carNamesArr[i] == searchName)
                        {
                            displaySingleCar(i);
                            found = true;
                            break;
                        }
                    if (!found)
                        cout << "Car not found!" << endl;
                }
                else if (customerOption == 3)
                    sortCarsbyPrice();
                else if (customerOption == 4)
                    sortcarsbyNames();
                else if (customerOption == 5)
                    buyCar();
                else if (customerOption == 6)
                    viewMyPurchases();
                else if (customerOption == 7)
                    affordableCars();
                else if (customerOption == 8)
                    checkAvailability();
                else if (customerOption == 9)
                    generateBill();
                else if (customerOption == 10)
                    cout << "Logging out." << endl;
                else
                    cout << "Invalid option!" << endl;

                getch();
            } while (customerOption != 10);
        }
        else if (role == 3)
        {
            cout << "Exiting program." << endl;
            break;
        }
        else
        {
            cout << "Invalid role selected!" << endl;
        }
    }

    return 0;
}