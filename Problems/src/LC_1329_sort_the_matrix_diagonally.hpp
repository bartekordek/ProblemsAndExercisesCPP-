#pragma once

#include "TestWithCUL.hpp"

class LC_1329_sort_the_matrix_diagonally:
    public TestWithCUL
{
protected:

    LC_1329_sort_the_matrix_diagonally();

    virtual ~LC_1329_sort_the_matrix_diagonally();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};