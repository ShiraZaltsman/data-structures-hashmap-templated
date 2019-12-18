#include <iostream>
#include "HashMap.h"
int main() {
    HashMap<int> hashMap(13);
    hashMap.insert("shira",22);
    hashMap.insert("elana",21);
    hashMap.insert("chana",21);

    hashMap.printHashTable();
    return 0;
}