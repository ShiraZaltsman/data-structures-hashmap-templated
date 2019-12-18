//
// Created by shira on 12/18/19.
//

#ifndef DATA_STRUCTURES_HASHMAP_TEMPLATED_SHIRAZALTSMAN_HASHMAP_H
#define DATA_STRUCTURES_HASHMAP_TEMPLATED_SHIRAZALTSMAN_HASHMAP_H

#include <vector>
#include "LinkedList.h"
using namespace std;


template <class T>
class HashMap {
public:
    explicit HashMap(size_t hashSize);
    void insert(const string, const T&);
    void printHashTable();

    struct Pair{
        Pair(const string &key, T val){
            m_key = key;
            m_value = val;
        }
//        friend std::ostream &operator<<(std::ostream &os, const Pair p){
//            os<<"key: "<<p.m_key<<"value: "<<p.m_value<<endl;
//            return os;
//        }
        string m_key;
        T m_value;

    };
    int Hash(string key);
    size_t getMTableSize() const;

private:
    size_t m_tableSize;
    size_t m_bucketsInUse;
    size_t m_numOfPairs;
    vector<LinkedList<Pair> > m_table;
};

//template <class U>
//void printList(LinkedList<U> list){
//    for (typename LinkedList<U>::Iterator iterator = list.begin(); iterator != list.end(); iterator++)
//    {
//        cout << (HashMap<U>::Pair)(*iterator).value << " ";
//    }
//
//    cout << endl;
//}
template<class T>
inline int HashMap<T>::Hash(string key) {
    int index =0;
    for (int i = 0; i < key.length(); ++i) {
        index += (int) key[i] * i;
    }
    return index % m_tableSize;
}

template<class T>
inline HashMap<T>::HashMap(size_t hashSize) :
        m_tableSize(hashSize),
        m_bucketsInUse(0),
        m_numOfPairs(0)
        {
            m_table =  vector<LinkedList<Pair> > (hashSize);

        }

template<class T>
inline void HashMap<T>::insert(const string key, const T &value) {
    Pair newPair(key, value);
    int index = Hash(key);
    m_table[index].add(newPair);

}
template<class T>
inline std::ostream &operator<<(std::ostream &os, const HashMap<T> &map) {
    for (int i = 0; i < map.getMTableSize(); ++i) {
        os << map.m_table[i];
    }

    return os;
}

template<class T>
inline size_t HashMap<T>::getMTableSize() const {
    return m_tableSize;
}

template<class T>
inline void HashMap<T>::printHashTable() {
    for (int i = 0; i < getMTableSize(); ++i) {
        std::cout<<"["<<i<<"] : ";
        //printList(m_table[i]);
        for (typename LinkedList<Pair>::Iterator it = m_table[i].begin(); it != m_table[i].end(); it++) {
            cout << "[" << (*it).m_key << "," << (*it).m_value << "] --> ";
        }
        std::cout<<std::endl;
    }
}




#endif //DATA_STRUCTURES_HASHMAP_TEMPLATED_SHIRAZALTSMAN_HASHMAP_H
