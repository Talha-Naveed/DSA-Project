#include "Product.h"
#include <iostream>
#include <iomanip>

using namespace std;

class List
{

private:
    Product *head;

public:
    List()
    {
        head = nullptr;
    }

    void setHead(Product *ptr) { head = ptr; }
    Product *getHead() { return head; }

    // Function to add products in the list
    void Add(const char Name[10], double Rate, int Quantity)
    {
        Product *newProduct = new Product(Name, Rate, Quantity);

        // Case 1. If list is empty
        if (head == nullptr)
        {
            head = newProduct;
        }
        // Case 2. Elements in the list
        else
        {
            // Inserting at head for O(1)
            newProduct->setNext(head);
            head = newProduct;
        }
    }

    // Function to view all elements in a list
    void Print()
    {
        // Case 1. List is empty
        if (head == nullptr)
        {
            std::cout << "\nList is empty.\n";
        }
        // Case 2. List is NON-EMPTY
        else
        {
            Product *iterator = head;
            cout << "       Products           Rate       Quantity\n--------           ----       --------\n";

            do
            {
                cout << setw(15) << iterator->getName() << setw(15) << iterator->getRate() << setw(15) << iterator->getQuantity() << endl;
            } while (iterator->getNext() != nullptr);
        }
    }

    // Function to delete an item from the list
    void Delete(Product *product, int Quantity)
    {
        // Case 1. List is empty
        if (head == nullptr)
        {
            cout << "List is empty. Cannot Delete\n";
        }
        // Case 2. List is non-empty
        else
        {
            product->setQuantity(product->getQuantity() - Quantity);
            if (product->getQuantity() <= 0)
            {
                // Case 2-A Element is head element
                if (strcmp(product->getName(), head->getName()))
                {
                    Product *temp = head;
                    head = head->getNext();
                    temp->setNext(nullptr); // To avoid dangling pointer
                    delete temp;
                }
                else
                {
                    // Case 2-B. Element is non head element
                    Product *iterator = head->getNext();
                    Product *previous = head;

                    do
                    {
                        if (strcmp(product->getName(), iterator->getName()))
                        {
                            previous->setNext(iterator->getNext());
                            delete iterator;
                            return;
                        }
                        previous = iterator;
                        iterator = iterator->getNext();

                    } while (iterator->getNext() != nullptr);
                }
            }
        }
    }

    ~List()
    {

        while (head != nullptr)
        {
            Product *iterator = head;
            head = head->getNext();

            delete iterator;
        }
    }
};