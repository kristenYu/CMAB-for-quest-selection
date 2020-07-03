cmake_minimum_required(VERSION 3.16)
project(AI_Director_Prototype)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Enums)
include_directories(Structs)

add_executable(AI_Director_Prototype
    Enums/Actions.h
    Enums/Creatures.h
    Enums/GatheredResources.h
    Enums/Locations.h
    Enums/NaturalResources.h
    Enums/RawMaterials.h
    Enums/RefinedResource.h
    Structs/ActionStruct.h
    Structs/EquippableItemStruct.h
    Structs/SchematicStruct.h
    Actions.cpp
    ActionUtils.cpp
    ActionUtils.h
    EquippableItemsList.cpp
    EquippableItemsList.h
    Game.cpp
    Game.h
    main.cpp
    Operators.cpp
    Operators.h
    Player.cpp
    Player.h
    PlayerModel.cpp
    PlayerModel.h
    SchematicList.cpp
    SchematicList.h)
