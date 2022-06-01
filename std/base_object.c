// /std/base_object.c
// Basic object, other objects, etc, inherit this
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>
#include <object_types.h>

// Variables
protected nosave int object_type = 0 ;

// Functions
protected void set_up() ;

void create()
{
    set_up() ;
}

protected void set_up()
{
    if(object_type & OT_OBJECT) call_other(this_object(), "_setup_object") ;
    if(object_type & OT_ROOM) call_other(this_object(), "_setup_room") ;
    if(object_type & OT_DAEMON) call_other(this_object(), "_setup_daemon") ;
}

void _setup_object()
{
    call_other(this_object(), "setup_object") ;
}
