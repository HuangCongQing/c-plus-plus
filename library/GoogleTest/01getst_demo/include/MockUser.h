/*
 * @Description: 
 * @Author: HCQ
 * @Company(School): UCAS
 * @Email: 1756260160@qq.com
 * @Date: 2023-03-02 16:15:15
 * @LastEditTime: 2023-03-02 16:31:17
 * @FilePath: /c-plus-plus/library/GoogleTest/01getst_demo/include/MockUser.h
 */

#include "User.h"
#include <gmock/gmock.h>

class MockUser: public User{
public:
    // 模拟函数实行
    MOCK_METHOD(int, getAge1, (), (override));
};
