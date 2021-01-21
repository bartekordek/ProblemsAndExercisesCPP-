#pragma once

#include "Gtest.hpp"
#include "CUL/CULInterface.hpp"
#include "CUL/STL_IMPORTS/STD_vector.hpp"
#include "CUL/STL_IMPORTS/STD_unordered_map.hpp"

template <typename Type>
using vector = std::vector<Type>;

class TestWithCUL:
    public ::testing::Test
{
public:
    CUL::CULInterface* getCUL();
protected:
    static void SetUpTestCase();
    static void TearDownTestCase();
private:
    static CUL::CULInterface* s_culInterface;
};