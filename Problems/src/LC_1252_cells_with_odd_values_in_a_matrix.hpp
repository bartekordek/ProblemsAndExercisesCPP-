#pragma once

#include "TestWithCUL.hpp"

class LC_1252_cells_with_odd_values_in_a_matrix:
    public TestWithCUL
{
protected:

    LC_1252_cells_with_odd_values_in_a_matrix();

    virtual ~LC_1252_cells_with_odd_values_in_a_matrix();

    static void SetUpTestCase();
    static void TearDownTestCase();
    void SetUp() override;
    void TearDown() override;
    void TestBody() override;
private:

};