/*
 * File: pokerHand.h
 * ------------------------
 * Contains methods to determine the higher ranking poker hand out of two hands.
 */
#ifndef pokerhand_h
#define pokerhand_h

#include <string>
#include <vector>

/*
 * Method: bestPokerHand
 * ----------------------------
 * This method takes input strings in the form of 
 * "2H 3D 5S 9C KD"
 * "2C 3H 4S 8C AH"
 * The first character in each pair of chracters represent the face value of the card. 
 * These values are denoted as 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A.
 * The second character represents the the card's suit. The suits are denoted as C, D, H, S.
 *
 * The method determines the higher ranking hand using helper functions to format
 * and categorize the hands. 
 * If the hands have different rankings, the method returns the winner.
 * If the hands have the same ranking, the method returns a tie.
 */
std::string bestPokerHand(std::string p1, std::string p2);

/*
 * Method: handleInput
 * ------------------------
 * This method takes a string representing a single poker hand and converts it into 
 * a vector of strings, with each element representing a single card.
 */
std::vector<std::string> handleInput(std::string hand);

/*
 * Method: handRank
 * --------------------------
 * This method takes two vectors of integers, one representing the suits in the hand,
 * and one representing the values in the same hand. Using helper functions, the rank 
 * of the hand is determined and returned as an integer value. Lower values represent
 * higher ranking hands:
 * 0 - Straight Flush
 * 1 - Four of a Kind
 * 2 - Full House
 * 3 - Flush
 * 4 - Straight
 * 5 - Three of a Kind
 * 6 - Two Pairs
 * 7 - One Pair
 * 8 - High Card
 */
int handRank(std::vector<int> suits, std::vector<int> values);

/*
 * Method: straightFlush 
 * ---------------------------
 * This method takes two vectors of integers, one representing the suits in a hand,
 * and one representing the values in the same hand. It determines whether or not 
 * the hand contains a straight flush. If it does, the method return true. If not,
 * the method returns false.
 */
bool straightFlush(std::vector<int> suits, std::vector<int> values);

/*
 * Method: straightFlushRank
 * -------------------------------
 * This method is used to determine the higher ranking straight flush between two 
 * hands that contain a straight flush. The method takes two vectors of integers,
 * representing the values in two separate hands. The highest card in each hand is 
 * determined and a string stating the winner is returned.
 */
std::string straightFlushRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: fourOfAKind
 * --------------------------------
 * This method takes a vector of integers representing the values in a hand.
 * It determines whether or not four of the same value are present in the hand. 
 * If there are, the method returns true. If not, it returns false.
 */
bool fourOfAKind(std::vector<int> values);

/*
 * Method: fourOfAKindRank
 * -------------------------------------
 * This method is used to determine the higher ranking four of a kind between two 
 * hands that contain four of a kind. The method takes two vectors of integers,
 * representing the values in two separate hands. The value of each four of a kind 
 * is determined, and the higher value is the winner. A string stating the winner is returned.
 */
std::string fourOfAKindRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: fullHouse
 * --------------------------------
 * This method takes a vector of integers representing the values in a hand.
 * It determines whether or not a full house is present in the hand. A full house
 * is a group of three cards of with the same value, with the remaining two 
 * cards in the hand being a pair with the same value.
 * If there is a full house, the method returns true. If not, it returns false.
 */
bool fullHouse(std::vector<int> values);

/*
 * Method: fullHouseRank
 * -------------------------------------
 * This method is used to determine the higher ranking full house between two 
 * hands that contain a full house. The method takes two vectors of integers,
 * representing the values in two separate hands. The value of each group of three
 * is determined, and the higher value is the winner. A string stating the winner is returned.
 */
std::string fullHouseRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: flush
 * --------------------------------
 * This method takes a vector of integers representing the suits in a hand.
 * It determines whether or not a flush is present in the hand. A flush is 
 * five cards that are all members of the same suit.
 * If there is a flush, the method returns true. If not, it returns false.
 */
bool flush(std::vector<int> suits);

/*
 * Method: flushRank
 * -------------------------------------
 * This method is used to determine the higher ranking flush between two 
 * hands that contain a flush. The method takes two vectors of integers,
 * representing the values in two separate hands. The highest value in each hand 
 * is repeatedly determined until the values are not equal to each other.
 * The higher value is the winner. A string stating the winner is returned.
 */
std::string flushRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: straight
 * --------------------------------
 * This method takes a vector of integers representing the values in a hand.
 * It determines whether or not a straight is present in the hand. A straight
 * is five cards with consecutive values.
 * If there is a straight, the method returns true. If not, it returns false.
 */
bool straight(std::vector<int> values);

/*
 * Method: straightRank
 * -------------------------------------
 * This method is used to determine the higher ranking straight between two 
 * hands that contain straights. The method takes two vectors of integers,
 * representing the values in two separate hands. The highest value in each hand
 * is determined, and the higher value is the winner. A string stating the winner is returned.
 */
std::string straightRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: threeOfAKind
 * --------------------------------
 * This method takes a vector of integers representing the values in a hand.
 * It determines whether or not three of the same value are present in the hand. 
 * If there are, the method returns true. If not, it returns false.
 */
bool threeOfAKind(std::vector<int> values);

/*
 * Method: threeOfAKindRank
 * -------------------------------------
 * This method is used to determine the higher ranking three of a kind between two 
 * hands that contain three of a kind. The method takes two vectors of integers,
 * representing the values in two separate hands. The value of each three of a kind 
 * is determined, and the higher value is the winner. A string stating the winner is returned.
 */
std::string threeOfAKindRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: twoPairs
 * --------------------------------
 * This method takes a vector of integers representing the values in a hand.
 * It determines whether or not two different pairs of the same value are present 
 * in the hand. If there are, the method returns true. If not, it returns false.
 */
bool twoPairs(std::vector<int> values);

/*
 * Method: twoPairsRank
 * -------------------------------------
 * This method is used to determine the higher ranking pairs between two 
 * hands that contain two pairs. The method takes two vectors of integers,
 * representing the values in two separate hands. The value of the higher pair 
 * is determined. If the pairs are of the same value, the other pair is compared.
 * If those are also the same, the remaining cards in the hands are compared, 
 * and the higher value is the winner. A string stating the winner is returned.
 */
std::string twoPairsRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: onePair
 * --------------------------------
 * This method takes a vector of integers representing the values in a hand.
 * It determines whether or not only two of the same value are present in the hand. 
 * If there are, the method returns true. If not, it returns false.
 */
std::pair<bool, int>  onePair(std::vector<int> values);

/*
 * Method: onePairRank
 * -------------------------------------
 * This method is used to determine the higher ranking pair between two 
 * hands that contain one pair. The method takes two vectors of integers,
 * representing the values in two separate hands. The value of each pair 
 * is determined. If the pairs are the same value, the remaining cards are 
 * compared in order of highest to lowest until they are not equal.
 * The higher value is the winner. A string stating the winner is returned.
 */
std::string onePairRank(std::vector<int> values1, std::vector<int> values2);

/*
 * Method: highCardRank
 * -------------------------------------
 * This method is used to determine the higher ranking card between two 
 * hands that contain no other ranking. The method takes two vectors of integers,
 * representing the values in two separate hands. The value of each card 
 * is determined and compared from the order of highest to lowest.
 * The higher value is the winner. A string stating the winner is returned.
 */
std::string highCardRank(std::vector<int> values1, std::vector<int> values2);


/*
 * Method: checkValues
 * -------------------------
 * This method takes a vector of strings whose elements each represent a single 
 * card in a poker hand. It checks the first character of each element, which
 * represents the face value of the card, and returns a vector of integers whose
 * elements correspond to the frequency of each value in the hand. Index 0 is 
 * the value 2 and index 12 is the value ace.
 */
std::vector<int> checkValues(std::vector<std::string> hand);

/*
 * Method: checkSuits
 * --------------------------
 * This method takes a vector of string whose elements each represent a single
 * card in a poker hand. It checks the second character of each element, which 
 * represents the suit of the card, and returns a vector of integers whose elements
 * correspond to the frequence of each suit in the hand. Index 0 is clubs, index 1
 * is diamonds, index 2 is hearts, and index 3 is spades.
 */
std::vector<int> checkSuits(std::vector<std::string> hand);

#endif
