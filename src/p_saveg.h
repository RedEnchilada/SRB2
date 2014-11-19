// SONIC ROBO BLAST 2
//-----------------------------------------------------------------------------
// Copyright (C) 1993-1996 by id Software, Inc.
// Copyright (C) 1998-2000 by DooM Legacy Team.
// Copyright (C) 1999-2014 by Sonic Team Junior.
//
// This program is free software distributed under the
// terms of the GNU General Public License, version 2.
// See the 'LICENSE' file for more details.
//-----------------------------------------------------------------------------
/// \file  p_saveg.h
/// \brief Savegame I/O, archiving, persistence

#ifndef __P_SAVEG__
#define __P_SAVEG__

#ifdef __GNUG__
#pragma interface
#endif

// Persistent storage/archiving.
// These are the load / save game routines.

void P_SaveGame(void);
void P_SaveNetGame(void);
boolean P_LoadGame(INT16 mapoverride);
boolean P_LoadNetGame(void);

mobj_t *P_FindNewPosition(UINT32 oldposition);

typedef struct
{
	UINT8 skincolor;
	UINT8 skin;
	UINT8 botskin;
	UINT8 botcolor;
	INT32 score;
	INT32 lives;
	INT32 continues;
	UINT16 emeralds;
} savedata_t;

extern savedata_t savedata;
extern UINT8 *save_p;

typedef struct luasavedata_s
{
    char key[64]; // Max length of keys in savedata (would a hashing mechanism work better? ?? ???)

    UINT16 valuelength; // 0 = int stored, >0 = string being stored, value is length of string

    // Possible values
    INT32 value;
    char *str;
} luasavedata_t;

extern luasavedata_t *luassgdata; // Array of data values
extern size_t luassgdataCount; // Amount of savedata vars held
extern size_t luassgdataAlloc; // Amount of savedata space allocated

#endif
