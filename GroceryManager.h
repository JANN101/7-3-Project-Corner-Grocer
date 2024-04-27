#ifndef GROCERY_MANAGER_H
#define GROCERY_MANAGER_H

#include <string>
#include <map>

class GroceryManager {
public:
    void AutoBackup();
    void ItemSearch();
    void CountItems();
    void TallyItems();

private:
    std::map<std::string, int> groceryList; //Private member variable, creates private string and int grocerylist
};

#endif // GROCERY_MANAGER_H

