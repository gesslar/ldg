// /daemon/auth.c
// Authentication daemon
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>

inherit STD_DAEMON ;

int authenticate(string name, string supplied)
{
    string home_path, password ;

    if(!name) raise_error("Missing arg 1 to authenticate.\n") ;
    if(!supplied) raise_error("Missing arg 2 to authenticate.\n") ;

    home_path = player_path(name) ;
    password = read_file(home_path + "password") ;
  
    if(!password) raise_error("No such password on file for "+name+"\n") ;
    if(password[<1] == '\n') password = password[0..<2] ;

    return crypt(supplied, password) == password ;
}

void update_password(string name, string supplied)
{
    string home_path, password ;

    if(!name) return ;
    if(!supplied) return ;

    home_path = player_path(name) ;
    password = crypt(supplied, 0) ;

    write_file(home_path + "password", password, 1) ;
}
