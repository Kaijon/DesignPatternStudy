// https://coliru.stacked-crooked.com/a/beca63b5f66b1657
// Design Pattern : Strategy
// 1. Add, Sub, Mult 的運算唯一的差別 : a+=b, a-=b, a*=b
// 2. 拉出來改成interface，Evaluate(int a, int b)
// 3. 繼承相同的interface，實作各自的運算

#include <iostream>
#include <vector>
using namespace std;

#if 1
struct IOperator {
    virtual int Evaluate(int a, int b) const = 0;
};

struct AddOperator : public IOperator {
    int Evaluate(int a, int b) const override;
};

struct MultiplyOperator : public IOperator {
    int Evaluate(int a, int b) const override;
};

struct SubstractOperator : public IOperator {
    int Evaluate(int a, int b) const override;
};

int Accumulate(vector<int> v, const IOperator& op);

int main() {
    vector<int> v{1, 9, 1, 7, 2};
    cout << "Sum: "       << Accumulate(v, AddOperator())       << endl
         << "Product: "   << Accumulate(v, MultiplyOperator())  << endl
         << "Subscract: " << Accumulate(v, SubstractOperator()) << endl;
}

int AddOperator::Evaluate(int a, int b) const {
    return a += b;
}

int MultiplyOperator::Evaluate(int a, int b) const {
    return a *= b;
}

int SubstractOperator::Evaluate(int a, int b) const {
    return a -= b;
}

int Accumulate(vector<int> v, const IOperator& op) {
    int res = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        res = op.Evaluate(res, v[i]);
    }
    return res;
}
#endif
// Design Pattern : Strategy

#if 0
int Sub(const vector<int> v){
    int final = v[0];
    for(size_t i=1; i< v.size(); i++){
        final -= v[i];    
    }
    return final;
}

int Add(const vector<int> v){
    int final = v[0];
    for(size_t i=1; i< v.size(); i++){
        final += v[i];    
    }
    return final;
}

int Mult(const vector<int> v){
    int final = v[0];
    for(size_t i=1; i< v.size(); i++){
        final *= v[i];    
    }
    return final;
}

int main() {
    vector<int> v{1, 9, 1, 7, 2};
    cout << "Add :" << Add(v) << endl;
    cout << "Mult :" << Mult(v) << endl;
    cout << "Sub :" << Sub(v) << endl;
    
    return 0;
}
#endif
