#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum class Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card {
public:
    Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

    // Implement getters, setters, and a method to display card information

private:
    Suit suit;
    Rank rank;
};

class Deck {
public:
    Deck() {
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 0; rank < 13; ++rank) {
                cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
            }
        }
    }

    void shuffle() {
        std::srand(std::time(0));
        std::random_shuffle(cards.begin(), cards.end());
    }

    Card deal() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

private:
    std::vector<Card> cards;
};

class Player {
public:
    void addCard(const Card& card) {
        hand.push_back(card);
    }

    // Implement methods for displaying hand and calculating hand value

private:
    std::vector<Card> hand;
};

void playGame() {
    Deck deck;
    Player player1, player2;

    while (true) {
        deck.shuffle();

        // Deal cards to each player
        for (int i = 0; i < 5; ++i) {
            player1.addCard(deck.deal());
            player2.addCard(deck.deal());
        }

        // Display hands
        // ...

        // Let players take actions (discard and draw)
        // ...

        // Determine the winner
        // ...

        // Ask if the players want to play again
        // ...
    }
}

int main() {
    playGame();
    return 0;
}
