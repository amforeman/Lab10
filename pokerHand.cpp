#include "pokerHand.h"

#include <regex>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

std::string bestPokerHand(std::string p1, std::string p2) {
  // convert input into a vector that is easier to iterate through
  std::vector<std::string> player1 = handleInput(p1);
  std::vector<std::string> player2 = handleInput(p2);

  // check that the poker hand is a valid size
  if (player1.size() != 5 || player2.size() != 5) {
    return "Invalid input";
  }

  // create a vector storing the frequency of the values
  std::vector<int> p1Values = checkValues(player1);
  std::vector<int> p2Values = checkValues(player2);

  //create a vector storing the frequency of the suits
  std::vector<int> p1Suits = checkSuits(player1);
  std::vector<int> p2Suits = checkSuits(player2);

  // determine the rank of each hand
  int player1Rank = handRank(p1Suits, p1Values);
  int player2Rank = handRank(p2Suits, p2Values);

  // if hands are completely different ranks, return winner
  if (player1Rank < player2Rank) {
    return "Player 1 wins";
  }
  if (player2Rank < player1Rank) {
    return "Player 2 wins";
  }
  // if hands are similar ranks (both straight flush, both full house, etc.)
  // determine the higher ranking one, and return the winner
  else {
    if (player1Rank == 0 && player2Rank == 0) {
      return straightFlushRank(p1Values, p2Values);
    }
    else if (player1Rank == 1 && player2Rank == 1) {
      return fourOfAKindRank(p1Values, p2Values);
    }
    else if (player1Rank == 2 && player2Rank == 2) {
      return fullHouseRank(p1Values, p2Values);
    }
    else if (player1Rank == 3 && player2Rank == 3) {
      return flushRank(p1Values, p2Values);
    }
    else if (player1Rank == 4 && player2Rank == 4) {
      return straightRank(p1Values, p2Values);
    }
    else if (player1Rank == 5 && player2Rank == 5) {
      return threeOfAKindRank(p1Values, p2Values);
    }
    else if (player1Rank == 6 && player2Rank == 6) {
      return twoPairsRank(p1Values, p2Values);
    }
    else if (player1Rank == 7 && player2Rank == 7) {
      return onePairRank(p1Values, p2Values);
    }
    else {
      return highCardRank(p1Values, p2Values);
    }
  }
}

std::vector<std::string> handleInput(std::string hand) {
  std::vector<std::string> cardsInHand = {};
  std::regex regCards ("[2-9TJQKA][CDHS]");
  std::smatch m;
  std::regex_search(hand, m, regCards);
  // while the input is in the correct format, add to the vector
  while(std::regex_search(hand, m, regCards)) {
    for(auto x : m) {
      cardsInHand.push_back(x);
    }
    hand = m.suffix();
  }
  // return cards that were able to be added
  // if the number in the vecotr is not equal to 5, the bestPokerHand function will not continue
  return cardsInHand;
}

int handRank(std::vector<int> suits, std::vector<int> values) {
  std::pair<bool, int> singlePair = onePair(values);
  if (straightFlush(suits, values)) {
    return 0;
  }
  else if (fourOfAKind(values)) {
    return 1;
  }
  else if (fullHouse(values)) {
    return 2;
  }
  else if (flush(suits)) {
    return 3;
  }
  else if (straight(values)) {
    return 4;
  }
  else if (threeOfAKind(values)) {
    return 5;
  }
  else if (twoPairs(values)) {
    return 6;
  }
  else if (singlePair.first == true) {
    return 7;
  }
  else {
    //high card
    return 8;
  }
}

bool straightFlush(std::vector<int> suits, std::vector<int> values) {
  if (flush(suits) == true && straight(values) == true) {
    return true;
  }
  else {
    return false;
  }
}

std::string straightFlushRank(std::vector<int> values1, std::vector<int> values2) {
  int highestCard1 = 0;
  int highestCard2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 1) {
      highestCard1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 1) {
      highestCard2 = j;
      break;
    }
  }
  if (highestCard1 > highestCard2) {
    return "Player 1 wins";
  }
  else if (highestCard1 < highestCard2) {
    return "Player 2 wins";
  }
  else {
    // if all values are the same
    return "Tie";
  }
}

bool fourOfAKind(std::vector<int> values) {
  for (int i = 0; i < values.size(); i++) {
    if (values[i] == 4) {
      return true;
    }
  }
  return false;
}

std::string fourOfAKindRank(std::vector<int> values1, std::vector<int> values2) {
  int cardValue1 = 0;
  int cardValue2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 4) {
      cardValue1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >=0; j--) {
    if (values2[j] == 4) {
      cardValue2 = j;
      break;
    }
  }
  if (cardValue1 > cardValue2) {
    return "Player 1 wins";
  }
  else {
    return "Player 2 wins";
  }
  // tie is not possible with only one deck
}

bool fullHouse(std::vector<int> values) {
  if (threeOfAKind(values) == true) {
    std::pair<bool, int> singlePair = onePair(values);
    return singlePair.first;
  }
  return false;
}

std::string fullHouseRank(std::vector<int> values1, std::vector<int> values2) {
  int cardValue1 = 0;
  int cardValue2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 3) {
      cardValue1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 3) {
      cardValue2 = j;
      break;
    }
  }
  if (cardValue1 > cardValue2) {
    return "Player 1 wins";
  }
  else {
    return "Player 2 wins";
  }
  // tie is not possible with one deck of cards
}

bool flush(std::vector<int> suits) {
  for (int i = 0; i < suits.size(); i++) {
    if (suits[i] == 5) {
      return true;
    }
  }
  return false;
}

std::string flushRank(std::vector<int> values1, std::vector<int> values2) {
  int cardValue1 = 0;
  int cardValue2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 1) {
      cardValue1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 1) {
      cardValue2 = j;
      break;
    }
  }
  if (cardValue1 > cardValue2) {
    return "Player 1 wins";
  }
  else if (cardValue1 < cardValue2) {
    return "Player 2 wins";
  }
  else if (cardValue1 == cardValue2 && cardValue1 > 0) {
    // remove highest value card from the vector
    values1.erase(values1.begin() + cardValue1);
    values2.erase(values2.begin() + cardValue2);
    return flushRank(values1, values2);
  }
  else {
    // if all values are the same
    return "Tie";
  }
}

bool straight(std::vector<int> values) {
  int run = 0;
  if (values[0] == 1) {
    run = 1;
  }
  int i = 1;
  //check for consecutive values
  while (i < values.size() && run < 4) {
    if (values[i] == 1 && values[i-1] == 1) {
      run++;
    }
    else {
      run = 0;
    }
    i++;
  }
  // five consecutive values
  if (run == 4) {
    return true;
  }
  else {
    return false;
  }
}

std::string straightRank(std::vector<int> values1, std::vector<int> values2) {
  int highestCard1 = 0;
  int highestCard2 = 0;
  for (int i = values1.size()-1; i >= 0 ; i--) {
    if (values1[i] == 1) {
      highestCard1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 1) {
      highestCard2 = j;
      break;
    }
  }
  if (highestCard1 > highestCard2) {
    return "Player 1 wins";
  }
  else if (highestCard1 < highestCard2) {
    return "Player 2 wins";
  }
  else {
    // if all values are the same
    return "Tie";
  }
}

bool threeOfAKind(std::vector<int> values) {
  for (int i = 0; i < values.size(); i++) {
    if (values[i] == 3) {
      return true;
    }
  }
  return false;
}

std::string threeOfAKindRank(std::vector<int> values1, std::vector<int> values2) {
  int cardValue1 = 0;
  int cardValue2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 3) {
      cardValue1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 3) {
      cardValue2 = j;
      break;
    }
  }
  if (cardValue1 > cardValue2) {
    return "Player 1 wins";
  }
  else {
    return "Player 2 wins";
  }
  // tie not possible with one deck of cards
}

bool twoPairs(std::vector<int> values) {
  std::pair<bool, int> singlePair = onePair(values);
  if (singlePair.first == true) {
    values.erase(values.begin() + singlePair.second);
    std::pair<bool, int> doublePairs = onePair(values);
    return doublePairs.first;
  }
  return false;
}

std::string twoPairsRank(std::vector<int> values1, std::vector<int> values2) {
  int cardValue1 = 0;
  int cardValue2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 2) {
      cardValue1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 2) {
      cardValue2 = j;
      break;
    }
  }
  if (cardValue1 > cardValue2) {
    return "Player 1 wins";
  }
  else if (cardValue1 < cardValue2) {
    return "Player 2 wins";
  }
  else if (cardValue1 == cardValue2 && values1.size() > 11) {
    // first pair is the same value
    values1.erase(values1.begin() + cardValue1);
    values2.erase(values2.begin() + cardValue2);
    return twoPairsRank(values1, values2);
  }
  else if (cardValue1 == cardValue2 && values1.size() == 11) {
    // second pair is the same value
    values1.erase(values1.begin() + cardValue1);
    values2.erase(values2.begin() + cardValue2);
    return highCardRank(values1, values2);
  }
  else {
    // remaining cards are the same value
    return "Tie";
  }
}

std::pair<bool, int> onePair(std::vector<int> values) {
  // pair representing the presence of a pair in the hand and the value of the hand's pair
  std::pair<bool, int> singlePair;
  for (int i = 0; i < values.size(); i++) {
    if (values[i] == 2) {
      singlePair.first = true;
      singlePair.second = i;
      return singlePair;
    }
  }
  singlePair.first = false;
  singlePair.second = -1;
  return singlePair;
}

std::string onePairRank(std::vector<int> values1, std::vector<int> values2) {
  int cardValue1 = 0;
  int cardValue2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 2) {
      cardValue1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if (values2[j] == 2) {
      cardValue2 = j;
      break;
    }
  }
  if (cardValue1 > cardValue2) {
    return "Player 1 wins";
  }
  else if (cardValue1 < cardValue2) {
    return "Player 2 wins";
  }
  else {
    // pairs are the same value, check remaining cards
    values1.erase(values1.begin() + cardValue1);
    values2.erase(values2.begin() + cardValue2);
    return highCardRank(values1, values2);
  }
}

std::string highCardRank(std::vector<int> values1, std::vector<int> values2) {
  int highestCard1 = 0;
  int highestCard2 = 0;
  for (int i = values1.size()-1; i >= 0; i--) {
    if (values1[i] == 1) {
      highestCard1 = i;
      break;
    }
  }
  for (int j = values2.size()-1; j >= 0; j--) {
    if(values2[j] == 1) {
      highestCard2 = j;
      break;
    }
  }
  if (highestCard1 > highestCard2) {
    return "Player 1 wins";
  }
  else if (highestCard1 < highestCard2) {
    return "Player 2 wins";
  }
  else if (highestCard1 == highestCard2 && highestCard1 > 0) {
    // cards are the same value
    values1.erase(values1.begin()+highestCard1);
    values2.erase(values2.begin()+highestCard2);
    return highCardRank(values1, values2);
  }
  else {
    // all cards in hand are the same value
    return "Tie";
  }
}

std::vector<int> checkValues(std::vector<std::string> hand) {
  std::vector<int> values(13, 0);
  std::regex twos ("[2][CDHS]");
  std::regex threes ("[3][CDHS]");
  std::regex fours ("[4][CDHS]");
  std::regex fives ("[5][CDHS]");
  std::regex sixes ("[6][CDHS]");
  std::regex sevens ("[7][CDHS]");
  std::regex eights ("[8][CDHS]");
  std::regex nines ("[9][CDHS]");
  std::regex tens ("[T][CDHS]");
  std::regex jacks ("[J][CDHS]");
  std::regex queens ("[Q][CDHS]");
  std::regex kings ("[K][CDHS]");
  std::regex aces ("[A][CDHS]");
  for (int i = 0; i < 5; i++) {
    if (std::regex_match(hand[i], twos)) {
      values[0]++;
      continue;
    }
    if (std::regex_match(hand[i], threes)) {
      values[1]++;
      continue;
    }
    if (std::regex_match(hand[i], fours)) {
      values[2]++;
      continue;
    }
    if (std::regex_match(hand[i], fives)) {
      values[3]++;
      continue;
    }
    if (std::regex_match(hand[i], sixes)) {
      values[4]++;
      continue;
    }
    if (std::regex_match(hand[i], sevens)) {
      values[5]++;
      continue;
    }
    if (std::regex_match(hand[i], eights)) {
      values[6]++;
      continue;
    }
    if (std::regex_match(hand[i], nines)) {
      values[7]++;
      continue;
    }
    if (std::regex_match(hand[i], tens)) {
      values[8]++;
      continue;
    }
    if (std::regex_match(hand[i], jacks)) {
      values[9]++;
      continue;
    }
    if (std::regex_match(hand[i], queens)) {
      values[10]++;
      continue;
    }
    if (std::regex_match(hand[i], kings)) {
      values[11]++;
      continue;
    }
    if (std::regex_match(hand[i], aces)) {
      values[12]++;
      continue;
    }
    else {
      std::vector<int> invalid = {};
      return invalid;
    }
  }
  return values;
}

std::vector<int> checkSuits(std::vector<std::string> hand) {
  std::vector<int> suits(4, 0);
  std::regex clubs ("[2-9TJQKA][C]");
  std::regex diamonds ("[2-9TJQKA][D]");
  std::regex hearts ("[2-9TJQKA][H]");
  std::regex spades ("[2-9TJQKA][S]");
  for (int i = 0; i < 5; i++) {
    if (std::regex_match(hand[i], clubs)) {
      suits[0]++;
      continue;
    }
    if (std::regex_match(hand[i], diamonds)) {
      suits[1]++;
      continue;
    }
    if (std::regex_match(hand[i], hearts)) {
      suits[2]++;
      continue;
    }
    if (std::regex_match(hand[i], spades)) {
      suits[3]++;
      continue;
    }
    else {
      std::vector<int> invalid = {};
      return invalid;
    }
  }
  return suits;
}
