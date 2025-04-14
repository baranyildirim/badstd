
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "badstd/string.h"

TEST(SplitTest, SplitIpV4) {
  const std::string ipV4Str = "127.0.0.1";
  EXPECT_THAT(split<std::vector<std::string>>(ipV4Str, "\\."),
              testing::Eq(std::vector<std::string>{"127", "0", "0", "1"}));
}

TEST(SplitTest, SplitIpV4StrTok) {
  std::string ipV4Str = "127.0.0.1";
  EXPECT_THAT(strtok_split<std::vector<std::string>>(ipV4Str, "."),
              testing::Eq(std::vector<std::string>{"127", "0", "0", "1"}));
}
