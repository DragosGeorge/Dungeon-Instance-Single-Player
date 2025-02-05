# Dungeon-Instance-Single-Player

`dungeon_new_jump_player` is a C++ function used in the Metin2 server source to create a private dungeon instance for a single player and teleport them to the specified coordinates.

## How It Works?
The function can be called using the following line of code in Lua scripts:
```lua
d.new_jump_player(DUNGEON_MAP_INDEX, x, y)
```
Where:
- `DUNGEON_MAP_INDEX` represents the index of the dungeon map to be created.
- `x` and `y` are the coordinates where the player will be teleported within the dungeon.

This creates a separate dungeon instance exclusively for the player and moves them to the specified location.

Don't forget to add the function in quest_function

d.new_jump_player


