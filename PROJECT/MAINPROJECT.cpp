#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int totalcars = 100;
    int currentcar = 0;
    // arrays required for admin code
    string carNamesArr[totalcars];
    string carModelArr[totalcars];
    string carColourArr[totalcars];
    string carConditionArr[totalcars];
    string carTypeArr[totalcars];
    int carMillingArr[totalcars];
    string carPaintcondArr[totalcars];
    string carRegistryyrArr[totalcars];
    int carPriceArr[totalcars];
    int stockArr[totalcars];
    string carStatusArr[totalcars];

    while (true)
    {
        // header
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
        cout << "\n";
        cout << "\n";
        cout << "\n";
        cout << "                             CARS SHOWROOM MANAGEMENT SYSTEM                             " << endl;
        cout << "||***************************************************************************************||" << endl;
        cout << "\n";
        // role selection
        cout << "------------------Choose your role-----------------------" << endl;
        int role;
        cout << "1.ADMIN" << endl;
        cout << "2.CUSTOMER" << endl;
        cout << "3.Exit" << endl;
        cin >> role;
        cout << " u chose " << role << " role" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "\n";
        if (role == 1)
        {
            // admin code
            system("cls");

            cout << "||===============  ADMIN MENU  ======================" << endl;
            int option;
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
            cout << "Enter the number of option u want to chose" << endl;
            cin >> option;
            string name;
            if (option == 1)
            {
                cout << "--Add Car--!" << endl;
                cout << "Enter the NAME of car: " << endl;
                cin.ignore();
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
                // storing in arrays
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
                currentcar = currentcar + 1;
                getch();
            }
            if (option == 2)
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
                getch();
            }
            if (option == 3)
            {
                // search car

                string searchName;
                bool found = false;

                cout << "Enter the name of the car u want to search: ";
                cin.ignore();
                getline(cin, searchName);

                for (int i = 0; i < currentcar; i++)
                {
                    if (searchName == carNamesArr[i])
                    {
                        found = true;

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
                    }
                }
                if (found == false)
                {
                    cout << "No car found!" << endl;
                }
                getch();
            }
            if (option == 4)
            {
                // field update system
                //  update car
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
                    }
                }
                getch();
            }
            if (option == 5)
            {
                // delete car
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
                        }
                        currentcar--; // to decrease the total number of cars after deletion
                        cout << "Car deleted successfully!" << endl;

                        break;
                    }
                }
                getch();
            }
            if (option == 6)
            {
                // sort car by price low to high
                for (int i = 0; i < currentcar - 1; i++)
                {
                    for (int j = 0; j < currentcar - i - 1; j++)
                    {
                        if (carPriceArr[j] > carPriceArr[j + 1])
                        {
                            string tempName = carNamesArr[j];
                            carNamesArr[j] = carNamesArr[j + 1];
                            carNamesArr[j + 1] = tempName;

                            // swapping model
                            string tempModel = carModelArr[j];
                            carModelArr[j] = carModelArr[j + 1];
                            carModelArr[j + 1] = tempModel;
                            // swapping colour

                            string tempColour = carColourArr[j];
                            carColourArr[j] = carColourArr[j + 1];
                            carColourArr[j + 1] = tempColour;
                            // swapping condition

                            string tempCondition = carConditionArr[j];
                            carConditionArr[j] = carConditionArr[j + 1];
                            carConditionArr[j + 1] = tempCondition;
                            // swapping type

                            string tempType = carTypeArr[j];
                            carTypeArr[j] = carTypeArr[j + 1];
                            carTypeArr[j + 1] = tempType;
                            // swapping miles

                            int tempMilling = carMillingArr[j];
                            carMillingArr[j] = carMillingArr[j + 1];
                            carMillingArr[j + 1] = tempMilling;
                            // swapping paint condition

                            string tempPaintcond = carPaintcondArr[j];
                            carPaintcondArr[j] = carPaintcondArr[j + 1];
                            carPaintcondArr[j + 1] = tempPaintcond;
                            // swapping registry time

                            string tempRegistryyr = carRegistryyrArr[j];
                            carRegistryyrArr[j] = carRegistryyrArr[j + 1];
                            carRegistryyrArr[j + 1] = tempRegistryyr;
                            // swapping price

                            double tempPrice = carPriceArr[j];
                            carPriceArr[j] = carPriceArr[j + 1];
                            carPriceArr[j + 1] = tempPrice;
                            // swapping stock

                            int tempStock = stockArr[j];
                            stockArr[j] = stockArr[j + 1];
                            stockArr[j + 1] = tempStock;
                            // swapping status

                            string tempStatus = carStatusArr[j];
                            carStatusArr[j] = carStatusArr[j + 1];
                            carStatusArr[j + 1] = tempStatus;
                        }
                    }
                }
                getch();
            }
            if (option == 7)
            {
                // sort car by name
                for (int i = 0; i < currentcar; i++)
                {
                    for (int j = 0; j < currentcar - i - 1; j++) // because last element already sorted after one loop
                    {
                        if (carNamesArr[j] > carNamesArr[j + 1])
                        {
                            string tempName = carNamesArr[j];
                            carNamesArr[j] = carNamesArr[j + 1];
                            carNamesArr[j + 1] = tempName;

                            // swapping model
                            string tempModel = carModelArr[j];
                            carModelArr[j] = carModelArr[j + 1];
                            carModelArr[j + 1] = tempModel;
                            // swapping colour

                            string tempColour = carColourArr[j];
                            carColourArr[j] = carColourArr[j + 1];
                            carColourArr[j + 1] = tempColour;
                            // swapping condition

                            string tempCondition = carConditionArr[j];
                            carConditionArr[j] = carConditionArr[j + 1];
                            carConditionArr[j + 1] = tempCondition;
                            // swapping type

                            string tempType = carTypeArr[j];
                            carTypeArr[j] = carTypeArr[j + 1];
                            carTypeArr[j + 1] = tempType;
                            // swapping miles

                            int tempMilling = carMillingArr[j];
                            carMillingArr[j] = carMillingArr[j + 1];
                            carMillingArr[j + 1] = tempMilling;
                            // swapping paint condition

                            string tempPaintcond = carPaintcondArr[j];
                            carPaintcondArr[j] = carPaintcondArr[j + 1];
                            carPaintcondArr[j + 1] = tempPaintcond;
                            // swapping registry time

                            string tempRegistryyr = carRegistryyrArr[j];
                            carRegistryyrArr[j] = carRegistryyrArr[j + 1];
                            carRegistryyrArr[j + 1] = tempRegistryyr;
                            // swapping price

                            double tempPrice = carPriceArr[j];
                            carPriceArr[j] = carPriceArr[j + 1];
                            carPriceArr[j + 1] = tempPrice;
                            // swapping stock

                            int tempStock = stockArr[j];
                            stockArr[j] = stockArr[j + 1];
                            stockArr[j + 1] = tempStock;
                            // swapping status

                            string tempStatus = carStatusArr[j];
                            carStatusArr[j] = carStatusArr[j + 1];
                            carStatusArr[j + 1] = tempStatus;
                        }
                    }
                }
                getch();
            }
            if (option == 8)
            {
                // low stock cars

                cout << "== Low Stock Cars ==\n";
                for (int i = 0; i < currentcar; i++)
                {
                    if (stockArr[i] < 5)
                    {
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

                getch();
            }
            if (option == 9)
            {
                // view sales history

                cout << "== Sales History ==\n";
                for (int i = 0; i < currentcar; i++)
                {
                    if (carStatusArr[i] == "sold")
                    {
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

                getch();
            }
            if (option == 10)
            {
                // total revenue

                cout << "== Total Revenue ==\n";
                int totalRevenue = 0;
                for (int i = 0; i < currentcar; i++)
                {
                    if (carStatusArr[i] == "sold")
                    {
                        totalRevenue += carPriceArr[i];
                    }
                }
                cout << "Total Revenue: " << totalRevenue << endl;

                getch();
            }
            if (option == 11)
            {
                // back
                continue;
            }

            cout << "your data has been saved" << endl;

            getch();
        }

        else if (role == 2)
        {
            // cutomer code
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

            int useroption;
            cout << "chose option: " << endl;
            cin >> useroption;

            if (useroption == 1)
            {
                system("cls");
                cout << "====  View cars  ===" << endl;

                if (currentcar == 0)
                {
                    cout << "No cars available!" << endl;
                }
                else
                {
                    // Header row
                    cout << "No.\tName\t\tModel\t\tColor\t\tCondition\tType\t\tPrice\t\tStock\t\tStatus" << endl;

                    for (int i = 0; i < currentcar; i++)
                    {
                        cout << i + 1 << "\t"
                             << carNamesArr[i] << "\t\t"
                             << carModelArr[i] << "\t\t"
                             << carColourArr[i] << "\t\t"
                             << carConditionArr[i] << "\t\t"
                             << carTypeArr[i] << "\t\t"
                             << carPriceArr[i] << "\t\t"
                             << stockArr[i] << "\t\t"
                             << carStatusArr[i] << endl;
                    }
                }
                getch();
            }
            else if (useroption == 2)
            {
                // search car
                system("cls");
                cout << "==== Search Car ===" << endl;
                string searchName;
                cout << "Enter the name of the car u want to search: ";
                cin.ignore();
                getline(cin, searchName);
                bool found = false;
                for (int i = 0; i < currentcar; i++)
                {
                    if (searchName == carNamesArr[i])
                    {
                        found = true;

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
                    }
                }
                if (!found)
                {
                    cout << "Car not found!" << endl;
                }
            }
            else if (useroption == 3)
            {
                // sort by price
                for (int i = 0; i < currentcar - 1; i++)
                {
                    for (int j = 0; j < currentcar - i - 1; j++)
                    {
                        if (carPriceArr[j] > carPriceArr[j + 1])
                        {
                            string tempName = carNamesArr[j];
                            carNamesArr[j] = carNamesArr[j + 1];
                            carNamesArr[j + 1] = tempName;

                            // swapping model
                            string tempModel = carModelArr[j];
                            carModelArr[j] = carModelArr[j + 1];
                            carModelArr[j + 1] = tempModel;
                            // swapping colour

                            string tempColour = carColourArr[j];
                            carColourArr[j] = carColourArr[j + 1];
                            carColourArr[j + 1] = tempColour;
                            // swapping condition

                            string tempCondition = carConditionArr[j];
                            carConditionArr[j] = carConditionArr[j + 1];
                            carConditionArr[j + 1] = tempCondition;
                            // swapping type

                            string tempType = carTypeArr[j];
                            carTypeArr[j] = carTypeArr[j + 1];
                            carTypeArr[j + 1] = tempType;
                            // swapping miles

                            int tempMilling = carMillingArr[j];
                            carMillingArr[j] = carMillingArr[j + 1];
                            carMillingArr[j + 1] = tempMilling;
                            // swapping paint condition

                            string tempPaintcond = carPaintcondArr[j];
                            carPaintcondArr[j] = carPaintcondArr[j + 1];
                            carPaintcondArr[j + 1] = tempPaintcond;
                            // swapping registry time

                            string tempRegistryyr = carRegistryyrArr[j];
                            carRegistryyrArr[j] = carRegistryyrArr[j + 1];
                            carRegistryyrArr[j + 1] = tempRegistryyr;
                            // swapping price

                            double tempPrice = carPriceArr[j];
                            carPriceArr[j] = carPriceArr[j + 1];
                            carPriceArr[j + 1] = tempPrice;
                            // swapping stock

                            int tempStock = stockArr[j];
                            stockArr[j] = stockArr[j + 1];
                            stockArr[j + 1] = tempStock;
                        }
                    }
                }
            }
            else if (useroption == 4)
            {
                // sort by name
                for (int i = 0; i < currentcar - 1; i++)
                {
                    for (int j = 0; j < currentcar - i - 1; j++) // because last element already sorted after one loop
                    {
                        if (carNamesArr[j] > carNamesArr[j + 1])
                        {
                            string tempName = carNamesArr[j];
                            carNamesArr[j] = carNamesArr[j + 1];
                            carNamesArr[j + 1] = tempName;

                            // swapping model
                            string tempModel = carModelArr[j];
                            carModelArr[j] = carModelArr[j + 1];
                            carModelArr[j + 1] = tempModel;
                            // swapping colour

                            string tempColour = carColourArr[j];
                            carColourArr[j] = carColourArr[j + 1];
                            carColourArr[j + 1] = tempColour;
                            // swapping condition

                            string tempCondition = carConditionArr[j];
                            carConditionArr[j] = carConditionArr[j + 1];
                            carConditionArr[j + 1] = tempCondition;
                            // swapping type

                            string tempType = carTypeArr[j];
                            carTypeArr[j] = carTypeArr[j + 1];
                            carTypeArr[j + 1] = tempType;
                            // swapping miles

                            int tempMilling = carMillingArr[j];
                            carMillingArr[j] = carMillingArr[j + 1];
                            carMillingArr[j + 1] = tempMilling;
                            // swapping paint condition

                            string tempPaintcond = carPaintcondArr[j];
                            carPaintcondArr[j] = carPaintcondArr[j + 1];
                            carPaintcondArr[j + 1] = tempPaintcond;
                            // swapping registry time

                            string tempRegistryyr = carRegistryyrArr[j];
                            carRegistryyrArr[j] = carRegistryyrArr[j + 1];
                            carRegistryyrArr[j + 1] = tempRegistryyr;
                            // swapping price

                            double tempPrice = carPriceArr[j];
                            carPriceArr[j] = carPriceArr[j + 1];
                            carPriceArr[j + 1] = tempPrice;
                            // swapping stock

                            int tempStock = stockArr[j];
                            stockArr[j] = stockArr[j + 1];
                            stockArr[j + 1] = tempStock;
                        }
                    }
                }
            }
            else if (useroption == 5)
            {
                // buy car
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
                            cout << "Car is available! Proceeding to purchase..." << endl;
                            stockArr[i]--;            // Decrease stock by 1
                            carStatusArr[i] = "sold"; // Update status to sold
                            cout << "Purchase successful! Thank you for buying " << carNamesArr[i] << "." << endl;
                        }
                        else
                        {
                            cout << "Sorry, this car is out of stock!" << endl;
                        }
                        break; // exit loop after finding the car
                    }
                }
                if (!found)
                {
                    cout << "Car not found!" << endl;
                }
            }
            else if (useroption == 6)
            {
                // view my purchases
                cout << "== My Purchases ==\n";
                bool hasPurchases = false;
                for (int i = 0; i < currentcar; i++)
                {
                    if (carStatusArr[i] == "sold")
                    {
                        hasPurchases = true;
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
                if (!hasPurchases)
                {
                    cout << "You have not purchased any cars yet!" << endl;
                }
            }
            else if (useroption == 7)
            {
                // view affordable cars
                cout << "== Affordable Cars (Under 2,500,000) ==\n";
                bool hasAffordableCars = false;
                for (int i = 0; i < currentcar; i++)
                {
                    if (carPriceArr[i] < 2500000)
                    {
                        hasAffordableCars = true;
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
                if (!hasAffordableCars)
                {
                    cout << "No affordable cars available at the moment!" << endl;
                }
            }
            else if (useroption == 8)
            {
                // check car availability
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
                        {
                            cout << "Car is available! Stock: " << stockArr[i] << endl;
                        }
                        else
                        {
                            cout << "Sorry, this car is out of stock!" << endl;
                        }
                        break; // exit loop after finding the car
                    }
                }
                if (!found)
                {
                    cout << "Car not found!" << endl;
                }
            }
            else if (useroption == 9)
            {
                // generate bill
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
                        if (carStatusArr[i] == "sold")
                        {
                            cout << "=== Bill ===" << endl;
                            cout << "Car Name: " << carNamesArr[i] << endl;
                            cout << "Model: " << carModelArr[i] << endl;
                            cout << "Price: " << carPriceArr[i] << endl;
                            cout << "Thank you for your purchase!" << endl;
                        }
                        else
                        {
                            cout << "This car has not been purchased yet. No bill can be generated." << endl;
                        }
                        break; // exit loop after finding the car
                    }
                }
                if (!found)
                {
                    cout << "Car not found!" << endl;
                }
            }
            else if (useroption == 10)
            {
                // logout
                continue; // go back to role selection menu
            }
        }
        else if (role == 3)
        {
            break;
        }
        else
        {
            cout << "you chosed an invalid option!" << endl;
        }
    }
}