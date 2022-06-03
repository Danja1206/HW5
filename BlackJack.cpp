#include <iostream>
#include <vector>

using namespace std;

class Card
{
public:
    enum suit {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    enum value {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };

    void setValue(value _value, suit _suit)
    {
        v = _value;
        s = _suit;
    }

    Card(value _value = ACE, suit _suit = SPADES, bool _cardPosition = true) : v(_value), s(_suit), cardPosition(_cardPosition) {}
    void Flip() 
    {
        if (!cardPosition)
            cardPosition = true;
        else cardPosition = false;
    }
    value getValue()
    {
        if (cardPosition)
        {
            return v;
        }
    }
protected:
    value v;
    suit s;
    bool cardPosition;
};

class Hand
{
public:

    void Add(Card* aCard)
    {
        cards.push_back(aCard);
    }
    void Clear()
    {
        for (auto i : cards)
            delete i;
    }
    int getAmount() const
    {
        if (cards.empty())
            return 0;
        int test = 0;
        for (auto crds : cards)
            test += crds->getValue();
        bool tests = false;
        for (auto crds : cards)
            if (crds->getValue() == crds->ACE) tests = true;
        if (tests && test <= 11)
            test += 10;
        return test;
    }
private:
    vector<Card*> cards;
};

class GenericPlayer : public Hand
{
public:
    GenericPlayer(string _name = "") {}
    ~GenericPlayer() {}

    virtual bool IsHitting() 
    {
        return false;
    }

    bool IsBoosted(int _getAmount) 
    {
            if(_getAmount > 21);
            {
                return true;
                Bust();
            }
    }

    void Bust() 
    {
            cout << "У игрока " << name << " перебор" << endl;
    }
private:
    string name;
};

int main()
{
    setlocale(LC_ALL, "rus");
    Card* C = new Card;
    C->setValue(C->NINE, C->DIAMONDS);
    //cout << C->getValue();
    //C->Flip();
    cout << C->getValue() << endl;
    Hand H;
    Hand* Hs = new Hand();
    H.Add(C);
    cout << H.getAmount() << endl;
    H.Add(C);
    H.Add(C);
    H.Add(C);
    //C->setValue(C->KING, C->DIAMONDS);
    //H.Clear();
    GenericPlayer G;
    cout << G.IsHitting() << endl;
    cout << G.IsBoosted(H.getAmount()) << endl;
    G.Bust();
    cout << H.getAmount();
}
