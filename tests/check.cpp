#include <gtest/gtest.h>

TEST(check_all, 1) {
    int a = 1, b = 1;
    ASSERT_EQ(a, b);
}

TEST(check_govno, 2) {
    bool f = 1;
    ASSERT_TRUE(f);
}