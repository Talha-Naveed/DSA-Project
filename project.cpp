#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "list.h"

void Intro();
void MainMenu();
void InventoryMenu();
void Backup();
void viewInventory();
void addInventory();
void sellInventory();
void changeProductRate();
void changeProductQuantity();
void SearchItem();

int main()
{
    Intro();
    int choice;

    do
    {
        MainMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        system("CLS");

        switch (choice)
        {
        case 1:
            InventoryMenu();
            int inventoryChoice;
            cout << "Enter your choice: ";
            cin >> inventoryChoice;

            switch (inventoryChoice)
            {
            case 1:
            {
                // Code to view inventory
                system("CLS");
                viewInventory();
                break;
            }
            case 2:
            {
                // Code to add inventory
                system("CLS");
                addInventory();
                break;
            }
            case 3:
            {
                // Code to sell inventory
                system("CLS");
                sellInventory();
                break;
            }
            case 4:
            {
                // Code to search specific item
                system("CLS");
                SearchItem();
                break;
            }
            case 5:
            {
                // code to change product rate
                system("CLS");
                changeProductRate();
                break;
            }
            case 6:
            {
                // Code to change product quantity
                system("CLS");
                changeProductQuantity();
                break;
            }
            case 7:
            {
                // Code to make backup
                system("CLS");
                Backup();
                break;
            }
            case 8:
                // To go back to main menu
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
            break;
        case 2:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }
    } while (choice != 2);

    return 0;
}

void Backup()
{
    string products, rate, quantity;
    ifstream storage;
    ofstream backup;

    backup.open("BackUp.txt", ios::out);
    storage.open("Inventory.txt");

    if (!backup || !storage)
    {
        cout << "Error in opening the file...";
    }

    while (storage >> products >> rate >> quantity)
    {
        backup << setw(15) << products << setw(15) << rate << setw(15) << quantity << endl;
    }

    cout << "Backup created succesfully..." << endl;
    backup.close();
    storage.close();
}

void Intro()
{
    cout << "---------------------------------------------------\n";
    cout << "---------Data Structures & Algorithms--------------\n";
    cout << "---------Dr. Hamid---------------------------------\n";
    cout << "---------------------------------------------------\n";
    cout << "---------Group members-----------------------------\n";
    cout << "---------Talha-----------------22-NTU-CS-1326------\n";
    cout << "---------Muhammad Hamza--------22-NTU-CS-1285------\n";
    cout << "---------Muhammad Taha Naeem---22-NTU-CS-1309------\n";
    cout << "---------------------------------------------------\n";
}

void MainMenu()
{
    cout << "\n--------------------------------------------------\n";
    cout << "---------Enter 1 to display Inventory Menu........\n";
    cout << "---------Enter 2 to exit..........................\n";
    cout << "--------------------------------------------------\n";
}

void InventoryMenu()
{
    cout << "\n------------------------------------------------\n";
    cout << "---------Enter 1 to view Inventory................\n";
    cout << "---------Enter 2 to add  Inventory................\n";
    cout << "---------Enter 3 to sell Invenory.................\n";
    cout << "---------Enter 4 to search item...................\n";
    cout << "---------Enter 5 to change rate...................\n";
    cout << "---------Enter 6 to change Quantity...............\n";
    cout << "---------Enter 7 to make back up..................\n";
    cout << "---------Enter 8 to go back.......................\n";
    cout << "--------------------------------------------------\n";
}

void viewInventory()
{
    ifstream inventory;
    string product, rate, quantity;
    inventory.open("Inventory.txt", ios::in);
    if (!inventory)
    {
        cout << "Inventory file not found!\n";
        return;
    }

    while (!inventory.eof())
    {
        inventory >> product >> rate >> quantity;
        cout << setw(15) << product << setw(15) << rate << setw(15) << quantity << endl;
    }

    inventory.close();
}

void addInventory()
{
    ofstream inventory;
    char productName[10];
    double productRate;
    int productQuantity;

    inventory.open("Inventory.txt", ios::app);
    if (!inventory)
    {
        cout << "Error opening inventory file!\n";
        return;
    }

    Product product;
    cout << "Enter product details:\n";
    cout << "Product: ";
    cin >> productName;
    product.setName(productName);

    cout << "Rate: ";
    cin >> productRate;
    product.setRate(productRate);

    cout << "Quantity: ";
    cin >> productQuantity;
    product.setQuantity(productQuantity);

    inventory << endl
              << setw(15) << product.getName() << setw(15) << product.getRate() << setw(15) << product.getQuantity();
    inventory.close();
    cout << "Inventory added successfully!\n";
}

void sellInventory()
{
    string product;
    int quantity;
    ifstream inventory;
    ofstream temp;
    inventory.open("Inventory.txt", ios::in);
    temp.open("Temp.txt", ios::out);
    if (!inventory || !temp)
    {
        cout << "Error opening inventory files!\n";
        return;
    }

    cout << "Enter the product you want to sell: ";
    cin >> product;
    cout << "Enter the quantity to sell: ";
    cin >> quantity;

    string p, r, q;
    bool found = false;
    while (!inventory.eof())
    {
        inventory >> p >> r >> q;
        if (p == product)
        {
            found = true;
            int oldQuantity = stoi(q);
            if (quantity > oldQuantity)
            {
                cout << "Not enough quantity available!\n";
                temp << setw(15) << p << setw(15) << r << setw(15) << q;
            }
            else
            {
                int newQuantity = oldQuantity - quantity;
                temp << setw(15) << p << setw(15) << r << setw(15) << newQuantity;
                cout << "Inventory sold successfully!\n";
            }
        }
        else
        {
            temp << setw(15) << p << setw(15) << r << setw(15) << q << endl;
        }
    }

    inventory.close();
    temp.close();

    if (!found)
    {
        cout << "Product not found in inventory!\n";
    }
    else
    {
        remove("Inventory.txt");
        rename("Temp.txt", "Inventory.txt");
    }
}

void changeProductRate()
{
    ifstream inventory;
    ofstream temp;
    inventory.open("Inventory.txt", ios::in);
    temp.open("Temp.txt", ios::out);
    if (!inventory || !temp)
    {
        cout << "Error opening inventory files!\n";
        return;
    }

    string product;
    double newRate;
    cout << "Enter the product for which you want to change the rate: ";
    cin >> product;
    cout << "Enter the new rate: ";
    cin >> newRate;

    string p, r, q;
    bool found = false;
    while (!inventory.eof())
    {
        inventory >> p >> r >> q;
        if (p == product)
        {
            found = true;
            temp << setw(15) << p << setw(15) << newRate << setw(15) << q;
            cout << "Rate changed successfully!\n";
        }
        else
        {
            temp << setw(15) << p << setw(15) << r << setw(15) << q;
        }
    }

    inventory.close();
    temp.close();

    if (!found)
    {
        cout << "Product not found in inventory!\n";
    }
    else
    {
        remove("Inventory.txt");
        rename("Temp.txt", "Inventory.txt");
    }
}

void changeProductQuantity()
{
    ifstream inventory;
    ofstream temp;
    inventory.open("Inventory.txt", ios::in);
    temp.open("Temp.txt", ios::out);
    if (!inventory || !temp)
    {
        cout << "Error opening inventory files!\n";
        return;
    }

    string product;
    int newQuantity;
    cout << "Enter the product for which you want to change the rate: ";
    cin >> product;
    cout << "Enter the new Quantity: ";
    cin >> newQuantity;

    string p, r, q;
    bool found = false;
    while (!inventory.eof())
    {
        inventory >> p >> r >> q;
        if (p == product)
        {
            found = true;
            temp << setw(15) << p << setw(15) << r << setw(15) << newQuantity;
            cout << "Rate changed successfully!\n";
        }
        else
        {
            temp << setw(15) << p << setw(15) << r << setw(15) << q;
        }
    }

    inventory.close();
    temp.close();

    if (!found)
    {
        cout << "Product not found in inventory!\n";
    }
    else
    {
        remove("Inventory.txt");
        rename("Temp.txt", "Inventory.txt");
    }
}

void SearchItem()
{
    ifstream inventory;
    inventory.open("Inventory.txt", ios::in);
    if (!inventory)
    {
        cout << "Error opening inventory files!\n";
        return;
    }

    string product;
    cout << "Enter the product whose rate you wanted to know  : ";
    cin >> product;

    string p, r, q;
    bool found = false;
    while (!inventory.eof())
    {
        inventory >> p >> r >> q;
        if (p == product)
        {
            cout << setw(15) << p << setw(15) << r << setw(15) << q << endl;
        }
    }

    inventory.close();
}