#include <iostream>
#include <vector>
#include <string>

class Item {
public:
    std::string name;
    int price;
    int quantity;

    Item(const std::string& name, int price, int quantity)
        : name(name), price(price), quantity(quantity) {}

    void display() const {
        std::cout << "Item: " << name << "\n";
        std::cout << "Price: $" << price << "\n";
        std::cout << "Quantity: " << quantity << "\n";
    }
};

class StoreManagementSystem {
private:
    std::vector<Item*> inventory;
    int totalSales;

    bool login() {
        std::string username, password;
        std::cout << "=== Login ===\n";
        std::cout << "Enter username: ";
        std::cin >> username;
        std::cout << "Enter password: ";
        std::cin >> password;

        // Add your login validation logic here
        // For simplicity, let's assume the correct credentials are "admin" for both username and password

        if (username == "admin" && password == "admin") {
            std::cout << "Login successful!\n";
            return true;
        }
        else {
            std::cout << "Login failed!\n";
            return false;
        }
    }

    void addItem() {
        std::string name;
        int price, quantity;

        std::cout << "Enter the item name: ";
        std::cin >> name;

        std::cout << "Enter the price: $";
        std::cin >> price;

        std::cout << "Enter the quantity: ";
        std::cin >> quantity;

        Item* newItem = new Item(name, price, quantity);
        inventory.push_back(newItem);

        std::cout << "Item added to inventory.\n";
    }

    void removeItem() {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }

        std::string name;
        std::cout << "Enter the item name: ";
        std::cin >> name;

        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i]->name == name) {
                delete inventory[i];
                inventory.erase(inventory.begin() + i);
                std::cout << "Item removed from inventory.\n";
                return;
            }
        }

        std::cout << "Item not found in inventory.\n";
    }

    void displayInventory() const {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }

        std::cout << "Current Inventory:\n";
        std::cout << "------------------\n";
        for (size_t i = 0; i < inventory.size(); ++i) {
            inventory[i]->display();
            std::cout << "------------------\n";
        }
    }

    void processSale() {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }

        std::string name;
        std::cout << "Enter the item name: ";
        std::cin >> name;

        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i]->name == name) {
                int quantity;
                std::cout << "Enter the quantity: ";
                std::cin >> quantity;

                if (quantity <= inventory[i]->quantity) {
                    inventory[i]->quantity -= quantity;
                    totalSales += quantity * inventory[i]->price;
                    std::cout << "Sale processed. Total amount: $" << quantity * inventory[i]->price << "\n";
                    return;
                }
                else {
                    std::cout << "Insufficient quantity in inventory.\n";
                    return;
                }
            }
        }

        std::cout << "Item not found in inventory.\n";
    }

    void displaySales() const {
        std::cout << "Total Sales: $" << totalSales << "\n";
    }

    void searchItem() const {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }

        std::string name;
        std::cout << "Enter the item name: ";
        std::cin >> name;

        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i]->name == name) {
                inventory[i]->display();
                return;
            }
        }

        std::cout << "Item not found in inventory.\n";
    }

    void updateItem() {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }

        std::string name;
        std::cout << "Enter the item name: ";
        std::cin >> name;

        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i]->name == name) {
                int choice;
                std::cout << "Select an option:\n";
                std::cout << "1. Update price\n";
                std::cout << "2. Update quantity\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;

                switch (choice) {
                    case 1: {
                        int newPrice;
                        std::cout << "Enter the new price: $";
                        std::cin >> newPrice;
                        inventory[i]->price = newPrice;
                        std::cout << "Price updated.\n";
                        return;
                    }
                    case 2: {
                        int newQuantity;
                        std::cout << "Enter the new quantity: ";
                        std::cin >> newQuantity;
                        inventory[i]->quantity = newQuantity;
                        std::cout << "Quantity updated.\n";
                        return;
                    }
                    default:
                        std::cout << "Invalid choice.\n";
                        return;
                }
            }
        }

        std::cout << "Item not found in inventory.\n";
    }

    void calculateInventoryValue() const {
        if (inventory.empty()) {
            std::cout << "Inventory is empty.\n";
            return;
        }

        int totalValue = 0;

        for (size_t i = 0; i < inventory.size(); ++i) {
            int itemValue = inventory[i]->price * inventory[i]->quantity;
            totalValue += itemValue;
        }

        std::cout << "Total Inventory Value: $" << totalValue << "\n";
    }

public:
    void run() {
        if (!login()) {
            std::cout << "Exiting program.\n";
            return;
        }

        int choice;
        while (true) {
            std::cout << "\nStore Management System\n";
            std::cout << "1. Add item to inventory\n";
            std::cout << "2. Remove item from inventory\n";
            std::cout << "3. Display inventory\n";
            std::cout << "4. Process sale\n";
            std::cout << "5. Display total sales\n";
            std::cout << "6. Search for an item\n";
            std::cout << "7. Update an item\n";
            std::cout << "8. Calculate total inventory value\n";
            std::cout << "9. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addItem();
                    break;
                case 2:
                    removeItem();
                    break;
                case 3:
                    displayInventory();
                    break;
                case 4:
                    processSale();
                    break;
                case 5:
                    displaySales();
                    break;
                case 6:
                    searchItem();
                    break;
                case 7:
                    updateItem();
                    break;
                case 8:
                    calculateInventoryValue();
                    break;
                case 9:
                    std::cout << "Exiting program.\n";
                    return;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }
};

int main() {
    StoreManagementSystem sms;
    sms.run();

    return 0;
}
