#ifdef __WAND__
target[name[param_group.o] type[object]]
#endif

#include "param_group.h"
#include "uiprovider.h"
		
void Config::ParamGroup::controlCreate(UIProvider& ui)
	{
	ui.create(*this);
	}

Config::Paramobj* Config::ParamGroup::create(const Paraminfo& info,ParamGroup* group)
	{return new ParamGroup(info,group);}
