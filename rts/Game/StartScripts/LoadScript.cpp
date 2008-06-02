#include <iostream>
#include <vector>
#include "StdAfx.h"
#include "LoadScript.h"
#include "ExternalAI/GlobalAIHandler.h"
#include "Game/GameSetup.h"
#include "Game/Team.h"
#include "Sim/Units/UnitDefHandler.h"
#include "System/LoadSaveHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/Platform/FileSystem.h"

extern std::string stupidGlobalMapname;

CLoadScript::CLoadScript(std::string file)
: CScript(std::string("Load ") + filesystem.GetFilename(file)),
  file(file)
{
}

CLoadScript::~CLoadScript(void)
{
}

void CLoadScript::Update(void)
{
	if(!started) {
		loader.LoadGame();
		started = true;
	}
}

void CLoadScript::ScriptSelected()
{
	loader.LoadGameStartInfo(file);		//this is the first time we get called after getting choosen
	started = false;
	loadGame = true;
}

std::string CLoadScript::GetMapName(void)
{
	return loader.mapName;
}

std::string CLoadScript::GetModName(void)
{
	//this is the second time we get called after getting choosen
	return loader.modName;
}
