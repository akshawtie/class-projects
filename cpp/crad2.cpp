#include <iostream>
#include <algorithm>
#include <random>

class crd {
  public:
    static int card[53];
    int user_total = 0;

    crd() {
        std::fill(card, card + 53, 0);
    }

    void print();
    int cardpicker(int n);
    int carddrawer(int pno);
};

void crd::print() {
    for (int i = 0; i < 53; i++) {
        std::cout << card[i] << std::endl;
    }
}

int crd::cardpicker(int n) {
    int pick;
    bool flag = true;
    while (flag == true) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> number(0, 52);
        pick = number(gen);
        if (card[pick] == 0) {
            card[pick] = n;
            flag = false;
        }
    }
    return pick;
}

int crd::carddrawer(int pno) {
    int card1 = cardpicker(pno);
    int value = card1 % 13 + 1;   // values 1–13
    if (value > 10) value = 10;   // J, Q, K = 10
    user_total += value;

    std::cout << "Drew card index: " << card1 << " -> value: " << value 
              << " | Total: " << user_total << std::endl;
    return value;
}

int crd::card[53];  // static definition

class prs : public crd {
  public:
    void player1(int pno);
};

void prs::player1(int pno) {
    bool flag = true;
    int i = 0;
    while (i < 2 && flag == true) {   // AND instead of OR
        carddrawer(pno);
        i++;
        if (user_total >= 21)
            flag = false;
    }
}

int main() {
    int n = 1;
    prs p1;
    p1.player1(n);
}
