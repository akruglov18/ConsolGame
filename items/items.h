#ifndef ITEMS_H
#define ITEMS_H
#include <string>

enum class ItemType {
    NONE,
    WEAPON,
    ARMOR
};

class Items {
public:
    ItemType get_type() const;
    std::string get_type_str() const;
    
protected:
    ItemType _type = ItemType::NONE;
};

#endif // ITEMS_H
