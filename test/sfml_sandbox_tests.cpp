#include <gtest/gtest.h>
#include "GameBoard.h"

using namespace std;

TEST(test_case_name, test_name) {
  auto board = new GameBoard(8, 8);
  EXPECT_EQ(1, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}