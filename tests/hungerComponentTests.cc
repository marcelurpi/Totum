#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "src/lib/entityManager.h"

class HungerComponentTests : public ::testing::Test
{
protected:
    std::shared_ptr<EntityManager> manager;
    std::shared_ptr<HungerComponent> hunger;

    HungerComponentTests()
    {
        manager = EntityManager::createEmptyInstance();

        auto entity = manager->createEntity(EntityType(""));
        hunger = entity->addComponent<HungerComponent>(0);

        manager->createEntity(EntityType("Grass"));
    }
};

TEST_F(HungerComponentTests, Value_Starts_At_0)
{
    EXPECT_EQ(0, hunger->getValue());
}

TEST_F(HungerComponentTests, Add_Hunger_20_Increments_Value_By_20)
{
    hunger->addHunger(20);

    EXPECT_EQ(20, hunger->getValue());
}

TEST_F(HungerComponentTests, Add_Hunger_100_Starves_Decrements_Entities_By_1)
{
    hunger->addHunger(100);

    EXPECT_EQ(1, manager->getAllEntities().size());
}

TEST_F(HungerComponentTests, Add_Hunger_50_Eats_1_Decrements_Entities_By_1)
{
    hunger->addHunger(50);

    EXPECT_EQ(1, manager->getAllEntities().size());
}

TEST_F(HungerComponentTests, Eat_1_Decrements_Entities_By_1)
{
    hunger->eat(1);

    EXPECT_EQ(1, manager->getAllEntities().size());
}

TEST_F(HungerComponentTests, Update_Adds_Value_To_Add_On_Update)
{
    hunger = std::make_shared<HungerComponent>(20);

    hunger->update();

    EXPECT_EQ(20, hunger->getValue());
}
