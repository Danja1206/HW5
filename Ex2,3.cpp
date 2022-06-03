#include <iostream>
#include <string>

using namespace std;

template<typename T, typename U>
class Pair
{

public:
    Pair(const T& _fst, const U& _snd) : fst(_fst), snd(_snd) {}
    ~Pair() {}
    T first() const { return fst; };
    U second() const { return snd; };

private:
    T fst;
    U snd;
};

template<typename V>
class StringValuePair : public Pair<string, V>
{
public:
    StringValuePair(const string& _frs, const V& _sc) : Pair<string, V> (_frs, _sc) {}
};

int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    
    return 0;
}
