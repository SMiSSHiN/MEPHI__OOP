#include "vector_D.h"
#include "gtest/gtest.h" 

using namespace Data_Types;

TEST(VectorConstructor, TestException)
{   
    ASSERT_NO_THROW(Vector a());
    ASSERT_NO_THROW(Vector a(10));
    ASSERT_NO_THROW(Vector a(20));
    ASSERT_NO_THROW(Vector a(10, 100));
    ASSERT_NO_THROW(Vector a(99, 99));
    ASSERT_NO_THROW(Vector a(100));

    ASSERT_THROW(Vector a(101), std::bad_alloc);
    ASSERT_THROW(Vector a(1000), std::bad_alloc);
    ASSERT_THROW(Vector a(-1), std::runtime_error);

    int *ar;

    ASSERT_THROW(Vector a(ar, -1), std::runtime_error);
    ASSERT_THROW(Vector a(ar, 101), std::bad_alloc);
    ASSERT_THROW(Vector a(ar, 1000), std::bad_alloc);
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
