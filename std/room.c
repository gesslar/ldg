// /std/room.c
// Standard inheritible for rooms
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>
#include <object_types.h>

inherit STD_OBJECT ;

protected void set_up()
{
    object_type |= OT_ROOM ;
    :set_up() ;
}

protected void _setup_room()
{
    call_other(this_object(), "setup_room") ;
}
