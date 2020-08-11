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
        Objects/ActionUtils.cpp
        Objects/ActionUtils.h
        Objects/EquippableItemsList.cpp
        Objects/EquippableItemsList.h
    Game.cpp
    Game.h
    main.cpp
        Player.cpp
    Player.h
    PlayerModel.cpp
    PlayerModel.h
        Objects/SchematicList.cpp
        Objects/SchematicList.h Objects/BuildingsList.cpp Objects/BuildingsList.h Objects/BlueprintsList.cpp Objects/BlueprintsList.h Structs/BlueprintStruct.h Structs/BuildingStruct.h AIDirector.cpp AIDirector.h Objects/SelfGoalsList.cpp Objects/SelfGoalsList.h Structs/SelfGoalStruct.h Enums/QuestCategory.h Objects/ObjectivesGenerator.cpp Objects/ObjectivesGenerator.h Structs/ObjectiveStruct.h Enums/AIDirectorBehavior.h Objects/Merchant.cpp Objects/Merchant.h Enums/Consumables.h)
