#ifdef __WAND__
target[name[paramobj.o] type[object]]
#endif

#include "paramobj.h"
#include "paraminfo.h"

Config::Paramobj::Paramobj(const Paraminfo& pi,ParamGroup* group):
	m_name(pi.m_name),m_group(group),m_id(pi.m_id)
	{}

