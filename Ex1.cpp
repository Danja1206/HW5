#include <iostream>

using namespace std;

template<typename T>
class Pair1
{

public:
    Pair1(const T& _fst, const T& _snd) : fst(_fst), snd(_snd) {}
    ~Pair1() {}
    T first() const { return fst; };
    T second() const { return snd; };

private:
    T fst, snd;
};

int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
