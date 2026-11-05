#ifndef ARCADE_BLACKJACK_H
#define ARCADE_BLACKJACK_H

#include "game.h"
#include "deck.h"
#include "hand.h"

/// @file blackjack.h
/// @brief Blackjack for one player against the dealer.

/// How a round ended, from the player's side.
enum class Outcome {
    player_blackjack, ///< the player has blackjack and the dealer does not
    player_win,       ///< the player's total beats the dealer's, or the dealer busts
    push,             ///< a tie
    player_loss       ///< the player busts, or the dealer's hand is better
};

/// The dealer draws until the hand is worth 17 or more. A soft 17 stands.
void dealer_turn(Hand &dealer, Deck &deck);

/// Decide who won. A player bust loses even if the dealer also busts.
Outcome settle(const Hand &player, const Hand &dealer);

/// How much the bankroll changes.
int payout(Outcome outcome, int bet);

class Blackjack : public Game {
public:
    Blackjack();

    void play();
    [[nodiscard]] int times_played() const;

private:
    int m_times_played;
};

#endif // ARCADE_BLACKJACK_H
