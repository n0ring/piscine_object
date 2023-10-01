#include <gtest/gtest.h>
#include "../Account.hpp"

TEST(AccountTest, AddValue) {
    Account account(1, 0);
    account.addValue(100);
    EXPECT_EQ(account.getValue(), 100);
}

// TEST(AccountTest, RemoveValue) {
//     Account account(1, 100);
//     account.removeValue(50);
//     EXPECT_EQ(account.getValue(), 50);
// }

// TEST(AccountTest, SetId) {
//     Account account(1, 100);
//     account.setId(2);
//     EXPECT_EQ(account.getId(), 2);
// }

// TEST(AccountTest, InvalidInputValue) {
//     Account account(1, 100);
//     EXPECT_THROW(account.addValue(-50), Account::InvalidInputValue);
// }