/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(currentpc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_call = 0x802d0660;
luaD_growstack = 0x802cff34;
luaD_throw = 0x802cfc7c;
luaF_getlocalname = 0x802d0f58;
luaO_chunkid = 0x802d28fc;
luaO_pushfstring = 0x802d2868;
luaO_pushvfstring = 0x802d256c;
luaO_rawequalObj = 0x802d23c0;
luaP_opmodes = 0x803d9e40;
luaT_typenames = 0x803da108;
luaV_tonumber = 0x802d7a5c;
strchr = 0x802ef198;
SECTIONS {
  .text.currentpc 0x802cea4c : { *(.text.currentpc) }
  .text.currentline 0x802cea98 : { *(.text.currentline) }
  .text.luaG_inithooks 0x802ceafc : { *(.text.luaG_inithooks) }
  .text.lua_sethook 0x802ceb4c : { *(.text.lua_sethook) }
  .text.lua_getstack 0x802ceb88 : { *(.text.lua_getstack) }
  .text.getluaproto 0x802cec24 : { *(.text.getluaproto) }
  .text.funcinfo 0x802cec48 : { *(.text.funcinfo) }
  .text.travglobals 0x802cece4 : { *(.text.travglobals) }
  .text.info_tailcall 0x802ced74 : { *(.text.info_tailcall) }
  .text.auxgetinfo 0x802cedf4 : { *(.text.auxgetinfo) }
  .text.lua_getinfo 0x802cef54 : { *(.text.lua_getinfo) }
  .text.precheck 0x802cf06c : { *(.text.precheck) }
  .text.checkopenop 0x802cf0c0 : { *(.text.checkopenop) }
  .text.checkRK 0x802cf110 : { *(.text.checkRK) }
  .text.luaG_symbexec 0x802cf144 : { *(.text.luaG_symbexec) }
  .text.luaG_checkcode 0x802cf590 : { *(.text.luaG_checkcode) }
  .text.kname 0x802cf5b8 : { *(.text.kname) }
  .text.getobjname 0x802cf5f0 : { *(.text.getobjname) }
  .text.getfuncname 0x802cf72c : { *(.text.getfuncname) }
  .text.isinstack 0x802cf7c8 : { *(.text.isinstack) }
  .text.luaG_typeerror 0x802cf7fc : { *(.text.luaG_typeerror) }
  .text.luaG_concaterror 0x802cf8c4 : { *(.text.luaG_concaterror) }
  .text.luaG_aritherror 0x802cf8fc : { *(.text.luaG_aritherror) }
  .text.luaG_ordererror 0x802cf958 : { *(.text.luaG_ordererror) }
  .text.addinfo 0x802cf9cc : { *(.text.addinfo) }
  .text.luaG_errormsg 0x802cfa50 : { *(.text.luaG_errormsg) }
  .text.luaG_runerror 0x802cfb10 : { *(.text.luaG_runerror) }
  .rodata 0x803d9a8c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
