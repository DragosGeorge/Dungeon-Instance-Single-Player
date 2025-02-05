Search:

int dungeon_new_jump_all(lua_State* L)

Add before:

int dungeon_new_jump_player(lua_State* L)
{
    if (lua_gettop(L) < 3 || !lua_isnumber(L, 1) || !lua_isnumber(L, 2) || !lua_isnumber(L, 3))
    {
        sys_err("dungeon_new_jump_player: not enough arguments");
        return 0;
    }

    long lDungeonMapIndex = (long)lua_tonumber(L, 1);
    int x = (int)lua_tonumber(L, 2);
    int y = (int)lua_tonumber(L, 3);

    LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();
    if (!ch)
    {
        sys_err("dungeon_new_jump_player: character is null");
        return 0;
    }

    LPDUNGEON pDungeon = CDungeonManager::instance().Create(lDungeonMapIndex);
    if (!pDungeon)
    {
        sys_err("dungeon_new_jump_player: cannot create dungeon %d", lDungeonMapIndex);
        return 0;
    }

    ch->SetDungeon(pDungeon);

    long realDungeonMapIndex = pDungeon->GetMapIndex();

    LPSECTREE_MAP pMap = SECTREE_MANAGER::instance().GetMap(realDungeonMapIndex);
    if (!pMap)
    {
        sys_err("dungeon_new_jump_player: cannot find map %d, dungeon not properly initialized?", realDungeonMapIndex);
        return 0;
    }

    ch->WarpSet(x * 100, y * 100, realDungeonMapIndex);

    return 0;
}

Search:

{ "new_jump_all", dungeon_new_jump_all },

Add before:

{ "new_jump_player",		dungeon_new_jump_player	},