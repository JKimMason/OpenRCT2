#pragma region Copyright (c) 2014-2017 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#include "../common.h"
#include "map.h"
#include "scenery.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    SMALL_SCENERY_FLAG_FULL_TILE            = (1 << 0),  // 0x1
    SMALL_SCENERY_FLAG_VOFFSET_CENTRE       = (1 << 1),  // 0x2
    SMALL_SCENERY_FLAG_REQUIRE_FLAT_SURFACE = (1 << 2),  // 0x4
    SMALL_SCENERY_FLAG_ROTATABLE            = (1 << 3),  // 0x8; when set, user can set rotation, otherwise rotation is automatic
    SMALL_SCENERY_FLAG_ANIMATED             = (1 << 4),  // 0x10
    SMALL_SCENERY_FLAG_CAN_WITHER           = (1 << 5),  // 0x20
    SMALL_SCENERY_FLAG_CAN_BE_WATERED       = (1 << 6),  // 0x40
    SMALL_SCENERY_FLAG_ANIMATED_FG          = (1 << 7),  // 0x80
    SMALL_SCENERY_FLAG_DIAGONAL             = (1 << 8),  // 0x100
    SMALL_SCENERY_FLAG_HAS_GLASS            = (1 << 9),  // 0x200
    SMALL_SCENERY_FLAG_HAS_PRIMARY_COLOUR   = (1 << 10), // 0x400
    SMALL_SCENERY_FLAG_FOUNTAIN_SPRAY_1     = (1 << 11), // 0x800
    SMALL_SCENERY_FLAG_FOUNTAIN_SPRAY_4     = (1 << 12), // 0x1000
    SMALL_SCENERY_FLAG_IS_CLOCK             = (1 << 13), // 0x2000
    SMALL_SCENERY_FLAG_SWAMP_GOO            = (1 << 14), // 0x4000
    SMALL_SCENERY_FLAG_HAS_FRAME_OFFSETS    = (1 << 15), // 0x8000
    SMALL_SCENERY_FLAG17                    = (1 << 16), // 0x10000
    SMALL_SCENERY_FLAG_STACKABLE            = (1 << 17), // 0x20000; means scenery item can be placed in the air and over water
    SMALL_SCENERY_FLAG_NO_WALLS             = (1 << 18), // 0x40000
    SMALL_SCENERY_FLAG_HAS_SECONDARY_COLOUR = (1 << 19), // 0x80000
    SMALL_SCENERY_FLAG_NO_SUPPORTS          = (1 << 20), // 0x100000
    SMALL_SCENERY_FLAG_VISIBLE_WHEN_ZOOMED  = (1 << 21), // 0x200000
    SMALL_SCENERY_FLAG_COG                  = (1 << 22), // 0x400000
    SMALL_SCENERY_FLAG_BUILD_DIRECTLY_ONTOP = (1 << 23), // 0x800000; means supports can be built on this object. Used for base blocks.
    SMALL_SCENERY_FLAG_HALF_SPACE           = (1 << 24), // 0x1000000
    SMALL_SCENERY_FLAG_THREE_QUARTERS       = (1 << 25), // 0x2000000
    SMALL_SCENERY_FLAG_PAINT_SUPPORTS       = (1 << 26), // 0x4000000; used for scenery items which are support structures
    SMALL_SCENERY_FLAG27                    = (1 << 27), // 0x8000000
}
SMALL_SCENERY_FLAGS;

sint32 scenery_small_get_primary_colour(const rct_tile_element * tileElement);
sint32 scenery_small_get_secondary_colour(const rct_tile_element * tileElement);
void scenery_small_set_primary_colour(rct_tile_element * tileElement, uint32 colour);
void scenery_small_set_secondary_colour(rct_tile_element * tileElement, uint32 colour);
bool scenery_small_get_supports_needed(const rct_tile_element * tileElement);
void scenery_small_set_supports_needed(rct_tile_element * tileElement);

bool scenery_small_entry_has_flag(const rct_scenery_entry * sceneryEntry, uint32 flags);

#ifdef __cplusplus
}
#endif
