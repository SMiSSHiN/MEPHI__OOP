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

TEST(VectorMethods, TestException)
{   
    Vector a;

    ASSERT_NO_THROW(a.setSize(0));
    ASSERT_NO_THROW(a.setSize(15));
    ASSERT_NO_THROW(a.setSize(99));

    ASSERT_THROW(a.setSize(101), std::bad_alloc);
    ASSERT_THROW(a.setSize(1000), std::bad_alloc);
    ASSERT_THROW(a.setSize(-1), std::runtime_error);
    ASSERT_THROW(a.setSize(-1000), std::runtime_error);
}

TEST(VectorMethods, Functions)
{
    Vector a;

    ASSERT_NE(0, a.max());
    ASSERT_NE(100, a.max());

    Vector b(3, 100);
    
    ASSERT_EQ(100, b.max());
    ASSERT_NE(-1, b.max());

    int ar[15];
    for(int i = 0; i < 15; i++)
        ar[i] = i * 15;
    
    Vector c(ar, 15);

    ASSERT_EQ(14 * 15, c.max());
    ASSERT_NE(15 * 15, c.max());
    ASSERT_NE(13 * 15, c.max());
}

int main(int argc, char *argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
