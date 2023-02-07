//https://coliru.stacked-crooked.com/a/a699e911da97d572
// Design Pattern : Strategy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Version 1, Normal
int Max(const vector<int> v) {
    int max = v[0];
    for(size_t i = 1; i < v.size(); i++)
        if (max < v[i])
            max = v[i];
    return max;
}

int Min(const vector<int> v) {
    int min = v[0];
    for(size_t i = 1; i < v.size(); i++)
        if (min > v[i])
            min = v[i];
    return min;
}

// Version 2, refactor
struct ICompare {
    virtual bool Compare(int a, int b) const = 0;    
};

struct IsGreater : public ICompare {
    bool Compare(int a, int b) const;
};

bool IsGreater::Compare(int a, int b) const {
    return a > b;    
}

struct IsLess : public ICompare {
    bool Compare(int a, int b) const;    
};

bool IsLess::Compare(int a, int b) const {
    return a < b;
}

int handler(const vector<int> v, const ICompare &compare) {
    int res = v[0];
    for(size_t i = 1; i < v.size(); i++)
        if (compare.Compare(v[i], res)) {
            res = v[i];    
        }  
    return res;
}

// Version 3, C++ Sort
bool Greater(int a, int b) {
    return a > b;    
}

bool Less(int a, int b) {
    return a < b;    
}

// Version 4, C++ generic
struct isGreater {
    bool Comparator(int a, int b) const;
};
struct isLess {
    bool Comparator(int a, int b) const;
};
bool isGreater::Comparator(int a, int b) const {
    return a > b;
}
bool isLess::Comparator(int a, int b) const {
    return a < b;
}

template<typename TComparator>
int handlerV2(const vector<int> v, const TComparator &comparator);

template<typename TComparator>
int handlerV2(const vector<int> v, const TComparator &comparator) {
    int res = v[0];
    for(size_t i = 1; i < v.size(); i++)
        if (comparator.Comparator(v[i], res)) {
            res = v[i];    
        }  
    return res;
}

int main() {
    vector<int> v = {5, 4, 9, 3, 1, 2, -5, 123};
    cout << "=== Version 1 ===" << endl;
    cout << "   Max : " << Max(v) << endl;
    cout << "   Min : " << Min(v) << endl;
    
    cout << "=== Version 2 ===" << endl;
    cout << "   Max : " << handler(v, IsGreater())  << endl;
    cout << "   Min : " << handler(v, IsLess())  << endl;
    
    cout << "=== Version 3 ===" << endl;
    sort(v.begin(), v.end(), Greater);
    cout << "   Max : " << v[0]  << endl;
    sort(v.begin(), v.end(), Less);
    cout << "   Min : " << v[0]  << endl;
    
    cout << "=== Version 4 ===" << endl;
    cout << "   Max : " << handlerV2(v, isGreater())  << endl;
    cout << "   Min : " << handlerV2(v, isLess())  << endl;    
    return 0;    
}
