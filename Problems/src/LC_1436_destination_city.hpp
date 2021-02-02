#pragma once

#include "TestWithCUL.hpp"

class LC_1436_destination_city:
    public TestWithCUL
{
protected:

    LC_1436_destination_city();

    virtual ~LC_1436_destination_city();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};