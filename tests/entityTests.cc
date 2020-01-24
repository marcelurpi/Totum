#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "src/lib/component.h"
#include "src/lib/entityManager.h"

class EntityTests : public ::testing::Test
{
protected:
    EntityType type;
    std::shared_ptr<Entity> entity;

    EntityTests() : type(EntityType("")) { entity = Entity::create(type); }
};

class MockComponent : public Component
{
public:
    MockComponent() : Component("Mock", 0) {}
    MOCK_METHOD(void, update, (), (override));
    MOCK_METHOD(std::shared_ptr<Component>, clone, (), (override));
};

TEST_F(EntityTests, Created_Has_Entity_Type)
{
    type = EntityType("Grass");
    type.addComponent<GrowthComponent>(0);

    entity = Entity::create(type);

    auto entityType = entity->getEntityType();
    EXPECT_EQ("Grass", entityType.getName());
    EXPECT_EQ(typeid(GrowthComponent),
              typeid(*(entityType.getComponents()[0])));
}

TEST_F(EntityTests, Created_Has_Entity_Type_Name)
{
    entity = Entity::create(EntityType("Grass"));

    EXPECT_EQ("Grass", entity->getName());
}

TEST_F(EntityTests, Created_Has_Entity_Type_Components)
{
    type.addComponent<GrowthComponent>(0);

    entity = Entity::create(type);

    EXPECT_EQ(typeid(GrowthComponent), typeid(*(entity->getComponents()[0])));
}

TEST_F(EntityTests, AddComponent_Adds_Component_Given)
{
    entity->addComponent<GrowthComponent>(0);

    EXPECT_EQ(typeid(GrowthComponent), typeid(*(entity->getComponents()[0])));
}

TEST_F(EntityTests, Update_Calls_Update_On_Components)
{
    auto component = std::make_shared<MockComponent>();
    entity->injectComponent(component);

    EXPECT_CALL(*component, update());

    entity->update();
}
