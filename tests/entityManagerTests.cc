#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "src/lib/entityManager.h"

class EntityManagerTests : public ::testing::Test
{
protected:
    std::shared_ptr<EntityManager> manager;

    EntityManagerTests() { manager = EntityManager::createEmptyInstance(); }
};

TEST_F(EntityManagerTests, Starts_Without_Entities)
{
    EXPECT_EQ(0, manager->getAllEntities().size());
}

TEST_F(EntityManagerTests, Create_Entity_Increments_Entities_Size_By_1)
{
    manager->createEntity(EntityType(""));

    EXPECT_EQ(1, manager->getAllEntities().size());
}

TEST_F(EntityManagerTests, Create_Entity_With_Type_Sets_Entity_Type)
{
    manager->createEntity(EntityType("Grass"));

    EXPECT_EQ("Grass", (manager->getAllEntities()[0])->getName());
}

TEST_F(EntityManagerTests, Create_Entities_With_2_Increments_Entities_Size_By_2)
{
    manager->createEntities(EntityType(""), 2);

    EXPECT_EQ(2, manager->getAllEntities().size());
}

TEST_F(EntityManagerTests, Destroy_Entity_Decrements_Entities_By_1)
{
    auto entity = manager->createEntity(EntityType(""));

    manager->destroyEntity(entity);

    EXPECT_EQ(0, manager->getAllEntities().size());
}

TEST_F(EntityManagerTests, Get_Entity_By_Name_Returns_Entity_Found)
{
    manager->createEntity(EntityType("Grass"));

    auto entity = manager->getEntityByName("Grass");

    EXPECT_EQ("Grass", entity->getName());
}

TEST_F(EntityManagerTests, Get_Entity_By_Name_Returns_Nullptr_If_Not_Found)
{
    auto entity = manager->getEntityByName("Grass");

    EXPECT_EQ(nullptr, entity);
}
