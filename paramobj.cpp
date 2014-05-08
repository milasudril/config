#ifdef __WAND__
target[name[paraminfo.o] type[object]]
#endif

#include "paramobj.h"
#include "paraminfo.h"

Config::Paramobj::Paramobj(const Paraminfo& pi,const Paramobj& group):
	m_name(pi.m_name),m_group(group),m_id(pi.m_id)
	{}

