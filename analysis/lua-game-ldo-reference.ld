/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(seterrorobj)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
exit = 0x802ed984;
longjmp = 0x802eff30;
luaC_collectgarbage = 0x802d1fe4;
luaF_close = 0x802d0d2c;
luaF_newLclosure = 0x802d0c20;
luaG_runerror = 0x802cfb10;
luaG_typeerror = 0x802cf7fc;
luaH_new = 0x802d68d8;
luaH_set = 0x802d6d30;
luaH_setnum = 0x802d6ddc;
luaM_realloc = 0x802d2108;
luaS_newlstr = 0x802d5e30;
luaT_gettmbyobj = 0x802d6f44;
luaU_undump = 0x802d79e8;
luaV_execute = 0x802d8a28;
luaY_parser = 0x802d371c;
setjmp = 0x802efe74;
SECTIONS {
  .text.seterrorobj 0x802cfbc8 : { *(.text.seterrorobj) }
  .text.luaD_throw 0x802cfc7c : { *(.text.luaD_throw) }
  .text.luaD_rawrunprotected 0x802cfcc0 : { *(.text.luaD_rawrunprotected) }
  .text.restore_stack_limit 0x802cfd38 : { *(.text.restore_stack_limit) }
  .text.correctstack 0x802cfda8 : { *(.text.correctstack) }
  .text.luaD_reallocstack 0x802cfe48 : { *(.text.luaD_reallocstack) }
  .text.luaD_reallocCI 0x802cfeb4 : { *(.text.luaD_reallocCI) }
  .text.luaD_growstack 0x802cff34 : { *(.text.luaD_growstack) }
  .text.luaD_growCI 0x802cff78 : { *(.text.luaD_growCI) }
  .text.luaD_callhook 0x802cffe4 : { *(.text.luaD_callhook) }
  .text.adjust_varargs 0x802d00d8 : { *(.text.adjust_varargs) }
  .text.tryfuncTM 0x802d0270 : { *(.text.tryfuncTM) }
  .text.luaD_precall 0x802d0344 : { *(.text.luaD_precall) }
  .text.callrethooks 0x802d0510 : { *(.text.callrethooks) }
  .text.luaD_poscall 0x802d0590 : { *(.text.luaD_poscall) }
  .text.luaD_call 0x802d0660 : { *(.text.luaD_call) }
  .text.resume 0x802d072c : { *(.text.resume) }
  .text.lua_resume 0x802d083c : { *(.text.lua_resume) }
  .text.lua_yield 0x802d08c8 : { *(.text.lua_yield) }
  .text.luaD_pcall 0x802d09b8 : { *(.text.luaD_pcall) }
  .text.f_parser 0x802d0a5c : { *(.text.f_parser) }
  .text.luaD_protectedparser 0x802d0b24 : { *(.text.luaD_protectedparser) }
  .rodata 0x803d9bc8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
