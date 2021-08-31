/*
 * File:   gameController.c
 * Author: sebastie.metral
 *
 * Created on 30. août 2021, 12:40
 */
#include "gameController.h"
typedef enum state{NOGAME,LOCAL,ONLINE} state;
enum state gameControllerState;

void gameControllerInit()
{
    gameControllerState=NOGAME;
    gameControllerController();    
}
void gameControllerSM(Event ev)
{
   switch(gameControllerState)
    {
        case NOGAME:
            //check position du touch voir les event a créer
            break;
        case LOCAL:
            //Update value for ball, both paddle and score for one player
            break;
        case ONLINE:
            //Update value for ball, both paddle and score for two player
            break;
        default:
            break;
    } 
}
void gameControllerController()
{
    switch(gameControllerState)
    {
        case NOGAME:
            break;
        case LOCAL:
            break;
        case ONLINE:
            break;
        default:
            break;
    }
}
