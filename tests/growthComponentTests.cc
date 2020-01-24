#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "src/lib/entityManager.h"

class GrowthComponentTests : public ::testing::Test
{
protected:
    std::shared_ptr<EntityManager> manager;
    std::shared_ptr<GrowthComponent> growth;

    GrowthComponentTests()
    {
        manager = EntityManager::createEmptyInstance();
        auto entity = manager->createEntity(EntityType(""));
        growth = entity->addComponent<GrowthComponent>(0);
    }
};

TEST_F(GrowthComponentTests, Value_Starts_At_0)
{
    EXPECT_EQ(0, growth->getValue());
}

TEST_F(GrowthComponentTests, Add_Growth_20_Increments_Value_By_20)
{
    growth->addGrowth(20);

    EXPECT_EQ(20, growth->getValue());
}

TEST_F(GrowthComponentTests, Add_Growth_100_Spreads_1_Increments_Entities_By_1)
{
    growth->addGrowth(100);

    EXPECT_EQ(2, manager->getAllEntities().size());
}

TEST_F(GrowthComponentTests, Spread_1_Increments_Entities_By_1)
{
    growth->spread(1);

    EXPECT_EQ(2, manager->getAllEntities().size());
}

TEST_F(GrowthComponentTests, Update_Adds_Value_To_Add_On_Update)
{
    growth = std::make_shared<GrowthComponent>(20);

    growth->update();

    EXPECT_EQ(20, growth->getValue());
}
