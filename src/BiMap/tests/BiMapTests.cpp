#include "gtest/gtest.h"
#include "BiMap.h"

TEST(BiMap, AccessNotExistingT) {
	BiMap<int, int> bm;
	try {
		bm.atT(0);
		FAIL() << "Expected an std::out_of_range exception to be thrown when accessing a non-existant key T";
	} catch(std::out_of_range) {}
}

TEST(BiMap, AccessNotExistingU) {
	BiMap<int, int> bm;
	try {
		bm.atU(0);
		FAIL() << "Expected an std::out_of_range exception to be thrown when accessing a non-existant key T";
	} catch(std::out_of_range) {}
}

TEST(BiMap, InsertionToEmptyBiMap) {
	BiMap<int, int> bm;
	EXPECT_TRUE(bm.insert(0, 0)) << "Failed to insert an element to an empty BiMap";
}

TEST(BiMap, ValidInsertion) {
	BiMap<int, int> bm;
	ASSERT_TRUE(bm.insert(0, 0)) << "Failed to insert an element to an empty BiMap";
	EXPECT_TRUE(bm.insert(1, 1)) << "Failed to insert a second element to the BiMap";;
}

TEST(BiMap, AccessExistingT) {
	BiMap<int, int> bm;
	ASSERT_TRUE(bm.insert(3, 7)) << "Failed to insert an element to an empty BiMap";
	EXPECT_EQ(bm.atT(3), 7);
}

TEST(BiMap, AccessExistingU) {
	BiMap<int, int> bm;
	ASSERT_TRUE(bm.insert(3, 7)) << "Failed to insert an element to an empty BiMap";
	EXPECT_EQ(bm.atU(7), 3);
}

TEST(BiMap, ConflictInsertionPair) {
	BiMap<int, int> bm;
	ASSERT_TRUE(bm.insert(0, 0)) << "Failed to insert an element to an empty BiMap";
	EXPECT_FALSE(bm.insert(0, 0)) << "Insert on an already existing pair was successful";
}

TEST(BiMap, ConflictInsertionT) {
	BiMap<int, int> bm;
	ASSERT_TRUE(bm.insert(0, 0)) << "Failed to insert an element to an empty BiMap";
	EXPECT_FALSE(bm.insert(0, 1)) << "Insert on a pair with an existing T was successful";
}

TEST(BiMap, ConflictInsertionU) {
	BiMap<int, int> bm;
	ASSERT_TRUE(bm.insert(0, 0)) << "Failed to insert an element to an empty BiMap";
	EXPECT_FALSE(bm.insert(1, 0)) << "Insert on a pair with an existing U was successful";
}
