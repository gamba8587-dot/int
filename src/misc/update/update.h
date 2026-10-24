#pragma once
#include "windows.h"

#include "lua.h"

#define reb(x) x + (uintptr_t)(GetModuleHandle(nullptr))

namespace update {
	namespace roblox {
		const uintptr_t print = reb(0x190fde0);
		const uintptr_t require_bypass = 0x870;
	}

	namespace lua {
		const uintptr_t luau_execute = reb(0x37a4540);
		const uintptr_t luad_throw = reb(0x379ccf0);
		const uintptr_t luao_nilobject = reb(0x5303228);
		const uintptr_t luah_dummynode = reb(0x5302c48);
		const uintptr_t opcode_lookup_table = reb(0x57a6ac0);
	}

	namespace datamodel {
		const uintptr_t fake_datamodel_pointer = reb(0x74287c8);
		const uintptr_t fake_datamodel_to_datamodel = 0x1c0;
		const uintptr_t script_context = 0x3d0;
		const uintptr_t game_loaded = 0x5f0;
	}

	namespace instance {
		const uintptr_t name = 0x60;
		const uintptr_t class_desc = 0x18;
		const uintptr_t class_name = 0x8;

		const uintptr_t parent = 0x50;
		const uintptr_t children = 0x60;
		const uintptr_t children_end = 0x8;
	}

	namespace script {
		namespace local_script {
			const uintptr_t bytecode = 0x1a8;
			const uintptr_t hash = 0x1b8;
		}

		namespace module_script {
			const uintptr_t bytecode = 0x150;
			const uintptr_t hash = 0x168;
		}
	}
}

namespace roblox {
	using print_t = void(__fastcall*)(int, const char*, ...);
	inline auto print = (print_t)(update::roblox::print);

	using luau_execute_t = void(__fastcall*)(lua_State*);
	inline auto luau_execute = (luau_execute_t)(update::lua::luau_execute);

	using luad_throw_t = void(__fastcall*)(lua_State*, int);
	inline auto luad_throw = (luad_throw_t)(update::lua::luad_throw);
}