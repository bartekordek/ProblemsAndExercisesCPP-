#include "LC_1436_destination_city.hpp"
#include "CUL/CULInterface.hpp"

using string = std::string;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_set<string> someSet;
        for( const auto& path: paths )
        {
            someSet.insert( path[0] );
        }

        for( const auto& path: paths )
        {
            auto it = someSet.find( path[1] );
            if( it == someSet.end() )
            {
                return path[1];
            }
        }

        return "";
    }
};

LC_1436_destination_city::LC_1436_destination_city()
{
}

void LC_1436_destination_city::SetUp()
{
}

void LC_1436_destination_city::TestBody()
{

}

void LC_1436_destination_city::SetUpTestCase()
{
    TestWithCUL::SetUpTestCase();
}

void LC_1436_destination_city::TearDownTestCase()
{
    TestWithCUL::TearDownTestCase();
}

TEST_F( LC_1436_destination_city, Test00 )
{
    Solution solution;
    vector < vector<string>> input = {
        {"B", "C"},
        {"D", "B"},
        {"C", "A"} };
    auto res = solution.destCity( input );
    GTEST_ASSERT_EQ( "A", res );
}

TEST_F( LC_1436_destination_city, Test01 )
{
    Solution solution;
    vector < vector<string>> input = {
        {"London","New York"},
        { "New York","Lima" },
        { "Lima","Sao Paulo" } };
    auto res = solution.destCity( input );
    GTEST_ASSERT_EQ( "Sao Paulo", res );
}

LC_1436_destination_city::~LC_1436_destination_city()
{

}

void LC_1436_destination_city::TearDown()
{

}