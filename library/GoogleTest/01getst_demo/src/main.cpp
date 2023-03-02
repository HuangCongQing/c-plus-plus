/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2023-03-02 14:56:32
 * @LastEditTime: 2023-03-02 16:35:45
 * @FilePath: /c-plus-plus/library/GoogleTest/01getst_demo/src/main.cpp
 */
#include <iostream>
#include <gtest/gtest.h>

// 
int add(int a, int b){
  return a+b;
}

// gtest
TEST(testCase1, should_3_get){
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(2, 1), 3);
}

TEST(testCase2, should_4_get){
  EXPECT_EQ(add(1, 2), 3);
  EXPECT_EQ(add(2, 1), 3);
  EXPECT_EQ(add(1, 2), 4);
}

// gmock
#include "MockUser.h"
#include <gmock/gmock.h>
TEST(testCase3, test){
  MockUser user;
  EXPECT_CALL(user, getAge1).
                          Times(::testing::AtLeast(3)). // 至少调用三次
                          WillOnce(::testing::Return(200)).
                          WillOnce(::testing::Return(300)).
                          WillOnce(::testing::Return(400)).
                          WillOnce(::testing::Return(500)).
                          WillRepeatedly(::testing::Return(555)); // 调用多次

  // 调用6次
  std::cout<<user.getAge1()<<std::endl;
  std::cout<<user.getAge1()<<std::endl;
  std::cout<<user.getAge1()<<std::endl;
  std::cout<<user.getAge1()<<std::endl;
  std::cout<<user.getAge1()<<std::endl;
  std::cout<<user.getAge1()<<std::endl;
}


// Gtest固定写法
int main(int argc, char **argv) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();   
}
