#include <cstring>

class Product
{
private:
    char name[10];
    double rate;
    int quantity;
    Product *next;

public:
    // Constructors for the class
    Product()
    {
        next = nullptr;
        rate = 0.0;
        quantity = 0;
    }

    Product(const char Name[10], double Rate, int Quantity)
    {
        next = nullptr;
        strcpy(name, Name);
        rate = Rate;
        quantity = Quantity;
    }

    // Getter and Setters for the class
    void setName(const char productName[10]) { strcpy(name, productName); }
    void setRate(double productRate) { rate = productRate; }
    void setQuantity(int productQuantity) { quantity = productQuantity; }
    void setNext(Product *ptr) { next = ptr; }

    char *getName() { return name; }
    double getRate() { return rate; }
    int getQuantity() { return quantity; }
    Product *getNext() { return next; }
};