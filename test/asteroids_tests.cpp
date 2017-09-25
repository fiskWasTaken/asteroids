#include <gtest/gtest.h>
#include <entities/WorldObject.h>
#include <entities/Asteroid.cpp>
#include <World.cpp>

TEST(asteroid, bounding_box) {
  auto asteroid = Asteroid();
  asteroid.setHeight(4);
  asteroid.setWidth(6);
  asteroid.pos.x = 10;
  asteroid.pos.y = 10;

  auto vecs = asteroid.getBoundingBox();
  EXPECT_EQ(7, vecs.first.x);
  EXPECT_EQ(8, vecs.first.y);
  EXPECT_EQ(13, vecs.second.x);
  EXPECT_EQ(12, vecs.second.y);
}

TEST(game_world, obj_wrap) {
  auto world = World(10, 10);

  auto object = new Asteroid();
  object->pos.x = 5;
  object->pos.y = 5;

  world.wrapObject(object);

  EXPECT_EQ(5, object->pos.x);

  object->pos.y = 11;
  world.wrapObject(object);

  EXPECT_EQ(1, object->pos.y);

  object->pos.y = -5;
  world.wrapObject(object);

  EXPECT_EQ(5, object->pos.y);

  object->pos.x = 13;
  world.wrapObject(object);

  EXPECT_EQ(3, object->pos.x);

  object->pos.x = -5;
  world.wrapObject(object);

  EXPECT_EQ(5, object->pos.x);
}

TEST(game_world, obj_management) {
  auto world = World(10, 10);

  auto object = Asteroid();
  auto object2 = Asteroid();

  EXPECT_TRUE(world.pushObject(&object));
  EXPECT_FALSE(world.pushObject(&object));
  EXPECT_EQ(1, world.getObjects().size());

  EXPECT_TRUE(world.pushObject(&object2));
  EXPECT_FALSE(world.pushObject(&object2));
  EXPECT_EQ(2, world.getObjects().size());

  EXPECT_TRUE(world.popObject(&object));
  EXPECT_EQ(1, world.getObjects().size());

  EXPECT_FALSE(world.popObject(&object));
  EXPECT_EQ(1, world.getObjects().size());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}