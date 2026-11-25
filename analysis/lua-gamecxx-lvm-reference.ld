/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(luaV_tonumber)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
luaD_call = 0x802d0660;
luaD_growstack = 0x802cff34;
luaG_concaterror = 0x802cf8c4;
luaG_ordererror = 0x802cf958;
luaG_runerror = 0x802cfb10;
luaG_typeerror = 0x802cf7fc;
luaH_get = 0x802d6ca0;
luaH_set = 0x802d6d30;
luaO_rawequalObj = 0x802d23c0;
luaO_str2d = 0x802d2454;
luaS_newlstr = 0x802d5e30;
luaT_gettm = 0x802d6eec;
luaT_gettmbyobj = 0x802d6f44;
luaZ_openspace = 0x802d9c08;
memcpy = 0x802eee50;
sprintf = 0x802ec254;
strcoll = 0x802ef2dc;
strlen = 0x802ef9c0;
SECTIONS {
  .text.luaV_tonumber 0x802d7a5c : { *(.text.luaV_tonumber) }
  .text.luaV_tostring 0x802d7acc : { *(.text.luaV_tostring) }
  .text.callTMres 0x802d7c88 : { *(.text.callTMres) }
  .text.callTM 0x802d7d2c : { *(.text.callTM) }
  .text.luaV_getnotable 0x802d7e80 : { *(.text.luaV_getnotable) }
  .text.luaV_gettable 0x802d7f1c : { *(.text.luaV_gettable) }
  .text.luaV_settable 0x802d7fb8 : { *(.text.luaV_settable) }
  .text.call_binTM 0x802d80e8 : { *(.text.call_binTM) }
  .text.get_compTM 0x802d8190 : { *(.text.get_compTM) }
  .text.call_orderTM 0x802d8270 : { *(.text.call_orderTM) }
  .text.luaV_strcmp 0x802d832c : { *(.text.luaV_strcmp) }
  .text.luaV_lessthan 0x802d83bc : { *(.text.luaV_lessthan) }
  .text.luaV_lessequal 0x802d8470 : { *(.text.luaV_lessequal) }
  .text.luaV_equalval 0x802d8560 : { *(.text.luaV_equalval) }
  .text.luaV_concat 0x802d8698 : { *(.text.luaV_concat) }
  .rodata 0x803da3e8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
