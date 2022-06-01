// /std/link.c
// This is the link object that exists when a player
// enters the game.
//
// Created:     2022/05/31: Gesslar
// Last Change: 2022/05/31: Gesslar
//
// 2022/05/31: Gesslar - Created

#include <global.h>
#include <input_to.h>

inherit STD_BASE ;

// Variables
private nosave int time_out = 120 ;

// Functions
private int valid_name(string str) ;

protected int logon()
{
    // time_to_save = 500;
    cat("/etc/WELCOME") ;
    input_to("get_name", INPUT_PROMPT, "What is your name: ") ;
    call_out("time_out", time_out) ;
    return 1 ;
}

protected void get_name(string str)
{
    if(!str || str == "")
    {
        destruct(this_object());
        return;
    }

    str = lower_case(str);

    if(!valid_name(str)) {
        input_to("logon2", INPUT_PROMPT, "What is your name: ");
        return;
    }

    string *banished = explode_file("/etc/banish.txt") ;
    if(member(banished, str) > -1)
    {
        write("That name is reserved.\n");
        destruct(this_object());
        return;
    }

    // if(!restore_object("players/" + str)) {
    //     write("New character.\n");
    // }
    // time_to_save = age + 500;
    // /*
    //  * Don't do this before the restore !
    //  */
    // name = str;                        /* Must be here for a new player. */
    // dead = ghost;
    // myself = this_player();
    // if(is_invis)
    //     cap_name = "Someone";
    // else
    //     cap_name = capitalize(name);

    // local_weight = 0;
    // armour_class = 0;
    // name_of_weapon = 0;
    // weapon_class = 0;
    // /* If this is a new character, we call the adventurers guild to get
    //  * our first title !
    //  */
    // if(level != -1)
    //     input_to("check_password", 1);
    // else
    //     input_to("new_password", 1);
    // write("Password: ");
    // if(name == "guest")
    //     write("(just CR) ");
    // attacker_ob = 0;
    // alt_attacker_ob = 0;
    // return;
}


/*
 * Check that a player name is valid. Only allow
 * lowercase letters.
 */
private int valid_name(string str)
{
    int length;

    length = sizeof(str);

    if(length < 3 || length > 11)
    {
        write("Your name must be from 3 to 11 alphabetic characters long.\n") ;
    }

    while(length--)
    {
        if(str[length] < 'a' || str[length] > 'z')
        {
            write("Your name may only contain alphabetic characters.\n") ;
            return 0;
        }
    }

    return 1;
}
 