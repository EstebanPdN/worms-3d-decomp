/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaV_tonumber)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaC_collectgarbage = 0x802d1fe4;
luaD_call = 0x802d0660;
luaD_callhook = 0x802cffe4;
luaD_growstack = 0x802cff34;
luaD_poscall = 0x802d0590;
luaD_precall = 0x802d0344;
luaF_close = 0x802d0d2c;
luaF_findupval = 0x802d0c98;
luaF_newLclosure = 0x802d0c20;
luaG_aritherror = 0x802cf8fc;
luaG_concaterror = 0x802cf8c4;
luaG_inithooks = 0x802ceafc;
luaG_ordererror = 0x802cf958;
luaG_runerror = 0x802cfb10;
luaG_typeerror = 0x802cf7fc;
luaH_get = 0x802d6ca0;
luaH_getstr = 0x802d6c48;
luaH_new = 0x802d68d8;
luaH_set = 0x802d6d30;
luaH_setnum = 0x802d6ddc;
luaO_rawequalObj = 0x802d23c0;
luaO_str2d = 0x802d2454;
luaS_newlstr = 0x802d5e30;
luaT_gettm = 0x802d6eec;
luaT_gettmbyobj = 0x802d6f44;
luaZ_openspace = 0x802d9c08;
memcpy = 0x802eee50;
sprintf = 0x802ec254;
strlen = 0x802ef9c0;
SECTIONS {
  .text.luaV_tonumber 0x802d7a5c : { *(.text.luaV_tonumber) }
  .text.luaV_tostring 0x802d7acc : { *(.text.luaV_tostring) }
  .text.traceexec 0x802d7b4c : { *(.text.traceexec) }
  .text.callTMres 0x802d7c88 : { *(.text.callTMres) }
  .text.callTM 0x802d7d2c : { *(.text.callTM) }
  .text.luaV_index 0x802d7dd8 : { *(.text.luaV_index) }
  .text.luaV_getnotable 0x802d7e80 : { *(.text.luaV_getnotable) }
  .text.luaV_gettable 0x802d7f1c : { *(.text.luaV_gettable) }
  .text.luaV_settable 0x802d7fb8 : { *(.text.luaV_settable) }
  .text.call_binTM 0x802d80e8 : { *(.text.call_binTM) }
  .text.get_compTM 0x802d8190 : { *(.text.get_compTM) }
  .text.call_orderTM 0x802d8270 : { *(.text.call_orderTM) }
  .text.luaV_lessthan 0x802d83bc : { *(.text.luaV_lessthan) }
  .text.luaV_lessequal 0x802d8470 : { *(.text.luaV_lessequal) }
  .text.luaV_equalval 0x802d8560 : { *(.text.luaV_equalval) }
  .text.luaV_concat 0x802d8698 : { *(.text.luaV_concat) }
  .text.Arith 0x802d8880 : { *(.text.Arith) }
  .text.luaV_execute 0x802d8a28 : { *(.text.luaV_execute) }
  .rodata 0x803da3e8 : { *(.rodata) }
  .sdata 0x804b1968 (NOLOAD) : {
    . = 0x0; luaO_nilobject = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
