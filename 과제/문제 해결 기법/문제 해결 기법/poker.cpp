#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

struct Card {
    char suit;
    int value;
};

bool compare(const Card& a, const Card& b) {
    return a.value < b.value;
}

vector<int> getValue(const vector<Card>& cards) {
    vector<int> values;

    for (const auto& card : cards) {
        values.push_back(card.value);
    }

    sort(values.begin(), values.end());

    return values;
}

bool isStraight(vector<int> values) {
    if (values[0] == 1) values.push_back(14);

    for (size_t i = 0; i <= values.size() - 5; ++i) {
        bool straight = true;
        
        for (size_t j = 0; j < 4; ++j) {
            if (values[i + j] + 1 != values[i + j + 1]) {
                straight = false;
                break;
            }
        }

        if (straight) return true;
    }

    return false;
}

bool isFlush(const vector<Card>& cards) {
    unordered_map<char, int> count;

    for (const auto& card : cards) {
        count[card.suit]++;
    }

    for (const auto& pair : count) {
        if (pair.second >= 5) return true;
    }
    
    return false;
}

string evaluate(const vector<Card>& cards) {
    vector<int> values = getValue(cards);
    unordered_map<int, int> valueCount;
    unordered_map<char, int> suitCount;

    for (const auto& card : cards) {
        valueCount[card.value]++;
        suitCount[card.suit]++;
    }

    bool flush = isFlush(cards);
    bool straight = isStraight(values);

    if (flush && straight) return "Straight Flush";
    if (flush) return "Flush";
    if (straight) return "Straight";

    int fourCard = 0, threeCard = 0, pairs = 0;

    for (const auto& pair : valueCount) {
        if (pair.second == 4) fourCard++;
        if (pair.second == 3) threeCard++;
        if (pair.second == 2) pairs++;
    }

    if (fourCard) return "Four Card";
    if (threeCard && pairs) return "Full House";
    if (threeCard) return "Triple";
    if (pairs == 2) return "Two Pair";
    if (pairs == 1) return "One Pair";

    return "Top";
}

vector<Card> parseInp(const string& line) {
    vector<Card> cards;
    istringstream iss(line);
    string cardStr;

    while (iss >> cardStr) {
        char suit = cardStr[0];
        char val = cardStr[1];
        int value;

        if (val == 'A') value = 1;
        else if (val == 'T') value = 10;
        else if (val == 'J') value = 11;
        else if (val == 'Q') value = 12;
        else if (val == 'K') value = 13;
        else value = val - '0';
        
        cards.push_back({ suit, value });
    }

    return cards;
}

string determine(vector<Card>& cards) {
    string bestHand = "Top";
    vector<int> indices = { 0, 1, 2, 3, 4, 5, 6 };

    do {
        vector<Card> hand;

        for (int i = 0; i < 5; ++i) {
            hand.push_back(cards[indices[i]]);
        }

        string currentHand = evaluate(hand);
        
        if (currentHand == "Straight Flush") return currentHand;
        if (currentHand == "Four Card" && bestHand != "Straight Flush") bestHand = currentHand;
        if (currentHand == "Full House" && bestHand != "Straight Flush" && bestHand != "Four Card") bestHand = currentHand;
        if (currentHand == "Flush" && bestHand != "Straight Flush" && bestHand != "Four Card" && bestHand != "Full House") bestHand = currentHand;
        if (currentHand == "Straight" && bestHand != "Straight Flush" && bestHand != "Four Card" && bestHand != "Full House" && bestHand != "Flush") bestHand = currentHand;
        if (currentHand == "Triple" && bestHand != "Straight Flush" && bestHand != "Four Card" && bestHand != "Full House" && bestHand != "Flush" && bestHand != "Straight") bestHand = currentHand;
        if (currentHand == "Two Pair" && bestHand != "Straight Flush" && bestHand != "Four Card" && bestHand != "Full House" && bestHand != "Flush" && bestHand != "Straight" && bestHand != "Triple") bestHand = currentHand;
        if (currentHand == "One Pair" && bestHand == "Top") bestHand = currentHand;
    } while (next_permutation(indices.begin(), indices.end()));

    return bestHand;
}

int main() {
    ifstream fin("poker.inp");
    ofstream fout("poker.out");

    int T;
    fin >> T;
    fin.ignore();

    for (int t = 0; t < T; ++t) {
        string line;
        getline(fin, line);

        vector<Card> cards = parseInp(line);

        fout << determine(cards) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}