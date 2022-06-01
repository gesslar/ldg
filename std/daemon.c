// /std/daemon.c
// Base inheritible for daemons
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>
#include <object_types.h>

inherit STD_BASE ;

protected void set_up()
{
    object_type |= OT_DAEMON ;
    ::set_up() ;
}

void _setup_daemon()
{
    call_other(this_object(), "setup_daemon") ;
}
