// /std/object.c
// Standard object inheritible
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>
#include <object_types.h>

inherit STD_BASE ;

inherit __DIR__ "modules/description"

protected void set_up()
{
    object_type = OT_OBJECT ;
    ::set_up() ;
}

void _setup_object()
{
    call_other(this_object(), "setup_object") ;
}
