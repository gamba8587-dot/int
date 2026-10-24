#pragma once
#include "windows.h"

#include "lua.h"
#include "lstate.h"

#include "misc/update/update.h"

class manager {
public:
	static uintptr_t get_datamodel();
	static uintptr_t get_script_context();
	static uintptr_t get_lua_state();

	static void set_proto_capabilities(Proto* proto, uintptr_t* c);
	static void set_thread_capabilities(lua_State* L, int i, uintptr_t c);
};