// /daemon/command.c
// The command daemon. Handles/manages all of the game commands!
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>

inherit STD_DAEMON ;

// Variables
private nosave string base = "/cmd/" ;
private nosave mapping commands = ([ ]) ;

// Functions
public void rehash_commands(string path) ;

void setup_daemon()
{

}

public void rehash_commands(string path = base)
{
    write(path + "\n") ;
}
