#include "gtest/gtest.h"
#include "pokerHand.h"

TEST(PokerHandTest, InvalidInput) {
    // Test with invalid inputs
    EXPECT_EQ("Invalid input", bestPokerHand("2C 3D 4H 5S", "6D 7H 8S 9C"));
    EXPECT_EQ("Invalid input", bestPokerHand("2C 3D 4H", "6D 7H 8S 9C"));
    EXPECT_EQ("Invalid input", bestPokerHand("5H 9D PH 2S 5C", "4H AD 5D 3C AH"));
    EXPECT_EQ("Invalid input", bestPokerHand("9G KH 5S QH JH", "4H AD 5D 3C AH"));
    EXPECT_EQ("Invalid input", bestPokerHand("9C KH 5S QH JH JC", "4H AD 5D 3C AH"));
    EXPECT_EQ("Invalid input", bestPokerHand("9C KH 5S QH JC", "4H AD 10D 3C AH"));
}

TEST(PokerHandTest, BestStraightFlush) {
    // Test for Straight Flush
    // Two straight flushes
    EXPECT_EQ("Player 1 wins", bestPokerHand("7H 8H 9H TH JH", "2C 3C 4C 5C 6C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "KH JH QH TH 9H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "2D 4D 3D 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH JH QH TH 9H", "AD KD JD TD QD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 3C 4C 5C 6C", "7H 8H 9H TH JH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2D 3D 4D 5D 6D", "AD KD JD TD QD"));
    // Straight flush and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "9H 9D 9C 9S TS"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("9H 9D 9C 9S TS", "AD KD JD TD QD"));
    // Straight flush and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 4D 3D 5D 6D", "3S 3C 3H 7H 7D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3S 3C 3H 7H 7D", "2D 4D 3D 5D 6D"));
    // Straight flush and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "7H 4H 3H 9H AH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 4H 3H 9H AH", "AD KD JD TD QD"));
    // Straight flush and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "2C 4D 3D 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 4C 3D 5H 6H", "AD KD JD TD QD"));
    // Straight flush and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "2C 2D 2H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 7C 7D 5C 6H", "AD KD JD TD QD"));
    // Straight flush and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 7C 6D 5C 6H", "AD KD JD TD QD"));
    // Straight flush and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 7C 4D 5C 6H", "AD KD JD TD QD"));
    //Straight flush and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("AD KD JD TD QD", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("JH 7C 6D 5C KH", "AD KD JD TD QD"));
    // Equal straight flushes
    EXPECT_EQ("Tie", bestPokerHand("2C 3C 4C 5C 6C", "2D 3D 4D 5D 6D"));
    EXPECT_EQ("Tie", bestPokerHand("6C 7C 8C 9C TC", "6D 7D 8D 9D TD"));
}

TEST(PokerHandTest, BestFourOfAKind) {
    // Test for Four of a Kind
    // Two four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 3S 3D 3C 4H", "2C 2D 2H 2S 3C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 6S 6C 8D", "3H 3S 3D 3C 4H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "KH KC KD KS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 2S 3C", "3H 3S 3D 3C 4H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 3S 3D 3C 4H", "6D 6H 6S 6C 8D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH KC KD KS TH", "AC AD AH AS TC"));
    // Four of a kind and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "KH KC KD KS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 2S 3C", "2D 3D 4D 5D 6D"));
    // Four of a kind and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "KH KC KD TS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5S 5C", "3H 3S 3D 3C 4H"));
    // Four of a kind and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2D 5D TD 7D 3D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2D 5D TD 7D 3D", "3H 3S 3D 3C 4H"));
    // Four of a kind and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2D 3H 4S 5D 6C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 4C 3D 5H 6H", "3H 3S 3D 3C 4H"));
    // Four of a kind and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 2D 2H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5D 6D", "3H 3S 3D 3C 4H"));
    // Four of a kind and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 5H 5D 6D", "3H 3S 3D 3C 4H"));
    // Four of a kind and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "3H 3S 3D 3C 4H"));
    // Four of a kind and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "3H 3S 3D 3C 4H"));
}

TEST(PokerHandTest, BestFullHouse) {
    // Test for Full House
    // Two full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 3S 3D 4C 4H", "2C 2D 2H 3S 3C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 6S 8C 8D", "3H 3S 3D 4C 4H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "KH KC KD TD TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 3S 3C", "3H 3S 3D 4C 4H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 3S 3D 4C 4H", "6D 6H 6S 8C 8D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH KC KD TS TH", "AC AD AH TD TC"));
    // Full house and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "KH KC KD TS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 3S 3C", "2D 3D 4D 5D 6D"));
    // Full house and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "KH KC KD TS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5S 5C", "3H 3S 3D 3C 4H"));
    // Full house and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "2D 5D TD 7D 3D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2D 5D TD 7D 3D", "3H 3S 3D 4C 4H"));
    // Full house and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "2D 3H 4S 5D 6C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 4C 3D 5H 6H", "3H 3S 3D 4C 4H"));
    // Full house and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "2C 2D 2H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5D 6D", "3H 3S 3D 4C 4H"));
    // Full house and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 5H 5D 6D", "3H 3S 3D 4C 4H"));
    // Full house and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "3H 3S 3D 4C 4H"));
    // Full house and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH TS TC", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "3H 3S 3D 4C 4H"));
}

TEST(PokerHandTest, BestFlush) {
    // Test for Flush
    // Two flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 7H 8H KH 4H", "4D 8D 2D 3D TD"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC 2C 4C 6C 8C", "KS JS TS 5S 9S"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("4S 5S 8S 2S 9S", "4C 5C 2C 9C 7C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("4D 8D 2D 3D TD", "3H 7H 8H KH 4H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KS JS TS 5S 9S", "AC 2C 4C 6C 8C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("4C 5C 2C 8C 7C", "4S 5S 8S 2S 9S"));
    // Flush and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "3H 7H 8H KH 4H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 7H 8H KH 4H", "2D 3D 4D 5D 6D"));
    // Flush and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 6S 8C 8D", "4D 8D 2D 3D TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("4D 8D 2D 3D TD", "6D 6H 6S 8C 8D"));
    // Flush and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "KS JS TS 5S 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2D 5D TD 7D 3D", "3H 3S 3D 3C 4H"));
    // Flush and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("KS JS TS 5S 9S", "2D 3H 4S 5D 6C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("7H 4C 3D 5H 6H", "KS JS TS 5S 9S"));
    // Flush and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("KS JS TS 5S 9S", "2C 2D 2H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5D 6D", "KS JS TS 5S 9S"));
    // Flush and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("KS JS TS 5S 9S", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 5H 5D 6D", "KS JS TS 5S 9S"));
    // Flush and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("KS JS TS 5S 9S", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "KS JS TS 5S 9S"));
    // Flush and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("KS JS TS 5S 9S", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "KS JS TS 5S 9S"));
    // Two equal flushes
    EXPECT_EQ("Tie", bestPokerHand("4S 5S 8S 2S 9S", "9D 2D 8D 5D 4D"));
    EXPECT_EQ("Tie", bestPokerHand("6C 7C 9C JC AC", "6D 7D 9D JD AD"));
    
}

TEST(PokerHandTest, BestStraight) {
    // Test for Straight
    // Two straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 4S 5D 6C 7H", "2C 3D 4H 5S 6C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 7H 8S 9C TD", "3H 4S 5D 6C 7H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC KD QH JS TC", "KH QC JD TS 9H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 3D 4H 5S 6C", "3H 4S 6D 5C 7H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 4S 5D 6C 7H", "6D 7H 8S 9C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH QC JD TS 9H", "AC KD QH JS TC"));
    // Straight and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "KH QC JD TS 9H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 3D 4H 5S 6C", "2D 3D 4D 5D 6D"));
    // Straight and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "KH QC JD TS 9H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH QC JD TS 9H", "3H 3S 3D 3C 4H"));
    // Straight and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("KH KC KD TS TH", "KH QC JD TS 9H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 3D 4H 5S 6C", "3H 3S 3D 4C 4H"));
    // Straight and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("KS JS TS 5S 9S", "KH QC JD TS 9H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH QC JD TS 9H", "KS JS TS 5S 9S"));
    // Straight and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 7H 8S 9C TD", "2C 2D 2H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5D 6D", "6D 7H 8S 9C TD"));
    // Straight and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 7H 8S 9C TD", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 5H 5D 6D", "6D 7H 8S 9C TD"));
    // Straight and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 7H 8S 9C TD", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "6D 7H 8S 9C TD"));
    // Straight and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 7H 8S 9C TD", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "6D 7H 8S 9C TD"));
    // Two equal straights
    EXPECT_EQ("Tie", bestPokerHand("4S 5C 6D 7C 8S", "4D 5D 6C 7S 8H"));
    EXPECT_EQ("Tie", bestPokerHand("AC KC QH JD TS", "TD JC QD KS AH"));
}

TEST(PokerHandTest, BestThreeOfAKind) {
    // Test for Three of a Kind
    // Two three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 3S 3D 7C 4H", "2C 2D 2H 9S 3C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 6S TC 8D", "3H 3S 3D 2C 4H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH 3S TC", "KH KC KD JS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H AS 3C", "3H 3S 3D AC 4H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 3S 3D JC 4H", "6D 6H 6S TC 8D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KH KC KD 2S TH", "AC AD AH 8S TC"));
    // Three of a kind and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "KH KC KD 9S TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H TS 3C", "2D 3D 4D 5D 6D"));
    // Three of a kind and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 2D 2H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("KC KD KH 8H 6D", "3H 3S 3D 3C 4H"));
    // Three of a kind and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("KH KC KD TS TH", "2C 2D 2H TS 3C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 2H 5D 6D", "2C 2D 2H 5S 5C"));
    // Three of a kind and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 5D TD 7D 3D", "TH TC TS 6D 9D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("TH TC TS 6D 9D", "2D 5D TD 7D 3D"));
    // Three of a kind and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3H 4S 5D 6C", "TH TC TS 6D 9D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("TH TC TS 6D 9D", "7H 4C 3D 5H 6H"));
    // Three of a kind and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("TH TC TS 6D 9D", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 5H 5D 6D", "TH TC TS 6D 9D"));
    // Three of a kind and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("TH TC TS 6D 9D", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "TH TC TS 6D 9D"));
    // Three of a kind and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("TH TC TS 6D 9D", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "TH TC TS 6D 9D"));
}

TEST(PokerHandTest, BestTwoPairs) {
    // Test for two pairs
    // Two two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 3S 4D 8C 4H", "2C 2D 3H 6S 3C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 7S 7C TD", "6S 6C 7D 7H 4H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD KH KS TC", "AH AS JD JS TH"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 6S 3C", "3H 3S 4D 8C 4H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6S 6D 7D 7H 4H", "6D 6H 7S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AH AS JD JS TH", "AC AD KH KS TC"));
    // Two pairs and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "6D 6H 7S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D 6H 7S 7C TD", "2D 3D 4D 5D 6D"));
    // Two pairs and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 2D 5H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AC AD KH KS TC", "3H 3S 3D 3C 4H"));
    // Two pairs and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("KH KC KD TS TH", "6D 6H 7S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AC AD KH KS TC", "2C 2D 2H 5S 5C"));
    // Two pairs and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 5D TD 7D 3D", "AC AD KH KS TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D 6H 7S 7C TD", "2D 5D TD 7D 3D"));
    // Two pairs and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3H 4S 5D 6C", "6D 6H 7S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AC AD KH KS TC", "7H 4C 3D 5H 6H"));
    // Two pairs and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("2C 2D 2H 5D 6D", "AC AD KH KS TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D 6H 7S 7C TD", "2C 2D 2H 5D 6D"));
    // Two pairs and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 7S 7C TD", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "6D 6H 7S 7C TD"));
    // Two pairs and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD KH KS TC", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "AC AD KH KS TC"));
    // Two equal two pairs
    EXPECT_EQ("Tie", bestPokerHand("4S 4C 6D 6C TS", "4D 4H 6H 6S TH"));
    EXPECT_EQ("Tie", bestPokerHand("KH KC QH QD 9S", "9D QC QS KS KD"));
}


TEST(PokerHandTest, BestOnePair) {
    // Test for one pair
    // Two one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 3S 5D 8C 4H", "2C 2D 3H 6S 8C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D 6H 9S 7C TD", "6S 6C 9D 7H 4H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD KH 3S TC", "AH AS TD 2S KD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 6S 8C", "3H 3S 4D 8C 5H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6S 6C 9D 7H 4H", "6D 6H 9S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AH AS TD 2S KD", "AC AD KH 3S TC"));
    // One pair and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "AC AD KH 3S TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AC AD KH 3S TC", "2D 3D 4D 5D 6D"));
    // One pair and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 2D 3H 5D 6D"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 5D 6D", "3H 3S 3D 3C 4H"));
    // One pair and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("KH KC KD TS TH", "6D 6H 9S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 6S 8C", "2C 2D 2H 5S 5C"));
    // One pair and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 5D TD 7D 3D", "2C 2D 3H 6S 8C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 2D 3H 6S 8C", "2D 5D TD 7D 3D"));
    // One pair and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3H 4S 5D 6C", "6D 6H 9S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 3S 5D 8C 4H", "7H 4C 3D 5H 6H"));
    // One pair and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("2C 2D 2H 5D 6D", "2C 2D 3H 6S 8C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D 6H 9S 7C TD", "2C 2D 2H 5D 6D"));
    // One pair and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("2C 2D 5H 5D 6D", "AC AD KH 3S TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H 3S 5D 8C 4H", "2C 2D 5H 5D 6D"));
    // One pair and high card
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H 3S 5D 8C 4H", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 7D 5H TD 9S", "AC AD KH 3S TC"));
    // Two equal pairs
    EXPECT_EQ("Tie", bestPokerHand("4S 4C 9D 6C TS", "4D 4H 9H 6S TH"));
    EXPECT_EQ("Tie", bestPokerHand("KH 4C QH QD 9S", "9D QC QS KS 4D"));
}

TEST(PokerHandTest, BestHighCard) {
    // Test for High Card
    // Two high cards
    EXPECT_EQ("Player 1 wins", bestPokerHand("3H TS 5D 8C 4H", "2C 5D 3H 6S 8C"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("6D KH 9S 7C TD", "6S KC 9D 7H 4H"));
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC JD KH 3S TC", "AH JS TD 2S KD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 5D 3H 6S 8C", "3H TS 4D 8C 5H"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6S KC 9D 7H 4H", "6D KH 9S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("AH JS TD 2S KD", "AC JD KH 3S TC"));
    // High card and straight flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3D 4D 5D 6D", "AC JD KH 3S TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D KH 9S 7C TD", "2D 3D 4D 5D 6D"));
    // High card and four of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("AC AD AH AS TC", "2C 7D 5H TD 9S"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D KH 9S 7C TD", "3H 3S 3D 3C 4H"));
    // High card and full house
    EXPECT_EQ("Player 1 wins", bestPokerHand("KH KC KD TS TH", "6D KH 9S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H TS 5D 8C 4H", "2C 2D 2H 5S 5C"));
    // High card and flush
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 5D TD 7D 3D", "2C 4D TH 6S 8C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("2C 5D 3H 6S 8C", "2D 5D TD 7D 3D"));
    // High card and straight
    EXPECT_EQ("Player 1 wins", bestPokerHand("2D 3H 4S 5D 6C", "6D 3H 9S 7C TD"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H KS 5D 8C 4H", "7H 4C 3D 5H 6H"));
    // High card and three of a kind
    EXPECT_EQ("Player 1 wins", bestPokerHand("2C 2D 2H 5D 6D", "2C JD 3H 6S 8C"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("6D AH 9S 7C TD", "2C 2D 2H 5D 6D"));
    // High card and two pairs
    EXPECT_EQ("Player 1 wins", bestPokerHand("2C 2D 5H 5D 6D", "AC 7D KH 3S TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H AS 5D 8C 4H", "2C 2D 5H 5D 6D"));
    // High card and one pair
    EXPECT_EQ("Player 1 wins", bestPokerHand("2C 8D 5H 5D 6D", "AC 7D KH 3S TC"));
    EXPECT_EQ("Player 2 wins", bestPokerHand("3H AS 5D 8C 4H", "2C 2D 9H 5D 6D"));
    // Two equal high cards
    EXPECT_EQ("Tie", bestPokerHand("4S KC 9D 6C TS", "4D KH 9H 6S TH"));
    EXPECT_EQ("Tie", bestPokerHand("KH 4C QH 5D 9S", "9D 5C QS KS 4D"));
}

// Test case for handleInput function
TEST(PokerHandTest, HandleInput) {
    // Valid input
  EXPECT_EQ((std::vector<std::string>{"2C", "3C", "4C", "5C", "6C"}), (handleInput("2C 3C 4C 5C 6C")));

    // Input with less than 5 cards
  EXPECT_EQ((std::vector<std::string>{"2C", "3C"}), (handleInput("2C 3C")));

    // Input with more than 5 cards
  EXPECT_EQ((std::vector<std::string>{"2C", "3D", "4H", "5S", "6C", "9H"}), (handleInput("2C 3D 4H 5S 6C 9H")));

    // Input with invalid card format
  EXPECT_EQ((std::vector<std::string>{"2C", "3D", "4H", "5S"}), (handleInput("2C 3D 4H 5S 10C")));
}

// Test case for checkValues function
TEST(PokerHandTest, CheckValues) {
    // Valid input
  EXPECT_EQ((std::vector<int>{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}), (checkValues({"2C", "3C", "4C", "5C", "6C"})));
  EXPECT_EQ((std::vector<int>{0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1}), (checkValues({"3C", "7C", "9C", "QH", "AD"})));

    // Valid input with multiple cards of the same value
  EXPECT_EQ((std::vector<int>{1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}), (checkValues({"2C", "3C", "4C", "4D", "5C"})));
  EXPECT_EQ((std::vector<int>{0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 1, 0, 0}), (checkValues({"7C", "7H", "7D", "7S", "QC"})));
  EXPECT_EQ((std::vector<int>{0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 2, 0}), (checkValues({"8C", "TC", "JC", "KD", "KC"})));

    // Invalid input with an invalid card format
  EXPECT_EQ((std::vector<int>{}), (checkValues({"2C", "3C", "4C", "5C", "XC"})));
  EXPECT_EQ((std::vector<int>{}), (checkValues({"2C", "3C", "10C", "5C", "3D"})));
  EXPECT_EQ((std::vector<int>{}), (checkValues({"2C", "3C", "9C", "5Q", "3D"})));
}

// Test case for checkSuits function
TEST(PokerHandTest, CheckSuits) {
    // Valid input
  EXPECT_EQ((std::vector<int>{5, 0, 0, 0}), (checkSuits({"2C", "3C", "4C", "5C", "6C"})));
  EXPECT_EQ((std::vector<int>{4, 1, 0, 0}), (checkSuits({"2C", "3C", "4C", "4D", "5C"})));
  EXPECT_EQ((std::vector<int>{0, 0, 3, 2}), (checkSuits({"2H", "3S", "4H", "4S", "5H"})));
  EXPECT_EQ((std::vector<int>{1, 1, 1, 2}), (checkSuits({"2S", "3H", "4D", "4S", "5C"})));

    // Invalid input with an invalid card format
  EXPECT_EQ((std::vector<int>{}), (checkSuits({"2C", "3C", "4C", "5C", "3P"})));
  EXPECT_EQ((std::vector<int>{}), (checkSuits({"2C", "3C", "4C", "5C", "10C"})));
  EXPECT_EQ((std::vector<int>{}), (checkValues({"2C", "FC", "8C", "5C", "3D"})));
}

// Test case for handRank function
TEST(PokerHandTest, HandRank) {
    // Straight Flush
    EXPECT_EQ(0, handRank({5, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));

    // Four of a Kind
    EXPECT_EQ(1, handRank({1, 2, 2, 0}, {0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0}));

    // Full House
    EXPECT_EQ(2, handRank({3, 0, 1, 1}, {0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0}));

    // Flush
    EXPECT_EQ(3, handRank({0, 5, 0, 0}, {0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0}));

    // Straight
    EXPECT_EQ(4, handRank({2, 1, 1, 1}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));

    // Three of a Kind
    EXPECT_EQ(5, handRank({1, 3, 1, 0}, {0, 0, 0, 0, 3, 0, 1, 0, 1, 0, 0, 0, 0}));

    // Two Pairs
    EXPECT_EQ(6, handRank({2, 0, 2, 1}, {2, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0}));

    // One Pair
    EXPECT_EQ(7, handRank({0, 4, 1, 0}, {0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1}));

    // High Card
    EXPECT_EQ(8, handRank({1, 2, 1, 1}, {1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0}));
}

// Test case for straightFlush function
TEST(PokerHandTest, StraightFlush) {
    // Valid Straight Flush
    EXPECT_TRUE(straightFlush({5, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));

    // Not a Straight Flush
    EXPECT_FALSE(straightFlush({5, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0}));

    // Not a Straight Flush with different suits
    EXPECT_FALSE(straightFlush({4, 0, 1, 0}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));
}

// Test case for fourOfAKind function
TEST(PokerHandTest, FourOfAKind) {
    // Valid Four of a Kind
    EXPECT_TRUE(fourOfAKind({0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0}));

    // Not a Four of a Kind
    EXPECT_FALSE(fourOfAKind({0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));
    EXPECT_FALSE(fourOfAKind({0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 0}));
}

// Test case for fullHouse function
TEST(PokerHandTest, FullHouse) {
    // Valid Full House
    EXPECT_TRUE(fullHouse({0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0}));

    //  Not a Full House
    EXPECT_FALSE(fullHouse({0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));
    EXPECT_FALSE(fullHouse({0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0}));
}

// Test case for flush function
TEST(PokerHandTest, Flush) {
    // Valid Flush
    EXPECT_TRUE(flush({5, 0, 0, 0}));

    // Not a Flush
    EXPECT_FALSE(flush({4, 0, 1, 0}));
    EXPECT_FALSE(flush({1, 1, 1, 2}));
}

// Test case for straight function
TEST(PokerHandTest, Straight) {
    //Valid Straight
    EXPECT_TRUE(straight({0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0}));

    // Not a Straight
    EXPECT_FALSE(straight({0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0}));
    EXPECT_FALSE(straight({0, 0, 2, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0}));
}

// Test case for threeOfAKind function
TEST(PokerHandTest, ThreeOfAKind) {
    // Valid Three of a Kind
    EXPECT_TRUE(threeOfAKind({0, 0, 0, 0, 3, 0, 0, 0, 1, 1, 0, 0, 0}));

    // Not a Three of a Kind
    EXPECT_FALSE(threeOfAKind({0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0}));
    EXPECT_FALSE(threeOfAKind({0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 0, 1, 0}));
}

// Test case for twoPairs function
TEST(PokerHandTest, TwoPairs) {
    // Valid Two Pairs
    EXPECT_TRUE(twoPairs({0, 0, 0, 0, 2, 2, 0, 0, 1, 0, 0, 0, 0}));

    // Test case 2: Not Two Pairs
    EXPECT_FALSE(twoPairs({0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0}));
    EXPECT_FALSE(twoPairs({0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3}));
}

// Test case for onePair function
TEST(PokerHandTest, OnePair) {
    // Valid One Pair
    EXPECT_EQ(std::make_pair(true, 4), onePair({1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 1}));

    // Not One Pair
    EXPECT_EQ(std::make_pair(false, -1), onePair({0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0}));
    EXPECT_EQ(std::make_pair(false, -1), onePair({0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 0, 0, 0}));
}
