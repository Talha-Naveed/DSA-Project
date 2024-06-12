#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "list.h"

void Intro();
void MainMenu();
void InventoryMenu();
void Backup();
void addInventory(List *list);
void sellInventory(List *list);
void changeProductRate(List *list);
void changeProductQuantity(List *list);
void SearchItem(List *list);
Product *objFinder(List *list, const char Name[10]);

int main()
{
    Intro();
    int choice;
    List *newList = new List();

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
                newList->Print();
                break;
            }
            case 2:
            {
                // Code to add inventory
                system("CLS");
                addInventory(newList);
                break;
            }
            case 3:
            {
                // Code to sell inventory
                system("CLS");
                sellInventory(newList);
                break;
            }
            case 4:
            {
                // Code to search specific item
                system("CLS");
                SearchItem(newList);
                break;
            }
            case 5:
            {
                // code to change product rate
                system("CLS");
                changeProductRate(newList);
                break;
            }
            case 6:
            {
                // Code to change product quantity
                system("CLS");
                changeProductQuantity(newList);
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

    delete newList;
    return 0;
}

void Backup(List *list)
{
    string products, rate, quantity;
    ofstream backup;

    Product *iterator = list->getHead();
    backup.open("BackUp.txt", ios::out);


    if (!backup)
    {
        cout << "Error in opening the file...";
    }

    do
    {
        backup << setw(15) << iterator->getName() << setw(15) << iterator->getRate() << setw(15) << iterator->getQuantity() << endl;
        iterator = iterator->getNext();

    } while (iterator->getNext() != nullptr);

    cout << "Backup created succesfully..." << endl;
    backup.close();
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

void addInventory(List *list)
{
    char Name[10];
    double Rate;
    int Quantity;

    cout << "Enter a value for Product Name : ";
    cin >> Name;
    cout << "Enter a value for Product Rate : ";
    cin >> Rate;
    cout << "Enter a value for Product Quantity : ";
    cin >> Quantity;

    list->Add(Name, Rate, Quantity);

    system("CLS");
    cout << "Product Added Successfuly!!\n";
}

Product *objFinder(List *list, const char Name[10])
{
    Product *product = list->getHead();
    while (!strcmp(product->getName(), Name))
    {
        product = product->getNext();
    }

    return product;
}
void sellInventory(List *list)
{
    char productName[10];
    int Quantity;
    cout << "Enter a value for Product Name : ";
    cin >> productName;
    cout << "Enter a value for quantity : ";
    cin >> Quantity;

    Product *theProduct = objFinder(list, productName);

    list->Delete(theProduct, Quantity);
}

void changeProductRate(List *list)
{
    char productName[10];
    double Rate;
    cout << "Enter a value for Product Name : ";
    cin >> productName;
    cout << "Enter a value for Rate : ";
    cin >> Rate;

    Product *theProduct = objFinder(list, productName);

    theProduct->setRate(Rate);
}

void changeProductQuantity(List *list)
{
    char productName[10];
    int Quantity;
    cout << "Enter a value for Product Name : ";
    cin >> productName;
    cout << "Enter a value for quantity : ";
    cin >> Quantity;

    Product *theProduct = objFinder(list, productName);

    theProduct->setQuantity(Quantity);
}

void SearchItem(List *list)
{
    char Name[10];

    cout << "Enter a value for Product Name : ";
    cin >> Name;

    Product *theProduct = objFinder(list, Name);
    cout << theProduct->getName() << setw(15) << theProduct->getRate() << setw(15) << theProduct->getQuantity() << endl;
}