/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_timer_cancel)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lua_gettop = 0x802cd7f4;
lua_isnumber = 0x802cda9c;
lua_settop = 0x802cd808;
lua_tonumber = 0x802cdc5c;
w3d_script_report_error = 0x801022ec;
w3d_timer_backend_cancel = 0x800c56b8;
SECTIONS {
  .text.w3d_timer_cancel 0x80060050 : { *(.text.w3d_timer_cancel) }
  .text.w3d_script_cancel_timer 0x80102cc4 : { *(.text.w3d_script_cancel_timer) }
  .rodata 0x80398fe8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
