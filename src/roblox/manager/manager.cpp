#include "manager.h"

uintptr_t manager::get_datamodel() {
	auto fake_dm_ptr = *(uintptr_t*)(update::datamodel::fake_datamodel_pointer);
	return *(uintptr_t*)(fake_dm_ptr + update::datamodel::fake_datamodel_to_datamodel);
}

uintptr_t manager::get_script_context() {
	uintptr_t children = *(uintptr_t*)(get_datamodel() + update::instance::children);
	uintptr_t script_context = *(uintptr_t*)(children) + update::datamodel::script_context;
	return *(uintptr_t*)(script_context);
}

uintptr_t manager::get_lua_state() {
	uintptr_t sc = manager::get_script_context();
	uintptr_t ptr = sc + 0x210 + (0x1F0);
	uint32_t key = (uint32_t)ptr;
	uint32_t low = *((uint32_t*)ptr) ^ key;
	uint32_t high = *((uint32_t*)(ptr + 4)) ^ key;
	uintptr_t lua_state = ((uintptr_t)high << 32) | low;
	return lua_state;
}

void manager::set_proto_capabilities(Proto* proto, uintptr_t* c) {
	if (!proto) return;
	proto->userdata = c;
	for (int i = 0; i < proto->sizep; ++i)
		set_proto_capabilities(proto->p[i], c);
}

void manager::set_thread_capabilities(lua_State* L, int i, uintptr_t c) {
	*(int*)((uintptr_t)(L->userdata) + 0x30) = i;
	*(uintptr_t*)((uintptr_t)(L->userdata) + 0x48) = c;
}