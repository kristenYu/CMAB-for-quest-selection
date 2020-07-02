cmake_minimum_required(VERSION 3.16)
project(AI_Director_Prototype)

set(CMAKE_CXX_STANDARD 14)

add_executable(AI_Director_Prototype main.cpp Actions.cpp ActionUtils.cpp ActionUtils.h PlayerModel.cpp PlayerModel.h Player.cpp Player.h Enums/Locations.h Operators.cpp Operators.h Enums/Creatures.h Enums/RawMaterials.h Game.cpp Game.h Enums/NaturalResources.h Enums/GatheredResources.h Structs/ActionStruct.h Enums/RefinedResource.h Structs/EquippableItemStruct.h Structs/SchematicStruct.h SchematicList.cpp SchematicList.h EquippableItemsList.cpp EquippableItemsList.h)